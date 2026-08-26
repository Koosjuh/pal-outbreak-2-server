# Charstats / character propagation RE (2026-08-26)

Goal: design the CORRECT server-side character propagation, replacing the reverted raw op-0x0c
relay (T25 regression). Answers T24/T25's open question: how a peer's charstats reach + get
APPLIED on other clients, and what the server must emit (NOT a raw op-0x0c echo).

Evidence: Ghidra live (main-EE 0x001xxxxx), overlay corpus
`reverse-engineering/network/sources/overlays/overlay-3dat-decompile/`,
`analysis/claude-helper-module-full-2026-05-29.txt` (helper:LINE), bioserv2 PacketHandler.java,
`analysis/callback-table-install-map-2026-05-25.md`.

## VERDICT (one line)
The recipient applies a peer charstats change via **cmd 0x0c → slot 0x0a → FUN_005bc430** (an
in-place charstats UPDATE by member-id), which is a DIFFERENT handler than the sender's completion
**slot 0x26**. The T25 "op-0x0c fires slot 0x26" hypothesis is **REFUTED**. But the server must
**TRANSLATE, not echo**: the client→server op-0x0c body is a raw 0xd4 charstats blob with no
{id,len} prefix, so a byte-identical relay never matches a seated member (that, not slot 0x26, is
why T25 rendered wrong/solo). Correct fix = capture the blob, then carry it as the **charstats
field (rec+0x18) of the op-06 seat record** (primary; what game-start reads) and/or a server-built
**translated op-0x0c** {memberId,len,charstats,trigger} for live in-room changes.

## 1. Inbound op-0x0c on the RECIPIENT — the APPLY path (Confirmed)
Dispatcher `FUN_001d9f78` (Ghidra 0x001d9f78): `iStack_14 = (cmd & 0x7f) - 3`; app body ptr passed
to every handler = `param_2 + 0x3c`; sender endpoint token = `param_2 + 0x30` (goes in the header
struct `cStack_40`, NOT the body).
- cmd 0x0c → iStack_14 = 9 → **case 9** → `slot conn+0x570 = slot 0x0a` (d9f78 case 9, lines
  ~130-135). NO flag sub-branch (unlike cmd 06/07/08). Any op-0x0c, any flags, lands here.
- Slot 0x0a handler = **FUN_005bc430** (installed `func_0x001d4d24(conn,0xa,0x5bc430)` in
  FUN_005bc860, helper:13036; the app installer writes conn+0x548+slot*4 — SAME table the
  transport uses, so "slot 0xa" == dispatcher cmd-0x0c slot).
- FUN_005bc430 (helper:12879): gated by `cRam0070047c` (in-room mode). Zeros scratch 0x6cd672;
  scans the 4-entry member table 0x6cdbe6 (stride 0x118); decodes each seated entry id via
  FUN_005c5120; on `decodedId == param_2[0]` copies name (entry+0x10) + charstats
  (`param_2+2`, len `param_2[1]`) into entry+0x24 (0x6cdc0a) and scratch 0x6cd696; if
  `*(char*)(param_2+0xe5)==1` fires FUN_005bdfe0(0x24)/(0x23) redraw via FUN_005bc370 (compacts
  active entries into DISPLAY roster 0x6ce046).
- **Distinct from slot 0x26.** Slot 0x26 (conn+0x5e0) is reachable ONLY via cmd 0x28 (case 0x25)
  with selector byte 12 (`iStack_18 = *body - 1 = 0xb`), d9f78 lines ~230/331. An op-0x0c frame
  (case 9) can NEVER reach it. The sender's OWN op-0x0c completion routes to 0x26 only because
  `FUN_001de470` does `FUN_001d4d24(1,0x26,cb)` before sending (Ghidra 0x001de470) — that is the
  op-0x28 sel-12 result addressed to the sender, unrelated to a broadcast op-0x0c.
- Discriminator between "my completion" and "a peer's change" = the **wire opcode**: 0x0c (data,
  case 9, slot 0x0a) vs 0x28+selector-12 (result wrapper, case 0x25, slot 0x26). Not a flag bit.

## 2. Echo vs TRANSLATE (Confirmed — bioserver = translate)
- Client SET: `sendCharSelect` (CHARSELECT, QUERY) → `cl.setCharacterStats(ps.getCharacterStats())`
  then replies CHARSELECT TELL with EMPTY body (PacketHandler.java:559-566). Server STORES, ACKs,
  never relays the SET.
- Server BROADCAST of the stored stats, as its OWN differently-typed packets:
  - **PLAYERSTATBC 0x6503** on JOINGAME: `status = cl.getCharacterStat(); broadcastInSlot(...)`
    (PacketHandler:1691-1694) — "broadcasting statistics of a joining player".
  - **PLAYERSTAT 0x6913**: pull of one player's `getPreGameStat(player)` (1442-1456).
  - **PLAYERSTATS 0x640A**: bulk pull by a joiner (1113-1120).
- PAL parity: the client→server op-0x0c body is a **raw 0xd4 charstats blob**, NO id/len prefix.
  `FUN_005b3790` (helper) builds `auStack_f0[0xd4]` (func_0x007de670 + char fields at +0xc8) →
  `FUN_005bd940(buf,0xd4,cb)` copies to 0x7004d0 → `func_0x001de470(conn,0x7004d0,0x5bd8c0)`
  frames cmd 0x0c, flags 0xa000, len = *(u16*)(conn+0x64) = 0xd4 (Ghidra 0x001de470,
  FUN_001e180c writes conn+0x44 token to frame+0x30). Recipient sees this blob at body+0 =
  charstats[0..], so `FUN_005bc430` reads param_2[0]=charstats[0:4] → matches no seated memberId →
  silently dropped; a chance match copies a bogus-len blob → wrong character. **This is the T25
  regression cause, not slot 0x26.** (Wire sample T24 decodes cleanly: `a100 050c`=flags/seq5/cmd0c,
  `028107d0`=token@+0x30, `0000292e`=seq32@+0x34, then app body@+0x10 = the charstats blob.)

## 3. DELIVERABLE — the exact server emission
Prereq CAPTURE: parse the inbound IN-ROOM op-0x0c (cmd 0x0c; app body @ wire+0x10 = the member's
0xd4/0xf0 charstats blob) and store it on the sender's room-roster profile. Disambiguate from the
select-time "room-query" op-0x0c (classifier game_udp_server.js:1336, kind 0xA1/0xE1, msg[3]=0x0c,
near-EMPTY body) by (a) in-room session state and (b) non-empty body.

**A. SEAT-TIME (primary; = PLAYERSTATBC-on-join; the only path game-start reads).** Put the real
0xf0 charstats in the op-06 member record at **rec+0x18** (today zeroed) in BOTH directions
(sendMemberJoinBroadcast A<->B and the roster-to-joiner op06). Load-bearing because op-06
`FUN_005bb4d0` (helper:12151, overlay FUN_005bb4d0.c) does `memcpy(0x6cd696, rec+0x18, 0xf0)` →
event 0x1f (FUN_005bdfe0(0x1f) → FUN_005b5ac0) SEATS into 0x6c7c2c → FUN_005c6210 start roster
0x6ff70d → game-start sub-7 charstats. Keep charstats+0xc8 (char-id, = rec+0x18+0xc8 = rec+0xe0)
and +0xca (class) distinct per member for the FUN_005b5ac0 dedup gate — the real blob carries them.
This fixes both in-room render AND "Jim" at game start. Routes to slot 0x02 (op-06), never 0x26.

**B. IN-ROOM CHANGE (secondary; = live "changed character").** Server-BUILT translated op-0x0c to
OTHER members (not sender): cmd 0x0c, flags 0xa000 (echo channel bits), reliable, app body =
`[u32 memberId][u32 len=0xf0][charstats 0xf0][body[0xe5]=1]`. **memberId must equal the id the
RECIPIENT seated for that member** = the recipient's own endpointToken (the existing
SNAP_MEMBER_ID_TOKEN scheme; FUN_005bc430 compares param_2[0] to FUN_005c5120-decoded seated ids
which op-06 encoded from rec+0x10). Routes to slot 0x0a → FUN_005bc430 in-place update. Updates the
DISPLAY table 0x6cdbe6 (via FUN_005bc370), NOT seated 0x6c7c2c — so a late change alone does not
alter what game-start sends unless the member re-seats. For the current milestone, A suffices; B is
polish for live mid-room swaps. (Inference: len=0xf0 + explicit body[0xe5]=1 so the redraw fires;
the 0xe5 trigger lives inside the charstats region — verify on the rig.)

**NOT op-06 UPDATE for a change:** op-06 always SEATS (event 0x1f → first empty 0x6c7c2c slot);
re-sending risks double-seat / dedup-drop. **NOT op-0a:** cmd 0x0a → slot 0x18/0x19 → FUN_005bb670
rebuilds the DISPLAY member list; seat/start authority is op-06→0x6c7c2c. The charstats-bearing
seat op is op-06; the in-place update op is op-0x0c. Not op-0a.

## Grades
- 1 (inbound op-0x0c → slot 0x0a → FUN_005bc430; NOT slot 0x26): **Confirmed** (Ghidra d9f78 +
  overlay + install map).
- 2 (bioserver stores+broadcasts, never echoes; PAL client op-0x0c body = raw blob): **Confirmed**
  (bioserv2 + Ghidra 0x001de470/0x001e180c + FUN_005b3790/FUN_005bd940).
- 3A (op-06 rec+0x18 charstats seats into 0x6c7c2c → game-start): **Confirmed** path; effect on
  render/"Jim" = **Likely** (needs rig).
- 3B (translated op-0x0c update, memberId=recipient token, trigger byte): **Likely / Inference**.

## Needs fresh Ghidra (ranked)
1. **FUN_005b5ac0** (event 0x1f seat into 0x6c7c2c) — confirm it copies scratch 0x6cd696 charstats
   into the seated 0x3b0 slot and the exact charstats offset the game-start sub-7 reads; verifies
   3A end-to-end and the +0xc8/+0xca dedup key positions in the seated record. (overlay; not fully
   in dumps.)
2. **FUN_005c6210 / 0x6ff70d builder** — confirm start-roster charstats come from 0x6c7c2c seat
   (not a re-pull), i.e. that seat-time charstats are sufficient with no later op needed.
3. **The 0xe5 trigger** in FUN_005bc430 vs charstats layout — is body[0xe5] a charstats byte or a
   trailing flag; decides whether B must force it to 1. (overlay FUN_005bc430 present; needs the
   charstats struct map, func_0x007de670.)
4. **FUN_005bc370 → 0x6c7c2c?** — confirm the op-0x0c update's redraw does NOT reach the seated
   table (it compacts 0x6cdbe6→0x6ce046), pinning B as display-only.

## Highest-leverage next experiment
Implement PATH A only, behind `SNAP_CHARSTATS_SEED` (default OFF): capture each member's inbound
in-room op-0x0c charstats blob into the room profile; write it into op-06 rec+0x18 for that member
in every seat/broadcast (self-record + roster-to-joiner + A<->B). Zero slot-0x26 risk (op-06 →
slot 0x02). Verify locally (no Pi): after a 2-console join, emulator PINE/savestate — seated table
0x6c7c2c (or 0x6cdbe6 / 0x6cdc0a) charstats+0xc8 char-id for the joiner's seat == the joiner's
chosen character; then game-start renders the real character, not Jim. nora review BEFORE deploy
(the discipline miss T25 flagged). Defer B until A is rig-confirmed.
