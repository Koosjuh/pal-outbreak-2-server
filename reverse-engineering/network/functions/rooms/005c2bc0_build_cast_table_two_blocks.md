# 0x005c2bc0 build_cast_table_two_blocks

| field | value |
|---|---|
| Original address | 0x005c2bc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2bc0 |
| Resolved name | build_cast_table_two_blocks |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005c2f40
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Builds up to two blocks of scenario cast/character display rows from a 4-byte descriptor into the 0x14a5-stride buffer at 0x6d2297, decoding count/range bitfields and memcpy-ing 0x20-byte character records.

## Notes / uncertainty
Emits up to 2 fixed cast blocks into scenario char-select table (dst 0x6d2297 stride 0x14a5) from 0x120-stride source groups; count/base from range bitfields of an 8-byte 2-subdesc descriptor. Renamed from build_cast_table_fixed. Copy size of func_0x00109eb8 and +0x44 signedness uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2bc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
