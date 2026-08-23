# 0x00616210 sif_rpc_send_cmd65

| field | value |
|---|---|
| Original address | 0x00616210 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00616210 |
| Resolved name | sif_rpc_send_cmd65 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060e060
**Callees:** FUN_00615670, FUN_00616ab0
**Referenced globals:** 0x70d240 (rpc send buf head); 0x70d200 (SifRpcClientData)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** rpc fno=0x65

## Behavioral explanation
SIF-RPC stub, fno 101 (0x65): stores one param at 0x70d240 head then fires RPC.

## Notes / uncertainty
SIF-RPC control stub fno 101 (0x65): single scalar at buffer head +0x00. Real caller FUN_0060e060; scalar meaning unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00616210.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
