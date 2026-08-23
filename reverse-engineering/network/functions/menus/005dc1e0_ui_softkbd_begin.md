# 0x005dc1e0 ui_softkbd_begin

| field | value |
|---|---|
| Original address | 0x005dc1e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dc1e0 |
| Resolved name | ui_softkbd_begin |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d1e80
**Callees:** FUN_006345e0, FUN_006371d0
**Referenced globals:** iRam00701068+0x68e89: OSK edit buffer; 0x643398: default/empty string
**Referenced strings:** (default string @0x643398)
**Referenced opcodes:** —
**State vars:** 0x68e89

## Behavioral explanation
UI software-keyboard init: seeds the edit buffer 0x68e89 with the current string (or default @0x643398, len-clamped to 0xff), positions the OSK and opens it via FUN_006345e0.

## Notes / uncertainty
Opens OSK: seeds buffer 0x68e89 (or default 0x643398), clamps len 0xff, positions+launches. param_3 charset/mode encoding not enumerated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dc1e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
