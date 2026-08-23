# 0x005e0320 drawcallback_register

| field | value |
|---|---|
| Original address | 0x005e0320 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e0320 |
| Resolved name | drawcallback_register |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ca6a0, FUN_005cd500
**Callees:** —
**Referenced globals:** 0x7010a0 (callback table); iRam00701098 (count)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701098

## Behavioral explanation
Appends a draw-callback fn-ptr to the 0x7010a0 table if not already present (dedup, cap 128).

## Notes / uncertainty
Dedup linear-scan append of a draw-callback fn-ptr to 0x7010a0, cap 128, silent drop on overflow. param_1 is a code ptr (confirmed by dispatch call site).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e0320.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
