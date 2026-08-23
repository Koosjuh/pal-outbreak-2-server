# 0x0062eff0 reply_handler_playercount

| field | value |
|---|---|
| Original address | 0x0062eff0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062eff0 |
| Resolved name | reply_handler_playercount |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c0f00, FUN_005c2890
**Referenced globals:** 0x6c4fe6 player count; 0x6c4fe8 player data
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Reply callback: on status 0 reads a 2-byte value (FUN_005c0f00) and stores player-count/state into 0x6c4fe6 and 0x6c4fe8 via FUN_005c2890; else zeroes both.

## Notes / uncertainty
Player-count reply cb: status 0 -> decode u16 (FUN_005c0f00) and distribute to 0x6c4fe6/0x6c4fe8 via FUN_005c2890; else zero both. u16->two-global split (current/max?) not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062eff0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
