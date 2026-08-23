# 0x005d7b60 txn_apply_reply_status

| field | value |
|---|---|
| Original address | 0x005d7b60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d7b60 |
| Resolved name | txn_apply_reply_status |
| Subsystem | errors |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d80c0
**Callees:** FUN_005d6a10
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** record+0x104 state; record+0x124 error class; record+0x125 detail

## Behavioral explanation
Maps a server reply's status code (reply struct +0x3d, 0x00..0x14) to the record's outcome: code 0 -> success state 5 (copies room id/handle, sets sub-result); all other codes -> state 6 with an error class written to +0x124 and detail +0x125.

## Notes / uncertainty
Already fully reconstructed. Reply-status decoder: guard reply+0x68==2, status 0=success(outcome 5), nonzero mapped to error classes at +0x124. Error-class -> UI-string mapping not yet established.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d7b60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
