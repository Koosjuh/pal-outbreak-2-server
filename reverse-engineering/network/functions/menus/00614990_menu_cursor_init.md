# 0x00614990 menu_cursor_init

| field | value |
|---|---|
| Original address | 0x00614990 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00614990 |
| Resolved name | menu_cursor_init |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00610830
**Callees:** —
**Referenced globals:** iRam0070d1c0 (+0x40..+0x48 cursor block)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0070d1c0+0x40 (menu idx); +0x42 (value); +0x44 (opts ptr); +0x48 (count)

## Behavioral explanation
Initializes menu selection state: stores options ptr(+0x44), current value(+0x42), count=1(+0x48), index=0(+0x40).

## Notes / uncertainty
Writes cursor sub-block +0x40/+0x42/+0x44/+0x48 of overlay UI state; offsets/widths exact, field names inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00614990.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
