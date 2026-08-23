# 0x0061c9f0 text_draw_with_name_subst

| field | value |
|---|---|
| Original address | 0x0061c9f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061c9f0 |
| Resolved name | text_draw_with_name_subst |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00619800
**Callees:** FUN_0061cc80, FUN_0061cce0
**Referenced globals:** 0x665e50 string-record table; 0x665df0 per-lang string ptr; iRam00715360 selected-name/index; 0x669bc8 name-format buffer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00715360

## Behavioral explanation
Draws a table-indexed text string (DAT_00665e50) line by line; on the '%'(0x25) token path it interpolates a player/entry name (via iRam00715360 into buffer 0x669bc8) before rendering.

## Notes / uncertainty
Message-block renderer (table 0x665e50, id<0xb7). mode0=multi-line with %-token redirect via 0x669b5a; mode!=0=single line with player-name substitution for entry iRam00715360 (skipped when 0x7f). Roster-adjacent but display-side only. Record field split inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061c9f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
