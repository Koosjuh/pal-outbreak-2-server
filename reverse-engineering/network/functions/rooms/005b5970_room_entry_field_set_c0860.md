# 0x005b5970 room_sel_copy_u32_to_6c0774

| field | value |
|---|---|
| Original address | 0x005b5970 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b5970 |
| Resolved name | room_sel_copy_u32_to_6c0774 |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c0f00 (get_selected_id), FUN_005c0860 (copy_u32 @src 0x6cfa18)
**Referenced globals:** 0x6d2158 (selection cursor), src 0x6cfa18 (stride 0x144), dest 0x6c0774 (stride 0x15c)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006d2158

## Behavioral explanation
Room-config field-marshal family, `u32` variant. Copies the 4-byte word at source offset 0x6cfa18
of record[`sel`] into entry `sel-1` of dest table 0x6c0774. 0x6cfa18 is the lowest offset of the
0x6cfa1x config cluster — a 32-bit field (candidate: room handle / id / owner token), copied
whole here while the siblings copy the u16/u8 members above it.

## Input / output
- Input: implicit cursor 0x6d2158. Output: `void`.

## Side effects
- Writes one `u32` at `(sel-1)*0x15c + 0x6c0774`.

## Important branches
None. Source indexed `idx*0x144`.

## Constants & flags
- `0x144`/`0x15c` strides. 32-bit field 0x6cfa18.

## Corrected reconstruction
```c
// helper FUN_005c0860
u32 room_copy_u32_6cfa18(u16 idx, u32 *out) {
    *out = *(u32*)((idx & 0xffff) * 0x144 + 0x6cfa18);
    return 0;
}

void room_sel_copy_u32_to_6c0774(void) {
    u16 sel;
    get_selected_id(&sel);
    room_copy_u32_6cfa18(sel, (u32*)((sel - 1) * 0x15c + 0x6c0774));
}
```

## Evidence
- `FUN_005b5970.c`: `FUN_005c0860(uStack_2,(uStack_2-1)*0x15c+0x6c0774);`
- `FUN_005c0860.c`: `*param_2 = *(undefined4*)((param_1&0xffff)*0x144 + 0x6cfa18);`
- Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b5970.c`  — untouched decompiler output.

## Remaining uncertainty
The u32 could be a handle/id/token or a packed flag word; not runtime-confirmed.
