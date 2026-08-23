# 0x005b9060 spawn_count_label_widget

| field | value |
|---|---|
| Original address | 0x005b9060 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b9060 |
| Resolved name | spawn_count_label_widget |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ad030, FUN_005ad530, FUN_005ad680, FUN_005ade20, FUN_005ae510, FUN_005ae9b0, FUN_005b20c0, FUN_005b33f0, FUN_005b3590, FUN_005b4a50, FUN_005f6a20, FUN_005f8060, FUN_005fb790, FUN_005fb860, FUN_005fb9b0, FUN_005ff760, FUN_00600d10, FUN_006178a0, FUN_0062ab50, FUN_0062c870
**Callees:** FUN_00618ba0
**Referenced globals:** 0x006c4fcd uRam; 0x006c4fce uRam; 0x006c4fcf uRam
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4fcd; uRam006c4fce; uRam006c4fcf

## Behavioral explanation
Allocates a display node with callback FUN_005ba2e0; icon 0x8d (subtype 0) or 0x143 (subtype 1) chosen by param&0x8000; stores data ptr at +0x10.

## Notes / uncertainty
Renamed from spawn_widget_cb2e0: installs count_widget_cb; icon 0x8d/0x143 by param bit 0x8000 (WIDGET-LOCAL mode flag, NOT the transport reliable bit).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b9060.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
