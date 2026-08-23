# 0x005b18c0 input_is_content_key

| field | value |
|---|---|
| Original address | 0x005b18c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b18c0 |
| Resolved name | input_is_content_key |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f4b80
**Callees:** —
**Referenced globals:** 0x6c4618 uRam006c4618 mode bitmask; 0x6c462a bRam006c462a menu-context byte
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4618; 0x6c462a

## Behavioral explanation
Sibling predicate to 0x5b16c0: returns availability by testing the context byte 0x6c462a against numeric ranges/exclusions, bypassed when bit 0x20 of 0x6c4618 set.

## Notes / uncertainty
RENAMED from menu_item_available_by_context_range: returns true for a content/select key (bit 0x20 confirm, or softkey in valid windows and not a nav/shoulder code). Mechanics certain; semantic label + meaning of 0x87-0x8b window inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b18c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
