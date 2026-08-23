# 0x0019a260 resource_table_copy_all

| field | value |
|---|---|
| Original address | 0x0019a260 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_0019a260 |
| Resolved name | resource_table_copy_all |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d1960
**Callees:** FUN_00199f70, FUN_0019a350
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Copies all count words (hdr+4=count, entries@+0xc) of the 0x50000-tagged section into out[]. param_1/param_2 unused. Section domain (module/resource ids) inferred; callees FUN_00199f70/FUN_0019a350 outside decompile set.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_0019a260.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
