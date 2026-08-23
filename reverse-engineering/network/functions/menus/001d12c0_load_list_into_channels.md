# 0x001d12c0 load_list_into_channels

| field | value |
|---|---|
| Original address | 0x001d12c0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d12c0 |
| Resolved name | load_two_archives_into_fixed_channels |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109eb8 (strcpy), FUN_001cb360 (archive_load), FUN_001a79b0 (decompress_record), FUN_001cb5f0 (slot_install)
**Referenced globals:** piRam003435bc (work buffer; scratch = base+0x40000)
**Referenced strings:** 0x24cf00 (archive-A name), 0x24cf20 (archive-B name)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Loads two archives into a fixed channel layout. From archive-A (0x24cf00, used **verbatim** — note: this loader copies the raw name, it does **not** go through `build_localized_asset_path`), it installs up to the first 4 records into channel slots 1,2,3 with the **4th (last processed) record routed to slot 10** instead of slot 4. Then it loads archive-B (0x24cf20) and installs its raw loaded buffer into channel slot 5. The special "last → slot 10" routing is a fixed menu layout convention (slot 10 = a distinguished tail/aggregate entry).

## Input / output
- **Params:** none.
- **Returns:** void.

## Side effects
- Overwrites work buffer + scratch; binds channel slots {1,2,3,10} (from A) and {5} (from B, raw).
- Second load overwrites the work buffer before slot 5 is bound to it.

## Important branches
- **`archive_load(A) == 0`** → do nothing.
- **Record count clamp:** `iVar7 = min(count, 4)` — never installs more than 4 records from A.
- **Last-record routing:** `if (i == n-1) slot = 10; else slot = running` — the final of the ≤4 records goes to slot 10; the running slot counter otherwise assigns 1,2,3…
- **`archive_load(B) != 0`** → `slot_install(5, work)` — installs B's raw work buffer (no decompress step) into slot 5.

## Constants & flags
- Clamp `4`; special slot `10`; B slot `5`.
- `archive_load` mode `1` (ARCHIVE_LOCAL) for both.
- Names passed **without** localization (raw `strcpy`/direct pointer) — unlike the 0x24ce50 loaders.

## Corrected reconstruction
```c
void load_two_archives_into_fixed_channels(void)
{
    uint32_t *work    = g_work;
    uint8_t  *scratch = (uint8_t*)work + 0x40000;
    char path[256];

    strcpy(path, NAME_A /*0x24cf00, verbatim*/);
    if (archive_load(path, work, ARCHIVE_LOCAL /*1*/, 0) != 0) {
        int n = work[1]; if (n > 4) n = 4;                 // clamp to 4
        int running = 1;
        uint32_t *rec = work;
        for (int i = 0; i < n; i++) {
            rec += 2;                                       // record[i] pair
            decompress_record((uint8_t*)work + *rec, scratch);
            int slot = (i == n - 1) ? 10 : running;         // last -> slot 10
            running  = slot + 1;
            slot_install(slot, scratch);
        }
        // NOTE: archive-B name 0x24cf20 used verbatim; B's raw buffer -> slot 5
        if (archive_load(NAME_B /*0x24cf20*/, work, ARCHIVE_LOCAL /*1*/, 0) != 0)
            slot_install(5, work);
    }
}
```

## Evidence
- Raw: `sources/executables/transport-decompile/FUN_001d12c0.c` — `if (4 < iVar7) iVar7 = 4`, `if (iVar5 == iVar7 + -1) iVar4 = 10`, `FUN_001cb5f0(iVar4, piVar9)`, second `FUN_001cb360(0x24cf20, work, 1, 0)` then `FUN_001cb5f0(5, piVar2=work)`.
- `FUN_00109eb8(auStack_100, 0x24cf00)` copies the raw name (no `FUN_001cf2b0` localization) — distinguishes this loader from the 0x24ce50 family.

## Remaining uncertainty
- Slot-10 routing meaning (aggregate/"All" entry?) is a convention guess.
- Whether slot 5 intentionally holds an un-decompressed buffer or the decompiler dropped a `decompress_record` call — the code as written installs `work` directly. Runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d12c0.c`  — untouched decompiler output.
