# 0x00195e00 subsystem_init_build_table10_register

| field | value |
|---|---|
| Original address | 0x00195e00 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_00195e00 |
| Resolved name | subsystem_init_build_table10_register |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00101f58, FUN_00101f80, FUN_00111600, FUN_0017e3f0, FUN_00183350, FUN_00195cf0, FUN_001a2220
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Init routine: aborts (ret 0) if FUN_00195cf0 prereq fails; else fills 10-entry u32 table at 0x28a2f4, sets ready latch uRam00289af0=1, registers handler 0x183680 over 0x1000 region 0x289af0 via FUN_00183350. Registration semantics assumed from signature.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_00195e00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
