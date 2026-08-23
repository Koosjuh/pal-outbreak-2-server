# 0x005bb060 record_ptr_0x34

| field | value |
|---|---|
| Original address | 0x005bb060 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bb060 |
| Resolved name | record_ptr_0x34_name |
| Subsystem | roster |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005affb0, FUN_005ba5b0
**Callees:** FUN_005bac60 (table-base fetch)
**Referenced globals:** 0x006c5480 (pointer array of record-table snapshots; `FUN_005bac60(0)` = current)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns a **pointer** to the +0x34 field of the current-snapshot 0x1e4-stride record. In
`record_changed_diff` (0x005bb0b0) this field is compared with `strcmp` (`func_0x00109d70`), proving
it is a NUL-terminated **string** — the record's display name/title. Callers `FUN_005affb0` /
`FUN_005ba5b0` take the pointer to draw or strcmp the name.

## Input / output
- `param_1` (uint) — record index (`& 0xffff`).
- Returns `char*` — `&record[index].name_0x34` (points into the live current snapshot). No bounds check.

## Side effects
None (pure address computation); returned pointer aliases mutable table memory.

## Important branches
None. Only the `& 0xffff` index truncation.

## Constants & flags
- `0x1e4` — record stride. `0x34` — field offset. Field is a C string (strcmp'd in the diff).

## Corrected reconstruction
```c
// name_0x34 is a NUL-terminated string (record_changed_diff strcmp's it)
char *record_ptr_0x34_name(uint index /*&0xffff*/) {
    lobby_record *cur = (lobby_record *)record_table_ptr[0];   // FUN_005bac60(0)
    return cur[index & 0xffff].name_0x34;                      // base + idx*0x1e4 + 0x34
}
```

## Evidence
- Raw decompile: `return base + (param_1&0xffff)*0x1e4 + 0x34` (address).
- `record_changed_diff` calls `func_0x00109d70(pcVar6+0x34, pcVar5+0x34)` = strcmp → string field.
- Runtime-unvalidated (static only).

## Remaining uncertainty
- Whether it is the room title vs a player name depends on the (inferred) record domain identity.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bb060.c`  — untouched decompiler output.
