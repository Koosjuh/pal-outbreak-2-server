# 0x006160a0 sif_rpc_send_cmd08

| field | value |
|---|---|
| Original address | 0x006160a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006160a0 |
| Resolved name | sif_rpc_send_cmd08 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00615670, FUN_00616ab0
**Referenced globals:** 0x70d250 (rpc send-buf field); 0x70d200 (SifRpcClientData); 0x70d240 (rpc send buf)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** rpc fno=8

## Behavioral explanation
EE->IOP SIF-RPC request stub: waits channel ready (FUN_00615670), copies param into send buffer 0x70d250, fires RPC fno 8 via sif_rpc_call.

## Notes / uncertainty
SIF-RPC stub fno 8: single string. fno==wire-op numeric coincidence explicitly flagged as NOT identity (EE->IOP selector namespace).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006160a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
