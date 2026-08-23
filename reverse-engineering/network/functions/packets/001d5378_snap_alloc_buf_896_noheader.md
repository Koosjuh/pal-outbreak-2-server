# 0x001d5378 snap_alloc_buf_896_noheader

| field | value |
|---|---|
| Original address | 0x001d5378 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d5378 |
| Resolved name | snap_alloc_buf_896_noheader |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ec1f8
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0x520 pool

## Behavioral explanation
Allocates a 0x380-byte buffer directly from the pool (no header reserve).

## Notes / uncertainty
pool_alloc(0x380, class=0, no header reserve); returns raw block (0 on fail), ignores rc. No static callers found — purpose (bulk/unreliable staging?) inferred from class-0/no-header shape; may be dead code.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d5378.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
