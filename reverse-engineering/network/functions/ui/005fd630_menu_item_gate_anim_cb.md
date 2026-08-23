# 0x005fd630 menu_item_gate_anim_cb

| field | value |
|---|---|
| Original address | 0x005fd630 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fd630 |
| Resolved name | menu_item_gate_anim_cb |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bac80
**Referenced globals:** 0x6c550e mode flag; 0x6c5498/0x6c5499 selection; 0x6947e8/0x6947ea area-unlock table; 0x649b50/0x649b62 coord tables
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam006c5498 selection; cRam006c550e mode

## Behavioral explanation
Per-frame menu-item widget callback: computes enabled/greyed state from selection bRam006c5498 (area-unlock gating) and pulses alpha via a sine table.

## Notes / uncertainty
Menu-item enable/grey gating + sine alpha pulse. Mode B (area grid) is the 6+10 greyed-area logic: idx<2 or ==10 always greyed, idx>=2 gated by unlock flag 0x6947e8+idx*0x14a8; idx 8/9 special. Gating outcome rig-observed; anim/pixel level unvalidated; special indices 8/9 not fully mapped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fd630.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
