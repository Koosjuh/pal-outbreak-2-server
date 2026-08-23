# 0x005fa820 lookup_id_to_byte

| field | value |
|---|---|
| Original address | 0x005fa820 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fa820 |
| Resolved name | lookup_id_to_byte |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005adcd0
**Callees:** —
**Referenced globals:** 0x3c4d50 id table (stride 0xc, 999-terminated)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Table lookup (@0x3c4d50 stride 0xc): maps (param-1) to the byte at +2, or 999 sentinel if not found.

## Notes / uncertainty
Linear search of table 0x3c4d50 (stride 0xc, u16 key/u8 value, 999 sentinel): key==id-1 -> value byte. Decode exact; table domain inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fa820.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
