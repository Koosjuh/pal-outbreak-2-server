# 0x005b7cd0 draw_markup_string

| field | value |
|---|---|
| Original address | 0x005b7cd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b7cd0 |
| Resolved name | draw_markup_string |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ba2e0, FUN_006080d0, FUN_0061eab0, FUN_00629d60
**Callees:** FUN_005af2c0, FUN_005b7320, FUN_005b76f0, FUN_005b7f00
**Referenced globals:** 0x6ca860/864/868/86c (pen/state); pcRam006ca87c (cursor); cRam006ca881 (parser end)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006ca881; uRam006ca87c

## Behavioral explanation
Public entry: given (x,y,z, text ptr) init markup render state and loop tokenize(FUN_005b7320)+render(FUN_005b76f0) up to 0x1a lines until parser end.

## Notes / uncertainty
Public draw entry (x,y,z,text), default metrics; init size=5/align=6, loop tokenize+render up to 0x1a lines until status!=0. Renderer reads shared global run array.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b7cd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
