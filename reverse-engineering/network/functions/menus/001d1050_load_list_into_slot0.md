# 0x001d1050 load_list_into_slot0

| field | value |
|---|---|
| Original address | 0x001d1050 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d1050 |
| Resolved name | ensure_slot0_from_localized_archive |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001cbcb0 (slot_query), FUN_001cf2b0 (build_localized_asset_path), FUN_00109eb8 (strcpy), FUN_001cb360 (archive_load), FUN_001a79b0 (decompress_record), FUN_001cb5f0 (slot_install)
**Referenced globals:** piRam003435bc (archive work buffer base; scratch = base+0x40000)
**Referenced strings:** 0x24ce50 (base filename)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Lazy, idempotent loader for **cache/channel slot 0**. If slot 0 is already populated it does nothing; otherwise it loads the localized archive 0x24ce50 into the shared work buffer, decompresses that archive's **last** record into a scratch region, and installs the result into slot 0. Because it is guarded by `slot_query(0)`, repeated calls after the first are no-ops — used to guarantee a default/fallback list entry exists before rendering.

## Input / output
- **Params:** none.
- **Returns:** void.

## Side effects
- On a cold slot 0: overwrites the shared work buffer (`piRam003435bc`) and the +0x40000 scratch, then binds slot 0 to the decompressed last record via `slot_install(0, scratch)`.
- No effect if slot 0 already loaded.

## Important branches
- **`slot_query(0) != 0`** (slot already loaded) → return immediately (guard).
- **`archive_load(...) == 0`** (load failed) → return without installing (slot 0 stays empty; will retry next call).
- Walk-to-last-record: `for (k=0; k<count-1; k++) p+=2` leaves `p` at the pair of `record[count-1]`; `*p` = its body offset.

## Constants & flags
- Work-buffer scratch offset `0x40000` (decompress target).
- `archive_load` mode `1` = `ARCHIVE_LOCAL` (see 0x1cf150 / 0x1d1110 for the mode analysis).
- Archive layout: `hdr[1]`=record count; record *k* at `hdr[2k+2]`=offset, `hdr[2k+3]`=length; bodies inline.

## Corrected reconstruction
```c
extern long  slot_query(int slot);                        // FUN_001cbcb0 (0 = empty)
extern void  slot_install(int slot, void *buf);           // FUN_001cb5f0
extern void  decompress_record(const void *src, void *dst);// FUN_001a79b0
static uint32_t *g_work;                                   // piRam003435bc

void ensure_slot0_from_localized_archive(void)
{
    if (slot_query(0) != 0) return;                        // already loaded

    uint8_t *scratch = (uint8_t*)g_work + 0x40000;
    char path[256];
    strcpy(path, build_localized_asset_path(BASE_LIST /*0x24ce50*/));

    if (archive_load(path, g_work, ARCHIVE_LOCAL /*1*/, 0) != 0) {
        uint32_t *rec = g_work;
        for (int k = 0; k < g_work[1] - 1; k++) rec += 2;  // -> record[count-1] pair
        decompress_record((uint8_t*)g_work + *rec, scratch);
        slot_install(0, scratch);
    }
}
```

## Evidence
- Raw: `sources/executables/transport-decompile/FUN_001d1050.c` — `FUN_001cbcb0(0)` guard, `FUN_001cf2b0(0x24ce50)`, walk-to-last (`piVar1[1]+-1`), `FUN_001a79b0((int)piVar1 + *piVar5, work+0x40000)`, `FUN_001cb5f0(0, work+0x40000)`.
- Shares archive/slot helper set with 0x1d1410 (same archive 0x24ce50, different install policy).

## Remaining uncertainty
- Semantics of slot ids (`0`) vs the 0x24xx / 0x42xx channel groups — inferred from usage, not a decoded slot map.
- Runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d1050.c`  — untouched decompiler output.
