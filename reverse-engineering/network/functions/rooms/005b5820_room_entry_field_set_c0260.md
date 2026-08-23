# 0x005b5820 room_sel_copy_name_to_6c0778

| field | value |
|---|---|
| Original address | 0x005b5820 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b5820 |
| Resolved name | room_sel_copy_name_to_6c0778 |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c0f00 (get_selected_id), FUN_005c0260 (strcpy field @src 0x6cfb76)
**Referenced globals:** 0x6d2158 (selection cursor), src table 0x6cfb76 (stride 0x144), dest table 0x6c0778 (stride 0x15c)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006d2158

## Behavioral explanation
Room-config field-marshal family, **string** variant. Reads the selection cursor
`sel = *(u16*)0x6d2158`, then `strcpy`s the name/label string of record[`sel`] from the source
table (field base 0x6cfb76, stride 0x144) into entry `sel-1` of the destination display table
(base 0x6c0778, stride 0x15c). This is the human-readable room title/label copy — the string
counterpart to the scalar siblings (5860/58a0/58e0/5930/5970).

## Input / output
- Input: none (implicit selection cursor 0x6d2158).
- Output: `void`. Side-effect only.

## Side effects
- Writes a NUL-terminated string into `(sel-1)*0x15c + 0x6c0778` (destination buffer length not
  bounded here; trusted-length copy).

## Important branches
None (straight-line). Note the helper indexes the source with `((idx&0xffff)-1)*0x144` — i.e. it
subtracts 1 before scaling, unlike the scalar siblings which use `idx*0x144`. Kept exactly.

## Constants & flags
- `0x144`/`0x15c` strides. Copy primitive `func_0x00109eb8` = strcpy(dst, src) [inferred].

## Corrected reconstruction
```c
// helper FUN_005c0260 — strcpy the name field of record[idx-1]
u32 room_copy_name_6cfb76(u16 idx, char *dst) {
    strcpy(dst, (char*)(((idx & 0xffff) - 1) * 0x144 + 0x6cfb76));  // func_0x00109eb8
    return 0;
}

void room_sel_copy_name_to_6c0778(void) {
    u16 sel;
    get_selected_id(&sel);                                  // *(u16*)0x6d2158
    room_copy_name_6cfb76(sel, (char*)((sel - 1) * 0x15c + 0x6c0778));
}
```

## Evidence
- `FUN_005b5820.c`: `FUN_005c0f00(&uStack_2); FUN_005c0260(uStack_2,(uStack_2-1)*0x15c+0x6c0778);`
- `FUN_005c0260.c`: `func_0x00109eb8(param_2,((param_1&0xffff)-1)*0x144 + 0x6cfb76);`
- Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b5820.c`  — untouched decompiler output.

## Remaining uncertainty
`func_0x00109eb8` assumed strcpy (2-arg, dst,src pattern); destination capacity unknown. Field
semantics (room title vs. other label) not runtime-confirmed.
