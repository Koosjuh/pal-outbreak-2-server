# 0x001d0d50 load_demo_motion_triple

| field | value |
|---|---|
| Original address | 0x001d0d50 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d0d50 |
| Resolved name | load_demo_motion_triple |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728, FUN_001cb360, FUN_001d09e0
**Referenced globals:** 0x4fc060/0x4fb3d0/0x528200 roster grids; cRam004fa64f flag; uRam003435bc work base
**Referenced strings:** 0x24cd90 template; 0x24cdc0 template; 0x24cdf0 template
**Referenced opcodes:** —
**State vars:** cRam004fa64f

## Behavioral explanation
Clears cRam004fa64f then fetches+decodes three rosters via FUN_001cb360+FUN_001d09e0 using tmpls 0x24cd90/0x24cdc0/0x24cdf0 into 0x4fc060/0x4fb3d0/0x528200.

## Notes / uncertainty
MISCLASSIFICATION CORRECTED: loads three DEMO motion sets (body d%02d.bin->0x4fc060, face d%02dface.bin->0x4fb3d0, head hd%02d.bin->0x528200) for scene r%03d take %02d; each gated on len>0. Also clears cRam004fa64f (re-arms FUN_001d0b00 load-once latch). Runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d0d50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
