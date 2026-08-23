# 0x00613b10 msgbox_layout_build_0x4e

| field | value |
|---|---|
| Original address | 0x00613b10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00613b10 |
| Resolved name | msgbox_layout_build_0x4e |
| Subsystem | errors |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00614b90
**Callees:** FUN_00614c80
**Referenced globals:** ctx+0x4e (message id); ctx+0x1f (prompt cursor); ctx+0x23 (variant)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x4e message id

## Behavioral explanation
Builds the message/error-box layout: switch(ctx+0x4e message id) enqueues frame element 0x1b and, for prompt-type messages, a cursor element 0x1a offset by ctx+0x1f (or element 0x1e for id 0x23).

## Notes / uncertainty
Dialog geometry: switch(ctx+0x4e) pushes frame 0x1b + cursor 0x1a (y=ctx+0x1f*-30), variant ctx+0x23==3 suppresses cursor, id 0x23 uses elem 0x1e. Element-id glyph meanings inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00613b10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
