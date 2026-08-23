# 0x00637260 kbd_resolve_enabled_key_for_dir

| field | value |
|---|---|
| Original address | 0x00637260 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637260 |
| Resolved name | kbd_resolve_enabled_key_for_dir |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006313a0, FUN_00631560, FUN_00631670, FUN_00635f80, FUN_00637430
**Callees:** —
**Referenced globals:** 0x715da8 state struct
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x20 disabled-key bitmask; 0x10 page-descriptor ptr

## Behavioral explanation
Neighbor-key resolver: given a direction code, computes candidate key indices and returns the first not-disabled per the bitmask 0x20, writing chosen index to out-params.

## Notes / uncertainty
Directional cursor resolver: switch(dir 0-5) builds candidate ring, returns first enabled key (bit clear in mask +0x20); cases 4/5 gate on page desc +0x10->+0x20/+0x28. Grid geometry constants (2,6,7,8,0xb,0xe,0xf,0x10) not mapped to physical keys.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637260.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
