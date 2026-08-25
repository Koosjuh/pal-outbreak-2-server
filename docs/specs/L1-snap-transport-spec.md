# L1 — SN@P Reliable Transport Specification (LIVING DOCUMENT)

**Purpose.** The graduation contract for the production SN@P transport library (`server/` L1). The
PAL client binary (SLES_533.19, main ELF) is the sole specification — there is **no** original SN@P
server and **no** historical capture. Every production transport decision must trace to a claim
here. Each claim is tagged **Confirmed** (decompile-backed, ideally runtime-corroborated) or
**Hypothesis** (plausible, not yet proven), with:

- **PAL fn/addr** — where in the binary.
- **Decompile finding** — what the code does.
- **Runtime** — observed behavior (PINE/pcap/journal), if any.
- **Harness test** — the experiment on `re-harness/` that validates it against the real client.
- **Production implication** — what L1 must do.

Status legend: ✅ Confirmed · 🟡 Hypothesis · ⛔ Rejected (kept to prevent rediscovery).
Addresses are main-ELF virtual addresses. Conn object base observed at EE `0x36d760`
(`= *DAT_0025b78c`); "conn+X" = offset into that object.

Last updated: 2026-08-24 (channel-context bits 0x2000/0x1000 + 0x0400 STRING bit Confirmed; openSNAP cross-refs). Previous: 2026-07-02. Owner: RE. Scope of the 07-02 revision: framing, crypto boundary, reliable
id/seq, ACK, windows, retransmit, buffer pool, session lifecycle, known/unknown, downgrades.

---

## 0. Object map (offsets referenced throughout)

| Symbol | Meaning | Evidence | Status |
|---|---|---|---|
| `DAT_0025b78c` | ptr to the connection object (`=0x36d760` runtime) | FUN_001d46ec sets `DAT_0025b78c = puVar1` | ✅ |
| `DAT_0025b790` | last-error global (0x64 no-conn, 0x65 alloc-fail, 0x66 send/latch) | FUN_001e0ed8/FUN_001e094c/FUN_001de840 write it | ✅ |
| conn+0x0c | outbound reliable-message id counter (post-increment) | FUN_001e180c: `iVar2=*(conn+0xc); msg+0x34=iVar2; *(conn+0xc)=iVar2+1` | ✅ |
| conn+0x58 | send/in-flight queue object ptr (word0=next?, +4=in-flight count) | FUN_001d46ec `conn[0x16]=FUN_001e1468(0x10)`; FUN_001d6468 uses `conn[0x16]` | ✅ struct, 🟡 exact field roles |
| conn+0x60 | retransmit queue object ptr | FUN_001d46ec `conn[0x18]=FUN_001d51e0(0x24)`; retransmit path | 🟡 |
| conn+0x50c | retry-exhaustion latch (300=retries, 200=list corruption) | FUN_001d5460 writes; FUN_001e0ed8/094c gate `if(conn+0x50c==0)` | ✅ |
| conn+0x518 | max-retry threshold compared against per-msg retry count | FUN_001d5460 `if(*(conn+0x518) < retrycount)` | ✅ |
| conn+0x520 | ptr to the shared message buffer POOL | FUN_001d5288 `FUN_001ec1f8(*(conn+0x520),…)`; init FUN_001ebed0 | ✅ |
| conn+0x7c | keepalive freshness field (phase-3 liveness) | prior RE (op40/FUN_001d9b6c); see §8 | ✅ (prior) |

---

## 1. SN@P frame structure

### 1.1 Wire header ✅ Confirmed
- **Decompile finding.** First `u16` big-endian at wire+0x00 = **flags | length**. Low 10 bits
  (`& 0x03ff`) = payload length (16-byte header + body, **excluding** the 4-byte trailer). Upper
  bits are flags (§1.2). wire+0x04..0x0f = 12-byte session token. wire+0x08 (`u32` BE) = reliable
  message **id/seq** (§3). wire+0x0c (`u32` BE) = **ack field** (§4). Struct↔wire: internal
  msg-object `+0x2c` == wire+0x00 (so msg+0x34 == wire+0x08).
- **Evidence.** FUN_001e180c writes flags to msg+0x2c and length `(param_4+0x10)&0x3ff` into it;
  FUN_001d6468 stamps id at msg+0x34; FUN_001ec1f8/FUN_001d6988 read `msg+0x2c & 0x3ff` as length.
- **Runtime.** Cross-checked on the wire: `a1 00`→len 0x100 (256B), `b0 40`→0x40 (64B),
  `60 10`→0x10 (16B, the 20-byte ack incl. trailer). Consistent.
- **Harness test.** Emit a reply with a deliberately wrong low-10-bit length; confirm the client
  drops it (already seen: writing the length high-byte into wire+0x02 corrupted opcode 0x48→0x148
  and the client dropped it — 2026-07-01 regression note).
- **Production implication.** L1 encodes/decodes: `flags16 = (flagbits) | (len & 0x3ff)` at wire+0;
  token at +4; id at +8; ack at +0xc; body at +0x10; 4-byte trailer `ba 47 66 11` last.

### 1.2 Flag bits (upper bits of the wire u16) ✅ Confirmed (all bits, 2026-08-24)
- **0x8000** = RELIABLE (message is tracked/retransmitted). FUN_001e180c reliable path taken when
  `param_3 & 0x8000`. ✅
- **0x4000** = carries-ACK (inbound frame frees a send). FUN_001d6988 invokes the ack-free path on
  this bit. ✅
- **0x0800** = COALESCED (more sub-frames follow in the same datagram). FUN_001d6988 walks
  sub-frames when set. ✅
- **0x2000 / 0x1000** = the CHANNEL-CONTEXT bits — ✅ Confirmed 2026-08-24 (upgraded from 🟡).
  `0x1000` distinguishes LOBBY-context (set, `0xB0xx`) from ROOM-context (clear, `0xA0xx`)
  messages of the same opcode, on BOTH directions of the wire:
  - **Send side:** matched sender pairs draw from separate per-channel reliable counters —
    lobby-leave `FUN_001dd07c` (`0xb000`, ctr `conn+0x61a`, arms slot 0x23) vs room-leave
    `FUN_001dd1dc` (`0xa000`, ctr `conn+0x61b`, arms slot 0x24). Explains "seq 0" on room-channel
    firsts (fresh counter), previously misread as anomalous.
  - **Receive side:** the op28 result dispatcher `FUN_001d9f78` routes the completion callback BY
    the received frame's `0x1000` bit (case 6: set → `conn+0x5d4` slot 0x23, clear → `conn+0x5d8`
    slot 0x24; same split cases 4/5 for sub 5/6; none for sub 4 create / sub 8 STAT).
    **Production rule: an op-0x28 completion's `0x3000` bits must equal the request's** — a
    lobby-flagged reply to a room-channel request fires the wrong callback class and parks the
    client (the C3 exit stall). Evidence: `analysis/op28-channel-bit-dispatch-2026-08-24.md`.
  - Independent cross-validation: the Auto Modellista SNAP client documents the identical
    `&0x1000` split in its callback tables (openSNAP `protocol/commands.py`; see
    `docs/findings/protocol/OPENSNAP-CROSSREF-2026-08-24.md` §2 — there `0x2000`=ROOM bit,
    `0x1000`=LOBBY bit, lobby context = both set, matching all our observed kind bytes).
- **0x0400** = STRING/relay bit (chat routing). ✅ Confirmed via v2 chat fix (RS1 round): the
  client dispatcher has no branch for a `0x1000`-set/`0x0400`-clear op-0x0F; room chat = `0xA4xx`,
  lobby/area chat = `0xB4xx` (`server-v2/src/udp/snap-lobby-session.js` `#onChat` notes). openSNAP
  agrees (`kkSendTextChat`: room `0xa400` / lobby `0xb400`).
- **Observed kind bytes (wire[0]):** `0x30` non-reliable DATA request; `0xB0` reliable DATA
  (0x8000|0x2000|0x1000, no ack bit); `0xB8` = `0xB0`|coalesce; `0x60` transport-ACK
  (0x4000|0x2000); `0xF0` reliable+ack DATA; `0xA1/0xE1` room-poll DATA. ✅ observed
- **Harness test.** For each kind, log whether the client advances/acks; already partially mapped.
- **Production implication.** L1 sets `0x8000` on all reliable sends, `0x4000` when piggybacking an
  ack, `0x0800`+sub-headers only if we ever coalesce (we should NOT need to). Routing bits set per
  app-layer opcode (L3 concern; L1 passes them through).

### 1.3 Trailer ✅ Confirmed
- 4 bytes `ba 47 66 11` at the end of every frame; the magic `0xba476600`/`…11` also gates
  inbound acceptance (§2). FUN_001d6468 appends `FUN_001e2304(0xffffffffba476611)`.
- **Production implication.** Append the 4-byte trailer to every outbound frame.

---

## 2. Crypto / framing boundaries

### 2.1 Body is Blowfish-encrypted; magic-gated ✅ Confirmed
- **PAL fn/addr.** Inbound: FUN_001d72a8 → decrypt → FUN_001edd9c; magic check `0xba476600`.
  Key material at conn+0x4d4 (ASCII "SNAP-SWAN", set in FUN_001d46ec at conn+0x4d5..).
- **Decompile finding.** FUN_001d72a8 reads a 4-byte value at `msg + reported_len + 0x28`, byte-
  swaps, compares to `0xba476600`; on match, sets the real length and decrypts the body; else drops
  the message (`iStack_50=0`). The 12-byte header (token) + the id/ack fields are **plaintext**;
  the **body** (from wire+0x10) is encrypted in 8-byte Blowfish ECB blocks.
- **Runtime.** Our op40 keepalive works only when its zero body is encrypted with the conn+0x4d4
  key (SNAP-SWAN) — PINE-confirmed prior session; a plaintext body overflowed a 136B client buffer.
- **Harness test.** Send a reply with correct plaintext header but garbage/unencrypted body →
  expect drop or crash; send correctly-encrypted → expect acceptance.
- **Production implication.** L1 must Blowfish-encrypt bodies with the per-session key (derived like
  the client: base key "SNAP-SWAN" region conn+0x4d4). Header/id/ack/trailer stay plaintext.

### 2.2 Coalesced sub-frames are parsed AFTER decryption ✅ Confirmed (critical)
- **PAL fn/addr.** FUN_001d6988 (called from FUN_001d72a8 after the decrypt/magic step).
- **Decompile finding.** When flag `0x0800` set: start = FUN_001ed6bc(msg) (decrypted body ptr),
  first sublen = `msg+0x2c & 0x3ff`; loop: advance by sublen, copy a 0x10-byte sub-header, next
  sublen = `subhdr[0] & 0x3ff`, each sub-frame has its own id. **Sub-headers live in the DECRYPTED
  body, not the raw datagram.**
- **Runtime.** The T8 regression proved this the hard way: a server-side walk over the **raw**
  (encrypted) datagram read ciphertext as fake sub-headers → garbage ack ids (0xcd0a0000,…) → freed
  wrong buffers → area-select lock.
- **Harness test.** Decode a coalesced `0xB8` op48 datagram both raw and post-decrypt; confirm only
  post-decrypt yields sane sub-ids.
- **Production implication.** To ack sub-frames of a coalesced datagram, L1 must **decrypt first**,
  then walk sub-headers. For outbound, prefer NOT to coalesce (send discrete frames) to keep acking
  simple. ~95% of client op48 frames are standalone `0xB0` anyway (§7 runtime), so single-frame
  handling covers the bulk.

---

## 3. Reliable message ID / sequence behavior

### 3.1 Per-connection monotonic id, stamped at transmit ✅ Confirmed
- **PAL fn/addr.** FUN_001d6468 (transmit), FUN_001e180c (finalize/enqueue), FUN_001ed68c (setter).
- **Decompile finding.** Reliable send id = `*(conn+0xc)`, post-incremented, written to msg+0x34
  (= wire+0x08). Non-reliable frames (`0x8000` clear) do not consume an id. FUN_001e180c enqueues
  the finalized message; FUN_001d6468 assigns the id at actual transmit and moves it to the
  in-flight set.
- **Runtime.** Journal op48 send-ids are small monotonic values (0x04,0x05,0x0b…0x10, then higher).
- **Harness test.** Observe that successive reliable client sends carry strictly increasing wire+0x08.
- **Production implication.** L1 maintains an outbound id counter per session; every reliable send
  gets the next id; the server’s own reliable pushes to the client use the server→client id space
  (separate direction). The two directions have independent id sequences.

### 3.2 Two independent directions 🟡 Hypothesis
- **Decompile finding.** Client stamps its own send ids (conn+0xc). Server→client reliable frames
  carry the seq the client uses for in-order delivery (the "recvBase"/wire+0x08 of our replies).
- **Runtime.** We capture the client's cumulative ack of server→client data from the transport-ack
  wire+0x0c (`s.gameAck`), and prior work found server pushes must be seq==recvBase to deliver.
- **Harness test.** Send two reliable server frames with seq = recvBase and recvBase+1; confirm both
  deliver in order; send with a gap and confirm the second buffers/doesn't deliver.
- **Production implication.** L1 tracks a server→client send seq per session, advanced by 1 per
  reliable frame, seeded from the client's recvBase; must not create gaps.

---

## 4. ACK format & semantics

### 4.1 ACK is per-message SELECTIVE by exact id — NOT cumulative ✅ Confirmed (correction)
- **PAL fn/addr.** FUN_001e1ac8 (free-on-ack), comparator FUN_001edfd0, invoked from FUN_001d6988
  when inbound flag `0x4000`.
- **Decompile finding.** The ack path searches the send/retransmit queues for the ONE entry whose
  `entry+0x28` (its stamped id) **== the acked value** (FUN_001edfd0 is a literal `==`), unlinks it,
  does RTT bookkeeping (FUN_001e19c4), and frees it to the pool (FUN_001ec9e0). If no entry matches,
  it is a **no-op**.
- **Runtime.** Our proven 20-byte ack (`60 10 00 00 | token | +0x08=0 | +0x0c=<id> | ba 47 66 11`)
  freed exactly the matching id; acking a garbage id (T8) freed an unintended entry → corruption.
- **Harness test.** Ack a known in-flight id → confirm that id stops retransmitting (journal) and the
  send-queue in-flight count drops by 1 (PINE conn+0x58+4). Ack an unknown id → confirm no effect.
- **Production implication.** L1 acks **each** reliable inbound message individually by echoing its
  exact id into wire+0x0c of a `0x60` frame. There is (so far) no evidence of a range/cumulative ack
  that frees multiple with one number — do NOT design around cumulative acking.
- ⚠️ **This corrects prior docs that called it "cumulative ACK."** See §10.

### 4.2 A separate cumulative recv-base may exist for ordered delivery 🟡 Hypothesis
- **Decompile finding.** FUN_001d6988 also maintains receive-window/ordering state (candidate SACK
  bitmask at conn+0x00/0x04 per earlier notes); the inbound wire+0x0c on the client's transport-acks
  looks like a cumulative ack of server→client data (`s.gameAck`).
- **Harness test.** Correlate `s.gameAck` progression with which server pushes the client delivers.
- **Production implication.** Ordered delivery of server→client frames likely uses a cumulative base
  distinct from the per-id free of client→server frames. Keep §3.2 and §4.1 as separate mechanisms
  until traced. **Unknown** until validated.

### 4.3 ACK frame shape ✅ Confirmed
- 20 bytes: `60 10 00 00` (kind 0x60 = 0x4000|0x2000, len 0x10), `token`=echo inbound wire+0x04..0x07,
  wire+0x08 = 0 (no reverse data) or our reverse-seq, wire+0x0c = acked id, trailer `ba 47 66 11`.
- **Runtime.** This exact shape stopped the 820 teardown on the f0/op2 channel (2026-06-21) and is
  the shape used for the (correct) op48 acks this session.

---

## 5. Send / receive window behavior

### 5.1 Client send window is bounded only by the server acking ✅ Confirmed (runtime)
- **Runtime.** With the server acking almost nothing, the client's in-flight reliable count
  (conn+0x58 queue depth) climbs **unbounded to 43** in the lobby (PINE, run 2026-07-02_08-24-58).
  A correct peer keeps it small by acking every reliable message.
- **Decompile finding.** No hard cap observed in FUN_001d6468/FUN_001e180c on in-flight count; growth
  is limited by buffer-pool availability (§7), not an explicit window size.
- **Harness test.** Ack every reliable inbound; confirm conn+0x58 in-flight stays low (single digits).
- **Production implication.** L1 MUST ack every reliable client message promptly. This is the core
  behavior a real peer provides and our harness never did — it is *the* likely root of the whole
  class of lobby/pool walls. (Not "cumulative drain" — per-id acking, §4.1.)

### 5.2 Receive window / in-order delivery 🟡 Hypothesis
- See §4.2. Server→client frames must arrive in-order (seq==recvBase, no gaps) to be delivered;
  out-of-window frames are buffered (and consume the client's pool). Not fully traced.
- **Production implication.** L1 sends server→client reliable frames strictly in seq order.

---

## 6. Retransmission behavior

### 6.1 Backoff and the exhaustion latch ✅ Confirmed
- **PAL fn/addr.** FUN_001d5460 (retransmit pass), gates in FUN_001e0ed8/FUN_001e094c/FUN_001de840
  (`if(*(conn+0x50c)==0)`).
- **Decompile finding.** Unacked reliable messages are retransmitted with a **+200 (ms) backoff**
  increment; per-message retry count compared against `conn+0x518`; if `retry > conn+0x518` the
  transport sets `conn+0x50c = 300` (a permanent latch: all subsequent sends fail with
  `DAT_0025b790 = 0x66`). List/queue corruption sets `conn+0x50c = 200`.
- **Runtime.** `conn+0x50c` observed **= 0 for every run** — the latch was never tripped; our walls
  were alloc-refusals (0x65), not retry exhaustion (0x66). The 7 stuck op48 ids retransmit ~39× each
  (they never give up within the observation window).
- **Harness test.** Never ack a reliable message; watch conn+0x50c eventually latch to 300 and all
  sends fail 0x66 (long-run). Ack it; watch retransmission stop.
- **Production implication.** If L1 acks promptly (§5.1), retransmission and the latch never engage.
  L1's own server→client retransmit policy is a free parameter (client doesn't dictate it) — pick a
  bounded backoff; must retransmit unacked server pushes until the client's cumulative base advances.

---

## 7. Buffer-pool / watermark constraints (the current wall's mechanism)

### 7.1 Pool layout ✅ Confirmed
- **PAL fn/addr.** Init FUN_001ebed0 (via conn init FUN_001d46ec as `FUN_001ebed0(conn+0x520,
  0x6e,0xf,0xa)`); alloc FUN_001ec1f8; free FUN_001ec9e0; alloc wrapper FUN_001d5288.
- **Decompile finding.** One pool, **three sub-pools**:
  | sub | block size | count | low-watermark |
  |---|---|---|---|
  | 0 (pool+0x00) | 0xec (236B) | 110 | pool+0x70 = **6** |
  | 1 (pool+0x14) | 0x22c (556B) | 15 | pool+0x72 = **3** |
  | 2 (pool+0x28) | 0x3ac (940B) | **10** | pool+0x74 = **3** |
  A request of size `S` (via `FUN_001d5288(conn,S)` → `FUN_001ec1f8(pool, S+0x14, 1, 1)`) is served
  by the first sub-pool with `S+0x14 ≤ blocksize−0x2c` **and** whose disable flag is clear.

### 7.2 Watermark hysteresis latch ✅ Confirmed (this is the op49 blocker)
- **PAL fn/addr.** FUN_001ec1f8 (alloc, param5=1 path), FUN_001eb2fc (flag check = `subpool+0xe
  bit0`), FUN_001eb33c (set flag), FUN_001eb37c (clear flag), FUN_001ec9e0 (free).
- **Decompile finding.** `param5=1` allocations (used by both op48 `FUN_001e094c` and op49
  `FUN_001e0ed8`, each requesting `0x2a8` → fits **only sub2**) are **refused** if the sub-pool's
  disable bit is set. Hysteresis: bit **SETS** when a post-alloc free count drops **below** the
  watermark (i.e. ≤ wm−1), **CLEARS** only when a post-free count rises **above** the watermark
  (≥ wm+1). For sub2 (wm 3): sets at free ≤2, clears at free ≥4.
- **Runtime.** PINE at op49-fail: sub-pool free counts 110 / 15 / **3**, `DAT_0025b790=0x65`. sub2
  oscillates 2–8 as op48 sends/frees churn; the disable flag toggles exactly at the ≤2 / ≥4
  boundaries. **The pool is NOT exhausted** — op49 is refused because sub2 is *latched*.
- **Harness test.** Watch `pool_sub2_free` (deref conn+0x520, +0x34) and `pool_sub2_disable_flag`
  (+0x36 bit0); confirm 0x65 coincides with the flag set, and clearing the flag (by freeing sub2
  blocks) lets op49 alloc.
- **Production implication.** L1's acking policy must keep the client's sub2 free count above its
  watermark **at the moment the client makes a sub2 alloc** (op48/op49). Since op49's send is
  one-shot at lobby entry (§8-related, app-layer), sub2 must already be healthy at that instant —
  which means acking the client's op48 sends **through the area-select→lobby transition**, not just
  after. This is a transport-level obligation the server must meet continuously.

### 7.3 Only op48/op49 pressure sub2 ✅ Confirmed
- **Decompile finding.** op48/op49 request 0x2a8 (→sub2, 940B). op0f (FUN_001de840) and other small
  ops request smaller sizes (→sub0/sub1). So the *unbounded window growth* (§5.1) is mostly small
  sub0 traffic; **sub2 pressure is specifically the op48 working set** (~7 concurrent).
- **Runtime.** Frame distribution (journals): ~2186 standalone 70B `0xB0` op48 vs ~108 coalesced
  136B `0xB8` (≈95% standalone). The 7 stuck ids retransmit as standalone frames.
- **Production implication.** To relieve sub2 it is sufficient (and necessary) to ack the client's
  op48 reliable sends by their outer id; coalesced op48 are rare and can be handled later via §2.2.

---

## 8. Session lifecycle

### 8.1 Connection creation ✅ Confirmed
- **PAL fn/addr.** FUN_001d46ec. Allocates a 0x624-byte conn object, zeroes it, sets `DAT_0025b78c`,
  stores the "SNAP-SWAN" key bytes at conn+0x4d5.., inits the buffer pool (FUN_001ebed0), the send
  (conn+0x58) / retransmit (conn+0x60) / delivery queues, opens a UDP socket and binds to a local
  port starting at 2000 (increments until bind succeeds), records the peer, sets defaults
  (conn+0x145=0x22 window?, conn+0x146=4). Returns 1 on success.
- **Production implication.** L1 models one connection object per client session with these
  sub-structures; the server side mirrors the peer's lifecycle but doesn't need identical internals.

### 8.2 Registration / session open 🟡 Hypothesis (partially prior-confirmed)
- The client's first datagram is a 154-byte kind-0x30 REGISTER; server replies a 154-byte
  `b0 96 00 2d` register-reply (proven to deliver — it seeds the recvBase). Post-register, a kind
  `0x31 op01` bind, then the app phase. (Prior sessions; re-verify under the clean L1.)
- **Harness test.** Full login→register→bind sequence capture; confirm the reply that advances.

### 8.3 Phase-3 keepalive / Error 840 ✅ Confirmed (prior)
- **PAL fn/addr.** FUN_001d9b6c (op40 consumer, refreshes conn+0x7c), timeout path FUN_001d7104 →
  FUN_001d94b0 (code 0x14=20 → Error 840).
- **Decompile finding.** The session stays alive only if the server periodically sends a reliable
  **op40** that refreshes conn+0x7c; absent it, phase-3 times out ~57s → 840.
- **Runtime.** Real-PS2 + emu validated (prior): a decoupled ~5s op40 keepalive prevents 840.
- **Production implication.** L1 sends a periodic op40 keepalive per session (body must be validly
  encrypted, §2.1). This is a transport-layer heartbeat, not app-layer.

---

## 9. Known vs Unknown (summary)

**Confirmed (safe to build L1 on):** frame header/flags/trailer (§1); Blowfish body boundary and
post-decrypt coalescing (§2); per-connection reliable id stamping (§3.1); **per-id selective ACK**
(§4.1, §4.3); unbounded client send window absent server acks (§5.1); +200 backoff + 0x50c latch
(§6.1); three-sub-pool layout + watermark hysteresis latch (§7); conn creation + op40 keepalive
(§8.1, §8.3).

**Unknown / Hypothesis (must validate before L1 relies on them):** two-direction seq detail and the
server→client cumulative recv-base / in-order delivery mechanism (§3.2, §4.2, §5.2); the exact
register/bind handshake bytes under a clean impl (§8.2); ~~routing-bit (0x2000/0x1000) general
semantics (§1.2)~~ — RESOLVED 2026-08-24, now Confirmed in §1.2; whether any range/cumulative ack
exists alongside the per-id free (§4.2); the encryption key derivation exact algorithm (we know the
"SNAP-SWAN" region works; the full key schedule is not documented here).

**AM-derived leads (openSNAP, 2026-08-24) — discovery only, each needs its one-function PAL check
before L1 relies on it** (`docs/findings/protocol/OPENSNAP-DEEP-DIVE-2026-08-24.md`):
- Client reliable receive window = **16** (`kkCreateARUDPRevWindow(0x10)`, both SLUS builds).
  PAL check: find the ARUDP window-create call in SLES_533.19 and its constant. Bears on v2's
  in-flight caps (currently 32-based) — an overrun would silently drop server reliables.
- Client retransmit = **200 ms cadence, oldest-pending only, retry gate < 5**, then park until a
  **60 s** inbound-silence timeout (`kkSendOperation` +0x00c8). PAL check: FUN_001d5460's cadence
  reload + `conn+0x518` default. Bears on v2's chosen RTO (1620 ms + 200/retry, cap 48 — graded
  "a CHOICE, not an observation" in `reliable-channel.js:210-218`).
- Client send-pool retirement reads the ack field **only from 0x4000-flagged frames**
  (`kkSetRevAck`). Consistent with our bare-0x6010-only acking; a PAL check would additionally
  license piggybacked acks (the one unclaimed reduction, `reliable-channel.js:72-80`).

---

## 10. Downgrades — previously-assumed claims now Hypothesis or Rejected

- ⛔ **"op49 fails because the conn+0x520 pool is EXHAUSTED; drain it."** REJECTED. T7 PINE: free
  counts 110/15/3 — the pool has free blocks. The blocker is the **sub2 watermark latch** (§7.2).
- ⛔ **"Correct cumulative-ACK advances the send window / drains the pool."** REJECTED as stated.
  The ack is **per-id selective** (§4.1). A cumulative recv-base may exist for the *other* direction
  (§4.2) but is unproven and is not the pool-drain mechanism.
- 🟡 **"Acking op48 will unlock the lobby."** DOWNGRADED to Hypothesis. Necessary for sub2 relief but
  not yet sufficient at runtime: op49's send is one-shot at the area-select→lobby transition, so the
  ack must keep sub2 healthy *through the transition*, which the op06-gated version did not (op49 had
  already failed its one shot). Open.
- 🟡 **"The op49 empty-reply (SNAP_ROOMLIST_REPLY) unlocks the cursor."** DOWNGRADED. Moot until op49
  actually transmits; and the reply's real record layout is unknown (app-layer, out of L1 scope).
- 🟡 **"Coalesced sub-frames can be walked from the datagram."** Corrected: only **post-decrypt**
  (§2.2); the raw-walk produced garbage acks (T8 regression).
- 🟡 **Prior "recvBase = cumulative ack we mirror in replies" as the delivery lever.** Re-open as
  §4.2 Hypothesis; not the pool mechanism.

---

## 11. Graduation checklist (RE → production L1)

A transport behavior may move into `server/` L1 only when:
1. It has a **Confirmed** claim here (decompile + at least one runtime corroboration), and
2. A harness test demonstrates the real PAL client accepting/advancing on it, and
3. It is expressible without any `SNAP_*` special-case flag (flags are harness-only).

First production milestone (L1 v0): a session that registers, keepalives (op40), and **acks every
reliable client message by per-id selective ACK**, keeping the send window small and sub2 above its
watermark continuously — validated by: client reaches the lobby, sub2 free stays ≥4 through the
transition, `DAT_0025b790` never latches 0x65, and op49 transmits (`cmd=0x49` on the wire).

---

## 12. RUNTIME VALIDATION — L1 v0 milestone ACHIEVED (2026-07-02)

Run `tests/results/2026-07-02_09-23-11_emulator_GT-003` (Pi node 59286, flags SNAP_ACK_OPS=all +
SNAP_ACK_OP48_ALWAYS=1). **User-confirmed: lobby cursor UNLOCKED, room/slot screens navigable.**

The core L1 hypothesis is now **runtime-validated** — promote §4.1 + §5.1 + §7.2 from
"Confirmed (decompile)" to "Confirmed (decompile + runtime)":
- We acked EVERY reliable client message per-id (outer id, no coalesced walk), INCLUDING op48
  through the area-select->lobby transition (SNAP_ACK_OP48_ALWAYS lifts the T9 op06 gate).
- PINE: `DAT_0025b790` stayed **0** (no 0x65), `pool_sub2_free` stayed **0x0a (10, full)`,
  `pool_sub2_disable_flag` stayed **0** — sub2 NEVER latched.
- op49 transmitted (wire: `f8/b0 .. 00 49`, seq 0x2d-0x30) and `ctx3_subq` reached **4** (all 4
  sub-queries completed); lobby SM advanced screen **02 -> 03**.
- Journal: 92 reliable-acks (vs 6 when gated), 33 op49 replies.

⇒ **Proven:** per-id selective ACK of all reliable client messages, applied continuously from
connect (not gated to post-op06), keeps the buffer pool healthy so the client's one-shot allocations
(op48/op49) succeed and the lobby state machine advances. This is the foundation for `server/` L1.

Open follow-ups (not blocking the milestone):
- Send-window in-flight count still climbs (0x48->0x66) — mostly small sub0 traffic; not all
  opcodes may be acked, or the client sends faster than one-ack-per-frame. Harmless for now (sub0
  has 110 blocks) but L1 should ack comprehensively to keep it bounded (§5.1).
- `player_total` = 0 and the room list is still our synthetic/empty reply — the MULTIPLAYER app
  layer (real rooms, seeing other consoles, area population) is the next problem, on top of this now-
  working transport. The op49 request layout is now capturable on the wire (op49 finally transmits).
