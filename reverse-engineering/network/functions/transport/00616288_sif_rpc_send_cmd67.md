# 0x00616288 sif_rpc_send_cmd67

| field | value |
|---|---|
| Original address | 0x00616288 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00616288 |
| Resolved name | sif_rpc_send_cmd67 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00615670, FUN_00616ab0
**Referenced globals:** 0x70d244/0x70d248 (rpc buf words); 0x654200 (default field src); 0x70d200/0x70d240
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** rpc fno=0x67; 0x654200 default

## Behavioral explanation
SIF-RPC stub, fno 103 (0x67): stores default field ram654200->0x70d244 and one param->0x70d248, fires RPC.

## Notes / uncertainty
SIF-RPC control stub fno 103 (0x67): session token@+0x04 + scalar@+0x08. Tokened per-session state verb; scalar meaning unknown, no callers.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00616288.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
