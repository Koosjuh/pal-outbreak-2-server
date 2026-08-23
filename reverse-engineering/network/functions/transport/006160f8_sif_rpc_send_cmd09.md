# 0x006160f8 sif_rpc_send_cmd09

| field | value |
|---|---|
| Original address | 0x006160f8 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006160f8 |
| Resolved name | sif_rpc_send_cmd09 |
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
**State vars:** rpc fno=9

## Behavioral explanation
SIF-RPC request stub identical to 0x6160a0 but function-number 9 (copies param to 0x70d250, calls rpc fno 9).

## Notes / uncertainty
SIF-RPC stub fno 9: single string, same shape as cmd08. Verb unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006160f8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
