# op-0x10 game-channel family — RE (snap-re, 2026-08-24)

Filed by the goal session (the agent harness cannot write analysis/). Full trace in
SESSION-LOG-2026-08-24.md T15; this is the durable reference.

## Wire framing (Confirmed)
op-0x10 body: `[BE32 swapCount=1][BE32 target handle][u8 sub +3pad][payload raw]`.
Dispatch FUN_001d9f78 case 0xD → slot 0x13 FUN_005bba20, switch on sub (body+0x08).
Callback signature: handler(hdr+8 = the frame's connHandle word, body+8). The connHandle
word is the LINK id, not the originating peer — load-bearing (see solo-start).

## Q1 — sub-1 is a selector stream, NOT a room-info blob (corrects ROOMCHAT §2)
FUN_005bbb90: selector u32 at payload+0x00; sel 0 → char-choice-OK (value at +0x04),
sel 1 + screen 0x0c → mail/message chunk reassembly. No scenario, no rules, no roster.
Our 772-zero "player-info push" reads as sel-0/value-0 and clobbers uRam006febe8.

## Q2/solo-start ROOT — Confirmed (mechanism CORRECTED 2026-08-25 by nora + savestate)

> CORRECTION: the accept scan does NOT compare the relayed frame's wire token. `FUN_005bbfc0`
> compares `a0` against a roster entry decoded from 8 ASCII chars (`FUN_005c5120`; the op-06
> handler `FUN_005bb4d0` ASCII-encodes the FUN_001d80c8-swapped memberId via `FUN_005c50a0`).
> `a0 = *(frame+0x30) = conn+0x44` — the RECEIVING link's OWN handle (FUN_001e180c stamps it),
> a per-link constant, NOT the wire token. SAVESTATE-CONFIRMED (slots 5/6/8/9, in-room host):
> `conn+0x44 = 0x02f807d0` = the host's endpointToken, NATIVE (no swap). So the fix outcome is
> still correct — memberId = recipient's endpointToken, written BE32, is FUN_001d80c8-swapped to
> native 0x02f807d0, ASCII-roundtripped, and equals `a0` = conn+0x44 → the joiner's roster slot
> matches → accepted. The endianness (BE) is right; only the original causal story was wrong.

0x6ff2b3 (tested `<2` → solo shortcut at states 8/0x0a) = the count of roster slots with
0x6ff2b5[i]==1 (ACCEPTED). Accept is set by sub-4 FUN_005bbfc0: scan roster memberIds
(0x6ff70d+i*0x114, from op-06 +0x10) for == a0 (the frame connHandle word). We stamp a0 with
the RECIPIENT's own session id and serve memberIds 1/2 → never equal → no accept → 0x6ff2b3=1
→ solo, every time. Serving real op-0a records would NOT fix it (roster count was already 2).
FIX (2-player): per-recipient memberId — a record pushed to R about ANOTHER member carries R's
own session handle; the self-record keeps a distinct id; also push existing members to a joiner.
N-player: stamp the ORIGINATOR's handle into relayed connHandle (Ghidra item #1: is +0x30
validated on ingress? read FUN_001d72a8 caller / FUN_001eb2d4 / FUN_001ec9e0).

## Q3 — per-sub body spec (Confirmed)
1 selector stream · 2 join-req(none) · 3 start-reset(none, gate 0x6ff2b1==1) · 4 accept(0x300
zeros, CORRECT) · 5 {myIdx,total} · 6 {peerIdx,0,handle16,name16} · 7 charstats {slot,len,
u16 off,data} into 0x6fffd1+slot*0x114 (5 chunks 4×0x32+0x28 = 0xF0) · 8 download barrier
(sets 0x6ff2af) · 9 abort · a/b time-limit · c/11 member count · d evt · e/f ping/pong
(0xf → 0x6ff2b2=3) · 10 refuse (0x6ff2b5=2).
Host start seq (FUN_005c6500): sub-3 to all → STAT op-08 hide → wait accepts → sub-5/6 →
sub-7×5/player → sub-8 → op-0x0D barrier (FUN_005c4760, joiner waits unbounded on 0x6ff2af).

## Q4 — scenario/rules ride the CREATE optionsWord (Confirmed, IMPLEMENTED)
rules screen FUN_005f99c0 → uRam006febe4; create FUN_005c3490 packs max/time/pw/area then
func_0x001dc508(..., optionsWord = febe4<<1 = STAT). optionsWord = op-04 body +0x28 BE32.
Joiner: room-list FUN_005c19d0 record+0x1c = STAT; scenario=(STAT>>1)&0xFF; &0x8000 locked;
&0x40000000 hidden. Proof: 0x020b0a10>>1&0xFF = 8 = host ring (T13b). FIX SNAP_ROOM_STAT:
room.flags=optionsWord → op-49 +0x1c (committed 2026-08-24).

## Doc corrections logged
ROOMCHAT §1 sub-7-chat = WRONG/harmful (sub-7 = charstats); §2 sub-1-blob = superseded.
GAME-START §2 solo = accept count not roster count. codec:1166 +0x28 = room STAT, refined.
