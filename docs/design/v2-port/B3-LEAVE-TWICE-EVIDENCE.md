# B3 — "cannot leave an area twice": the second exit is not a missing op-0x07, it is an unanswered op-0x02 CLOSE

Evidence doc, 2026-08-08. Sources: `captures/v2-live/T37-20260808-090328.pcap` (+ its journal
log), corpus records under `reverse-engineering/network/`, raw decompiles under
`reverse-engineering/network/sources/overlays/overlay-3dat-decompile/`, and
`docs/findings/protocol/G12-exit-contract-RE-2026-07-17.md` (the V1 two-stage-teardown RE).
Evidence ranking: runtime > PINE > wire > decompile > notes. Every claim below is tagged
**O**bservation / **I**nference / **H**ypothesis / **C**onclusion.

---

## TL;DR (Conclusion)

The task statement "the client sends NO second op-0x07 at all" is true but incomplete. **On the
second exit press the client DOES send something: a zero-body reliable op-0x02 — the SN@P
transport session-CLOSE (`FUN_001dbd0c snap_send_close`, the tag-0x20 stage-2 teardown of the
exit-contract RE). The server has no handler for it** (journal: `lobby-observed-message
opcode 0x2 … "no handler for this opcode in the post-selection phase"`), sends only the bare
transport ack, and the client parks in its close-wait (`cRam006cbbe0` never reaches 2 — the
exact freeze mechanism the exit-contract doc already described). One instance self-recovered by
a full in-place re-register ~7 s later; the next instance wedged permanently (client stopped
answering op-0x40 keepalives).

So B3 decomposes into:
1. **Proximate, server-fixable:** op-0x02 is unanswered. Completing the close handshake turns the
   wedge into a (heavy but working) back-out — the client's own recovery path already proved the
   re-register lands back on a working Area Select.
2. **Root cause, still open:** why the client routes the *second* exit down the transport-close
   path instead of sending op-0x07 again. The first leave's replies were correct as far as the
   V1-proven format goes; the candidate state-corruption mechanisms and the one-shot PINE reads
   that discriminate them are in §6.

---

## 1. The wire record (Observation — pcap, both consoles)

Framing (per `server-v2/src/transport/reliable-channel.js` `#decodeMessageAt`): 16-byte header
`[flags|len u16 BE][sub u8][opcode u8][token u32][seq u32 BE][ack u32][payload…]`, then a 4-byte
datagram trailer — **constant `ba 47 66 11` in every datagram of this capture, both directions,
both consoles** (O; relevant in §5).

### 1a. Session B — the clean post-deploy repro (.248, `test123`)

| frame | time (UTC) | dir | message | raw |
|---|---|---|---|---|
| 2713 | 07:35:56.4 | C→S | **op-0x06 ENTER box 2**, sub=0x00, seq 0x0b | `b014 0006 02f807d0 0000000b 00000000 00000002` |
| — | | S→C | ack + **op-0x28 sel-6 status-0, sub 0x00** | payload `00000006 00000000` |
| … | | C↔S | op-0x0F probe, op-0x49 LOID/STAT probes, op-0x09 USER count — all answered | |
| 2755 | 07:35:59.9 | C→S | **op-0x07 LEAVE**, sub=0x00, seq 0x16, ZERO payload | `b010 0007 02f807d0 00000016 00000000` |
| 2756 | +4 ms | S→C | transport ack (op-0x00 flags 0x6, ack 0x16) | |
| 2757 | +5 ms | S→C | **op-0x28 sel-7 status-0, sub 0x00**, seq 0x14 | `b018 0028 02f807d0 00000014 00000000` + `00000007 00000000` |
| 2758 | +41 ms | C→S | client acks seq 0x14 | |
| 2759 | +240 ms | C→S | op-0x48 area-name refresh — **client is back on Area Select and healthy** | |
| 2774 | 07:36:01.5 | C→S | **op-0x06 ENTER box 1, sub=0x01**, seq 0x1b | `b014 0106 02f807d0 0000001b 00000000 00000001` |
| 2776 | +3 ms | S→C | ack + **op-0x28 sel-6 status-0, sub 0x01 (echoed)** | `b018 0128 … 00000006 00000000` |
| … | to 07:36:08 | C↔S | the SAME probe set as after enter 1 (op-0x0F "OBAREA-V3", op-0x49 LOID box 1, op-0x09 sub=0x01 USER → count reply sub echoed) — all answered | |
| **2826** | **07:36:10.9** | C→S | **exit press #2 = op-0x02, sub 0x00, seq 0x29, ZERO payload** | `b010 0002 02f807d0 00000029 11000000` |
| 2827 | +2 ms | S→C | **transport ack ONLY. No app reply, ever.** | |
| 2828–2864 | 07:36:11–16 | S→C | op-0x40 keepalives; **client stops answering op-0x41** | |
| 2868–2881 | 07:36:17.9 | C→S | client self-recovery: full **re-register** (op-0x2c/0x2d, op-0x01 sign-in, op-0x48, op-0x0c) on the same socket — fresh epoch, seqs reset | |
| 2897 | 07:36:21.4 | C→S | **op-0x06 ENTER box 4, sub=0x00**, seq 0x6 — answered normally, probes answered | `b014 0006 … 00000004` |
| **2940** | **07:36:28.6** | C→S | **exit press #3 = op-0x02 again**, seq 0x12 | `b010 0002 02f807d0 00000012 00000000` |
| 2941+ | | S→C | ack only. **Client wedges permanently** — no further op-0x41 keepalive responses, no recovery, only server op-0x40s until capture end (07:40+) | |

### 1b. The same pattern on the PS2 (.129, `real`) — session A

- 07:09:58.583 (frame 1031): **op-0x07** leave, answered op-0x28 sel-7 status-0. Journal line 489:
  `lobby-leave from {box 9, room 1, slot 0, depth 4} → depth 2, answered:true`. Works. (O)
- 07:11:23.674 (frame 1123): exit press #2 from the in-area room list → **op-0x02**, seq 0x6b.
  Journal line 514: `lobby-observed-message opcode 0x2 … no handler`. (O)
- 07:11:45.9: client self-recovery re-register — journal line 523/524: *"a fresh register epoch
  replaced this session"*. (O — the journal and pcap agree to the second.)

### 1c. op-0x02 is ALSO part of the normal connect ritual (Observation, important context)

.129's very first contact (frames 78–86): op-0x2c/0x2d register → **short op-0x01 (326 B)** →
op-0x28 sel-1 → **op-0x02 (zero body, seq 0)** → server acks only → **21 s of silence** → full
re-register with the long op-0x01 (566 B). The same connect-time op-0x02 appears from .248
(frames 420, 1288, 2553). So the client already uses op-0x02 as "close this session" during its
probe-connect, tolerates the missing close-confirm there, and appears to sit out a ~20 s timeout
before proceeding. (O for the sequence; the "timeout" reading of the 21 s gap is **I**.)

---

## 2. What op-0x02 is (decompile, corpus)

`OPCODE_INDEX.md` §0x02: `0x001dbd0c snap_send_close`, `0x001dbe60 snap_close`,
`0x001ef5c0 snap_req_op02`, `0x005c5ff0 send_op02`.

- The observed frame — flags 0xb, inner length 16, **zero payload** — matches
  `FUN_001dbd0c` exactly: `FUN_001e180c(conn, buf, 0xb000, 0, /*opcode*/2, /*len*/0)`. This is
  **the "SN@P 0xb000 type-2 CLOSE" of `G12-exit-contract-RE-2026-07-17.md` stage 2 (tag 0x20)** —
  the flags word 0xb000 and opcode 2 are what that doc's V1 trace called "type-2 close". (C)
- `FUN_005c5ff0 send_op02` builds a **4-byte** body — not what is on the wire here; excluded. (O)
- Per the exit-contract RE, after sending the close the client's screen-6 SM parks until the
  transport signals disconnect-complete (`cRam006cbbe0 == 2`, completion `FUN_005be7b0`), and
  `FUN_001dbd0c` is also reachable from the receive dispatcher `FUN_001d9f78` — *"the close is a
  bidirectional 0xb000 handshake the dispatcher mirrors."* (decompile, from that doc)

The park, the 7 s give-up, and the eventual full re-register observed in §1 are precisely the
behavior that doc predicted for an uncompleted close. (C)

Note per the task brief: **op-0x08 is the `"STAT"` named-channel query and is NOT involved in the
exit path here** — no op-0x08 appears anywhere near the exits in this capture. (O)

---

## 3. The first-leave exchange, byte-level, vs. the contract (Observation + decompile)

The first leave is **fully answered and fully works**:

```
C→S  b0 10 00 07 | 02 f8 07 d0 | 00 00 00 16 | 00 00 00 00 |            | ba 47 66 11
     flags RELIABLE, len 16 (zero payload), sub 0x00, op 0x07, seq 0x16
S→C  60 10 00 00 …  transport ack of seq 0x16                    (+4 ms)
S→C  b0 18 00 28 | 02 f8 07 d0 | 00 00 00 14 | 00 00 00 00 | 00 00 00 07  00 00 00 00 | ba 47 66 11
     op-0x28, sub 0x00 (echoes request sub), payload = selector 7 (AREA_LEAVE), status 0  (+5 ms)
C→S  ack of 0x14 (+41 ms); op-0x48 Area-Select refresh (+240 ms)
```

Client-side machinery this feeds (raw decompiles on disk):

- **Sender:** the leave pump `FUN_005c1c80` step 2 → `FUN_005bfe00` → `func_0x001dd07c`
  (zero-length reliable op-0x07, reply cb `FUN_005bfe90`), request slot allocated in the 128-slot
  pool at `0x6ca980` (stride 0x20; id `+0x6ca97c`, send-seq `+0x6ca97e`) by `FUN_005be0a0`. (O)
- **Reply handler `FUN_005bfe90`:** `param[0]==0` → success: clears **channel 1**
  (`FUN_005bf130(1)` → `0x6ce5cf = 0`), latches `0x6cbc80 = (u16)*(u32*)(param+0xc)`,
  `0x6cbc7e=2`, `0x6cbc7c=FUN_005c2080(1)`, then `FUN_005bdfe0(0)` → `FUN_005be120` sweeps the
  pool for `sendSeq==0x6cbc80 && id==0x6cbc7c`, and **only on a match** clears the slot and fires
  the stored continuation (the pump's step-3 release). (O — decompile)
- **Pump completion (step 4):** with `cRam0070047c==0`, **commits pending→committed for ALL three
  location channels** (`FUN_005bf180(0/1/2)`): committed ch0 `0x6ce5ce`, ch1 `0x6ce5cf`, ch2
  `0x6ce5d0` ← pending `0x6ce5c4/c5/c6`. The exit flow arms the pump via
  `FUN_005c0e30(0,0,0,cb)` — pending target **(0,0,0)** — so a completed leave zeroes all three
  committed channels. (O — decompile `FUN_005c1c80.c`, `FUN_005c0e30.c`, `FUN_005f8060.c`)

**Contract deviation found (the only one):** the handlers latch a 32-bit word at reply
**payload+0xc**, but our sel-7 (and sel-6) payload is only **8 bytes**. Bytes 0x8–0xb beyond it
are the constant datagram trailer `ba 47 66 11`; +0xc is past the datagram entirely. The
create-accept RE (`G12-create-accept-wireformat`) and the exit-contract RE both say the real
reply carries **the request's echoed send-seq at +0xc** for the dual-key pool match. Our reply
cannot satisfy that read. (O for the lengths; **C** that the read goes out-of-message.)
Empirically the enter/leave continuations still fire (the client visibly advances within 240 ms),
so either the callback's `param` base is not the payload start, or completion travels the direct
slot-dispatch path and the `FUN_005be120` sweep just fails and **leaks the pool slot**. Which of
these is true is not decidable from the on-disk dumps — see gap G3. (**H**)

---

## 4. What re-arms the exit path — and what the wire says about it

Decompile chain for the re-arm (all files on disk):

- Area ENTER launcher `FUN_005bfa70`: writes **pending ch0 = box** (`FUN_005bf0e0(0, box)`),
  sends op-0x06 via `func_0x001dc9fc` with reply cb **`FUN_005bfb40`**, which on `param[0]==0`
  **commits ch0** (`FUN_005bf180(0)` → `0x6ce5ce = box`). (O)
- The pump only sends op-0x07 when **committed ch0 or ch1 is non-zero**
  (`FUN_005c1c80` step 2: `if (bf1e0(1)==0 && bf1e0(0)==0 || pending-ch0!=0) skip to success`). (O)
- Therefore: **the op-0x07 exit path is re-armed by the op-0x06 enter-accept committing ch0.**
  If ch0 stays 0, a pump-based exit "succeeds" silently without sending anything, and the exit
  flow falls through to the screen-6 transition — whose teardown is exactly the op-0x02 close
  (`FUN_005f6970 → FUN_005f6aa0 → FUN_005f7270` tag 0x20 → `FUN_005be690/700` →
  `snap_close`). (**C** for the mechanism; assembled from the raw decompiles + exit-contract RE)

Against the wire:

- After the second enter the server's replies are **byte-identical in kind** to the first
  (op-0x28 sel-6 status-0, sub correctly echoed 0x01; every follow-up probe answered the same).
  Nothing the server sent distinguishes enter#2 from enter#1 except the echoed sub. (O)
- The second enter's continuation **did apparently run** — the same op-0x0F/op-0x49/op-0x09 probe
  volley fired ~60 ms after the sel-6 accept, as after enter#1. (**I**: those probes follow the
  accept, not precede it, in every instance in this capture.)
- Yet exit#2 emitted the close, not op-0x07 — and did so **even in the fresh epoch** (re-register
  + sign-in + enter box 4, request sub back to 0x00, transport seqs reset), where no op-0x07 had
  been sent in that epoch at all. So whatever mis-routes the exit **survives a full re-register
  and sign-in; it is client process RAM, not per-epoch session state.** (O + **C**)

Two candidate mechanisms remain (both consistent with every observed byte):

- **M1 — dead re-arm:** `FUN_005bfb40` did not run (or ran without the pool continuation, cf. the
  +0xc mismatch) on the re-enter, committed ch0 stayed 0, the pump short-circuited, the exit flow
  degraded to the transport close. Predicts `0x6ce5ce == 0` while standing in the area. (**H**)
- **M2 — nav-route flip:** ch0 is fine, but the exit input routes down the screen-6 close path
  without consulting the pump at all — some flag set by the *first* completed leave (candidates:
  `iRam0035b9e0`, `0x70047c`, the screen-6 reason byte `0x6c4ba0`, tag `0x6c4fbb` residue)
  persists and reroutes every later exit. Predicts `0x6ce5ce == box` and `0x6c4fbb == 0x20` at
  the second press. (**H**)

The discriminator is a **single PINE read set** — §6.

---

## 5. Server-side status quo (Observation, code + journal)

- `server-v2/src/udp/snap-lobby-session.js` `#onLeave` answers op-0x07 with op-0x28 selector 7
  status 0 and one presence `ascend()`. Both T37 leaves were answered (`answered:true`) and the
  presence depths moved correctly. **The op-0x07 half of the server is not the defect.** (O)
- op-0x02 falls into the unhandled bucket: `lobby-observed-message`, note *"no handler for this
  opcode in the post-selection phase"* — transport-acked, never answered, session left open until
  `gap-abandoned`/displacement. (O)

---

## 6. What settles the remainder (targeted, one rig/emulator run)

PINE sampler on the emulator, watch list — read at four moments (after enter#1, after leave#1,
after enter#2, at the second exit press):

| addr | meaning | M1 predicts | M2 predicts |
|---|---|---|---|
| `0x6ce5ce` | committed ch0 (area) | **0 after enter#2** | box id after enter#2 |
| `0x6ce5cf` / `0x6ce5d0` | committed ch1 / ch2 | 0 / 0 | 0 / 0 |
| `0x6c4fbb` | pending tag | 0x20 at press #2 | 0x20 at press #2 |
| `0x6cbb6c` / `0x6cbb68` | pump armed / step | armed then instant-complete | never arms |
| `0x6cbbe0` / `0x6cbbe4` | close progress / armed | sticks <2, ==1 (both) | sticks <2, ==1 (both) |
| `0x6cbc80` | latched reply word | 0x47ba if +0xc reads the trailer (settles G3) | same |

Ghidra targets if decompile is preferred: the in-area screen's Triangle handler (the router that
chooses pump-leave vs `FUN_005f6970`), the `FUN_005c0e30` callers `FUN_0062cb00` /
`FUN_0062e720` / `FUN_00617a50`, and the writer of `cRam006cbbe0 = 2` (the close-complete signal
— exit-contract needs-decompile #2, still the highest-value unknown).

---

## 7. Server-side fix candidates (for the implementing session — NOT yet validated)

1. **Answer the close (proximate fix, decompile-grounded).** On op-0x02 in the post-selection
   phase: keep the transport ack and **mirror the close back** — a server→client zero-body
   op-0x02 (flags 0xb, len 16, stamped seq), per the exit-contract note that the 0xb000 handshake
   is bidirectional and the dispatcher mirrors it; then close/release the server-side session so
   the follow-up register epoch is clean (the client re-registers by itself, and T37 proves that
   recovery lands on a working Area Select). Flag-gate it. Success criterion on the rig:
   `0x6cbbe0 → 2`, screen leaves the park, second exit no longer wedges the console. (**H** until
   rig-confirmed; the exact close-confirm shape is gap G1.)
2. **Make the +0xc echo real (root-cause candidate, cheap).** Extend the op-0x28 completion
   payload for sel-6/sel-7 from 8 to 0x10 bytes with the request's **send-seq echoed at +0xc**
   (exactly what the create-accept/exit-contract REs say the real reply carries). This makes the
   documented dual-key completion deterministic instead of dependent on an out-of-message read,
   and is the only observed deviation from the RE'd reply contract in the whole first-leave
   exchange. If M1 is the mechanism, this is the actual fix for "leave twice". (**H**)
3. Re-run the B3 repro with 1+2 and the PINE watch of §6 — one run decides M1 vs M2 and validates
   or kills both fixes.

---

## 8. Corrections / reconciliation

- The B3 statement in `COLD-START-2026-08-08.md` §2 ("the client sends NO second op-0x07 at all")
  should be amended: the client sends an **op-0x02 close** on every post-first-leave exit press
  (3 clean instances in T37: .129 07:11:23, .248 07:36:10, .248 07:36:28). Not a contradiction —
  a refinement.
- `G12-exit-contract-RE-2026-07-17.md` stage-2 is hereby **wire-confirmed for the first time**
  (its "0xb000 type-2 CLOSE" = the observed zero-body op-0x02, and the predicted park/timeout
  behavior is observed end-to-end). Its stage-1 (tag 0x19 STAT/op28-sel-8) did NOT appear on this
  path — the area exits go op-0x07 (once) then op-0x02 (ever after).
- Corpus records touched and found consistent: `001dd07c_snap_send_leave`,
  `005bfe00_start_leave_txn`, `005bfe90_leave_reply_handler`, `005c1c80_pump_room_enter_sequence`
  (name is misleading — it is the LEAVE pump; suggest rename note), `005bfa70`/`005bfb40`
  (area-enter pair), `005be0a0`/`005be120` (pool), `001dbd0c_snap_send_close`. The
  `005c5ff0 send_op02` record's "sign-in call site" inference is unaffected but that variant
  (4-byte body) is not what B3's wire shows.
