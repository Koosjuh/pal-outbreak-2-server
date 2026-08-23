# 0x001cf150 build_composite_request

| field | value |
|---|---|
| Original address | 0x001cf150 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cf150 |
| Resolved name | assemble_composite_dataset (local + session archive) |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001cf2b0 (build_localized_asset_path), FUN_001cb360 (archive_load), FUN_001069a8 (memcpy), FUN_00109728 (sprintf)
**Referenced globals:** piRam003435bc (archive work buffer base); uRam0034362c (published: composite dest base / param); uRam00343628 (published: advanced dest after part 1); uRam0034357a (session/room id)
**Referenced strings:** 0x24cb10 (part-1 base filename); 0x24cb40 (part-2 filename format, `%…`-with session id)
**Referenced opcodes:** —
**State vars:** uRam0034357a

## Behavioral explanation
Assembles a **composite in-memory dataset** at a caller-supplied destination by concatenating one record extracted from a static localized archive with one record extracted from a **session-specific** localized archive, and returns the combined byte length. Both archives are loaded (one at a time) into the shared work buffer `piRam003435bc`, then a chosen record body is `memcpy`'d out to the growing destination:

1. **Part 1 (static, local):** load localized archive 0x24cb10 into the work buffer (mode 1 = local). If it loaded, copy the **last** record's body (`record[count-1]`) to `param_1`, then advance `param_1` past it, 0x40-aligned. Cache the advanced pointer to 0x343628.
2. **Part 2 (session, remote):** build a filename from format 0x24cb40 + the session id `uRam0034357a`, localize it, load it into the work buffer with **mode 0x10001 (remote/alternate source)**. If it loaded, add **record[3]**'s length to the running total and copy its body to the (advanced) destination.
3. Return the accumulated length.

The session id in the part-2 filename plus the remote load mode indicates part 2 is fetched per-session (server/HDD content keyed to the current room/session), while part 1 is bundled local content — the two are stitched into one contiguous, aligned buffer.

## Input / output
- **Params:** `param_1` = destination base address for the composite dataset (also the running write cursor).
- **Returns:** `int` = total bytes contributed (part-1 last record length + part-2 record[3] length; 0 if neither loaded).

## Side effects
- Loads into the shared work buffer `piRam003435bc` **twice** (destroys prior contents there).
- `uRam0034362c = param_1` (the incoming dest, published early).
- `uRam00343628 = param_1` after part-1 append+align (published mid-way — the part-2 write base).
- Writes the composite data into the caller's `param_1` region.

## Important branches
- **Part-1 `archive_load(...,1) != 0`** → walk pairs to last record (`for k=0..count-2: p+=2`), copy `record[count-1]` (`off=p[2]`, `len=p[3]`) to dest, advance dest `= (dest+len+0x3f) & ~0x3f`. Failure → dest unchanged, `iVar7` stays 0.
- **Part-2 `archive_load(...,0x10001) != 0`** → fixed 3-iteration walk lands `piVar5=work+6`, `piVar6=work+8`; add `piVar5[3]` (record[3] length) to total; copy `record[3]` body (`work + piVar6[0]` = `work + off(record3)`) to dest. Failure → skip.
- The two loads are unconditional attempts; each append is individually gated on its load succeeding.

## Constants & flags
- `archive_load` mode `1` = `ARCHIVE_LOCAL`; mode `0x10001` = `ARCHIVE_REMOTE` (bit 0x10000 selects the secondary/remote source) [inferred].
- `0x3f` / `& 0xffffffc0` = 0x40-byte alignment of the destination cursor between parts.
- Archive header layout (shared with siblings): `hdr[1]` = record count; record *k* pair at `hdr[2k+2]=body offset`, `hdr[2k+3]=body length`; bodies inline after the table.
- Part-2 selects **record index 3** via the fixed 3-step pointer walk (`piVar6 = work + 8` ⇒ `work[8]/work[9]` = record 3 off/len).

## Corrected reconstruction
```c
// Indexed archive in the work buffer: hdr[1]=count; record k -> {off=hdr[2k+2], len=hdr[2k+3]}.
extern long archive_load(const char *name, void *dst, uint32_t mode, int flags); // FUN_001cb360
static uint32_t *g_work;      // piRam003435bc
static void    *g_comp_dst0;  // uRam0034362c (dest as passed in)
static void    *g_comp_dst1;  // uRam00343628 (dest after part 1)
static uint32_t g_session_id; // uRam0034357a

int assemble_composite_dataset(uint8_t *dst)
{
    uint32_t *work = g_work;
    int total = 0;
    g_comp_dst0 = dst;

    // ---- Part 1: static local archive 0x24cb10, take the LAST record ----
    char *p1 = build_localized_asset_path(BASE_PART1 /*0x24cb10*/);
    if (archive_load(p1, work, ARCHIVE_LOCAL /*1*/, 0) != 0) {
        uint32_t *rec = work;
        for (int k = 0; k < work[1] - 1; k++) rec += 2;   // -> pair of record[count-1]
        total = rec[3];                                    // last record length
        memcpy(dst, (uint8_t*)work + rec[2], total);       // copy last record body
        dst = (uint8_t*)(((uintptr_t)dst + total + 0x3f) & ~0x3fu); // advance, 0x40-align
    }
    g_comp_dst1 = dst;

    // ---- Part 2: per-session remote archive (fmt 0x24cb40 + session id), take record[3] ----
    char name[256];
    sprintf(name, FMT_PART2 /*0x24cb40*/, g_session_id);
    char *p2 = build_localized_asset_path(name);
    if (archive_load(p2, work, ARCHIVE_REMOTE /*0x10001*/, 0) != 0) {
        // fixed walk lands on record index 3
        total += work[9];                                  // record[3] length  (rec pair at work[8]/work[9])
        memcpy(dst, (uint8_t*)work + work[8], /*len*/ work[9]); // record[3] body  [len arg garbled in decompile]
    }
    return total;
}
```

## Evidence
- Raw: `sources/executables/transport-decompile/FUN_001cf150.c`. Part-1 loop `iVar7 < piVar1[1]+-1` then `piVar6[2]/[3]`; dest advance `iVar7 + param_1 + 0x3f & 0xffffffc0`. Part-2 `FUN_00109728(...,0x24cb40, uRam0034357a)`, `archive_load(...,0x10001,0)`, 3-step walk, `iVar7 += piVar5[3]`, `memcpy(param_1, work + *piVar6)`.
- Mode 1 vs 0x10001 split mirrors 0x1d1110 (offline uses 1, online uses 0x10001) → confirms 0x10000 = remote/online source bit.

## Remaining uncertainty
- The part-2 `memcpy` length argument is missing in the decompiler output; reconstructed as `work[9]` (record[3] length) from the surrounding index math — **not certain**.
- Why part 1 takes the *last* record while part 2 takes *record[3]* specifically is data-format-dependent (unknown archive schema).
- Meaning of the composite (config blob? localized text + session data?) unresolved without the 0x24cb10/0x24cb40 strings. Runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cf150.c`  — untouched decompiler output.
