# 0x005b5930 room_sel_copy_u8_to_6c076f

| field | value |
|---|---|
| Original address | 0x005b5930 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b5930 |
| Resolved name | room_sel_copy_u8_to_6c076f |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c0f00 (get_selected_id), FUN_005c09c0 (copy_u8 @src 0x6cfa31)
**Referenced globals:** 0x6d2158 (selection cursor), src 0x6cfa31 (stride 0x144), dest 0x6c076f (stride 0x15c)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006d2158

## Behavioral explanation
Room-config field-marshal family, `u8` variant — the second of the adjacent byte pair (0x6cfa31,
immediately after 0x6cfa30 handled by sibling 5860). Copies that byte of record[`sel`] into
entry `sel-1` of dest table 0x6c076f (stride 0x15c). Dest 0x6c076f is likewise adjacent to
0x6c076e, preserving the source layout.

## Input / output
- Input: implicit cursor 0x6d2158. Output: `void`.

## Side effects
- Writes one `u8` at `(sel-1)*0x15c + 0x6c076f`.

## Important branches
None. Source indexed `idx*0x144`.

## Constants & flags
- `0x144`/`0x15c` strides. Byte field 0x6cfa31.

## Corrected reconstruction
```c
// helper FUN_005c09c0
u32 room_copy_u8_6cfa31(u16 idx, u8 *out) {
    *out = *(u8*)((idx & 0xffff) * 0x144 + 0x6cfa31);
    return 0;
}

void room_sel_copy_u8_to_6c076f(void) {
    u16 sel;
    get_selected_id(&sel);
    room_copy_u8_6cfa31(sel, (u8*)((sel - 1) * 0x15c + 0x6c076f));
}
```

## Evidence
- `FUN_005b5930.c`: `FUN_005c09c0(uStack_2,(uStack_2-1)*0x15c+0x6c076f);`
- `FUN_005c09c0.c`: `*param_2 = *(undefined1*)((param_1&0xffff)*0x144 + 0x6cfa31);`
- Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b5930.c`  — untouched decompiler output.

## Remaining uncertainty
Field semantics unknown; not runtime-confirmed.
