# op-0x28 result dispatch: does the RECEIVED frame's 0x1000 bit select the completion callback?

Date: 2026-08-24 · Agent: snap-re · Binary: SLES_533.19 (main-ee) + 3.DAT overlay
Question (from SESSION-LOG-2026-08-24 T1/T2): for op28 sub-selector 0x07 (leave) and 0x06 (join),
does the received frame's flag word (wire +0x2c) participate in choosing which completion callback runs?

## VERDICT: **CONFIRMED** (decompile-backed, exact branch quoted)

The received op-0x28 frame's **0x1000 bit is THE discriminator** between the room-context and
lobby-context completion callbacks for sub-selectors **0x05, 0x06, 0x07** (and 0x09, 0x0a).
The PAL client implements exactly the split openSNAP documents for the Auto Modellista client.
`FUN_001d9f78` is the **only** function in the transport decompile corpus that reads
`*(ushort*)(hdr+0x2c) & 0x1000 / 0x2000` (discovery-grade: linear sweep of
`reverse-engineering/network/sources/executables/transport-decompile/*.c`, see Caveats).

**Required reply flag word for the in-room Exit leave: `0xA020`** (0x8000 reliable | 0x2000 |
len 0x20 = 16-byte body). Our current `0xB020` sets 0x1000 → routes to the LOBBY-leave slot.

---

## 1. Wire header layout (Confirmed)

Send side, `FUN_001e180c` (`reverse-engineering/network/functions/transport/001e180c_snap_packet_enqueue_send.md`):
stamps `+0x2c = who_flags | (bodyLen+0x10) & 0x3ff`, `+0x2e = (pktid << 8) | opcode`, `+0x30 = src id`.

Receive side, `FUN_001d9f78` (`transport-decompile/FUN_001d9f78.c:20-38`, identical to
`analysis/decompile-fun_001d9f78-2026-05-25.txt:56-74`) builds a 0x10-byte header struct on the stack
and passes `&cStack_40` as **param_1 of every callback**:

| off | var | value |
|---|---|---|
| +0x00 | `cStack_40` | cmd-type marker: `'\''`(0x27) if the frame was **cmd 0x27**, else 0 (cmd 0x28/0x29). This is the OK/FAIL signal. |
| +0x01 | `uStack_3f` | `(flags & 0x2000) == 0` |
| +0x02 | `uStack_3e` | pktid if 0x2000 clear, else **0** |
| +0x04 | `uStack_3c` | body length = `(flags & 0x3ff) - 0x10` |
| +0x06 | `sStack_3a` | **`0x1000` if `flags & 0x1000` else `0`** ← the channel bit |
| +0x08 | `uStack_38` | `*(hdr+0x30)` (src id) |
| +0x0c | `uStack_34` | pktid = `*(u16*)(hdr+0x2e) >> 8`, **always** |

Arithmetic check against the pcap: reply `b020 0028` → len `(0x020-0x10)=0x10` = the 16-byte body OK,
`0x0028 & 0x7f = 0x28` = op28 OK, pktid `0x0028>>8 = 0`. Request `a010 0007` → 0-byte body, op07,
pktid 0 OK. Lobby reply `b020 0128` → pktid 1 OK.

## 2. The op-0x28 result dispatch (Confirmed)

`FUN_001d9f78`: `uStack_2c = *(u16*)(hdr+0x2e) & 0x7f;  iStack_14 = uStack_2c - 3;  switch(iStack_14)`.
`case 0x24` (cmd 0x27) sets `cStack_40 = 0x27` and **falls through** `case 0x26` (cmd 0x29) into
`case 0x25` (cmd 0x28) — one shared result-dispatch for 0x27/0x28/0x29.

`case 0x25` (`FUN_001d9f78.c:239-...`, dump lines 265-330): bswaps the first two body words
(`FUN_001d7f6c`) then `iStack_18 = body[0] - 1` and switches. **sub = iStack_18 + 1**:

| sub | dispatcher branch | slot (offset) | meaning |
|---|---|---|---|
| 1 | `conn+0x5b8` | 0x1c | session/named-slot |
| 3 | `conn+0x5bc` | 0x1d | |
| 4 | `conn+0x5c4` — **no flag split** | 0x1f | create-slot completion (`FUN_005c3a40`) |
| 5 (delete) | `sStack_3a==0x1000 ? conn+0x5c0 : conn+0x5c8` | 0x1e / 0x20 | **split** |
| 6 (join) | `sStack_3a==0x1000 ? conn+0x5cc : (cStack_40==0x27 ? conn+0x5d0 : bswap + conn+0x5d0(body+4))` | 0x21 / 0x22 | **split** |
| **7 (leave)** | **`sStack_3a==0x1000 ? conn+0x5d4 : conn+0x5d8`** | **0x23 / 0x24** | **split** |
| 8 (STAT) | `conn+0x5dc` — **no flag split** | 0x25 | |
| 9 / 10 | `0x5a4/0x5a0`, `0x5ac/0x5a8` | | **split** |

Exact leave branch (`transport-decompile/FUN_001d9f78.c:282-289`; dump
`analysis/decompile-fun_001d9f78-2026-05-25.txt:316-325`):

```c
case 6:                                   /* body[0] == 7  => sub-selector 0x07, LEAVE */
  if (sStack_3a == 0x1000) {              /* received flags & 0x1000 */
    if (*(int *)(param_1 + 0x5d4) != 0)   /* slot 0x23 = LOBBY-leave completion */
      (**(code **)(param_1 + 0x5d4))(&cStack_40,puStack_30);
  }
  else if (*(int *)(param_1 + 0x5d8) != 0) /* slot 0x24 = ROOM-leave completion */
    (**(code **)(param_1 + 0x5d8))(&cStack_40,puStack_30);
  break;
```

Slot arithmetic `slot = (off - 0x548)/4` (`FUN_001d4d24`, `analysis/callback-table-install-map-2026-05-25.md:1-12`);
cross-checked by the known anchor sub-4 → `0x5c4` → slot 0x1f = `FUN_005c3a40`.

## 3. Who installs slot 0x23 vs 0x24 — the two leave senders (Confirmed)

Raw decompiles: `analysis/claude-sles-press-x-chain-2026-05-30.txt:29954` and `:30005`.

| sender | who-word | wire flags | seq counter | installs |
|---|---|---|---|---|
| `FUN_001dd07c` (lobby leave) | `0xb000` | **0xB010** | `conn+0x61a` | `FUN_001d4d24(1, 0x23, cb)` |
| `FUN_001dd1dc` (room leave) | `0xa000` | **0xA010** | `conn+0x61b` | `FUN_001d4d24(1, 0x24, cb)` |

```c
/* FUN_001dd1dc — the ROOM leave (this is the 0xA010 seq-0 frame in pcap 5185) */
lVar5 = FUN_001e180c(iVar2,iVar3,0xa000,0,7,*(undefined1 *)(iVar2 + 0x61b));
if (lVar5 == 0) { FUN_001d4d24(1,0x24,param_2); ... return (*(byte*)(iVar2+0x61b))++; }
```

The design is a **matched pair**: the who-word the client sends (0xa000 vs 0xb000) determines the
slot it arms, and the dispatcher picks the slot from the SAME bit on the reply. The reply must
mirror the request's 0x1000 bit or the wrong continuation is invoked.

## 4. The full room-Exit state machine (Confirmed unless noted)

Entry: `FUN_005c0e30` / `FUN_005c22a0` (overlay) → `cRam006cbb6c=1`, `cRam006cbb68=0`,
`uRam006ff2b1=3`, driver `pcRam006cbb48=FUN_005c1c80`, completion `uRam006cbb4c=<caller's cb>`.

`FUN_005c1c80` (`sources/overlays/overlay-3dat-decompile/FUN_005c1c80.c`) — per-frame:

```
state 0  if level-2(room) handle set -> FUN_005c0750(cb=0x5c1c30)   [sends op07 0xA010 (+STAT)]  -> state 1
         else -> state 2
state 1  wait cRam006cbb6d:  1 -> state 2   |  2 -> state 5(fail)          <-- WE ARE PARKED HERE
state 2  if level-1/0 handle -> FUN_005bfe00(cb=0x5c1c30)           [sends op07 0xB010]          -> state 3
state 3  wait cRam006cbb6d:  1 -> state 4   |  2 -> state 5
state 4  clear level flags; (*pcRam006cbb4c)(0)   -> screen advances
state 5  (*pcRam006cbb4c)(0xff)
```

**This explains the pcap exactly:** Exit emits ONE op07 (0xA010, the room leave) and then nothing.
The lobby leave (0xB010) is state 2 and is never reached. The client is parked in state 1.

`FUN_005c0750` = kkLeaveFromGameRoom (`analysis/claude-helper-module-full-2026-05-29.txt:16185-16199`):
```c
if (cRam006ff2b1 == '\0') { FUN_005bf130(2); (*extraout_a2_lo)(...); return 0; }
lVar2 = FUN_005be0a0(1,0,param_1);                       /* alloc pending slot, cb=0x5c1c30 */
cRam006ff2b1 = '\x03';
if (cRam006ff2b0 != '\0')                                 /* host/owner */
    func_0x001dd33c(uRam006febac,0x53544154,&uStack_4,4,0,0x5c06b0);   /* op08 'STAT' */
uVar1 = FUN_005c2080(2);            *(u16*)(slot*0x20 + 0x6ca97c) = uVar1;   /* TAG   */
uVar1 = func_0x001dd1dc(uRam006febac,0x5c06c0);
                                    *(u16*)(slot*0x20 + 0x6ca97e) = uVar1;   /* TXNID */
```

Pending/request table (`FUN_005be0a0`), base **0x6ca960**, stride **0x20**:
`+0x08` param2 · `+0x0c` continuation cb · `+0x1c` **tag** · `+0x1e` **txnid (pktid)**.
(CORRECTION 2026-08-24, nora review: the original line also listed "`+0x20` in-use", which cannot
coexist with stride 0x20 — `+0x20` is the next record's byte 0. The in-use marker's true offset is
unresolved; the slot-7 read shows record[1] byte0 = 1 for an armed-adjacent entry.)

Completion matcher `FUN_005be120` (helper dump; called from `FUN_005bdfe0` when `sRam006cbc7e==2`):
```c
if ((sRam006cbc80 == *(short *)(iVar1 + 0x6ca97e)) &&      /* txnid/pktid */
    (sRam006cbc7c == *(short *)(iVar1 + 0x6ca97c)))        /* TAG */
   { ...clear slot...; (**(code **)(iVar1 + 0x6ca96c))(&uStack_10,&uStack_10); }
```
Tag generator `FUN_005c2080` (helper:17190): `arg 2 -> FUN_005be9e0(0x7018d0, 0x70)` (ROOM),
`arg 1 -> FUN_005be9e0(0x7018d0, 0x43)` (LOBBY), `arg 0 -> 0x3e`. **The tags differ.**

## 5. What actually happens today with the 0xB020 reply (Confirmed mechanism)

Frame 5189 (`b020 0028`, body `00000007 00000000 00000000 00000000`) → `sStack_3a = 0x1000`
→ dispatcher calls **slot 0x23 = `FUN_005bfe90`** (the LOBBY-leave completion, installed earlier
in the session by the working lobby leave at pcap rows 4630-4634):

```c
void FUN_005bfe90(char *param_1) {                       /* helper:15779 */
  FUN_005c7d00();                                        /* uRam006febdf=0; febe0=Ram00368490 */
  if (*param_1 == '\0') { uRam006cbc84 = 0; FUN_005bf130(1); /* clears uRam006ce5cf = LOBBY handle! */
                          uRam006cbc80 = *(u32*)(param_1 + 0xc); }
  else { if (*param_1==0x27) uRam006cbc84 = 0xff; uRam006cbc80 = *(u32*)(param_1 + 0xc); }
  uRam006cbc7e = 2;
  uRam006cbc7c = FUN_005c2080(1);                        /* LOBBY tag (0x43-derived) */
  FUN_005bdfe0(0);                                       /* -> FUN_005be120 */
}
```

`FUN_005be120` then scans all 0x80 slots for `(txnid==0 && tag==LOBBY-tag)`. The room-leave's
pending slot holds `(txnid==0, tag==ROOM-tag)` → **no match** → returns -1 → `cRam006cbb6d` is
never set → `FUN_005c1c80` stays in state 1 forever → the 144.8 s screen watchdog fires. Exactly
the observed park, with no error and no further traffic.

**Collateral damage (Confirmed, PINE-testable):** the mis-fired lobby callback also runs
`FUN_005bf130(1)` which zeroes **`0x6ce5cf` (the LOBBY level handle)** and `FUN_005c7d00`
(`0x6febdf=0`). So even a later correct room completion would find `FUN_005bf1e0(1)` false at
state 2 and skip the lobby leave.

### PINE falsifier available with NO server change
At the park, predict: `0x6ff2b1 == 3`, `0x6cbb6c == 1`, `0x6cbb68 == 1`, `0x6cbb6d == 0`,
`0x6ce5d0 != 0` (room handle still set), **`0x6ce5cf == 0` (lobby handle wrongly cleared)**,
`0x6cbc7c == FUN_005c2080(1)` value, and a live pending slot in `0x6ca960[i]` with
`+0x20 == 1`, `+0x1e == 0`, `+0x1c == <room tag>`, `+0x0c == 0x005c1c30`.
Finding `0x6ce5cf == 0` while `0x6ce5d0 != 0` is a **unique fingerprint** of the wrong-slot dispatch.

## 6. Answers to the three sub-questions

**(1) Chain, UDP receive → sel-7 completion consumer**
```
UDP recv -> FUN_001d6988 (transport hdr: 0x8000 reliable / 0x800 / 0x3ff len; NO 0x1000 use)
         -> FUN_001d72a8 / FUN_001d6468 (reliable window + SACK; NO wire-flag routing;
            their 0x1000/0x2000 constants are FUN_001ebb90 buffer-state flags, not wire flags)
         -> FUN_001d6dfc -> FUN_001d9f78 (app demux)
              hdr struct built; sStack_3a = flags & 0x1000
              switch((op & 0x7f) - 3):  case 0x24(op27)/0x26(op29) fall through -> case 0x25(op28)
                 iStack_18 = body[0]-1
                 case 6 (sub 7): sStack_3a==0x1000 ? conn+0x5d4 : conn+0x5d8
         -> [0x1000 set]  FUN_005bfe90  -> tag=FUN_005c2080(1) -> FUN_005bdfe0 -> FUN_005be120 -> NO MATCH
         -> [0x1000 clr]  FUN_005c06c0  -> (tag=FUN_005c2080(2), inferred) -> FUN_005be120 -> match
                                        -> FUN_005c1c30 -> cRam006cbb6d = 1
                                        -> FUN_005c1c80 state 1->2 -> sends the 0xB010 lobby leave
```

**(2) Verdict:** **CONFIRMED.** The 0x1000 bit of the RECEIVED op28 frame selects room vs lobby
completion for sub 0x07 (slots 0x23/0x24), sub 0x06 (slots 0x21/0x22) and sub 0x05 (slots 0x1e/0x20).
Evidence per step is quoted above. The PAL client matches the openSNAP/AM `<> &1000` table.

**(3) Is anything ELSE gating it?** Yes — a SECOND key, but it is *downstream of* and *consistent
with* the flag bit, and it is already satisfied when the flag is right:
- `sRam006cbc80` = header `+0x0c` = **pktid** (`wire+0x2e >> 8`), matched against pending `+0x1e`.
  Our reply already carries pktid 0.
- `sRam006cbc7c` = **tag**, produced by the *callback itself* (`FUN_005c2080(1)` in the lobby cb,
  `FUN_005c2080(2)` expected in the room cb), matched against pending `+0x1c`.
  **The tag is not on the wire — it is a pure consequence of WHICH callback ran.** That is why the
  echo keys "both correct" in frame 5189 did not help.
- Correction to `docs/findings/protocol/_archive/lobby-back-exitarea-RE-2026-07-03.md` §5: the
  OK/FAIL byte is header `+0x00` = the **cmd-type** (0x27 frame = fail, 0x28 = OK), NOT `body[0]`
  (body[0] is the sub-selector); and the match id is header `+0x0c` (pktid), NOT `body+0xc`.
  Proof: the working lobby leave had pktid 1 and `body+0xc = 0x19`; the pending slot stored the
  `FUN_001dd07c` return = pktid = 1, so only the header reading matches.

## 7. Exact reply the server must send for the 0xA010 room leave

Target: `flags & 0x1000 == 0`, `flags & 0x3ff == bodyLen + 0x10`, keep 0x8000 (reliable) and 0x2000
(mirrors the request and the working lobby reply; with 0x2000 set the header `+0x02` field is zeroed
and the callback uses `+0x0c` instead — the lobby twin `FUN_005bfe90` reads `+0x0c`).

```
+0x2c  0xA020        (0x8000 reliable | 0x2000 room | len 0x20 -> 16-byte body)
+0x2e  0x0028        ((pktid=0) << 8 | op 0x28)   <- pktid must echo the request's pktid byte
body   00000007  00000000  00000000  <seq echo, LE>      (unchanged from today's reply)
```
i.e. **the only byte that must change is the high byte pair of the flag word: 0xB0 -> 0xA0.**
Rule: **mask 0x3000 of an op-0x28 completion must equal mask 0x3000 of the request it completes.**
This confirms the T1 "fix shape" line verbatim.

Scope of the rule (from the dispatcher table):
- sub 0x05, 0x06, 0x07, 0x09, 0x0a → **must** echo 0x1000. (sub 0x06 additionally: in ROOM context
  the callback receives `body + 4` after `FUN_001d8ed8` bswaps `body[2]` — the room-join completion
  body layout differs from the lobby one. Relevant to the create-self op06 12/13 work.)
- sub 0x01, 0x03, 0x04, 0x08, 0x0b, 0x0c, 0x0d → single slot, 0x1000 is **don't-care** for dispatch.
  So the sel-8 STAT reply (frame 5188) at 0xB020 was NOT mis-dispatched; echoing it to 0xA020 is
  harmless/consistent but is not the bug. (Note for later: sub-8's non-0x27 path runs
  `FUN_001d861c` — bswap `body[2]`, and `body[3]` too unless `body[2]=='NAME'` — then hands the cb
  `body + 4`.)
- H2 from T2 (bare-ACKing an embedded multi-child) is **not** contradicted by this trace, but it is
  also **not required** to explain the park: the wrong-slot dispatch fully accounts for it, and the
  client did transport-ack 5189, i.e. the frame WAS delivered to `FUN_001d9f78`.

## 8. Needs fresh Ghidra decompile (prioritized)

1. **`FUN_005c06c0`** (slot 0x24, ROOM-leave completion) — absent from every dump and from
   `sources/overlays/overlay-3dat-decompile/` (gap between the function ending at `LAB_005c065c`
   and `FUN_005c0750`). Needed to CONFIRM (a) it sets `sRam006cbc7c = FUN_005c2080(2)`,
   (b) which header offset it reads for the txnid (`+0x0c` assumed by symmetry with `FUN_005bfe90`),
   (c) whether it reads header `+0x01`/`+0x02` (i.e. whether the 0x2000 bit also matters).
   *If (c) turns out to require 0x2000 CLEAR, the reply would be 0x8020 instead of 0xA020.*
2. **`FUN_005c06b0`** (sel-8 STAT completion cb) — same gap; confirm it is fire-and-forget
   (not registered in the 0x6ca960 pending table), which the trace assumes.
3. **`FUN_005c1c30`** — the shared pending continuation; confirm `arg0==0 -> cRam006cbb6d=1`,
   `else 2`.
4. `FUN_005be9e0` / `FUN_005bea10` / `FUN_005bea80` (0x7018d0) — the tag generator internals; would
   give the literal 16-bit tag values so they can be read/compared over PINE.
5. `FUN_005bf1e0` — the level-handle test used at states 0 and 2 (assumed to read 0x6ce5ce/cf/d0).

## 9. Caveats (corpus methodology)

- "FUN_001d9f78 is the only reader of the wire channel bits" is a **linear text sweep** of
  `sources/executables/transport-decompile/*.c` (`grep "0x2c) & 0x1000|0x2000|0x3000"` → 1 file).
  Discovery-grade, not proof of absence: a mask loaded into a register, an overlay reader, or a
  module outside that export directory would be missed. The *positive* claim (case 6 branches on
  the bit) is Confirmed and is sufficient for the fix.
- `FUN_005c06c0`'s behavior is **Likely (high)**, inferred from the matched-pair design and from
  `FUN_005c0750` storing `FUN_005c2080(2)` as the tag. It is not decompile-confirmed.
- Nothing here is runtime-validated; the Pi is offline as of this session.

## 10. Highest-leverage next experiment

**Server change:** in the op-0x28 completion builder, set the reply flag word's 0x3000 bits from the
request's 0x3000 bits (`replyFlags = 0x8000 | (reqFlags & 0x3000) | (bodyLen + 0x10)`), behind a
flag (e.g. `SNAP_OP28_ECHO_CHANNEL_BITS`). For the in-room Exit this makes 5189 go out as **0xA020**.

**Verify, in order:**
1. *Local, no rig:* byte-exact fixture replaying pcap frame 5185 → assert the sel-7 reply's first
   u16 == `0xA020` and `+0x2e == 0x0028`.
2. *PINE, pre-fix (works today, cheap, high information):* at the in-room Exit park, read
   `0x6ce5cf`, `0x6ce5d0`, `0x6ff2b1`, `0x6cbb68`, `0x6cbb6d`, `0x6cbc7c`. Predicted
   `0x6ce5cf==0 && 0x6ce5d0!=0 && 0x6cbb68==1 && 0x6cbb6d==0` — that combination is only producible
   by the wrong-slot dispatch and would upgrade this to runtime-Confirmed **before** any deploy.
3. *Rig, post-fix:* Exit must now emit a SECOND op07 with flags **0xB010** (the state-2 lobby leave)
   within a frame or two — that outbound 0xB010 is the unambiguous success signal on the pcap,
   independent of what the screen does afterwards.
