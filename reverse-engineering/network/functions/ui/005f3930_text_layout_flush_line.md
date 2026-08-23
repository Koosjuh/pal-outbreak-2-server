# 0x005f3930 text_layout_flush_line

| field | value |
|---|---|
| Original address | 0x005f3930 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f3930 |
| Resolved name | text_layout_flush_line |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f3ac0, FUN_005f3bc0, FUN_005f3cc0
**Callees:** FUN_005f3150
**Referenced globals:** iRam007012a0(0x1c cursor, 0xd8c8/0xd8ce/0xd8d2 pen, 0x18d)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam007012a0+0x1c

## Behavioral explanation
Flushes the pending text line if the cursor is non-empty and resets layout state.

## Notes / uncertainty
End-of-block line flush guarded on run_cursor!=0; terminates+flushes pending run, snaps pen to line start, clears cursor/break flags. Caller-passed block arg unused by body.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f3930.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
