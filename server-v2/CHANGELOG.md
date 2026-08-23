# Server v2 changelog

## Unreleased

### Added

- **The UDP attachment nonce (T33), off by default behind `PAL_V2_UDP_ATTACHMENT_NONCE`.**
  The register reply's tail blob is the only value in the register/bind exchange the server chooses
  and - **Inference, not yet Observation** - the client returns. `FUN_001d9678` decrypts our reply,
  reads a BE32 length from plaintext `+0x34` and `memcpy`s that many bytes to `conn+0xac`;
  `FUN_001d6ee0` copies the connection template containing it into the bind body at `+0x24`/`+0x28`.
  Written at one site in the client, read at one site, then dead: an opaque cookie. V1 always sent
  length 0 (`server/game_udp_server.js:542`), so the field has never carried anything and the
  captures cannot tell an echo from no echo. T33 is the gate that settles it.
  `RegistrationNonceTable` keys pending registrations BY THE NONCE. Source address, port and
  endpoint token are demoted to telemetry and rate-limit context, because none is a proof: the token
  is only `(3rd octet << 24) | (4th octet << 16) | localPort` of the client's own LAN address, a
  truncated routing hint. There is deliberately no fallback to the source address on any failure
  path - that fallback is what makes two players behind one NAT collide, and it is what V1 did.
  128-bit nonces, uniqueness against live pending registrations, short expiry, constant-time
  comparison, one successful bind per nonce, a bounded retransmission window, and distinguishable
  refusals for absent / malformed / unknown / expired / consumed. The nonce is OBSERVED at the bind,
  not yet enforced: the experiment must be able to fail without breaking a path that works.

  **SETTLED 2026-08-06 (T33 rig run).** An unmodified retail client echoed the nonce back in its
  bind - `captures/v2-live/t33-run11-nonce-echo.pcap`, where the 16 bytes appear in cleartext
  exactly once, in the client's bind - so the echo is Observation, not Inference, and
  `PAL_V2_UDP_ATTACHMENT_NONCE` now defaults ON. The paragraph above is left as written because it
  records what the gate was for; only this note states the outcome.

- **The client's capacity as a named production safety invariant.** `FUN_001d9678`'s memcpy takes
  our declared length with **no clamp**, so the server is the only bound that exists and the target
  is an unmodified retail console, where a crash is indistinguishable from a protocol bug. Encoded
  as constants and asserted against directly: `<= 0x100` safe echo window, `> 0x100` corrupts the
  lobby blob, `>= 0x3d8` overwrites the ACCOUNT PASSWORD, `~0x578` overruns the allocation. V2 emits
  exactly 16 bytes or none, refused rather than clamped, with a startup assertion that the layout
  still fits both the 0x80 plaintext and V1's proven 128-byte encrypted region. The previous bound
  was on OUR buffer and was safe only by the coincidence that our plaintext is small.

- **`0x6503`, the server-entry list - the only command that writes the client's entry table, and the
  reason Server Select rendered empty.** `FUN_001c70b0` is its sole writer: it stores the entry total
  at `0x365e1e` and streams `0x260`-byte entries into `0x365e20` as host (`<= 0x3e`), name
  (`<= 0x0f`), eight raw bytes and description (`<= 0xff`). Until it runs the total stays 0, and the
  screen's fill loop is `for i < count`, so the row is never filled at all. V2 now answers it, serving
  the window the client asked for - `FUN_001c7000` sends both the offset and the count, and the parser
  advances its cursor by the batch count it was sent - rather than dumping the whole list into one
  frame against a receive buffer of unknown size. `total` is bounded 1..16 at the encoder: the parser
  treats 0 as terminal and routes anything above 16 on a connection state word V2 cannot observe, so
  V2 never sends a value whose handling would depend on it. The offset is validated against the
  connection's own cursor rather than clamped, because seating entries at the wrong index would
  corrupt the table the client walks.
- **The `0x6501` mode is now conditional instead of a hardcoded `0`.** `FUN_001c6e80` proves the mode
  SELECTS the client's route (Observation): mode 1 goes to `0x6503` whatever the connection's state
  word, mode 0 with state word 5 goes straight to `0x6510`, mode 0 otherwise to `0x6502`. V2 answers
  mode 1 on a connection that presented `0x1007` and mode 0 on one that opened at `0x6501` - an
  **Inference**, flagged as one in `selectCommand6501Mode`, because V2 cannot see the state word and
  the `0x6501`-first connection is the route whose current shape already works. The policy lives in
  one function that both the standalone providers and the composed application call, so the two
  cannot drift apart. The mode-1 BE32s ship as `0`/`0` because zero is the least-assertive value,
  not because they are free: the first is a COOLDOWN the client acts on (`FUN_005c7900` loads it
  into a countdown when a Server Select fetch starts and returns early while that countdown is
  above zero; `FUN_006233e0` decrements it per tick), known at overlay-decompile grade and recorded
  as **Inferred**; the second is echoed back and otherwise unread. Closes the OQ-016 divergence; see
  `docs/open-questions.md` for what remains Unknown.

### Fixed

- **The second entry's `0x6502` was observed but never answered.** `FUN_001c7a70`'s tail increments
  `0x365e0c` when an entry's records are complete and, while `0x365e0c < 0x365e1e`, routes to phase 8
  - the `0x6502` builder - for the NEXT entry rather than to `0x6510`. V2 preserved that frame as
  unimplemented and the walk would have stalled. It was unreachable until now for the same reason
  Server Select was empty: `0x365e1e` is written only by `0x6503`, so the total stayed 0 and no client
  could reach a second entry however many the server held. Multi-entry directories have therefore
  never worked. Found by a two-entry walk over a real socket, and now also covered by a session-level
  unit test on that state - which is where it should have been caught.
  Note the consequence for load: one connection can now walk EVERY entry's records rather than only
  entry 0's, so the bytes a single connection can make the server emit rise from roughly 20 KB to
  roughly 318 KB on a full 16-entry, 64-record directory (measured). There is no per-connection byte
  budget; that is unchanged by this commit and is worth one before the server faces the internet.
- The resume guard asked whether ENTRY 0 held records, so a directory whose first entry had none -
  an area with no rooms - failed every resume with `PROJECTION_RESUME_EMPTY`, the player-visible
  "could not connect to lobby server". It now asks whether the projection holds any records at all.
  Latent until `0x6503` shipped, for the same reason as the defect above: the client could not walk
  past entry 0 while the entry total stayed 0.

- **The SN@P UDP :9090 register (`cmd 0x2c` -> `0x2d`), the exchange the real client stalls on.**
  `src/protocol/snap-udp-register-codec.js` frames datagrams exactly as the client's own receive path
  does - length from the header's `who & 0x3ff` and never from `udp.length`, every message `>= 0x10`
  and closing exactly on `datagramLength - 4`, trailer validated on its top three bytes only - and
  decodes the register's fields at their proven offsets. `src/udp/register-service.js` looks the
  account up by LOGIN IDENTITY, Blowfish-encrypts the 0x80-byte reply body with that account's
  password, and echoes the request's endpoint token. The reply is byte-identical to the one V1 sent
  and a real client provably accepted, including the six filler bytes at wire `0x90..0x95`.
  The exchange IS the authentication: there is no status field, and the client decrypts and
  `strcmp`s the plaintext against the identity it sent. So there is no error reply to design - on an
  unknown account or an unopenable secret V2 stays SILENT (the documented path: the connect screen
  retries three times and then reports its own failure) and logs a distinguishable reason for each,
  rather than sending the uncaptured `0x31` reject. `PAL_V2_UDP_BIND_ADDRESS` must be the exact IPv4
  the client dials and can never be a wildcard, because the client discards any reply whose source
  address differs - which presents as broken crypto. Note port 9090 conflicts with V1, and startup is
  all-or-nothing; see `docs/runbooks/v2-server.md`.
- A real, idempotent V1-to-V2 account migration: `src/database/v1-account-import.js`
  (`importV1Accounts`) maps V1's raw `password` to the V2 reversible compatibility secret (the
  UDP-9090 register's Blowfish key) and V1's `handle` to the V2 roster `displayName`, rejects an
  unsafe account per-record with a specific code/reason instead of guessing, resetting or repairing
  it (invalid/missing identity or password, a `userid`/`handle` key disagreement, a display-name
  collision with a different account), and leaves any pre-existing row byte-identical on re-run
  (counted as `skippedExisting`, never overwritten). CLI entry point `bin/import-v1-accounts.js`
  sources `PAL_V2_DATA_DIR`/`PAL_V2_MASTER_KEY` the same way the composed server does (via
  `openProductionRepositories`), supports `--dry-run` (writes nothing, via a transaction that is
  always rolled back), and exits non-zero on any rejection. V1's `created`/`lastLogin` are NOT
  preserved - `SecureAccountRepository#create()` has no parameter for them - and every run reports
  that explicitly rather than inventing a way to backdate them.
- One composed executable, `bin/pal-server-v2.js`: DNS, DNAS, HTTP and the TCP lobby service in a
  single ordinary Node.js process with shared validated configuration (`src/config/server-config.js`),
  structured JSON logging on stdout (`src/logging/logger.js`), ordered fail-fast startup with rollback
  of every started listener if any enabled one cannot bind, reverse-order shutdown that closes the
  database last, and a non-zero exit on any startup or runtime failure. Zero runtime dependencies:
  persistence is built-in `node:sqlite`. Runbook and systemd unit in `docs/runbooks/v2-server.md` and
  `deploy/pal-server-v2.service`.
- End-to-end DNAS identity. The HTTP flow binds the token presented on
  `GET /mhweb/index.jsp?DNAS=` to the session created by the subsequent POST, by threading the token
  through this server's own links and form actions - an implementation security control, not
  reproduced protocol behaviour, chosen because source-address correlation cannot separate two
  consoles behind one NAT. The TCP side associates a connection presenting the same token in
  `0x1007`, and refuses unknown, released, malformed or expired-session tokens without serving a byte.
- `PublishableDirectoryProvider` and an operator directory document loader
  (`src/state/directory-source.js`). Publishing a newer snapshot is a pointer swap, so a projection
  keeps the snapshot it captured and cannot be corrupted mid-walk. The loader has no defaults: a
  missing field is refused rather than filled in, and a `test-fixture` document is refused at startup.

- One authoritative directory store (`src/state/directory-state.js`) behind all four TCP providers,
  modelling the structure proved in T17: entries of stride `0x260`, each owning records of stride
  `0x134`, with every PAL parser bound enforced and no invented limit on how much the server may
  hold. Record identity is kept separate from the `unknownField0` protocol key, provenance must be
  declared, and a test-fixture directory is refused at startup rather than served.
- A per-connection projection (`src/state/client-directory-projection.js`) holding the field codec
  word, traversal position, the proven 64-record client residency budget with entry eviction, and the
  `0x6510` correlation. Eviction and disconnect touch only the connection; authoritative state is
  immutable to it, so two clients may hold different entries resident at once.
- Keyed `0x6510` correlation: each request key is decoded under the connection's own codec state,
  required to checksum, matched to exactly one record the connection currently holds in the current
  entry and window, and answered in request order. Undecodable, unknown, stale, duplicate,
  cross-entry keys and mismatched counts all fail closed. Grounded on `FUN_001c85c0` sending each
  resident record's `unknownField0` and `FUN_001c8790` storing reply word `i` at cursor `+ i`.
- `createTcp10127Service({ createConnectionProviders })`, an additive per-connection provider factory
  whose `close()` runs on socket close. Behaviour is unchanged when it is not supplied.

- The instruction-verified status-`0xff` client-default path for exactly the three TCP ladder
  handlers `0x6212`, `0x6211`, and `0x6213`. Their explicit provider/value branches remain available;
  no sentinel rule is generalized to other commands.
- The instruction-verified `0x6501` request/reply boundary with a required tagged resolver, ordered
  mode-1 BE32 fields, and neutral preservation of `0x6502`/`0x6510` or `0x6503` according to mode.
- The instruction-verified normal-status `0x6502` boundary with opaque dynamic-field preservation,
  tagged mode-0/mode-1 replies, and branch-specific continuation without V1 value defaults.
- The decoded and runtime-corroborated normal-status `0x6504` boundary: two-BE16-plus-variable-field
  requests, bounded variable record replies using the PAL `MINAMIOH` transform/checksum, an explicit
  synchronous data provider, and neutral `0x6504`/`0x6502`/`0x6510` continuation states.
- The instruction-verified normal-status `0x6510` record-key batch boundary: exact count-byte plus
  encoded-field request consumption, a required `resolveCommand6510Response` provider with no
  status-`0xff` fallback, an echoed request count so the client's batch-count gate passes, one BE16
  per requested record, one trailing field bounded to `0x3e` decoded bytes, repeated-batch handling,
  and neutral preservation of the decoded `0x6203` and `0x1004` continuations.
- The instruction-verified terminal `0x1004` lobby-initialization completion: payload-less request
  validation, an empty status-zero reply, and a terminal state that decodes nothing further. The
  PAL receiver `FUN_001c8e90` is `jr ra; li v0,1`, so no provider is required and the FIN/close is
  deliberately not modeled.
- A durable connection/session/player identity model in `src/sessions/connection-identity.js`, keyed
  on the DNAS token the client presents in-band on both HTTP and TCP `0x1007` rather than on source
  address, with fail-closed association and bounded connection/binding tables. `decodeSnapField` makes
  the `0x1007` identity field self-validating through its checksum.
- Capture-proven connection termination: the client ends the TCP 10127 connection after the `0x1004`
  reply, so the server never closes first, writes nothing further, and reports a post-completion reset
  as expected termination rather than a socket fault.
- The decoded `0x6203` major-state-4 route out of `0x6510`: `FUN_001c4960` writes substate `0x14` on
  mode 2 unconditionally, so V2 answers it with the existing `0x6203` handler and re-enters the
  `0x6211` -> `0x6213` -> `0x6501` sub-ladder.

### Added

- **The R-019 resume connection, as a distinct entry path.** After a completed lobby initialization
  the client resets and reopens on a fresh source port whose FIRST frame is `0x6501` - there is no
  second `0x1007`. V2 refused it, and the player saw "could not connect to lobby server", then D901.
  Observed 2026-08-04: complete 18:10:26, resume 18:10:41.
  The resume is NOT routed through the fresh-initialization handler. It validates the frame, then
  ATTACHES the new transport to the session that already completed an initialization - `userid`,
  `accountSessionId` and the completed-initialization state all survive, and no new identity is
  created. Only a session that actually completed one is a candidate, which is what stops a resume
  becoming a second, weaker way into an account. Replies are the ones the fresh ladder already
  produces; nothing new was invented.
  Resolution: the resume frame differs from the fresh `0x6501` ONLY in its sequence byte (`0x0a` vs
  `0xb4`), payloads identical, so the sequence is the only protocol-carried state and is used as a
  replay filter - one byte cannot be an identity. Otherwise source address as a filter plus
  exactly-one, ambiguity refused, and the window narrowed to 45 s against an observed 15 s gap.
  **Accepted residual risk, recorded in code and in a test named for it:** an attacker sharing a
  source address who connects inside that window will be handed the session. Exactly-one protects
  against choosing between two; it does nothing against an outsider taking the only one, and the
  resume presents no credential. Same class of cost as the register being the authentication event.

- **An opt-in per-session DNAS platform token** (`src/dnas/dynamic-token-packet-store.js`,
  `PAL_V2_DYNAMIC_DNAS_TOKEN`, default off). V2 replays canned DNAS replies, so every console
  receives the identical 32-byte token and it identifies nobody (T27). The client never validates it -
  `0x35ba00` is write-only on its side, unlike the register reply it does `strcmp` - so the server may
  choose the value. Each reply is COPIED and only the 32 bytes of the `01 00 00 00 20` record are
  replaced with `crypto.randomBytes`; the asset on disk is never touched, every other byte passes
  through, more than one such record in a packet is refused rather than guessed at, and each issued
  token is logged. The generator is injectable so tests are deterministic. Off by default because
  whether the DNAS reply carries an integrity check over that field is UNKNOWN - if it breaks DNAS,
  turn it off; nothing depends on it. It does NOT make the token an identity key, and distinct tokens
  do not yet resolve two simultaneous players at one address: that would mean letting the token select
  a session, which review has already shown can escalate. See OQ-023.

### Changed

- **The DNAS token is no longer the account identity key, and the three session layers are modelled
  separately.** The token is not a credential: V2 mints it from a static DNAS replay asset, so every
  console receives the identical value (T27, OQ-022). Keying identity on it made the browser the only
  route into the lobby - a client whose memory card already holds an account never opens it - and it
  would have rejected player two, since both consoles present the same token. There was a passing
  test asserting exactly that rejection.
  - **Layer 1, DNAS/platform:** completed before the lobby by the cracked-certificate path. Not
    modelled, because V2 issues nothing meaningful there.
  - **Layer 2, game account (`src/sessions/account-session.js`, new):** established by the UDP-9090
    register followed by the client's continuation into the bind - the reply is Blowfish-keyed on the
    account password and the client only continues if it decrypts under the password IT holds, so a
    bind proves both ends share it. An HTTP login establishes one too, which is what preserves the
    browser path. An account has at most one live session; a second displaces the first, as the
    reference server does.
  - **Layer 3, lobby transport:** a TCP 10127 connection presenting `0x1007`, correlated to exactly
    one layer-2 session or refused.
  Correlation never uses the source address as identity. The address is a NECESSARY filter deciding
  which sessions are candidates at all - a null address on either side matches nothing, never
  everything - and identity itself comes from the account session. Exactly one candidate is claimed;
  zero or several is refused rather than guessed, and NOTHING narrows an ambiguous set. An earlier
  draft let the DNAS token break a tie; review demonstrated that an attacker sharing a source address
  with a victim who had used the browser then received the victim's identity, so the tie-break was
  removed. Claims are single-use while held and released on close so a player can reconnect.
  Multiple accounts may share one DNAS token, which is no longer a conflict.

  **Known limitations, recorded rather than hidden.** Two players behind ONE source address cannot
  both be admitted: both sessions are eligible, nothing distinguishes them, and the connection is
  refused. This is a regression in capability against the old model, which separated them by token -
  a separation that only worked because the test used synthetic distinct tokens, and which real
  consoles could never have achieved. And lobby identity no longer requires a scrypt-verified
  password anywhere: anyone who knows a login identity and can send two datagrams obtains a lobby
  identity as that user, because the register authenticates the server to the client rather than the
  reverse. Both are accepted costs of making the UDP register the authentication event, and both are
  documented at the top of `src/sessions/account-session.js`.

- **The two account names are now named for what they are**, per
  `docs/findings/protocol/HANDLE-MODEL-RE-2026-08-03.md`: `userid` (login identity - authentication,
  the memory-card value, the register `handle` field and `<userid>@cee-auth`) and `displayName` (the
  roster name the server places in member records). The unqualified term "handle" is no longer used in
  code for either. The `accounts.handle` COLUMN keeps its name - the separation was already correct and
  a rename would be a schema migration for no functional gain. `getCompatibilitySecretByHandle` became
  `getCompatibilitySecretByLoginIdentity` and now keys on `userid`: keying the Blowfish password on the
  display name would have worked only for as long as the two happened to be equal.

### Fixed

- **Session lifecycle hardening.** Three defects review demonstrated against the shipped modules, all
  of which made retained lobby state unbounded in time or count.
  - *The resume deadline slid forever.* `markInitializationComplete` re-armed unconditionally, and
    every resumed ladder ends in `0x1004`, so each resume pushed the window out. Review drove 20
    resumes at 40 s spacing and the session was still resumable **800 s** after the original
    completion, which made the stated 45 s bound fiction. The deadline is now ABSOLUTE, set once from
    the original completed initialization and never extended.
  - *The sequence byte bounded nothing.* Alternating `0x00`/`0x01` gave review **45,000** successful
    resumes. It is now documented for what it is - duplicate suppression that catches a verbatim
    retransmission, NOT authentication and NOT replay protection - and the real bound is an explicit
    attempt budget (default 3 **per fresh initialization**, an implementation control rather than a
    protocol fact; the capture shows one resume and the rest is retry margin). Attempts are charged
    at resolve time so a resume that is resolved and then refused downstream still costs budget.
    Note the bound is per fresh ladder, not per account session: a fresh initialization resets the
    counter, so review obtained 15 attempts across 5 fresh ladders. That grants an attacker nothing
    new - completing a fresh ladder already means claiming the session, which hands over the
    identity outright - but the bound must not be described as "3 per session".
    **Honest limit:** this does NOT stop an attacker sharing the source address from exhausting a
    victim's budget - review demonstrated three dropped connections locking the victim out. It
    cannot, because a resume carries no credential and the address is not identity.
    **And the recovery is narrower than first claimed.** A FRESH `0x1007` does clear the budget and
    re-arm the deadline, but reaching it again for the same session needs the address still armed
    (90 s from the bind) and the session unclaimed inside the 120 s claim window - review measured
    the boundary at accepted +119 s, refused +125 s - after which the session stays exhausted for
    the rest of its 30-minute TTL. No capture shows the client ever sending a second `0x1007` on a
    live session (R-019: the second ladder does not begin with one), so that path is unevidenced as
    client behaviour. The recovery that always works is a NEW UDP register, and it does not run this
    code at all: `establish` displaces the old session for a new one whose budget starts at zero.
  - *Retained lobby sessions leaked.* Six HTTP logins for one account produced six retained
    projections, because the HTTP displacement branch logged the displaced account session but never
    released it, unlike the UDP branch. Release is now driven by a single hook fired from
    `#forget` - the one place a session is ever forgotten - so account replacement, HTTP
    displacement, UDP displacement, expiry, explicit removal and shutdown all release the owned
    `LobbySession` and its `ClientDirectoryProjection` on the same path, exactly once. Release is
    idempotent, and a released session is inert: a stale reference throws rather than resurrecting it.
  Cleanup no longer depends on lookup-time sweeps alone - an unref'd 15 s timer sweeps expiry
  regardless of traffic, and `stop()` clears everything.

- **The resume refusal reported the wrong reason, in a narrower way than before.** The exhausted-
  attempts test has now been misplaced twice. Originally it ran FIRST, so one exhausted session
  anywhere on the server made every unrelated refusal report `RESUME_ATTEMPTS_EXHAUSTED`. The
  correction moved it below the claimed and source-address filters but left it ABOVE the window and
  duplicate-sequence filters, while stating in its commit message that it now ran "only for sessions
  that are otherwise candidates for this source" - which the shipped code contradicted. Review
  demonstrated two surviving misreports **for the session's own source address**, which on a
  single-client rig is the only address there is: an exhausted session whose 45 s window had lapsed
  75 s earlier, and a duplicate-sequence refusal. The check now runs LAST, so `exhausted` means
  exactly "would have been a candidate but for the budget". Review proved the reorder is purely
  diagnostic: 239,739 differential resolve calls against the old and new modules produced zero
  resolution or state divergence, and six refusal-code-only differences.
  A third case is unchanged and correctly so: a second account behind the same NAT still sees
  `RESUME_ATTEMPTS_EXHAUSTED` **while the exhausted session is still inside its window**, because
  such a session genuinely exists at that address and the address is not identity, so the two cannot
  be told apart. Telling them apart would mean treating the address as identity, which the module
  refuses by design.

- **A duplicate-sequence refusal said something untrue.** With the reorder, a verbatim retransmission
  fell through to `NO_RESUMABLE_SESSION` - "no completed lobby initialization from this source is
  waiting to be resumed" - while a completed, unclaimed, in-window session *was* waiting. The
  behaviour was right and the sentence was false, which is the same defect class as the misreport
  above, one layer down. There is now a distinct `DUPLICATE_RESUME_SEQUENCE` code naming the repeated
  sequence byte and saying explicitly that this is duplicate suppression, not authentication and not
  replay protection. The three refusal buckets are disjoint by construction, since the duplicate test
  runs before the attempt test.

- **`markInitializationComplete` no longer guesses whether a ladder was fresh or resumed.** The
  `{ resumed }` flag defaulted to `false`, which is the branch that re-arms the deadline and clears
  the budget - so a caller that simply forgot it would silently reintroduce the unbounded resume
  window. There is no safe default: the other direction silently withholds the only recovery. Both
  have shipped. The flag is now required and a missing or non-boolean value throws
  `RESUMED_FLAG_REQUIRED`.

- **D907 regression: a lobby arming outlived a reboot.** Arming from the UDP bind used a 5-minute TTL,
  so a player who rebooted a few minutes after playing had their address still armed and the fresh
  boot's BOOT-AUTH connection was handed the `0x6001` lobby challenge instead of the
  `0x1001`/`0x1002`/`0x1004` transcript. Observed on 2026-08-04: armed 18:00:48, reboot 18:03:58,
  D907. The TTL is now 90 seconds - comfortably covering the observed sequence, where the lobby
  connection follows the bind by about a second and the resume follows the ladder by about 14 - and
  DNAS now clears any arming for that address, because DNAS is the platform step that precedes boot
  auth on a fresh start.

- **Sized for hundreds of concurrent players rather than one rig.** Caps raised (account sessions and
  register sessions 256 -> 4096, lobby armings 256 -> 4096, connections 1024 -> 8192, token bindings
  4096 -> 8192), and the account-session registry no longer scans. It keeps userid, claimed-connection
  and unclaimed indexes, so establishing, finding, claiming and releasing are constant-time instead of
  walking every live session, and lobby resolution considers only unclaimed sessions. The expiry sweep
  is rate-limited to once a second rather than running on every lookup. A test resolves 400
  simultaneous players, each to their own account.

- **The login identity is capped at 10 bytes, and an over-long one is rejected rather than truncated.**
  The client's account-creation path copies the identity out of the server's HTML with a fixed-width
  `strncpy(dst, cursor + 12, 10)` (overlay netwk `0x005e74ac`-`0x005e7500`). V2 previously accepted
  3-14 characters and rendered `maxlength="14"`, so an 11-to-14 character identity would have been
  written truncated to the memory card and registered truncated, missing its account row - and because
  the UDP-9090 register reply is Blowfish-keyed on that account's password, the failure would have
  surfaced as a crypto fault rather than a bad username. All limits are now BYTE limits, measured
  explicitly, because the client copies raw bytes and its marker table contains Shift-JIS.

  **Evidence grade: Inference, not runtime-validated.** The 10-byte ceiling is read off the
  instruction, and no identity longer than 10 has ever been on the wire - the longest ever seen is
  exactly 10 (`12345abcde`, in V1's store). Tracked as OQ-020(b); a real-client run with an 11-byte
  identity would settle it.

  **Operator note.** An account already in V2's SQLite store with an 11-14 byte `userid` can no longer
  authenticate, and the refusal is a validation error rather than a loud startup failure. No such row
  is known to exist - V2's store has only browser-created accounts, and all 16 V1 accounts are <= 10
  bytes - but check before deploying if you have created accounts by hand:
  `SELECT userid FROM accounts WHERE length(userid) > 10;` must return no rows.


- `associateDnasToken` was never passed to the lobby-initialization session, so the `0x1007` identity
  field was decoded, checksum-verified and then discarded, and any client was served regardless of
  whether an authenticated HTTP session had ever presented its token. The identity model added in
  `8251a0f5` had been unreachable since it was written. Caught by the first run of the composed
  integration suite; every unit test of the registry had passed throughout, because the unit was
  correct and simply never called.
- Shared post-command follow-up diagnostics now name the state that rejected the frame instead of
  always reporting `post-0x6501`.

- Corpus-grounded SN@P datagram codec and reliable channel with captured-wire fixtures.
- Atomic JSON persistence for isolated V2 data.
- Account creation and login repository retaining the exact compatibility secret required by PAL UDP
  registration.
- HTTP browser flow with runtime-confirmed `COMP-SIGNUP` / `INPUT-IDS` markers and decoded
  `CRS-GAME-START` / `CRS-LBS-INFO-GET` CSV order.
- Architecture charter requiring V1-versus-corpus review and stopping a slice at unresolved protocol
  fields.
- Evidence-backed TCP 10127 eight-byte framing, incremental stream reassembly, and the captured
  pre-browser transcript behind an explicit connection-purpose resolver.
- Byte-exact, fragmentation, coalescing, payload-limit, purpose-resolution, and real-socket TCP tests.
- An explicit `lobby-initialization` TCP 10127 session that handles captured PAL command `0x1007`,
  returns only the decoded mode-0 response, keeps the 49-byte request body opaque, and records later
  framed commands without inventing responses.
- A bounded pre-purpose TCP buffer so asynchronous connection-purpose correlation cannot retain
  unbounded client input.
- The next decoded lobby state, `0x6103`: three captured payload-less requests now receive an exact
  two-byte empty keyed manifest, avoiding V1's synthetic `0x01234567` record and chunk body.
- The canonical `0x6212` PAL exchange: a payload-less request now receives one BE32 field obtained
  from a required server-state dependency, with no hard-coded success value. Missing or invalid providers
  fail closed.
- The decoded/capture-backed `0x6203` mode-2 exchange: V2 validates the variable encoded-field
  envelope without interpreting its second u16, content, or meaning; emits the captured one-byte
  `0x02` response; and advances to the following payload-less `0x6211`.
- The instruction-verified canonical `0x6211` exchange: V2 requires a synchronous uint32 server-state
  provider, serializes one BE32 field with no literal fallback, and preserves the following `0x6213`
  without inventing a reply. V1's captured zero remains a compatibility fixture, not protocol truth.
- The instruction-verified canonical `0x6213` exchange: V2 requires a synchronous array of eight
  uint16 server-state words, serializes the canonical 16-byte payload in decoded BE16 parser order,
  and preserves the following `0x6501` without inventing a reply. V1's zeros and the parser's
  peer-sentinel values remain evidence, not production defaults.
- Repository-local PAL disassembly: the existing SLES disassembler now defaults to the tracked
  extracted executable while retaining an optional explicit ELF path.

### Verification

- 2026-08-02: After the `0x6213` slice, the full local V2 suite completed 85 tests: 78 passed,
  0 failed, and 7 external-DNAS tests skipped because their fixture directories were not configured.
- 2026-08-02: 33/33 focused TCP tests passed, including two exact saved `0x6213` exchanges,
  eight-word BE16 order, missing/invalid provider failures, genuine state-order rejection,
  fragmented `0x6213`, coalesced unanswered `0x6501`, and provider remote-context assertions.
- 2026-08-01: After the `0x6211` slice, the full local V2 suite completed 80 tests: 73 passed,
  0 failed, and 7 external-DNAS tests skipped because their fixture directories were not configured.
- 2026-08-01: 28/28 focused TCP tests passed, including two exact saved `0x6211` exchanges,
  BE32 boundaries, missing/invalid provider failures, genuine state-order rejection, fragmented
  `0x6211`, coalesced unanswered `0x6213`, and provider remote-context assertions.
- 2026-08-01: After the `0x6203` slice, the full local V2 suite completed 75 tests: 68 passed,
  0 failed, and 7 external-DNAS tests skipped because their fixture directories were not configured.
- 2026-08-01: 23/23 focused TCP tests passed, including both unique saved `0x6203` exchanges,
  dynamic-envelope boundaries, genuine state-order rejection, a longer opaque field, fragmented
  `0x6203`, coalesced `0x6211`, and exact response-count/state assertions.
- 2026-08-01: After the `0x6212` slice, the full local V2 suite completed 72 tests: 65 passed,
  0 failed, and 7 external-DNAS tests skipped because their fixture directories were not configured.
- 2026-08-01: 20/20 focused TCP tests passed, including two unique captured `0x6212` exchanges,
  BE32 boundary serialization, state-provider failures, socket cleanup, and a coalesced
  `0x1007 -> 0x6103 -> 0x6212 -> 0x6203` ladder.
- 2026-08-01: After the `0x6103` slice, the full local V2 suite completed 67 tests: 60 passed,
  0 failed, and 7 external-DNAS tests skipped because their fixture directories were not configured.
- 2026-08-01: 15/15 focused TCP tests passed after correcting one stale state-label assertion; the
  composed socket ladder emitted `0x1007` and `0x6103` replies and observed `0x6212` without replying.
- 2026-08-01: Full local V2 suite completed 65 tests: 58 passed, 0 failed, and 7 external-DNAS
  replay tests skipped because their fixture directories were not configured.
- 2026-08-01: 13/13 focused TCP 10127 tests passed, covering three captured `0x1007` requests,
  malformed invariants, opaque payload preservation, fragmentation, delayed purpose resolution, and
  bounded pre-purpose input, plus observation of the following `0x6103` frame without a response.
- 2026-07-31: 56/56 local Node.js tests passed with the preserved DNAS capture, packet, and V1
  runtime fixture directories enabled.
