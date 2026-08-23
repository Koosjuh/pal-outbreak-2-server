# 0x00637180 kbd_close_if_flagged

| field | value |
|---|---|
| Original address | 0x00637180 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637180 |
| Resolved name | kbd_close_if_flagged |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acd60, FUN_005acda0, FUN_005ae510, FUN_005ae8a0, FUN_005b45f0, FUN_005c84e0, FUN_005dc2b0, FUN_005f4be0, FUN_005f6970, FUN_005f8b50, FUN_005f8c20, FUN_005f97c0, FUN_005faa60, FUN_005fb670, FUN_005ff830, FUN_00614ad0, FUN_00616bd0, FUN_00617a00, FUN_0062adb0, FUN_0062d430, FUN_0062e2a0, FUN_0062e720
**Callees:** FUN_00637170, FUN_00637210, FUN_00637250
**Referenced globals:** 0x715da8 state struct
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x31 flag; 0x32 exit-code

## Behavioral explanation
If flag 0x31 is set, clears it (637250), deactivates (637210) and sets exit-code 0x32=0xff — the 'dismiss keyboard' hook called from ~23 menu screens.

## Notes / uncertainty
Per-frame dismiss hook: if flag +0x31 set, clear it, deactivate, set exit-code +0x32=0xFF. Callee 637170 (flag getter) not in batch; assumed reads +0x31.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637180.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
