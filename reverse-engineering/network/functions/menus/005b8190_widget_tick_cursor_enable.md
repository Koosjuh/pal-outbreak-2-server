# 0x005b8190 widget_tick_cursor_enable

| field | value |
|---|---|
| Original address | 0x005b8190 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b8190 |
| Resolved name | widget_tick_cursor_enable |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00618c20
**Referenced globals:** cRam006c4fd3 (teardown flag); uRam006c45fe (room member count); obj+2 (item type); obj+3 (item index)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fd3; uRam006c45fe

## Behavioral explanation
Per-frame widget update (state machine at obj+4: 0->init,1->run,2->free via FUN_00618c20): computes selectable/highlight (obj+1) by comparing the widget's index (obj+3) against its data pointer, with a special case for item-type 0x06 gated on room member count uRam006c45fe.

## Notes / uncertainty
3-state widget tick; type 0x06 rows disabled when index>=roster count uRam006c45fe (roster-gating hook). +1 polarity 'equal->0' means placeholder/non-current flag; consuming draw not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b8190.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
