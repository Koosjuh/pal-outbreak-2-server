# 0x005b6900 timeout_counter_tick

| field | value |
|---|---|
| Original address | 0x005b6900 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b6900 |
| Resolved name | timeout_counter_tick |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acea0, FUN_005ad030, FUN_005ad530, FUN_005ad680, FUN_005ade20, FUN_005ae8a0, FUN_005b25c0, FUN_005b2e40, FUN_005b3070, FUN_005b3590, FUN_005b4a50, FUN_005f78c0, FUN_005f8060, FUN_005f8220, FUN_005f8ec0, FUN_005f91f0, FUN_005f9280, FUN_005f99c0, FUN_005fa190, FUN_005fada0, FUN_005fb790, FUN_005fb9b0, FUN_005fe8d0, FUN_005fed70, FUN_005ff690, FUN_005ff760, FUN_005ffa90, FUN_005ffdc0, FUN_00600d10, FUN_00616d30, FUN_00617270, FUN_006173c0, FUN_006176a0, FUN_00617a50, FUN_0062c7b0, FUN_0062d810, FUN_0062d9f0, FUN_0062dc40, FUN_0062de90, FUN_0062e440, FUN_0062e720, FUN_0062e800
**Callees:** FUN_005f6970
**Referenced globals:** uRam006c5500 (countdown); uRam006c5504 (expiry flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c5500; uRam006c5504

## Behavioral explanation
Decrement countdown uRam006c5500; when it goes negative set expiry flag uRam006c5504=1 and fire FUN_005f6970(4); returns expired-bool.

## Notes / uncertainty
Shared single-slot per-frame countdown (44 callers); on <0 latches uRam006c5504 and fires FUN_005f6970(4). Meaning of event code 4 and the paired seeder untraced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b6900.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
