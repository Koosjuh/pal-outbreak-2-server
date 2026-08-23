# 0x00621ed0 screen_struct_init

| field | value |
|---|---|
| Original address | 0x00621ed0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00621ed0 |
| Resolved name | screen_struct_init |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00621f10, FUN_00623600
**Callees:** FUN_005f42c0
**Referenced globals:** 0x715298 screen struct ptr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00715298

## Behavioral explanation
Zeroes the 0x19c-byte screen/overlay struct at iRam00715298 and initializes its sub-object via FUN_005f42c0.

## Notes / uncertainty
memset(*0x715298,0,0x19c) + init bg/anim sub-object +0x110..+0x150 via FUN_005f42c0. Defines the struct-family screen object layout.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00621ed0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
