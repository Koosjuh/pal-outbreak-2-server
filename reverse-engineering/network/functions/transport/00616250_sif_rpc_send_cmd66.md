# 0x00616250 sif_rpc_send_cmd66

| field | value |
|---|---|
| Original address | 0x00616250 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00616250 |
| Resolved name | sif_rpc_send_cmd66 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006162d8
**Callees:** FUN_00615670, FUN_00616ab0
**Referenced globals:** 0x70d200 (SifRpcClientData); 0x70d240 (rpc send buf)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** rpc fno=0x66

## Behavioral explanation
Parameterless SIF-RPC stub issuing function-number 102 (0x66).

## Notes / uncertainty
SIF-RPC control stub fno 102 (0x66), parameterless. Identified as session CLOSE verb via its sole caller FUN_006162d8 (close-then-clear-flag); wire effect runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00616250.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
