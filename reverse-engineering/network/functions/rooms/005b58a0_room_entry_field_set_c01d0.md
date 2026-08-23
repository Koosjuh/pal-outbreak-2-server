# 0x005b58a0 room_sel_copy_u16_to_6c0762

| field | value |
|---|---|
| Original address | 0x005b58a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b58a0 |
| Resolved name | room_sel_copy_u16_to_6c0762 |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c0f00 (get_selected_id), FUN_005c01d0 (copy_u16 @src 0x6cfa1e)
**Referenced globals:** 0x6d2158 (selection cursor), src 0x6cfa1e (stride 0x144), dest 0x6c0762 (stride 0x15c)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006d2158

## Behavioral explanation
Room-config field-marshal family, `u16` variant. Copies the `u16` at source offset 0x6cfa1e of
record[`sel`] into entry `sel-1` of dest table 0x6c0762. Offset 0x6cfa1e sits just below the
0x6cfa22-0x6cfa2a five-field block that sibling 58e0 copies, so this is the head field of that
config cluster.

## Input / output
- Input: implicit cursor 0x6d2158. Output: `void`.

## Side effects
- Writes one `u16` at `(sel-1)*0x15c + 0x6c0762`.

## Important branches
None. Source indexed `idx*0x144`.

## Constants & flags
- `0x144`/`0x15c` strides. Field 0x6cfa1e.

## Corrected reconstruction
```c
// helper FUN_005c01d0
u32 room_copy_u16_6cfa1e(u16 idx, u16 *out) {
    *out = *(u16*)((idx & 0xffff) * 0x144 + 0x6cfa1e);
    return 0;
}

void room_sel_copy_u16_to_6c0762(void) {
    u16 sel;
    get_selected_id(&sel);
    room_copy_u16_6cfa1e(sel, (u16*)((sel - 1) * 0x15c + 0x6c0762));
}
```

## Evidence
- `FUN_005b58a0.c`: `FUN_005c01d0(uStack_2,(uStack_2-1)*0x15c+0x6c0762);`
- `FUN_005c01d0.c`: `*param_2 = *(undefined2*)((param_1&0xffff)*0x144 + 0x6cfa1e);`
- Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b58a0.c`  — untouched decompiler output.

## Remaining uncertainty
Field semantics unknown; not runtime-confirmed.
