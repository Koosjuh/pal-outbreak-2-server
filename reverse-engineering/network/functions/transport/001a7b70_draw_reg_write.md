# 0x001a7b70 draw_reg_write

| field | value |
|---|---|
| Original address | 0x001a7b70 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001a7b70 |
| Resolved name | draw_reg_write |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001a0eb0, FUN_001a7a80, FUN_001cf360, FUN_001cf570, FUN_001cf6a0, FUN_001cfb30, FUN_001cfc90, FUN_001d0040, FUN_001d0230, FUN_001d0400, FUN_001d1960, FUN_001d1b80
**Callees:** FUN_0018c8d0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Draw/GS register-write shim -> FUN_0018c8d0. Decompiler dropped the 2nd param but all call sites pass (reg_id,value) e.g. (0x14,argb),(0x66,1). FUN_0018c8d0 behaviour (poke vs GIF queue) unconfirmed.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001a7b70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
