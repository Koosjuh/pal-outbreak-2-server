# 0x00623600 screen_teardown_reinit

| field | value |
|---|---|
| Original address | 0x00623600 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00623600 |
| Resolved name | screen_teardown_reinit |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_006233e0
**Callees:** FUN_0061e940, FUN_0061e9c0, FUN_0061f0d0, FUN_00621ed0
**Referenced globals:** 0x715298 struct ptr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00715298

## Behavioral explanation
Tears down and reinitializes the overlay screen: cancels callbacks, resets buffers, re-inits struct (FUN_00621ed0) and re-registers the frame callback 0x622130.

## Notes / uncertainty
In-place screen teardown+reinit: cancels callback, resets render/pipeline, re-inits ctx (0x715298), sets ctx+0x108=1 active flag, re-registers frame cb 0x622130. Engine primitives (func_0x001a*/001c*) inferred from call shape, not decompiled.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00623600.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
