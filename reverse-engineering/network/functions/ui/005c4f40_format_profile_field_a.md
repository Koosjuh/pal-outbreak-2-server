# 0x005c4f40 format_profile_field_a

| field | value |
|---|---|
| Original address | 0x005c4f40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c4f40 |
| Resolved name | format_profile_field_a |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bca90, FUN_005c0ff0, FUN_005c7020
**Callees:** —
**Referenced globals:** 0x365d20 user-record-table; 0x86f800 user-index; 0x700fb0 scratch-out; 0x6405b0 fmt-str
**Referenced strings:** fmt@0x6405b0
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Formats a per-user record (table 0x365d20 indexed by 0x86f800) into scratch 0x700fb0 using format string 0x6405b0.

## Notes / uncertainty
Formats profile record[uRam0086f800] (stride 0x260, offset 0) into scratch 0x700fb0 + suffix 0x6405b0. char*/strcpy vs numeric/itoa hinges on unread 0x109eb8.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c4f40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
