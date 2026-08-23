# 0x005b8cf0 spawn_message_widget

| field | value |
|---|---|
| Original address | 0x005b8cf0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b8cf0 |
| Resolved name | spawn_message_widget |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ad350, FUN_005b1fa0, FUN_005b20c0, FUN_005b25c0, FUN_005b8da0, FUN_005f6a20, FUN_005f8ec0, FUN_005f9280, FUN_005fa190, FUN_005fb060, FUN_005fb270, FUN_005fb860, FUN_005fe8d0, FUN_00604180, FUN_00606af0, FUN_00606fc0, FUN_00607370, FUN_006076c0, FUN_00607cf0, FUN_00616d30, FUN_006178a0, FUN_00619680, FUN_0061ded0, FUN_00628210, FUN_006293f0, FUN_006296a0, FUN_0062a8c0, FUN_0062be30, FUN_0062c580, FUN_0062c870, FUN_0062e2a0
**Callees:** FUN_00618ba0
**Referenced globals:** 0x006c4fcd uRam=msg channel id; 0x006c4fce uRam=msg flag; 0x006c4fcf uRam=msg flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4fcd; uRam006c4fce; uRam006c4fcf

## Behavioral explanation
Allocates a display node (FUN_00618ba0), installs render callback FUN_005b9150, stores type in +2, picks icon 0x8e vs 0x8d by type (0x86/0xaf/0x88); resets the uRam006c4fcd/ce/cf message-channel state.

## Notes / uncertainty
Dialog spawner (31 callers); installs message_render_cb, resets channel state (uRam006c4fcd=0xff), icon 0x8e/0x8d by type. Certain behavior.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b8cf0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
