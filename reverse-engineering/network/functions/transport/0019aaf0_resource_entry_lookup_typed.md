# 0x0019aaf0 resource_entry_lookup_typed

| field | value |
|---|---|
| Original address | 0x0019aaf0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_0019aaf0 |
| Resolved name | resource_entry_lookup_typed |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d1960
**Callees:** FUN_00199f70, FUN_0019a210, FUN_0019a2f0, FUN_0019a350, FUN_0019abf0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Bounds-checked entry lookup by (key,index); only entry type-tag==4 fills output (attr@+0x20 via FUN_0019a210, body via FUN_0019abf0); types 8/7/6/3 explicit no-op. Type enum meaning unknown; FUN_0019a210 arg-count mismatch is a decompiler artifact worth Ghidra recheck.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_0019aaf0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
