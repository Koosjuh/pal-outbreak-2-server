# 0x00616a00 sif_rpc_guard_sema_init

| field | value |
|---|---|
| Original address | 0x00616a00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00616a00 |
| Resolved name | sif_rpc_guard_sema_init |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00616ab0
**Callees:** —
**Referenced globals:** 0x654208 (rpc guard sema handle)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x654208 sema (-1 = uncreated)

## Behavioral explanation
Lazily creates the single-slot semaphore (DAT_00654208) that serializes access to the SIF-RPC client channel.

## Notes / uncertainty
Lazy create-once guard sema (0x654208); returns handle on fresh create, -1 if already-exists/fail; exact sema field slot for the '1' value (max vs init count) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00616a00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
