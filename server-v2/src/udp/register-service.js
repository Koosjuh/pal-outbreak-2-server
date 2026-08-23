import { createHash } from 'node:crypto';
import dgram from 'node:dgram';

import { blowfishEcbEncrypt, createBlowfishKey } from '../crypto/blowfish.js';
import {
  OPCODE_APP_ACK,
  OPCODE_BIND,
  OPCODE_REGISTER,
  OPCODE_TRANSPORT_ACK,
  buildRegisterReplyPlaintext,
  decodeBindRequest,
  decodeRegisterRequest,
  decodeSnapUdpDatagram,
  encodeRegisterReply,
  encodeSlot1cPush,
  encodeTransportAck,
  readBindTailBlob
} from '../protocol/snap-udp-register-codec.js';
import { RegisterSessionTable } from './register-sessions.js';
import { RegistrationNonceTable } from './registration-nonces.js';
import { latencyTicksFromTlvs } from './snap-lobby-sessions.js';

export const REGISTER_PORT = 9090;

/**
 * WHAT A BIND PROVED ABOUT ITS REGISTRATION, as one named value per outcome.
 *
 * Only `VERIFIED` is proof. The rest are the distinguishable ways a bind can
 * fail to prove anything, kept separate because on the rig they mean very
 * different things - a client that echoes nothing is a client behaviour, a nonce
 * minted for another account is an attack, and the two must never read alike in
 * a journal.
 */
export const BIND_ATTACHMENT = Object.freeze({
  /** The bind echoed a live nonce we minted for THIS account. */
  VERIFIED: 'verified',
  /** The nonce is switched off, so no bind can prove anything at all. */
  NOT_CONFIGURED: 'nonce-not-configured',
  /** The body is too short to carry the tail field. */
  TAIL_FIELD_ABSENT: 'tail-field-absent',
  /** A declared length that does not fit the body or the client's echo window. */
  TAIL_MALFORMED: 'tail-malformed',
  /** Length 0: the client did not echo. */
  TAIL_EMPTY: 'tail-empty',
  /** Sixteen bytes that no live pending registration holds. */
  NONCE_NOT_ATTACHED: 'nonce-not-attached',
  /** A nonce we did mint, but for a DIFFERENT account than this register named. */
  HANDLE_MISMATCH: 'nonce-belongs-to-another-account'
});

/**
 * The client sends one message per datagram in this phase. A generous cap that
 * still bounds the work an unauthenticated source can make us do: without it,
 * one 64 KB datagram of unknown opcodes produced 4000 log lines.
 */
const MAXIMUM_MESSAGES_PER_DATAGRAM = 8;

/**
 * The post-register bind's message length, `who & 0x3ff` = 0x146 (326 bytes,
 * 330 on the wire). Opcode 0x01 is reused for game-phase snapshots at other
 * lengths, and those must not be treated as a bind.
 */
const POST_REGISTER_BIND_MESSAGE_LENGTH = 0x146;

/**
 * The POST-LOBBY SNAPSHOT: opcode 0x01 again, message length `0x236` (566; 570
 * on the wire). The client sends it after the TCP-10127 lobby walk, once Server
 * Select has resolved an entry host and it opens a SN@P session there.
 *
 * IT IS THE SAME REGISTER BUILDER. `FUN_005bd2e0.c:93` passes `0xf0` as the last
 * argument of `func_0x001db7e8` where the connect screen `FUN_00626900.c:57`
 * passes `0`, and that argument is `conn+0x64` - which is both the bind's extra
 * body length and the op-0x0c body length (`FUN_001de470.c:14,29`). The archive's
 * 570-byte datagram carries `00 00 00 f0` at body `+0x04`, which closes V1's
 * long-standing "unknown +0x14" note.
 *
 * V1 classified it on the first wire byte (`game_udp_server.js:1298`,
 * `kindByte === 0x32`), the same discriminator as this length: byte 0's low two
 * bits are the length's high bits, so `0x31 -> 0x146` and `0x32 -> 0x236`.
 *
 * Runtime evidence, which outranks everything else here: V1 answered it in 38
 * archived sessions and the client proceeded. V2 previously observed and did not
 * answer it, citing V1's guard at `game_udp_server.js:2770-2776` - a MISREADING
 * that stalled the 2026-08-06 T32 rig run into error 840. That guard says do not
 * ARM THE TCP LOBBY from this message, because arming from it "leaves stale
 * pending entries that make the next TCP connect run the wrong state machine".
 * It says nothing about answering, and V1 does both (`:2985-2987`).
 */
const POST_LOBBY_SNAPSHOT_MESSAGE_LENGTH = 0x236;

/**
 * The sequence the register reply carries, and the base the post-selection
 * stamped stream continues from.
 *
 * The archive's third register epoch is the whole argument: reply at seq 0, the
 * slot-0x1c push at seq 0, then the op-0x48 reply at 1, the op-0x0c completion
 * at 2 and the member list at 3 - every one of them delivered by a real PS2. So
 * the client's ordered window does NOT consume the 0x2d (it is handled by
 * `FUN_001d9678` before the reliable channel exists); the PUSH is what takes
 * `recvBase` to 1, and the stamped stream starts above it.
 */
const REGISTER_REPLY_SEQUENCE = 0;

/**
 * The sequence BOTH slot-0x1c pushes carry, and it is a constant on purpose.
 *
 * The push is RELIABLE (`b0 18 00 28`), so it sits in the client's ordered
 * receive window and its sequence is what `recvBase` reaches when it is
 * delivered. Every archived push - after the bind and after the 566-byte
 * snapshot - carries 0, and every archived client message this answers also
 * carries 0, so a mirror and a constant are INDISTINGUISHABLE on all observed
 * input. They are not indistinguishable on a synthetic non-zero: a mirrored
 * push at sequence N goes out reliable at N while the epoch this service opens
 * behind it starts the client's stream at 0, and a reliable message above
 * `recvBase` is buffered, never delivered, and the connect spinner never ends -
 * which is the failure `#onBind` already cites as the reason ITS push must not
 * mirror.
 *
 * V1 mirrored here (`game_udp_server.js:2991-3000`) and constant-zeroed at the
 * bind; both shipped and both were accepted, because the client never gave
 * either one a non-zero to mirror. The constant is chosen for both because it
 * is the one reading that cannot desynchronise a fresh epoch.
 */
const SLOT1C_PUSH_SEQUENCE = 0;

/**
 * The SN@P UDP :9090 register service.
 *
 * This exchange IS the authentication. There is no status field in a 0x2d
 * reply: the client decrypts the body with the password IT holds and
 * `strcmp`s the plaintext against the login identity it sent
 * (`FUN_001d9678`). Only a server holding the same password can produce a body
 * that matches. So there is no error reply to design - we either hold the
 * password or we do not.
 *
 * On a miss we deliberately STAY SILENT rather than send opcode 0x31. Silence
 * is the documented, observed path: `conn+0x80` stays 1 and the connect screen
 * retries three times before showing its own failure (`FUN_00626900` case 7).
 * The 0x31 reject path is decompile-derived but has never been captured, so
 * sending it would be guessing at a wire format. Every silent drop is logged
 * with its reason, so a rig result is always attributable.
 *
 * BINDING: the service binds a specific interface address, never 0.0.0.0.
 * `FUN_001d72a8` discards any datagram whose source IP:port does not exactly
 * match serverIP:9090, and a wildcard bind on a multi-homed host can answer
 * from a different source address - which looks exactly like broken crypto.
 */
export class SnapRegisterService {
  /**
   * @param {object} options
   * @param {string} options.bindAddress interface address to bind. Required and
   *   never a wildcard - see the note above.
   * @param {string} options.advertisedAddress IPv4 the client should use for all
   *   post-register traffic. Placed at reply plaintext +0x28.
   * @param {object} options.accountRepository must expose
   *   `getCompatibilitySecretByLoginIdentity(userid)` returning the plaintext
   *   password, which is the Blowfish key.
   * @param {object} options.logger structured logger.
   * @param {number} [options.port]
   */
  constructor({
    bindAddress,
    advertisedAddress,
    accountRepository,
    logger,
    port = REGISTER_PORT,
    sessions = null,
    onLobbyReady = null,
    /*
     * THE ATTACHMENT NONCE.
     *
     * When absent the register reply carries tail length 0, which is
     * byte-identical to what V1 and every previous V2 build have sent - so this
     * is the negative control, and the rollback, in one option.
     *
     * When present a 16-byte nonce is minted per registration and placed in the
     * reply's tail blob, INSIDE the body we encrypt under the account password.
     * T33 was the gate on whether an unmodified client echoes it back in the
     * bind; the rig run of 2026-08-06 settled that it does
     * (`captures/v2-live/t33-run11-nonce-echo.pcap`; the nonce appears in
     * cleartext exactly once in that capture, in the client's bind).
     *
     * The echo is now the bind's ATTACHMENT PROOF - it is what lets a bind show
     * which registration, and therefore which authenticated account, it belongs
     * to. It still does NOT gate the bind's own reply: a client that does not
     * echo is answered exactly as before, because refusing it would break a path
     * that works for a property the ACK and push do not carry. What the echo
     * gates is displacement of a live account session (`account-session.js`).
     */
    registrationNonces = null,
    /*
     * THE POST-SELECTION SUBSYSTEM (`udp/snap-lobby-sessions.js`).
     *
     * Absent, this service behaves exactly as it did before: the 566-byte
     * snapshot and every post-selection opcode are observed and not answered.
     * That is the rollback, and it is also what every existing test exercises.
     *
     * Present, it owns everything after the bind - the reliable channel, the
     * ack-all-reliable rule, the monotonic outbound sequence and the op-0x40
     * keepalive. It is injected rather than constructed here because it needs
     * the process's one timing wheel, and a service that made its own would
     * reintroduce a timer per session.
     */
    lobby = null
  }) {
    if (!bindAddress || bindAddress === '0.0.0.0' || bindAddress === '::') {
      throw new Error(
        'register service needs a specific bind address; the client drops replies ' +
          'whose source address is not exactly the one it registered against'
      );
    }
    if (!advertisedAddress) throw new Error('advertisedAddress is required');
    if (typeof accountRepository?.getCompatibilitySecretByLoginIdentity !== 'function') {
      throw new Error('accountRepository must expose getCompatibilitySecretByLoginIdentity');
    }
    this.bindAddress = bindAddress;
    this.advertisedAddress = advertisedAddress;
    this.accountRepository = accountRepository;
    this.logger = logger;
    // Keep the CONFIGURED port separate from the bound one. `port` becomes the
    // actual bound port after start(), so the reply advertises somewhere real,
    // but a restart must re-bind what was configured rather than the ephemeral
    // port a previous run happened to be given.
    this.configuredPort = port;
    this.port = port;
    this.socket = null;
    // Which source addresses have completed a register, and as whom. The bind
    // carries no credential, so this is how it inherits the register's proof
    // instead of opening a second, unauthenticated identity path.
    this.sessions = sessions ?? new RegisterSessionTable();
    // Called once a client has completed the bind, so the composed application
    // can arm its address for the TCP 10127 LOBBY transcript. Without this a
    // client that reaches the lobby through the UDP register - which is what
    // happens whenever the memory card already holds an account, so no browser
    // flow runs - gets the boot-auth transcript and resets. V1 armed at exactly
    // this point (`game_udp_server.js:2787-2793`).
    this.onLobbyReady = onLobbyReady;
    this.registrationNonces =
      registrationNonces === true ? new RegistrationNonceTable() : (registrationNonces || null);
    this.lobby = lobby;
  }

  async start() {
    if (this.socket) throw new Error('register service already started');
    const socket = dgram.createSocket({ type: 'udp4', reuseAddr: false });
    socket.on('message', (datagram, remote) => this.#onDatagram(datagram, remote));
    socket.on('error', (error) => {
      this.logger?.error?.('udp9090 socket-error', { message: error.message });
    });
    try {
      await new Promise((resolve, reject) => {
        const onError = (error) => reject(error);
        socket.once('error', onError);
        socket.bind(this.configuredPort, this.bindAddress, () => {
          socket.removeListener('error', onError);
          resolve();
        });
      });
    } catch (error) {
      // Never leave the dgram handle open behind a failed bind: the composed
      // startup rolls back by calling stop(), which would not see this socket.
      await new Promise((resolve) => socket.close(resolve));
      throw error;
    }
    this.socket = socket;
    // Advertise the port we ACTUALLY bound, not the one we asked for. The reply
    // plaintext's +0x30 is the port the client talks to from here on, so an
    // ephemeral bind that advertised its requested 0 would send the client
    // nowhere.
    this.port = socket.address().port;
    this.logger?.info?.('udp9090 listening', {
      address: this.bindAddress,
      port: this.port,
      advertisedAddress: this.advertisedAddress
    });
    return this;
  }

  async stop() {
    // Sessions are released even if the socket was never bound: they own timing
    // entries, and a shutdown that leaves those behind is a leak the wheel's
    // owner assertion would only catch later, somewhere unrelated.
    const releasedLobbySessions = this.lobby?.closeAll('udp9090-stopped') ?? 0;
    if (!this.socket) return;
    const socket = this.socket;
    this.socket = null;
    await new Promise((resolve) => socket.close(resolve));
    this.logger?.info?.('udp9090 closed', { port: this.port, releasedLobbySessions });
  }

  address() {
    return this.socket ? this.socket.address() : null;
  }

  #onDatagram(datagram, remote) {
    const source = `${remote.address}:${remote.port}`;
    let messages;
    try {
      messages = decodeSnapUdpDatagram(datagram);
    } catch (error) {
      this.logger?.warn?.('udp9090 framing-rejected', {
        source,
        bytes: datagram.length,
        code: error.code,
        reason: error.message
      });
      return;
    }

    // ONE reply-producing message per datagram, whatever its opcode, and a hard
    // cap on how many messages we will even look at. The real client sends one
    // message per datagram here; anything else is either a bug or an attempt to
    // make the server amplify. Without this a 16 KB datagram of app-ACKs
    // produced 1000 outbound datagrams, and a datagram of unknown opcodes
    // produced 4000 log lines from an unauthenticated source.
    if (messages.length > MAXIMUM_MESSAGES_PER_DATAGRAM) {
      this.logger?.warn?.('udp9090 datagram-message-cap', {
        source,
        messages: messages.length,
        cap: MAXIMUM_MESSAGES_PER_DATAGRAM,
        note: 'datagram ignored; the client sends one message per datagram here'
      });
      return;
    }
    /*
     * POST-SELECTION ROUTING, decided before the per-message loop.
     *
     * Once a lobby session exists for this source, the whole DATAGRAM belongs to
     * its reliable channel - which is the only thing that can acknowledge by the
     * outer frame id, hold the ordered receive base and free retransmits. The
     * loop below is a one-reply-per-datagram register handshake and cannot do
     * any of that.
     *
     * Register and bind stay on the handshake path even when a session exists: a
     * re-register opens a FRESH epoch, and the channel it would be handed to is
     * the one that epoch replaces.
     */
    const lobbySession = this.lobby?.get(source) ?? null;
    const leadOpcode = messages[0].opcode;
    if (lobbySession != null && leadOpcode !== OPCODE_REGISTER && leadOpcode !== OPCODE_BIND) {
      this.#onLobbyDatagram(lobbySession, datagram, source);
      return;
    }

    let answered = false;
    let answeredRegister = false;
    for (const message of messages) {
      if (message.opcode === OPCODE_BIND) {
        // ONLY the 326-byte post-register bind. Opcode 0x01 is reused later for
        // game-phase snapshots (the 570-byte `32 36 00 01`), which are already
        // downstream of the TCP lobby walk. V1 guards this explicitly
        // (`game_udp_server.js:2770-2776`): arming from those "leaves stale
        // pending entries that make the next TCP connect run the wrong state
        // machine". Answering them would also re-send a push the client has
        // long since acknowledged.
        if (message.length === POST_LOBBY_SNAPSHOT_MESSAGE_LENGTH) {
          if (answered) {
            this.#logExtraMessageIgnored(source, message);
            continue;
          }
          answered = true;
          this.#onPostLobbySnapshot(message, remote, source);
          continue;
        }
        if (message.length !== POST_REGISTER_BIND_MESSAGE_LENGTH) {
          this.logger?.info?.('udp9090 observed-message', {
            source,
            opcode: '0x1',
            length: message.length,
            sequence: message.sequence,
            note: 'opcode 0x01 that is neither the post-register bind nor the post-lobby ' +
              'snapshot; observed, not answered'
          });
          continue;
        }
        if (answered) {
          this.#logExtraMessageIgnored(source, message);
          continue;
        }
        answered = true;
        this.#onBind(message, remote, source);
        continue;
      }
      if (message.opcode === OPCODE_APP_ACK) {
        if (answered) {
          this.#logExtraMessageIgnored(source, message);
          continue;
        }
        answered = true;
        this.#onAppAck(message, remote, source);
        continue;
      }
      if (message.opcode === OPCODE_TRANSPORT_ACK) {
        // The client acknowledging one of ours. Consumed, never answered -
        // acking an ack is how a loop starts.
        this.logger?.debug?.('udp9090 transport-ack-received', {
          source,
          acknowledged: message.acknowledgement
        });
        continue;
      }
      if (message.opcode !== OPCODE_REGISTER) {
        // Observed, not answered. Specifying these is a later slice.
        this.logger?.info?.('udp9090 observed-message', {
          source,
          opcode: `0x${message.opcode.toString(16)}`,
          length: message.length,
          sequence: message.sequence
        });
        continue;
      }
      if (answered || answeredRegister) {
        this.#logExtraMessageIgnored(source, message);
        continue;
      }
      answered = true;
      answeredRegister = true;
      this.#onRegister(message, remote, source, datagram);
    }
  }

  #onRegister(message, remote, source, datagram) {
    const datagramBytes = datagram.length;
    let request;
    try {
      request = decodeRegisterRequest(message);
    } catch (error) {
      this.logger?.warn?.('udp9090 register-undecodable', {
        source,
        bytes: datagramBytes,
        code: error.code,
        reason: error.message
      });
      return;
    }

    const context = {
      source,
      bytes: datagramBytes,
      loginIdentity: request.loginIdentity,
      auth: request.auth,
      endpointToken: `0x${request.endpointToken.toString(16).padStart(8, '0')}`,
      clientAddress: `${Array.from(request.clientIpv4).join('.')}:${request.clientPort}`,
      selector: `0x${request.selector.toString(16)}`,
      quantum: request.quantum,
      tlvs: request.tlvs.map((tlv) => `${tlv.tag}=${tlv.value}`).join(',')
    };
    this.logger?.info?.('udp9090 register-request', context);

    // The client builds `auth` as "<identity>@cee-auth" from the SAME buffer as
    // the identity, so a mismatch means we are looking at the documented
    // alternative form (identity + DNAS blob) or at something unmodelled.
    // Recorded, never gated on: rejecting would break a path we have not seen.
    const expectedAuth = `${request.loginIdentity}@cee-auth`;
    if (request.auth !== expectedAuth) {
      this.logger?.info?.('udp9090 register-auth-unexpected-form', {
        source,
        expected: expectedAuth,
        actual: request.auth
      });
    }

    if (!request.loginIdentity) {
      this.logger?.warn?.('udp9090 register-refused', {
        ...context,
        outcome: 'silent-drop',
        reason: 'empty login identity'
      });
      return;
    }

    let password;
    try {
      // The identity is already a trimmed C string: the codec reads it out of
      // its 40-byte NUL-padded field, which is the lookup key's contract.
      password = this.accountRepository.getCompatibilitySecretByLoginIdentity(
        request.loginIdentity
      );
    } catch (error) {
      // An account row that exists but whose sealed secret will not open is a
      // real fault, not a missing account - say so rather than blaming the client.
      this.logger?.error?.('udp9090 register-secret-unsealable', {
        ...context,
        outcome: 'silent-drop',
        reason: error.message
      });
      return;
    }

    if (!password) {
      this.logger?.warn?.('udp9090 register-refused', {
        ...context,
        outcome: 'silent-drop',
        reason: 'no account for this login identity',
        note: 'the client will retry three times and then show its own connect failure'
      });
      return;
    }

    let reply;
    /*
     * Mint the attachment nonce BEFORE building the reply, so a failure to mint
     * (capacity, bad random source) refuses the registration rather than
     * silently sending a reply with no nonce that the bind can never match.
     * Declared out here because the send callback reports it.
     */
    let attachmentNonce = null;
    try {
      if (this.registrationNonces != null) {
        try {
          attachmentNonce = this.registrationNonces.issue({
            handle: request.loginIdentity,
            sourceAddress: remote.address,
            sourcePort: remote.port,
            endpointToken: message.endpointToken,
            epoch: message.sequence
          });
        } catch (error) {
          this.logger?.warn?.('udp9090 register-nonce-unavailable', {
            source,
            loginIdentity: request.loginIdentity,
            code: error.code,
            reason: error.message,
            outcome: 'silent-drop'
          });
          return;
        }
      }
      const plaintext = buildRegisterReplyPlaintext({
        loginIdentity: request.loginIdentity,
        serverIpv4: this.advertisedAddress,
        portNow: this.port,
        // +0x2c stays 0 so the port set at +0x30 is the one that holds; the
        // client only re-points at bind time when this is non-zero.
        portAtBind: 0,
        tailBlob: attachmentNonce
      });
      const encrypted = blowfishEcbEncrypt(createBlowfishKey(password), plaintext);
      reply = encodeRegisterReply({
        encryptedBody: encrypted,
        endpointToken: request.endpointToken,
        // First server->client reliable message of the epoch.
        sequence: REGISTER_REPLY_SEQUENCE,
        // V1 built its reply as a copy of the request, so wire 0x90..0x95 - the
        // six bytes past the encrypted body, which the client never reads -
        // carried the request's own tail. Mirroring it makes our datagram
        // byte-identical to the one a real client provably accepted, rather
        // than merely spec-equivalent.
        filler: message.length >= 0x96 ? Buffer.from(datagram.subarray(0x90, 0x96)) : null
      });
    } catch (error) {
      this.logger?.error?.('udp9090 register-build-failed', {
        ...context,
        outcome: 'silent-drop',
        reason: error.message
      });
      return;
    }

    this.socket?.send(reply, remote.port, remote.address, (error) => {
      if (error) {
        this.logger?.error?.('udp9090 register-send-failed', {
          ...context,
          reason: error.message
        });
        return;
      }
      // A register opens a FRESH epoch: the client resets its own sequence
      // numbering, so any channel from the previous one describes a stream that
      // no longer exists and its retransmit timers would fire into it forever.
      this.lobby?.close(source, 'a fresh register epoch replaced this session');
      const session = this.sessions.register({
        address: remote.address,
        port: remote.port,
        loginIdentity: request.loginIdentity,
        endpointToken: request.endpointToken,
        /*
         * `conn+0x510`, the client's own declared latency quantum. The register
         * watchdog is `LC * 32 + 4000` ms, so this is what makes the keepalive
         * budget a per-session value the CLIENT declared rather than a constant
         * this server assumed.
         */
        latencyTicks: latencyTicksFromTlvs(request.tlvs)
      });
      if (!session) {
        this.logger?.warn?.('udp9090 session-table-full', {
          ...context,
          note: 'the reply was sent but no bind will be accepted for it'
        });
      }
      this.logger?.info?.('udp9090 register-replied', {
        ...context,
        outcome: 'accepted',
        /*
         * The HASH, never the value. The nonce is the bind's attachment proof,
         * so a journal that records it is a journal that can be replayed from -
         * and journals outlive the session that produced them. The hash still
         * matches a reply to the bind that echoes it, which is all the
         * diagnostics need.
         */
        attachmentNonceSha256: attachmentNonce == null
          ? null
          : createHash('sha256').update(attachmentNonce).digest('hex'),
        registerCount: session?.registerCount ?? null,
        replyBytes: reply.length,
        advertisedAddress: this.advertisedAddress,
        advertisedPort: this.port,
        note: 'expect a 20-byte transport ACK then a 330-byte opcode-0x01 bind'
      });
    });
  }

  /**
   * The post-lobby snapshot, opcode 0x01 at message length `0x236`.
   *
   * Answered with the SAME two datagrams as the bind - a transport ACK and the
   * slot-0x1c push - because that is what V1 sent and what 38 archived sessions
   * show the client accepting. The body is not read at all: V1 records it is not
   * Blowfish-encrypted here, and the reply is a pure function of the transport
   * header, as it was in every archived session.
   *
   * Two things differ from the bind, and both matter:
   *
   * 1. **It does not arm the TCP lobby and does not mark the session bound.** The
   *    client is already downstream of the lobby walk; arming here leaves a stale
   *    pending entry that makes the NEXT TCP connect run the wrong state machine
   *    (`game_udp_server.js:2770-2776`).
   * 2. **The push does NOT consume a stamped sequence.** It carries the constant
   *    `SLOT1C_PUSH_SEQUENCE`, exactly as the bind's does - V1 mirrored the
   *    client's sequence here and constant-zeroed at the bind, and the two forms
   *    are the same bytes on every observed input. Stamping from the session
   *    counter is the third option and is the one that is actually wrong: V1
   *    shipped it and recorded the consequence at `:2991-3000`, "the following
   *    named-slot/cmd0c reply landed at seq=2 > recvBase=1 -> buffered -> 840".
   *
   * It is ALSO where the post-selection subsystem starts. The client's 55.2 s
   * `conn+0x51c` clock is running from here, and op-0x40 is the only thing that
   * refreshes it.
   */
  #onPostLobbySnapshot(message, remote, source) {
    // The endpoint token is the correlation key. A snapshot from a source with no
    // registered session is answered with nothing: it cannot be correlated, and
    // inventing a reply for an unauthenticated source is how an amplifier is
    // built.
    const resolved = this.sessions.resolve({
      address: remote.address,
      port: remote.port,
      endpointToken: message.endpointToken
    });
    if (resolved.refusal) {
      this.logger?.warn?.('udp9090 post-lobby-snapshot-refused', {
        source,
        outcome: 'silent-drop',
        reason: resolved.refusal,
        endpointToken: `0x${message.endpointToken.toString(16).padStart(8, '0')}`,
        length: message.length,
        note: 'implementation security control, not captured behaviour: V1 answered any snapshot'
      });
      return;
    }
    const session = resolved.session;
    const context = {
      source,
      loginIdentity: session.loginIdentity,
      endpointToken: `0x${message.endpointToken.toString(16).padStart(8, '0')}`,
      snapshotSequence: message.sequence,
      length: message.length
    };
    this.logger?.info?.('udp9090 post-lobby-snapshot', {
      ...context,
      note: 'the SN@P session after Server Select; answered with an ACK and the slot-0x1c push, ' +
        'and deliberately does NOT arm the TCP lobby'
    });

    this.#send(
      encodeTransportAck({
        endpointToken: message.endpointToken,
        acknowledgedSequence: message.sequence
      }),
      remote,
      'post-lobby-snapshot-transport-ack',
      context
    );
    this.#send(
      // CONSTANT 0, not the snapshot's sequence. See SLOT1C_PUSH_SEQUENCE: V1
      // mirrored here, the two are the same byte on every real client input, and
      // the constant is the only one of the two that cannot put a reliable push
      // above the fresh epoch's receive base.
      encodeSlot1cPush({
        endpointToken: message.endpointToken,
        sequence: SLOT1C_PUSH_SEQUENCE
      }),
      remote,
      'post-lobby-snapshot-slot1c-push',
      { ...context, selector: 1, status: 0, pushSequence: SLOT1C_PUSH_SEQUENCE }
    );

    this.#openLobbySession(session, message, remote, source);
  }

  /**
   * Hand this client over to the post-selection subsystem.
   *
   * The stamped stream starts one above the slot-0x1c push, which is the
   * sequence the client's `recvBase` reaches when it delivers it. The push is a
   * constant, so this is one too: in the archive the snapshot, the push and the
   * base were all 0 and the first op-0x48 reply went out at 1, which is what
   * this still produces - but it now derives from the sequence we ACTUALLY sent
   * rather than from a number the peer chose.
   */
  #openLobbySession(session, message, remote, source) {
    if (this.lobby == null) return null;
    const lobbySession = this.lobby.open({
      routingKey: source,
      // IDENTITY COMES FROM THE REGISTRATION, never from the source address. The
      // snapshot carries no credential at all; the register is what
      // authenticated and the attachment nonce is what tied it to an account.
      loginIdentity: session.loginIdentity,
      endpointToken: message.endpointToken,
      outboundSequence: (SLOT1C_PUSH_SEQUENCE + 1) >>> 0,
      // The client's reliable send stream restarts at 0 on every register epoch:
      // the archive's op-0x48 query immediately after this snapshot carries
      // sequence 0.
      inboundReceiveBase: 0,
      latencyTicks: session.latencyTicks ?? null,
      transmit: (datagram, transmitContext) =>
        this.#transmitForLobby(datagram, remote, source, transmitContext)
    });
    // The keepalive is armed by `open()` itself: see the note there on why it is
    // not the caller's to remember.
    return lobbySession;
  }

  /** One datagram belonging to an open post-selection session. */
  #onLobbyDatagram(lobbySession, datagram, source) {
    const result = lobbySession.accept(datagram);
    for (const refusal of result.refusals ?? []) {
      /*
       * BATCH_NOT_WALKED is expected traffic, not a fault: the archive shows the
       * client coalescing two op-0x48 queries into one 136-byte datagram with
       * `0x0800` set on the first. V1 acknowledged the OUTER frame only and the
       * client carried on, which is the standing obligation (gap table X1) -
       * walking a client datagram is what read Blowfish ciphertext as sub-headers
       * and freed the wrong buffers in 2026-07-02's T9.
       */
      const expected = refusal.code === 'BATCH_NOT_WALKED';
      const log = expected ? this.logger?.debug : this.logger?.warn;
      log?.call(this.logger, 'udp9090 lobby-datagram-refusal', {
        source,
        loginIdentity: lobbySession.loginIdentity,
        code: refusal.code,
        detail: refusal.detail
      });
    }
    return result;
  }

  /** The outlet the reliable channel retransmits and acknowledges through. */
  #transmitForLobby(datagram, remote, source, transmitContext) {
    this.socket?.send(datagram, remote.port, remote.address, (error) => {
      if (!error) return;
      this.logger?.error?.('udp9090 lobby-send-failed', {
        source,
        kind: transmitContext?.kind ?? null,
        opcode: transmitContext?.opcode == null
          ? null
          : `0x${transmitContext.opcode.toString(16)}`,
        sequence: transmitContext?.sequence ?? null,
        reason: error.message
      });
    });
  }

  /**
   * The post-register bind, opcode 0x01. Answered with a transport ACK and the
   * slot-0x1c push, as two separate datagrams - which is what the archived V1
   * traces show and what the client provably accepted.
   */
  #onBind(message, remote, source) {
    let bind;
    try {
      bind = decodeBindRequest(message);
    } catch (error) {
      this.logger?.warn?.('udp9090 bind-undecodable', {
        source,
        code: error.code,
        reason: error.message,
        length: message.length
      });
      return;
    }

    // The bind carries no credential. It inherits the register's proof or it
    // gets nothing: the endpoint name it carries is client-supplied and is a
    // correlation hint only, never an authenticator.
    const resolved = this.sessions.resolve({
      address: remote.address,
      port: remote.port,
      endpointToken: bind.endpointToken
    });
    if (resolved.refusal) {
      this.logger?.warn?.('udp9090 bind-refused', {
        source,
        outcome: 'silent-drop',
        reason: resolved.refusal,
        endpointName: bind.endpointName,
        endpointToken: `0x${bind.endpointToken.toString(16).padStart(8, '0')}`,
        note: 'implementation security control, not captured behaviour: V1 answered any bind'
      });
      return;
    }
    const session = resolved.session;

    // Correlation evidence, so a rig log proves the register and the bind are
    // the same client. The name the client sent is the login identity plus the
    // dash FUN_00626900 appends; a mismatch is worth seeing but is not a gate,
    // because the authenticated value is the session's, not the client's.
    const identityMatches = bind.endpointIdentity === session.loginIdentity;
    const context = {
      source,
      loginIdentity: session.loginIdentity,
      endpointName: bind.endpointName,
      endpointIdentityMatchesSession: identityMatches,
      endpointToken: `0x${bind.endpointToken.toString(16).padStart(8, '0')}`,
      bindSequence: bind.sequence,
      registeredAgoMs: this.sessions.clock() - session.registeredAtMs,
      duplicateBind: session.boundAtMs != null
    };
    if (!identityMatches) {
      this.logger?.warn?.('udp9090 bind-endpoint-identity-mismatch', {
        ...context,
        note: 'answering with the session identity; the bind name is not an authenticator'
      });
    }
    const attachment = this.#resolveAttachment(message, session, context);

    this.logger?.info?.('udp9090 bind-request', { ...context, attachment: attachment.reason });

    // A duplicate bind is answered again, identically: the client retries when
    // it does not see our reply, and treating a retry as an error would strand it.
    const ack = encodeTransportAck({
      endpointToken: bind.endpointToken,
      acknowledgedSequence: bind.sequence
    });
    // SEQUENCE 0, deliberately NOT the bind's, and the same constant the
    // post-lobby snapshot's push now carries - see SLOT1C_PUSH_SEQUENCE for why
    // the two were reconciled onto the constant rather than onto the mirror.
    const push = encodeSlot1cPush({
      endpointToken: bind.endpointToken,
      sequence: SLOT1C_PUSH_SEQUENCE
    });
    this.#send(ack, remote, 'bind-transport-ack', context);
    this.#send(push, remote, 'bind-slot1c-push', {
      ...context,
      selector: 1,
      status: 0,
      note: 'expect a transport ACK then an opcode-0x02 app ACK'
    });
    this.sessions.markBound(session);

    // Arm with the SESSION's identity, never the endpoint name the client put in
    // the bind.
    //
    // THIS NOW GRANTS IDENTITY, and the earlier note here was wrong to say it
    // did not. Since the session model was corrected, a completed bind
    // establishes the game-account session that a lobby connection resolves
    // against - so this is no longer only a transcript hint.
    //
    // The register authenticates the SERVER to the CLIENT (the client strcmps
    // our decrypted body); it verifies nothing about the sender. So anyone who
    // knows a login identity and can send two datagrams still obtains a lobby
    // identity as that user when nobody is logged in as them - the accepted cost
    // of treating the register as the authentication event, written down in
    // `account-session.js`. What that no longer buys, since the audit
    // demonstrated it, is EVICTING a player who is already in: the attachment
    // verdict travels with this event and displacement needs it (D-2).
    if (this.onLobbyReady) {
      try {
        this.onLobbyReady({
          address: remote.address,
          port: remote.port,
          loginIdentity: session.loginIdentity,
          // The FACT the service observed, not a policy label. What it is worth
          // is decided in one place, by the session registry's caller.
          attachment
        });
      } catch (error) {
        // Arming is a transcript hint, not part of the protocol exchange: a
        // failure here must not cost the client its bind reply, which has
        // already been sent.
        this.logger?.error?.('udp9090 lobby-arming-failed', {
          source,
          loginIdentity: session.loginIdentity,
          reason: error.message
        });
      }
    }
  }

  /**
   * Decide what this bind proved about the registration it claims, and say so in
   * the log whichever way it went.
   *
   * The proof is the 16-byte nonce at bind body +0x24/+0x28. It reached the
   * client only inside the register reply's Blowfish body, keyed by the account
   * password, so echoing it demonstrates the sender could read that body - see
   * `ACCOUNT_PROOF` in `sessions/account-session.js` for exactly how far that
   * goes and where it stops.
   *
   * @returns {{verified: boolean, reason: string}}
   */
  #resolveAttachment(message, session, context) {
    if (this.registrationNonces == null) {
      return { verified: false, reason: BIND_ATTACHMENT.NOT_CONFIGURED };
    }
    const echoed = readBindTailBlob(message);
    if (echoed == null) {
      this.logger?.warn?.('udp9090 bind-tail-absent', {
        ...context,
        note: 'the bind body is too short to carry the tail field at all'
      });
      return { verified: false, reason: BIND_ATTACHMENT.TAIL_FIELD_ABSENT };
    }
    if (echoed.refusal != null) {
      this.logger?.warn?.('udp9090 bind-tail-malformed', {
        ...context,
        declaredLength: echoed.declaredLength,
        reason: echoed.refusal
      });
      return { verified: false, reason: BIND_ATTACHMENT.TAIL_MALFORMED };
    }
    if (echoed.declaredLength === 0) {
      this.logger?.warn?.('udp9090 bind-tail-empty', {
        ...context,
        note: 'the client echoed length 0; either it dropped our nonce or the ' +
          'bind was built before the register reply was parsed'
      });
      return { verified: false, reason: BIND_ATTACHMENT.TAIL_EMPTY };
    }

    const attached = this.registrationNonces.consume(echoed.blob);
    /*
     * The HASH, never the value. The nonce is the bind's attachment proof, so a
     * journal that records it is a journal that can be replayed from - and
     * journals outlive the session that produced them.
     */
    const echoedNonceSha256 = createHash('sha256').update(echoed.blob).digest('hex');
    if (attached.registration == null) {
      this.logger?.warn?.('udp9090 bind-tail-echoed', {
        ...context,
        declaredLength: echoed.declaredLength,
        echoedNonceSha256,
        matched: false,
        refusal: attached.refusal ?? null,
        note: 'the tail round-tripped but attaches to no live registration'
      });
      return { verified: false, reason: BIND_ATTACHMENT.NONCE_NOT_ATTACHED };
    }
    /*
     * THE CROSS-ACCOUNT CHECK, and it is not theoretical.
     *
     * The nonce says which REGISTRATION this bind belongs to; the register
     * session says which ACCOUNT the register named. A holder of any account can
     * mint a nonce it can read - its own - and then register as somebody else
     * from the same socket, so without this the readable nonce would "prove" the
     * victim's account. The proof only carries when the two agree.
     */
    if (attached.registration.handle !== session.loginIdentity) {
      this.logger?.warn?.('udp9090 bind-tail-handle-mismatch', {
        ...context,
        echoedNonceSha256,
        attachedHandle: attached.registration.handle,
        note: 'the echoed nonce was minted for a different account; proving nothing here'
      });
      return { verified: false, reason: BIND_ATTACHMENT.HANDLE_MISMATCH };
    }
    this.logger?.info?.('udp9090 bind-tail-echoed', {
      ...context,
      declaredLength: echoed.declaredLength,
      echoedNonceSha256,
      matched: true,
      retransmission: attached.retransmission,
      attachedHandle: attached.registration.handle,
      note: 'the bind proved which registration it belongs to'
    });
    return { verified: true, reason: BIND_ATTACHMENT.VERIFIED };
  }

  /**
   * The client's opcode-0x02 application acknowledgement. This is the success
   * signal for the whole exchange: V1's trace annotates it "game proceeding to
   * TCP 10127 lobby phase". It is RELIABLE, so it must itself be acknowledged.
   */
  #onAppAck(message, remote, source) {
    const resolved = this.sessions.resolve({
      address: remote.address,
      port: remote.port,
      endpointToken: message.endpointToken
    });
    if (resolved.refusal) {
      this.logger?.warn?.('udp9090 app-ack-refused', {
        source,
        outcome: 'silent-drop',
        reason: resolved.refusal
      });
      return;
    }
    const session = resolved.session;
    this.sessions.markAppAcknowledged(session);

    const context = {
      source,
      loginIdentity: session.loginIdentity,
      sequence: message.sequence,
      boundAgoMs: session.boundAtMs == null ? null : this.sessions.clock() - session.boundAtMs
    };
    this.logger?.info?.('udp9090 app-ack-received', {
      ...context,
      note: 'the client accepted the slot-0x1c push; next is the TCP 10127 lobby phase'
    });
    this.#send(
      encodeTransportAck({
        endpointToken: message.endpointToken,
        acknowledgedSequence: message.sequence
      }),
      remote,
      'app-ack-transport-ack',
      context
    );
  }

  #logExtraMessageIgnored(source, message) {
    this.logger?.warn?.('udp9090 extra-message-ignored', {
      source,
      opcode: `0x${message.opcode.toString(16)}`,
      note: 'only the first reply-producing message in a datagram is answered'
    });
  }

  #send(datagram, remote, event, context) {
    this.socket?.send(datagram, remote.port, remote.address, (error) => {
      if (error) {
        this.logger?.error?.(`udp9090 ${event}-send-failed`, {
          ...context,
          reason: error.message
        });
        return;
      }
      this.logger?.info?.(`udp9090 ${event}`, { ...context, bytes: datagram.length });
    });
  }
}

export async function createSnapRegisterService(options) {
  return new SnapRegisterService(options).start();
}
