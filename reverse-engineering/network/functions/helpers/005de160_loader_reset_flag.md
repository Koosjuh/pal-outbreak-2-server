# 0x005de160 loader_reset_flag

| field | value |
|---|---|
| Original address | 0x005de160 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005de160 |
| Resolved name | loader_reset_flag |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c9a00
**Callees:** —
**Referenced globals:** uRam00701060 (loader state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam00701060

## Behavioral explanation
Clears loader busy flag uRam00701060=0.

## Notes / uncertainty
Already reconstructed; trivial single store uRam00701060=0 (loader idle). Complete.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005de160.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
