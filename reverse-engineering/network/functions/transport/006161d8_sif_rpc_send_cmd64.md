# 0x006161d8 sif_rpc_send_cmd64

| field | value |
|---|---|
| Original address | 0x006161d8 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006161d8 |
| Resolved name | sif_rpc_send_cmd64 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00615670, FUN_00616ab0
**Referenced globals:** 0x70d200 (SifRpcClientData); 0x70d240 (rpc send buf)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** rpc fno=0x64

## Behavioral explanation
Parameterless SIF-RPC stub issuing function-number 100 (0x64).

## Notes / uncertainty
SIF-RPC control stub fno 100 (0x64), parameterless zero-payload. Control-range verb (init/reset inferred); no callers.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006161d8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
