# 0x00606a70 async_op_poll_complete

| field | value |
|---|---|
| Original address | 0x00606a70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606a70 |
| Resolved name | async_op_poll_complete |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00606af0, FUN_006088b0, FUN_00623670
**Callees:** —
**Referenced globals:** uRam0070cd90 (req handle); uRam0070cd88 (state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x70cd90

## Behavioral explanation
Polls an async request (func_0x001c2770 on 0x70cd90/0x70cd88); returns true and clears the handle when it reports completion (==1).

## Notes / uncertainty
Poll via func_0x001c2770; status==1 => consume handle + return true. Non-1 status codes (pending vs error) not distinguished here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00606a70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
