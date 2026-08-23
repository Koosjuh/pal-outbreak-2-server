# 0x005b6070 result_code_menu_state_dispatch

| field | value |
|---|---|
| Original address | 0x005b6070 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b6070 |
| Resolved name | result_code_menu_state_dispatch |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bd830, FUN_005bd860, FUN_005bd890, FUN_005bda30, FUN_005be9a0, FUN_005f6970
**Referenced globals:** uRam006c4b9e/9f/ba0 (menu step regs); uRam006c550a (error code); cRam00874f35 (user state); 0x874fb0/0x874fc0 (user/handle copy dest); 0x6c69bc/cc/e0 (source blocks); cRam00874f35
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4b9e; uRam006c4b9f; uRam006c550a; cRam00874f35

## Behavioral explanation
Dispatch on a 16-bit result code (hi/lo bytes): 0xFF-prefixed codes 7/8/9 set error step (uRam006c550a 1/2) or FUN_005f6970(4); low-byte cases 0-5 set menu step uRam006c4b9e/9f and, on case 2, copy user/handle blocks (0x874fb0/0x874fc0) from 0x6c69bc/cc.

## Notes / uncertainty
Login/register result callback: 16-bit code (byte0 class, byte1 sub). class 0xFF -> error screens (0x6c550a 1/2). success sub 0..5 drives lobby menu regs 6c4b9e/9f/ba0; sub 2 commits identity (memcpy user->0x874fb0/0x10, handle->0x874fc0/0x11). Per-menu-value screen meanings partly inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b6070.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
