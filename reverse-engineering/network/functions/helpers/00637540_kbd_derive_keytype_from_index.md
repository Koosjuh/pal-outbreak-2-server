# 0x00637540 kbd_derive_keytype_from_index

| field | value |
|---|---|
| Original address | 0x00637540 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637540 |
| Resolved name | kbd_derive_keytype_from_index |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00631100, FUN_006312c0, FUN_006313a0, FUN_00631560, FUN_00631670, FUN_00634890, FUN_00635bb0, FUN_00635f80, FUN_00636f90, FUN_006375d0
**Callees:** —
**Referenced globals:** 0x715da8 state struct; 0x692430 keyindex→type table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x1e active-key; 0x1f key-type

## Behavioral explanation
Sets key-type 0x1f = table[key-index 0x1e] via lookup DAT_00692430 (maps active cell to its category).

## Notes / uncertainty
+0x1f = KEY_TYPE_TABLE[0x692430][+0x1e]. Full table contents not dumped; only types 4/5 exercised downstream.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637540.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
