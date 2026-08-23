# 0x005cf3a0 display_entry_autoscroll_gate

| field | value |
|---|---|
| Original address | 0x005cf3a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005cf3a0 |
| Resolved name | display_entry_autoscroll_gate |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005cab10, FUN_005cfb20
**Callees:** FUN_005cebc0, FUN_0061e720
**Referenced globals:** 0x701068+0x5ffc0 display-list; 0x701068+0x68e88 scroll-req flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701068+0x68e88

## Behavioral explanation
Given a display-list index, decides by entry type ([2]) and name-match whether the entry warrants an auto-scroll, then calls FUN_005cebc0 to bring it on-screen (with an optional focus SFX).

## Notes / uncertainty
Row-type gate on node[2]: type2 header dedup via strcmp(name@+0x60) vs prev array ov+0x5ffbc; {3-7,0xB,0xC} always; 8 needs node[0]==0xB; 0x11/0x12 need non-empty name; 0xD needs node[0]in{3,5}. Accept -> ov+0x68e88=1, SFX, scroll_view_to_entry. Row-type semantics inferred; +0x60 name ptr-vs-inline uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005cf3a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
