# 0x00637430 kbd_validate_key_enabled

| field | value |
|---|---|
| Original address | 0x00637430 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637430 |
| Resolved name | kbd_validate_key_enabled |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00636f90, FUN_006379e0
**Callees:** FUN_00635ba0, FUN_00637260, FUN_00637570
**Referenced globals:** 0x715da8 state struct
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x1e active-key; 0x20 disabled-key bitmask

## Behavioral explanation
Key-enable classifier: for key-class <6 defers to 637260; classes 6-9 validate letter/digit membership via 637570/635ba0 against the disabled bitmask; returns 0=enabled.

## Notes / uncertainty
Class-dispatched selectable test: <6 delegate to 637260; 6/7 via 635ba0; 8/9 via 637570 split by +0x1e&8 mode bit. 0=enabled,1=invalid. 635ba0 not in batch (membership check, [inferred]).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637430.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
