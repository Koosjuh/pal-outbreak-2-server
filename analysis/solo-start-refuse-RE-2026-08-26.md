# Solo-start REFUSE root cause (2026-08-26) — the accept-then-refuse race

Headline for the coordinator's live-wire pattern (3 identical attempts):
`recv op-0x10 sub-3 START -> send sub-4 ACCEPT -> send sub-0x10 REFUSE (~10ms later)` -> solo.

## VERDICT (Confirmed by decompile)
The REFUSE is **NOT a roster/charstats/scenario validation failure**. It is a **screen-state race
caused by the joiner receiving op-0x10 sub-3 START MORE THAN ONCE.** The host start SM sends sub-3
to EVERY seated member id — including its OWN seat0 — so with {host, joiner} seated it emits TWO
sub-3 frames. Both reach the joiner. The joiner ACCEPTs the first (screen 4/0xe), the accept path
advances the joiner's screen off 4/0xe, and the SECOND sub-3 then falls into the else-branch =
REFUSE. On the host the refuse marks the joiner's accept slot `0x6ff2b5[i]=2`, the accept count
never holds at 2, so the host takes the solo shortcut and never emits sub-5/6/7/8.

**Direct server fix: deliver EXACTLY ONE sub-3 to the joiner — do not forward the host's
self-targeted op-0x10 to the joiner.** No charstats/memberId change is needed for the refuse (that
is the separate character-render problem; see charstats-propagation-RE-2026-08-26.md).

## The send-side proof chain (all overlay-3dat, Confirmed)
- op-0x10 sub-dispatch `FUN_005bba20` (slot 0x13 = cmd 0x10 flag 0x8000): `switch(body[8])`
  case 3 -> `FUN_005bbf20` (sub-3 recv), case 4 -> FUN_005bbfc0 (accept recv, sets 0x6ff2b5[i]=1),
  case 0x10 -> FUN_005bc050 (refuse recv, sets 0x6ff2b5[i]=2).
- `FUN_005bbf20(param_1 = sub-3 originator id)`:
  ```
  if (cRam006ff2b1 == 1) {
    uRam006ff2b2 = 0; uRam006ff2af = 0;            // barrier RESET every sub-3
    memset(0x6fb758, 0, 0x654);
    if (cRam006c4b90 == 4 || cRam006c4b90 == 0xe)  // IN-ROOM screen gate
         { FUN_005c5c10(param_1); FUN_005bdf90(1,0); }   // -> send sub-4 ACCEPT, advance screen
    else { FUN_005c5c70(param_1); }                      // -> send sub-0x10 REFUSE
  }
  ```
- `FUN_005c5c10` sends sub-4 ACCEPT (buf[0]=4); `FUN_005c5c70` sends sub-0x10 REFUSE (buf[0]=0x10);
  both via `func_0x001df380(conn, 0x8000, buf, 0x304, 1, param_1)`.
- **Exclusivity (Confirmed):** `FUN_005c5c70` has exactly ONE caller (FUN_005bbf20); FUN_005bbf20
  has exactly ONE caller (FUN_005bba20 case 3). No timer/poll reaches the refuse. Therefore a
  REFUSE is emitted **iff a second op-0x10 sub-3 is dispatched** with screen != 4/0xe. The refuse
  is proof of a duplicate sub-3 delivery.
- The ONLY conditions in the accept-vs-refuse branch are `0x6ff2b1==1` and `0x6c4b90 ∈ {4,0xe}`.
  There is NO read of the roster record, charstats (+0x18), memberId, or scenario in this decision.
  -> The "charstats zeros / memberId / scenario gate" candidates for the refuse are **Refuted.**
- Screen advance: the accept branch calls `FUN_005bdf90(1,0)` (event dispatch via table
  0x6ca8a0[1]) which moves the joiner off screen 4/0xe (to standby/loading). (Inference, strong —
  required by the observed refuse and matches T22 "standing by for game start"; the exact 0x6c4b90
  write is behind the runtime pointer table 0x6ca8a0.)

## Why TWO sub-3 leave the host (Confirmed)
Host start SM `FUN_005c6500` state 0->1 (overlay FUN_005c6500.c:135-172):
```
bRam006ff2b3 = 0; memset(0x6ff2b5,0,4); uRam006ff2b5 = 1;   // host self-slot pre-ACCEPTED
for (seat 0..3) if (0x6ff2bd[seat] occupied) { copy 0x114 -> 0x6ff70d[n]; bRam006ff2b3++; }
for (i=0; i < bRam006ff2b3; i++) { FUN_005c5120(0x6ff70d[i], &id); FUN_005c5bb0(id); }  // sub-3 to EACH seat, incl. self@0
```
`FUN_005c5bb0(id)` -> `func_0x001df380(conn, 0x8000, buf{[0]=3}, 4, 1, id)`. With 2 seated slots the
host sends sub-3 to seat0.id (itself) and seat1.id (joiner), back-to-back (~10ms).

## The op-0x10 wire frame (from func_0x001df380 + FUN_001e180c, Ghidra)
App body = `[u32 count=1 BE][u32 targetId BE][sub payload...]`; cmd 0x10, flags = 0x8000|0x2000 =
0xA000; reliable. On the wire (after the 0x10-byte SN@P header): **targetId at wire[0x14..0x17]
(BE), sub byte at wire[0x18].** The frame's originator (host endpointToken) is at wire[0x08]
(header+0x30). The seated ids come from the host roster 0x6ff70d (per T23 live: seat0=host id=1,
seat1=joiner id=0x02f807d0).

## THE FIX (server-side, direct — the solo-start keystone)
When relaying the host's targeted op-0x10 (game/START channel) frames:
1. Parse `targetId = wire.readUInt32BE(0x14)` and `sub = wire[0x18]`.
2. **Forward to the joiner ONLY frames whose targetId == the joiner's minted memberId. Frames whose
   targetId == the host's OWN seat0 memberId (the room-handle/self id, e.g. 1) must be looped back
   to the host or dropped — NEVER forwarded to the joiner.** This delivers exactly one sub-3 to the
   joiner -> the joiner ACCEPTs and never refuses.
3. Result: joiner's single sub-4 ACCEPT relayed to host -> originator re-stamped to host token ->
   `FUN_005bbfc0` scans 0x6ff70d for id==host-token -> marks seat1 = 1; with the pre-set self
   accept `0x6ff2b5[0]=1`, accept count = 2 -> non-solo -> host proceeds sub-5/6/7/8 (peer-info +
   charstats + barrier) -> both consoles load.

Applies to the WHOLE targeted-op-0x10 start family (sub-3/5/6/7/9), which all loop over seats the
same way (FUN_005c6500 states) — target-route every one; never fan a self-targeted frame to a peer.

## Secondary check (wire, cheap)
Confirm in the pcap that the joiner receives TWO sub-3 deliveries and whether their targetIds
DIFFER (seat-loop = the primary cause above) or are IDENTICAL (would indicate a reliable-op-0x10
RETRANSMIT because the server didn't ACK the host's sub-3 -> also cured by proper transport ACK).
Both are fixed by target-routing + not re-fanning; identical targetIds additionally need the sub-3
transport ACK checked.

## Grades
- Refuse = second-sub-3 screen race, single-path exclusivity: **Confirmed** (overlay call graph).
- No roster/charstats/scenario validation in the refuse decision: **Confirmed** (FUN_005bbf20 body).
- Host sends sub-3 to every seat incl. self -> 2 frames: **Confirmed** (FUN_005c6500:145-172).
- Accept path advances screen off 4/0xe: **Inference (strong)**.
- Fix (target-route; drop self-targeted to peer) yields count=2: **Likely** (needs rig/wire verify).

## Needs fresh Ghidra
1. `0x6ca8a0[1]` target of `FUN_005bdf90(1,0)` — the exact write to screen 0x6c4b90 (confirms the
   screen-advance mechanism; runtime pointer table, not in static dump).
2. Confirm the host does NOT require a self sub-4 (0x6ff2b5[0] pre-set to 1 at state 0 — appears
   sufficient, FUN_005c6500:144) so the self-targeted sub-3 can be dropped rather than looped.

## WIRE CONFIRMATION + IMPLEMENTED FIX (2026-08-26, goal session)
Re-captured a solo-start run (Pi at the milestone code 9b0dc394; rig2 pcap). Three identical
attempts, all `recv sub-3 -> ACCEPT -> REFUSE`. Decisive frame analysis (attempt 3):
- Tokens established from the create/join handshake: **PS2/129 token = 0x028107d0, PC/248 token =
  0x02f807d0** (per-source wire+0x04). Attempt 3 host = PS2 (sub-3 originator).
- The host's "one" PS2->Pi datagram is a **0x0800-multi BUNDLE** carrying THREE frames:
  `op10 sub-3 word0=0x00000002` + `op10 sub-3 word0=0x028107d0` + `op08 STAT`. The transport walks
  the bundle (reliable-channel #walk), so each sub-3 dispatches separately and BOTH relay to the
  joiner (Pi->PC seqs 0x37, 0x38).
- **word0=0x028107d0 == the host's OWN endpointToken = its self-targeted seat0 frame.**
  word0=0x02 = the joiner's seat id (its own frame). So the agent's model is confirmed: the SM
  loops every seat incl. self; the extra frame reaching the joiner is the host's self-frame. NOT a
  server duplication (the earlier "server rewrites targetId" read was wrong - both frames are the
  host's own, bundled).
- `event.words[0]` (codec decodeRoomEvent, offset +0x04) IS the target discriminator for the
  op-0x10 start family (varies self vs joiner) - refines the RS1-B "word0 = sender handle, never
  routing" note for THIS opcode family (that note stands for chat/other op-0x10).

**FIX IMPLEMENTED (flag SNAP_OP10_DROP_SELF, default OFF): in #onRoomEventRelay, drop the frame
when `event.words[0] === this.#endpointToken` before the peer fan-out.** Removes exactly the host's
self-targeted start frame; the joiner then receives one sub-3 -> ACCEPT, no REFUSE. Covers the whole
seat-looping start family (each self-frame carries word0 == the sender token). The host pre-sets its
own accept (FUN_005c6500:144) so it never needs the self-frame echoed. Local test
`test/snap-lobby-op10-drop-self.test.js`: OFF -> joiner gets 2 sub-3; ON -> exactly 1 (the
joiner-targeted). Full v2 suite 833 pass / 0 fail. PENDING: nora review + rig 2-console confirm
(the milestone worked once with BOTH frames via lucky accept/refuse timing; this makes it
deterministic - it can only help, but must be rig-verified before MET).

### Refinement (nora review 2026-08-26): scope the drop to the start sub-family
nora cleared the fix as GROUNDED (safe to rig-test flag ON) and retired the "self-frame echo"
concern (the relay is except-sender - the host never received its own start frames; dropping only
changes the JOINER's stream). Two gaps to watch:
- GAP 1 (closed in code): the codec RS1-B note is that EVERY op-0x10 carries word0 = the sender's
  own handle, which on the wire host == the token - so a bare `word0==token` drop would also remove
  a non-start op-0x10 (e.g. host sub-1 member-info) from the joiner. FIX: gate the drop on the
  seat-looping START subs only (OP10_START_SEAT_LOOP_SUBS = {3,5,6,7,9}); every other op-0x10
  relays unchanged. Test added: a self-targeted sub-1 is NOT dropped.
- GAP 2 (rig must watch): the drop fires only if the host's seat0-id == its endpointToken (as in
  attempt 3). If a run emits a SMALL seat0 handle instead (RS1/T23 showed seat0 id=1), word0 != token
  and the drop is a safe NO-OP. So a still-solo rig result does NOT falsify the mechanism - read the
  extra sub-3's word0 on the wire to know which case occurred. Also confirm roster/member/chat still
  render with the flag ON.
