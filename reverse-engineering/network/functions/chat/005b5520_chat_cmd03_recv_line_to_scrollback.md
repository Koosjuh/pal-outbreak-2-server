# 0x005b5520 chat_cmd03_recv_line_to_scrollback

| field | value |
|---|---|
| Original address | 0x005b5520 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b5520 |
| Resolved name | chat_cmd03_recv_line_to_scrollback |
| Subsystem | chat |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c3e80, FUN_00604860
**Referenced globals:** 0x6c5562 chat-log ring (8 x 0xa5); 0x6c555e log count; 0x870880 last-line compare buffer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c555e log entry count

## Behavioral explanation
Registered command handler (selector id 3): parses an incoming chat line (sender/name/text via 0x5c3e80), dedupes against 0x870880, and inserts it into the 8-entry scrollback log (0x6c5562, stride 0xa5).

## Notes / uncertainty
Command-selector-3: inserts received chat line into 8-row scrollback (stride 0xa5 = valid+sender0x10+name0x10+gap4+text0x80) after name-filter (0x870880) returns -1; shifts ring, bumps count (cap8), sets redraw flags, SFX 3. Filter=mute-vs-dedup uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b5520.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
