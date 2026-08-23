# 0x005de330 localized_status_string

| field | value |
|---|---|
| Original address | 0x005de330 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005de330 |
| Resolved name | localized_status_string |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d60a0, FUN_005d81b0, FUN_005dbca0, FUN_005dc010, FUN_005dd660, FUN_005e2060, FUN_005e4b00, FUN_005e4f10, FUN_005e5200, FUN_005e5650
**Callees:** —
**Referenced globals:** cRam0035ba80 (language selector); PTR tables 0x64xxxx per language
**Referenced strings:** Esci; Quitter; salir; Verlassen; exit; A connection error has occurred; Address; Reload; Ricarica; Recargar; Neu laden; Recharger
**Referenced opcodes:** —
**State vars:** cRam0035ba80

## Behavioral explanation
Returns a localized UI/status string pointer keyed by language (cRam0035ba80: 5=IT,4=DE,3=ES,2=FR,else EN) and category id (9=exit,8=connection-error,4=Address,3=Reload).

## Notes / uncertainty
Already reconstructed; 5-language x 4-category (9/8/4/3) PTR-table lookup verified. param_2 index bound not derivable here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005de330.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
