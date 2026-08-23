# 0x005bdb00 init_overlay_tables

| field | value |
|---|---|
| Original address | 0x005bdb00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bdb00 |
| Resolved name | init_overlay_tables |
| Subsystem | initialization |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3590
**Callees:** FUN_005be0a0, FUN_005bf230
**Referenced globals:** 0x6fc8e8 0x2000 data buf; 0x6cc668 0x1004 table; 0x86f860 ROM template src; 0x6cbc88/8c/90 buffer descriptor; 0x6cbc84 flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cbc84 init flag

## Behavioral explanation
Overlay init: zeroes a 0x1004 header + 0x2000 buffer at 0x6fc8e8, allocates a task slot, byte-swaps/copies a 0x802-short template from 0x86f860 into 0x6cc668, then runs FUN_005bf230.

## Notes / uncertainty
Allocs task slot (FUN_005be0a0), sets buf descriptor 0x6cbc88/8c/90, zeroes 0x6cc668(0x1004)+0x6fc8e8(0x2000), then on success plain 2B/iter copy of ROM template 0x86f860->0x6cc668 + FUN_005bf230. Prior 'byte-swap' note corrected to plain memcpy; duplicated block is codegen artifact.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bdb00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
