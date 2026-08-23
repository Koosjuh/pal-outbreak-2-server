# 0x00618c30 sprite_table_dispatch

| field | value |
|---|---|
| Original address | 0x00618c30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00618c30 |
| Resolved name | sprite_table_dispatch |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac400, FUN_005acab0, FUN_00606af0, FUN_00606cf0
**Callees:** —
**Referenced globals:** 0x7133f0 sprite table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Iterates the 64-slot sprite table and invokes each active entry's per-object callback at +0xc.

## Notes / uncertainty
Update/tick pass: iterates 64-slot table, calls each active (byte0!=0) record's +0xc callback with self-arg. Counterpart to compositor render pass. Installed callbacks not enumerated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00618c30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
