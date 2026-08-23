# 0x006335f0 set_candidate_cell

| field | value |
|---|---|
| Original address | 0x006335f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006335f0 |
| Resolved name | set_candidate_cell |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006336d0, FUN_00633840
**Callees:** —
**Referenced globals:** 0x7158f0 (candidate cell array, 0x12 stride); 0x68f290 (prediction dictionary)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Populates candidate slot [param_1] header byte and glyph from the prediction dictionary (u_..._0068f290) at index param_1+param_2.

## Notes / uncertainty
Fills cell idx from wchar dict 0x68f290[idx+page_base]: label@+0, glyph@+2, flags@+4=0. Void; callers' use of 'return' is a decompiler artifact.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006335f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
