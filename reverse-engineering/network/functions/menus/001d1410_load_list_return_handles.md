# 0x001d1410 load_list_return_handles

| field | value |
|---|---|
| Original address | 0x001d1410 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d1410 |
| Resolved name | load_list_into_sequential_slots_return_handles |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001cf2b0 (build_localized_asset_path), FUN_00109eb8 (strcpy), FUN_001cb360 (archive_load), FUN_001a79b0 (decompress_record), FUN_001cb5f0 (slot_install), FUN_001cbcb0 (slot_query)
**Referenced globals:** piRam003435bc (work buffer; scratch = base+0x40000)
**Referenced strings:** 0x24ce50 (base filename)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Loads the same localized archive as 0x1d1050 (0x24ce50) but installs its list entries across **sequential slots starting at 1** and writes each slot's resulting handle back into a caller-provided output array. It decompresses records `0 .. count-2` (i.e. `count-1` entries — the trailing record is not installed here; that one is slot 0's job in 0x1d1050) into slots 1, 2, 3, …, querying each slot's handle after install and storing it in `param_1[i]`. This is how a menu builds a live list of cache handles it can later reference/draw.

## Input / output
- **Params:** `param_1` = `undefined4*` output array; receives one slot handle per installed record (count-1 entries).
- **Returns:** void (results via `param_1`).

## Side effects
- Overwrites work buffer + 0x40000 scratch; binds slots `1..count-1`.
- Writes `count-1` handles into `param_1[]`.
- If the load fails, `param_1` is left untouched.

## Important branches
- **`archive_load(...) == 0`** → skip the whole loop; no slots installed, `param_1` untouched.
- **Loop bound** `while (iVar7 < count-1)` with pre-increment `piVar9 += 2` → processes records index `0..count-2`; slot index `iVar8` runs 1,2,….

## Constants & flags
- Same archive schema and `ARCHIVE_LOCAL` (mode 1) as siblings.
- Scratch at work+0x40000.

## Corrected reconstruction
```c
void load_list_into_sequential_slots_return_handles(uint32_t *out_handles)
{
    uint32_t *work    = g_work;                  // piRam003435bc
    uint8_t  *scratch = (uint8_t*)work + 0x40000;
    char path[256];
    strcpy(path, build_localized_asset_path(BASE_LIST /*0x24ce50*/));

    if (archive_load(path, work, ARCHIVE_LOCAL /*1*/, 0) == 0) return;

    int count = work[1];
    int slot  = 1;
    uint32_t *rec = work;
    for (int i = 0; i < count - 1; i++) {
        rec += 2;                                            // record[i] pair
        decompress_record((uint8_t*)work + *rec, scratch);
        slot_install(slot, scratch);
        *out_handles++ = slot_query(slot);                   // publish handle
        slot++;
    }
}
```

## Evidence
- Raw: `sources/executables/transport-decompile/FUN_001d1410.c` — loop `iVar1 + -1 <= iVar7 break`, `FUN_001cb5f0(iVar8, work+0x40000)`, `uVar3 = FUN_001cbcb0(iVar8); *param_1 = uVar3; param_1++`.
- Complements 0x1d1050 (last record → slot 0) on the identical archive 0x24ce50.

## Remaining uncertainty
- Why the last record is excluded here (owned by slot-0 loader) vs included elsewhere — archive-schema convention.
- `out_handles` capacity is assumed ≥ count-1 (no bound in code). Runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d1410.c`  — untouched decompiler output.
