# 0x006179e0 mode8_object_init

| field | value |
|---|---|
| Original address | 0x006179e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006179e0 |
| Resolved name | mode8_object_init |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005aec70
**Callees:** FUN_005aec20
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0(type)=8; +0x11 param

## Behavioral explanation
Constructor stamping a scene object with type byte=8 and clearing its state header (+0xe/+0xf/+0x10), storing param_2 at +0x11.

## Notes / uncertainty
Constructor for type-8 scene; stores param_2 into obj+0x11 variant. Lighter than 0x617a00 (no FUN_00637180). type-8 per-tick dispatcher not in batch.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006179e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
