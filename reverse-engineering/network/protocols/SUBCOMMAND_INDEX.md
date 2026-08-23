# SUBCOMMAND_INDEX — op10 sub-selectors & op28 selectors

The app protocol multiplexes several messages inside opcodes **0x10** (game-channel room-info) and
**0x28** (the generic reply). The first app-payload word selects the sub-handler. Values below are
Confirmed/High from prior RE (session logs + rig) unless noted; per-handler records deepen in the
roster/rooms subsystem reconstruction.

## op10 sub-selectors (game-channel, overlay dispatch slot 0x13 = `FUN_005bba20`)
Dispatched on app-payload byte[0] (wire+0x18).

| Sub | Name | Handler | Direction | Meaning | Conf |
|---|---|---|---|---|---|
| 0x01 | member/player-info | FUN_005bbb90 | S→C | member/player info push | High |
| 0x02 | join-request | FUN_005bbc20 | C→S (joiner→host via FUN_005c5ff0) | joiner asks host to admit | Confirmed |
| 0x0c | join-confirm | FUN_005bbe00 | S→C (host→joiner via FUN_005c6050) | payload `[0x0C][count LE]`; fires joiner continuation → room renders | Confirmed |
| 0x0e | 6s-fallback escalation | thunk_FUN_005c61b0 | C→S | separate retry/escalation query (not a param of 0x02) | High |
| 0x03 | config/panel refresh | FUN_005bbf20 | S→C | owner-gated; fires an upstream type-4 query | Medium |
| 0x05 | room-limits (cur/max) | FUN_005bc0e0 | S→C | `[0x05][?][max@+4][cur@+5]` → writes 0x6ff2b4/0x6ff2b3 (in-room "MAX/CUR P"); write-only, no event | Confirmed |
| 0x11 | member-count update | FUN_005bbea0 | S→C | writes room-list count 0x6cfb70; fires event 0x21 | High |

## op28 selectors (generic reply, dispatcher `FUN_001d9f78` → overlay slots)
Dispatched on who-byte DATA/set bits + body[0] selector.

| Sel | Name | Slot/handler | Meaning | Conf |
|---|---|---|---|---|
| 4 | create-slot accept | slot 0x1f = FUN_005c3a40 | op04 accept: sets 0x6cba7d=1, 0x6ff2b0=1, handle→0x6fee8c; unlocks 0x6ff2b1 | Confirmed |
| 6 | enter/area confirm | slot 0x21 (area, who=0xB0) / slot 0x22 = FUN_005c05c0 (room-enter, who=0xA0) | area-confirm or room-enter accept (sets 0x6ff2b1/2) | Confirmed |
| 0x0a | member-list | who=0xA0→slot 0x18 FUN_005c0ae0 (fill+count) / who=0xB0→slot 0x19 FUN_005c2460 (count-setter) | fills 0x6cdbe6 + count 0x6ca890 | Confirmed |
| 12 | cmd0c reply | slot 0x26 | prepare/cmd0c selector-12 reply (create handshake) | High |

## Notes
- The **transport** op10 builders (`FUN_001de9e8` `snap_send_op10_multi` etc.) are a different layer:
  multi-recipient framing (count + htonl id list), not the app sub-selector. See rooms records.
- op28's SUB byte (wire+0x02) doubles as the op06 completion match-key (send-seq echo) — see
  `functions/roster/` and FACTS.md G2.
- Evidence: SESSION-LOG-2026-07-25.md, FACTS.md CURRENT MODEL, analysis/G12-*-RE-2026-07-1x.txt,
  roster-row-draw-RE-2026-07-25.txt, max-players-display-RE-2026-07-25.txt.

## Reconciliation notes (deep-reconstruction vs rig evidence)
- **op10 sub-0x05 (FUN_005bc0e0):** deep-reconstruction (wave 4) read the two payload bytes at +4/+5 as
  a *scenario-selection* pair; rig evidence (2026-07-26, Confirmed) showed sending `[0x05][?][max=4@+4]
  [cur=1@+5]` rendered the in-room header "4/…" (the MAX digit), i.e. **room-limits (max/cur)**. Both
  observe the same two bytes at +4/+5; the *label* differs. Rig-Confirmed wins for the header effect;
  whether the same handler also feeds a scenario field is open — see the function record + UNRESOLVED.
- Auto-extracted supplement (regenerated, may be sparse): `SUBCOMMAND_INDEX_AUTO.md`.
