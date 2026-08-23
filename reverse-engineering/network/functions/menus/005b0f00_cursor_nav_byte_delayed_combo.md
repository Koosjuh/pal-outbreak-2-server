# 0x005b0f00 cursor_nav_byte_delayed_combo

| field | value |
|---|---|
| Original address | 0x005b0f00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b0f00 |
| Resolved name | cursor_nav_byte_delayed_combo |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00629200
**Callees:** FUN_005b14b0, FUN_005b16c0
**Referenced globals:** 0x6ca078/0x6ca07a delay counters; 0x6c462a pad latch; 0x6c4628 pad-held latch; 0x6c462b pad extra-mask
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Cursor navigation with hold-delay repeat plus extra button gating: additionally allows the '+' (Start/combo) button with mask bits (bRam006c462b & 0x22) as a navigation trigger; delay counters at 0x6ca078/7a.

## Notes / uncertainty
Renamed _gated->_combo: delayed variant plus '+' combo button driving primary dir when (0x6c462b & 0x22) set; '+' excluded from secondary. Counters 0x6ca078/7a. Physical meaning of mask 0x22 unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b0f00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
