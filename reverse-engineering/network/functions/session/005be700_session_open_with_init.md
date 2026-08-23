# 0x005be700 session_open_with_init

| field | value |
|---|---|
| Original address | 0x005be700 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005be700 |
| Resolved name | session_open_with_init |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f7270
**Callees:** FUN_005be060, FUN_005be080
**Referenced globals:** 0x6cbbe4 session-active guard; 0x6ca950 net-active; 0x6cbbc0 callback; 0x6cbbc4 param; 0x35b9e0 socket/handle
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cbbe4 session-active; 0x6ca950 net-active; 0x35b9e0 handle (-1=none)

## Behavioral explanation
Session-open variant that first lazily initializes the net subsystem (iRam006ca950/init leaves) if inactive, then latches the FUN_005be7b0 connect callback and invokes transport open when handle valid.

## Notes / uncertainty
Variant of session_open that lazily bootstraps net subsystem (FUN_005be060/080, sets 0x6ca950) first; only connects if handle 0x35b9e0 != -1. FUN_005be060/080 responsibilities not decompiled.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005be700.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
