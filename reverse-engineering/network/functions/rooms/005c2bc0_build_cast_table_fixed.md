# 0x005c2bc0 build_cast_table_fixed

| field | value |
|---|---|
| Original address | 0x005c2bc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2bc0 |
| Resolved name | build_cast_table_two_blocks |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005c2f40 (scenario cast-table assembler)
**Callees:** func_0x00109eb8 (fixed-size record copy)
**Referenced globals:** — (operates on caller-supplied dest 0x6d2297 base, stride 0x14a5, and a 0x120-stride source group base)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Emits up to TWO fixed cast-display blocks into the scenario character-select table (dest rows of stride
0x14a5, base 0x6d2297 as passed by FUN_005c2f40). The descriptor `param_4` is an 8-byte struct = two 4-byte
sub-descriptors `{u8 group_idx, u8 range_bits, u8 active, u8 tag}`. For each active sub-descriptor it:
1. Locates the source group record `src = param_5 + group_idx*0x120`.
2. Decodes an entry range from `range_bits` and writes the block header: `dst+0x43 = count`,
   `dst+0x44 = start_offset`, `dst+0x42 = tag`.
3. Copies the group header (`dst+1 ← src`) and then `count` character entries
   (`dst + i*0x41 + 0x65 ← src + (i+start)*0x20 + 0x20`), i.e. 0x41-stride rows from 0x20-stride source cells.
4. Advances `dst += 0x14a5` and increments the return counter.

Block 1 uses a 2-bit start (`range_bits>>2 & 3`) and a 2-bit end (`range_bits>>4 & 3`), count = end-start+1,
and a signed low-2-bit base offset `(range_bits & 3) - start`. Block 2 uses a simpler `count = (range_bits>>3
& 7) + 1` and `base = range_bits & 7`, sourced from the second sub-descriptor's group. Returns the number of
blocks written (0, 1, or 2). This is the "fixed slots" first pass of the scenario cast table (the always-present
protagonist/partner pair), before FUN_005c2d70 appends the variable extra-character blocks.

## Input / output
- `param_1` (int dst): base of the next cast row (0x14a5-stride) to fill.
- `param_2` (undefined8): unused/context.
- `param_3` (int = 2 from caller): unused in body (caller tag; block-count hint).
- `param_4` (char* descriptor[8]): two `{group_idx, range_bits, active, tag}` sub-descriptors.
- `param_5` (int src base): base of 0x120-stride source group records (FUN_005c2e90(n)).
- **returns** int block count written (0..2).

## Side effects
- Writes cast rows at dst and dst+0x14a5 (header +0x1..+0x41, tag +0x42, count +0x43, base +0x44, entries +0x65..).

## Important branches
- `param_4[2] != 0` → emit block 1 (count = (range_bits>>4 &3) - (range_bits>>2 &3) + 1), dst += 0x14a5, ret=1.
- `param_4[6] != 0` → emit block 2 (count = (range_bits2>>3 &7) + 1), ret += 1.
- both inactive → ret 0 (nothing emitted).

## Constants & flags
- 0x120 = source group-record stride.
- 0x20 = source character-cell stride; entry copy starts at src+0x20 (cell 0 is the header).
- 0x41 = dest per-entry stride; 0x65 = dest entries base; 0x42/0x43/0x44 = tag/count/base header fields.
- 0x14a5 = dest cast-row stride.

## Corrected reconstruction
```c
struct cast_subdesc { u8 group_idx; u8 range_bits; u8 active; u8 tag; };  // 4 bytes
struct cast_desc    { struct cast_subdesc a, b; };                        // 8 bytes

// dst rows: stride 0x14a5; header at +0x42 tag, +0x43 count, +0x44 base; entries at +0x65 stride 0x41.
// src groups: stride 0x120; character cells: stride 0x20 starting at +0x20.
int build_cast_table_two_blocks(u8 *dst, void *ctx, int nblk /*=2*/,
                                const struct cast_subdesc *d, int src_base) {
    int written = 0;

    if (d[0].active) {                                   // param_4[2]
        u32 start = (d[0].range_bits >> 2) & 3;
        u32 count = ((d[0].range_bits >> 4) & 3) - start + 1;
        dst[0x43] = (u8)count;
        dst[0x44] = (d[0].range_bits & 3) - (u8)start;    // signed base offset [inferred]
        int src = src_base + d[0].group_idx * 0x120;
        rec_copy(dst + 1, (void *)src);                   // group header
        dst[0x42] = d[0].tag;                             // param_4[3]
        for (u32 i = 0; i < (count & 0xffff); i++)
            rec_copy(dst + i*0x41 + 0x65, (void *)(src + (i + start)*0x20 + 0x20));
        written = 1;
        dst += 0x14a5;
    }
    if (d[1].active) {                                   // param_4[6]
        int count = ((d[1].range_bits >> 3) & 7) + 1;
        dst[0x43] = (u8)count;
        dst[0x44] = d[1].range_bits & 7;
        src_base += d[1].group_idx * 0x120;
        rec_copy(dst + 1, (void *)src_base);
        dst[0x42] = d[1].tag;                             // param_4[7]
        for (int i = 0; i < count; i++)
            rec_copy(dst + i*0x41 + 0x65, (void *)(src_base + i*0x20 + 0x20));
        written += 1;
    }
    return written;
}
```

## Evidence
- Raw decompile: bitfield decode `param_4[1]>>2&3`, `>>4&3`, `&3`; second block `param_4[5]>>3&7`, `&7`.
- Caller FUN_005c2f40 builds the 8-byte descriptor from a scenario blob (`FUN_005c2ae0`) and passes dst base
  0x6d2297, count tag 2, src = FUN_005c2e90(0); return feeds the running row offset for FUN_005c2d70.
- Runtime-unvalidated; bitfield field-naming inferred.

## Remaining uncertainty
- Exact size copied by func_0x00109eb8 for the header (dst+1) vs the 0x20 entry cells.
- Whether +0x44 is a signed base index or a flags nibble (the `- start` term suggests signed base).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2bc0.c`  — untouched decompiler output.
