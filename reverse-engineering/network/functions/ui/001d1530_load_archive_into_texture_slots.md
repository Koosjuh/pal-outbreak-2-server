# 0x001d1530 load_archive_into_texture_slots

| field | value |
|---|---|
| Original address | 0x001d1530 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d1530 |
| Resolved name | load_archive_into_channel_slots_4200_return_handles |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001cbc20 (slot_group_reserve), FUN_001cf2b0 (build_localized_asset_path), FUN_001cb360 (archive_load), FUN_001a79b0 (decompress_record), FUN_001cb5f0 (slot_install), FUN_001cbcb0 (slot_query)
**Referenced globals:** piRam003435bc (work buffer; scratch = base+0x40000)
**Referenced strings:** 0x24cf40 (base archive name)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Loads every record of the localized archive 0x24cf40 into the `0x4200` channel-slot group and returns each installed slot's handle to the caller. It first reserves the group base (`FUN_001cbc20(0x4200)`), loads and localizes the archive, then for each of the `count` records decompresses the body into scratch, installs it into slot `0x4200 + i`, and writes that slot's queried handle into `param_2[i]`. `param_1` is passed but unused in the body (likely a context/tag the callee/reserve consumes, or a leftover). The teardown counterpart is 0x1d1610.

## Input / output
- **Params:** `param_1` = (unused in body) group/context tag [inferred]; `param_2` = `undefined4*` output array, receives one handle per record.
- **Returns:** void (handles via `param_2`).

## Side effects
- Reserves slot group at 0x4200, overwrites work buffer + 0x40000 scratch, binds slots `0x4200..0x4200+count-1`, writes `count` handles to `param_2[]`.
- On load failure: only the reserve happened; no slots installed.

## Important branches
- **`archive_load(...) == 0`** → skip the install loop (reserve already done).
- **Loop** `for (i=0; i<count; i++)` — installs **all** records (contrast 0x1d1410 which skips the last).

## Constants & flags
- Group base `0x4200`; scratch at work+0x40000; `archive_load` mode 1 (ARCHIVE_LOCAL).
- Note: unlike 0x1d1050/0x1410, this passes the `FUN_001cf2b0` result **directly** to `archive_load` (no intermediate `strcpy`) — safe because it consumes it before the next localize call.

## Corrected reconstruction
```c
extern void slot_group_reserve(int base);  // FUN_001cbc20

void load_archive_into_channel_slots_4200_return_handles(void *ctx /*param_1, unused*/,
                                                         uint32_t *out_handles /*param_2*/)
{
    slot_group_reserve(0x4200);
    uint32_t *work    = g_work;
    uint8_t  *scratch = (uint8_t*)work + 0x40000;

    char *path = build_localized_asset_path(BASE_TEX /*0x24cf40*/);
    if (archive_load(path, work, ARCHIVE_LOCAL /*1*/, 0) == 0) return;

    int count = work[1];
    uint32_t *rec = work;
    for (int i = 0; i < count; i++) {
        rec += 2;                                           // record[i] pair
        decompress_record((uint8_t*)work + *rec, scratch);
        slot_install(0x4200 + i, scratch);
        *out_handles++ = slot_query(0x4200 + i);
    }
}
```

## Evidence
- Raw: `sources/executables/transport-decompile/FUN_001d1530.c` — `FUN_001cbc20(0x4200)`, loop `iVar8 < iVar1(=count)`, `FUN_001cb5f0(iVar8 + 0x4200, work+0x40000)`, `uVar3 = FUN_001cbcb0(iVar8 + 0x4200); *param_2 = uVar3`.
- Reserve/free pairing with 0x1d1610.

## Remaining uncertainty
- `param_1`'s role (unused in this body) unresolved — possibly consumed indirectly or a stale signature.
- "texture" vs generic "channel" grouping is a naming carryover; the mechanism is the same archive→slot loader as the menu functions. Runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d1530.c`  — untouched decompiler output.
