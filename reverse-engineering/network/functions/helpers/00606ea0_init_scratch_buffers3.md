# 0x00606ea0 init_scratch_buffers3

| field | value |
|---|---|
| Original address | 0x00606ea0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606ea0 |
| Resolved name | init_record_buffers3 |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac610 (overlay_init_full), FUN_005ac6f0, FUN_00606e40 (teardown_overlay_state)
**Callees:** func_0x00106b60 (memset)
**Referenced globals:** uRam003435d4 (0x8000 scratch arena base); 0x6c5480 (record-buffer pointer array [3])
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Zeroes the 0x8000-byte scratch arena at `0x3435d4` and carves it into three record buffers,
publishing their base pointers into the array at `0x6c5480`. Each buffer is spaced 0x17bb bytes
apart, rounded **down** to a 0x40 boundary (`& 0xffffffc0`), so the three room/member record
tables that the overlay draws from are non-overlapping and cache-line aligned. Run at overlay
init and again on teardown so the record tables always start clean.

## Input / output
- No parameters, void return. Output is the populated pointer array 0x6c5480[0..2].

## Side effects
- `memset(0x3435d4, 0, 0x8000)`.
- Writes 3 pointers: `0x6c5480[0] = base`, `[1] = (base+0x17bb)&~0x3f`, `[2] = (prev+0x17bb)&~0x3f`.

## Important branches
- Fixed 3-iteration loop (`iVar2 < 3`); no data-dependent branches.

## Constants & flags
- arena size **0x8000**; per-buffer advance **0x17bb**; alignment mask **0xffffffc0** (0x40).
- pointer array **0x6c5480** — the "record-table base-pointer array" (GLOBALS calls it [2]; the
  loop actually writes **3** entries).

## Corrected reconstruction
```c
void init_record_buffers3(void) {
    memset((void*)uRam003435d4, 0, 0x8000);      // scratch arena

    u32 base = uRam003435d4;
    for (int i = 0; i < 3; i++) {
        ((u32*)0x6c5480)[i] = base;              // publish buffer base
        base = (base + 0x17bb) & 0xffffffc0;     // next, 0x40-aligned
    }
}
```

## Evidence
- Raw decompile: FUN_00606ea0.c (104 bytes) — memset size, stride 0x17bb, mask, 3-entry loop
  all literal.
- 0x6c5480 role ("record-table base-pointer array") from GLOBALS.md.
- Runtime-unvalidated.

## Remaining uncertainty
- Which of the three buffers backs which drawn table (room list / member list / detail) — the
  consumers (FUN_005bac60 family) index 0x6c5480 but are not read here.
