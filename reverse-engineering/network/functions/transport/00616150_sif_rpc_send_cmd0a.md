# 0x00616150 sif_rpc_send_cmd0a

| field | value |
|---|---|
| Original address | 0x00616150 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00616150 |
| Resolved name | sif_rpc_send_cmd0a |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060ee80
**Callees:** FUN_00615670, FUN_00616ab0
**Referenced globals:** 0x70d250/0x70d350 (rpc buf fields); 0x70d248/0x70d244 (rpc buf words); 0x654200 (default field source)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** rpc fno=10; 0x654200 default

## Behavioral explanation
SIF-RPC stub, fno 10: marshals param_1->0x70d250, param_2->0x70d248, param_3->0x70d350, default field ram654200->0x70d244, then rpc fno 10.

## Notes / uncertainty
SIF-RPC stub fno 10 (t3-shape: str1+mode+str2+token). Has real caller FUN_0060ee80 (actively used); verb name still pending caller RE.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00616150.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
