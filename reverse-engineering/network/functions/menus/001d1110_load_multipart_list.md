# 0x001d1110 load_multipart_list

| field | value |
|---|---|
| Original address | 0x001d1110 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d1110 |
| Resolved name | load_multipart_list_into_2600_channels |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001cf2b0 (build_localized_asset_path), FUN_00109728 (sprintf), FUN_00109eb8 (strcpy), FUN_001cb360 (archive_load), FUN_001a79b0 (decompress_record), FUN_001cb5f0 (slot_install), FUN_001cbcb0 (slot_query)
**Referenced globals:** iRam003435bc (work buffer; scratch = base+0x100000); 0x24ce80 (`DAT_0024ce80[4]` sub-slice offset table); cRam00343577 (asset-source / offline-mode flag); uRam0034357a (session/room id)
**Referenced strings:** 0x24ce90 (base archive), 0x24ceb8 + 0x24ced0 (online follow-up name parts), 0x24cef0 (offline follow-up name format)
**Referenced opcodes:** —
**State vars:** cRam00343577, uRam0034357a

## Behavioral explanation
Loads a **multi-part list dataset** into the `0x2600`-based channel group. First it loads the base archive 0x24ce90, decompresses the whole container into a scratch region, and installs **4 fixed sub-slices** (at offsets from the table `DAT_0024ce80[4]`) into channels `0x2600..0x2603`. It then lazily loads a 5th part into channel `0x2604` **only if that channel is empty**, choosing the source by the offline flag `cRam00343577`:

- **Online (`flag == 0`):** build the follow-up name from parts 0x24ceb8/0x24ced0, load it (mode 1), and install its raw buffer directly into `0x2604`.
- **Offline (`flag != 0`):** build the follow-up name from format 0x24cef0 + the **session id** (`uRam0034357a`), load it (mode `0x10001`), then explicitly `decompress_record` the result before installing into `0x2604`.

The session id and the two source branches indicate part 5 is dynamic/per-session content (e.g. a room- or session-scoped list) with distinct online vs offline retrieval + decode paths.

## Input / output
- **Params:** none.
- **Returns:** void.

## Side effects
- Overwrites work buffer + the +0x100000 scratch.
- Binds channels `0x2600, 0x2601, 0x2602, 0x2603` (always, on base load) and conditionally `0x2604`.
- Reads `cRam00343577` (source mode) and `uRam0034357a` (session id).

## Important branches
- **`archive_load(0x24ce90) == 0`** → nothing installed.
- **Sub-slice loop** `do { install(0x2600+i, scratch + DAT_0024ce80[i]) } while (i < 4)` — exactly 4 sub-slices.
- **`slot_query(0x2604) == 0`** (5th channel empty) → attempt the follow-up load; otherwise skip (already present).
- **`cRam00343577 == 0`** → online branch: name = 0x24ceb8+0x24ced0, `archive_load(..., 1)`, install raw into 0x2604 (on success).
- **`cRam00343577 != 0`** → offline branch: name = sprintf(0x24cef0, session), `archive_load(..., 0x10001)`, then `decompress_record` into scratch, install into 0x2604 (on success).

## Constants & flags
- Channel base `0x2600`; 5 channels `0x2600..0x2604`.
- `DAT_0024ce80[4]` = byte offsets of the 4 sub-slices within the decompressed base container.
- Work scratch offset `0x100000` (1 MiB above base — larger than the 0x40000 used by the smaller loaders, sized for the whole decompressed container).
- **Load modes:** online part 5 = `1` (ARCHIVE_LOCAL, result used raw); offline part 5 = `0x10001` (ARCHIVE_ALT — result requires an explicit `decompress_record` before use). The `0x10000` bit correlates with "load compressed / decode-separately", **not** cleanly with remote-vs-local [inferred; note this refines the tentative "remote" reading in 0x1cf150].
- `cRam00343577`: 0 = online/default source, non-0 = offline/HDD source (polarity per GLOBALS "offline-mode" tag) [inferred].

## Corrected reconstruction
```c
extern const int32_t DAT_0024ce80[4];   // sub-slice byte offsets
static uint8_t g_offline_mode;           // cRam00343577
static uint32_t g_session_id;            // uRam0034357a

void load_multipart_list_into_2600_channels(void)
{
    uint32_t *work    = g_work;                    // iRam003435bc
    uint8_t  *scratch = (uint8_t*)work + 0x100000;
    char path[256];

    strcpy(path, build_localized_asset_path(BASE_MULTI /*0x24ce90*/));
    if (archive_load(path, work, ARCHIVE_LOCAL /*1*/, 0) == 0) return;

    decompress_record(work, scratch);              // unpack whole container
    uint8_t *slice = NULL;
    for (int i = 0; i < 4; i++) {
        slice = scratch + DAT_0024ce80[i];
        slot_install(0x2600 + i, slice);           // channels 0x2600..0x2603
    }

    if (slot_query(0x2604) != 0) return;           // 5th part already present

    if (g_offline_mode == 0) {                      // ONLINE
        char name[256];
        sprintf(name, /*0x24ceb8*/ FMT_ONLINE_5, /*0x24ced0*/ SUB_ONLINE_5, g_session_id);
        strcpy(path, build_localized_asset_path(name));
        if (archive_load(path, slice, ARCHIVE_LOCAL /*1*/, 0) != 0)
            slot_install(0x2604, slice);            // raw
    } else {                                        // OFFLINE
        char name[256];
        sprintf(name, /*0x24cef0*/ FMT_OFFLINE_5, g_session_id);
        strcpy(path, build_localized_asset_path(name));
        int ok = archive_load(path, slice, ARCHIVE_ALT /*0x10001*/, 0);
        decompress_record(slice, scratch);          // decode before install
        if (ok != 0)
            slot_install(0x2604, scratch);
    }
}
```

## Evidence
- Raw: `sources/executables/transport-decompile/FUN_001d1110.c` — 4-iteration `DAT_0024ce80[i]` install loop into `iVar6=0x2600++`; `FUN_001cbcb0(0x2604)` guard; `if (cRam00343577 == '\0')` online (mode 1, raw install) vs `else` offline (mode 0x10001, `FUN_001a79b0` then install); session id `uRam0034357a` in both follow-up names.
- Mode 1 vs 0x10001 pairing with/without a trailing `FUN_001a79b0` decode step is the direct evidence for the "0x10000 = decode-separately" reading.

## Remaining uncertainty
- Exact contents of `DAT_0024ce80` and the follow-up name format strings not dumped here.
- Offline branch installs `scratch` after `decompress_record`, but calls it even when `ok==0` (decodes stale data harmlessly since install is gated) — preserved as-is.
- Precise semantics of the `0x10000` load-mode bit and the offline flag polarity are inferred. Runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d1110.c`  — untouched decompiler output.
