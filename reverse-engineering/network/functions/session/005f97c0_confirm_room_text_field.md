# 0x005f97c0 confirm_room_text_field

| field | value |
|---|---|
| Original address | 0x005f97c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f97c0 |
| Resolved name | confirm_room_text_field |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f9150
**Callees:** FUN_00632ce0, FUN_006345e0, FUN_00634ab0, FUN_00637180, FUN_006371d0
**Referenced globals:** 0x6970a2/0x6970b2 (name/char buffers); 0x6c4610/0x6c4618/0x6c4620 (net status); param+0x908 (choice)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0x10; param+0x908

## Behavioral explanation
SM on +0x10: submits the chosen character/name (buffers 0x6970a2/0x6970b2) to the server via FUN_006345e0 and polls the ack FUN_00634ab0; on ready advances the join substate.

## Notes / uncertainty
Submits one of two fixed-len text fields via the 0x634xxx pipeline: field A 0x6970a2 (8B, type1), field B 0x6970b2 (15B, type2); choice 0x0a=cancel. Title-vs-password identity of the fields inferred from lengths.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f97c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
