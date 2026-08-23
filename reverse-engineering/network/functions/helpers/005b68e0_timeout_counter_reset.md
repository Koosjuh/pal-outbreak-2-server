# 0x005b68e0 timeout_counter_reset

| field | value |
|---|---|
| Original address | 0x005b68e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b68e0 |
| Resolved name | timeout_counter_reset |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acea0, FUN_005ad030, FUN_005ad530, FUN_005ad680, FUN_005ade20, FUN_005ae8a0, FUN_005b25c0, FUN_005b2bc0, FUN_005b2e40, FUN_005b3070, FUN_005b3590, FUN_005b3790, FUN_005b4a50, FUN_005f78c0, FUN_005f8060, FUN_005f8220, FUN_005f8ec0, FUN_005f91f0, FUN_005f9280, FUN_005f99c0, FUN_005fa190, FUN_005fada0, FUN_005fb790, FUN_005fb9b0, FUN_005fe8d0, FUN_005fed10, FUN_005ff690, FUN_005ff760, FUN_005ffa90, FUN_005ffdc0, FUN_00600d10, FUN_00616d30, FUN_006173c0, FUN_00617a50, FUN_00627b00, FUN_0062ab50, FUN_0062bee0, FUN_0062cb00, FUN_0062d810, FUN_0062d9f0, FUN_0062dc40, FUN_0062de90, FUN_0062e440, FUN_0062e720, FUN_0062e800
**Callees:** —
**Referenced globals:** uRam006c5504 (expiry flag); uRam006c5500 (frame countdown, 0xe10)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c5500; uRam006c5504

## Behavioral explanation
Reset a countdown: clear expiry flag uRam006c5504 and load counter uRam006c5500=0xe10 (3600).

## Notes / uncertainty
Shared UI/network watchdog re-arm called from 45 state-entry sites: clears expiry flag 0x6c5504, reloads countdown 0x6c5500=0xE10 (3600 frames ~60s). Values exact; frame->seconds and tick-down/consumer sites inferred/external.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b68e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
