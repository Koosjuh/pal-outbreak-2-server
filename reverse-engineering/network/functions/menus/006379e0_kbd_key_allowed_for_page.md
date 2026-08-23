# 0x006379e0 kbd_key_allowed_for_page

| field | value |
|---|---|
| Original address | 0x006379e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006379e0 |
| Resolved name | kbd_key_allowed_for_page |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00635900, FUN_00636890
**Callees:** FUN_00632290, FUN_00637430, FUN_00637980, FUN_00637b90, FUN_00637ba0, FUN_00637bf0, FUN_00637c40, FUN_00637c70, FUN_00637ca0
**Referenced globals:** 0x715da8 state struct
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x1d page-id

## Behavioral explanation
Master input-filter: decides if a key descriptor is permitted on the current page 0x1d, dispatching to digit/upper/symbol/dead-key/kana predicates (637c40/637c70/637ca0/637bf0/637ba0/637b90/637430).

## Notes / uncertainty
Master software-keyboard per-key allow filter for create-room text entry; branches on input-mode gate FUN_00632290 then per-page id at iRam00715da8+0x1d (6=alnum,7=dialpad,5=accent,1/2=symbol,0x0f=reject). Page->semantic mapping inferred from callees; FUN_00632290/00637430/00637980 internals not opened. Not on net path but gates typed room name.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006379e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
