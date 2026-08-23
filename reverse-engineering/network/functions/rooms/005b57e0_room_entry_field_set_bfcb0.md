# 0x005b57e0 room_sel_copy_u16_to_6c3032

| field | value |
|---|---|
| Original address | 0x005b57e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b57e0 |
| Resolved name | room_sel_copy_u16_to_6c3032 |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c0f00 (get_selected_id), FUN_005bfcb0 (copy_u16 @src 0x6cf142)
**Referenced globals:** 0x6d2158 (selection cursor), src table 0x6cf142 (stride 0x144), dest table 0x6c3032 (stride 0x15c)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006d2158

## Behavioral explanation
One member of the room-config field-marshal family. Reads the current selection cursor
`sel = *(u16*)0x6d2158` (1-based), then copies a single `u16` field of record[`sel`] from the
source config table (base 0x6cf142, stride 0x144 = 324) into entry `sel-1` of the destination
display/UI table (base 0x6c3032, stride 0x15c = 348). Pure per-selection scalar copy; no packet,
no branch.

## Input / output
- Input: none (implicit — global selection cursor 0x6d2158).
- Output: `void`. Side-effect only.

## Side effects
- Writes one `u16` at `(sel-1)*0x15c + 0x6c3032`.

## Important branches
None. Straight-line: fetch cursor -> copy field. (No bounds check on `sel`; caller is trusted
to have a valid 1-based selection.)

## Constants & flags
- `0x144` (324) source-record stride; `0x15c` (348) destination-record stride.
- Field offset within source record is folded into the base `0x6cf142` (this field lives in a
  different sub-table from the 0x6cfa1x cluster used by the siblings).

## Corrected reconstruction
```c
// helper FUN_005bfcb0 — generic "read u16 field @0x6cf142 of record[idx]"
u32 room_copy_u16_6cf142(u16 idx, u16 *out) {   // [inferred] out is a u16 sink
    *out = *(u16*)((idx & 0xffff) * 0x144 + 0x6cf142);
    return 0;
}
// helper FUN_005c0f00 — read the global selection cursor
u32 get_selected_id(u16 *out) { *out = *(u16*)0x6d2158; return 0; }

void room_sel_copy_u16_to_6c3032(void) {
    u16 sel;
    get_selected_id(&sel);                                  // sel = *(u16*)0x6d2158, 1-based
    room_copy_u16_6cf142(sel, (u16*)((sel - 1) * 0x15c + 0x6c3032));
}
```

## Evidence
- `FUN_005b57e0.c`: `FUN_005c0f00(&uStack_2); FUN_005bfcb0(uStack_2,(uStack_2-1)*0x15c+0x6c3032);`
- `FUN_005bfcb0.c`: `*param_2 = *(undefined2*)((param_1&0xffff)*0x144 + 0x6cf142);`
- `FUN_005c0f00.c`: `*param_1 = uRam006d2158;`
- Runtime-unvalidated (static reconstruction).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b57e0.c`  — untouched decompiler output.

## Remaining uncertainty
Which of the two tables is master vs. derived, and the domain meaning of the copied field
(the 0x6cf142 sub-table is distinct from the 0x6cfa1x room-config cluster). No runtime trace.
