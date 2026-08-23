# 0x005b5860 room_sel_copy_u8_to_6c076e

| field | value |
|---|---|
| Original address | 0x005b5860 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b5860 |
| Resolved name | room_sel_copy_u8_to_6c076e |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c0f00 (get_selected_id), FUN_005c0210 (copy_u8 @src 0x6cfa30)
**Referenced globals:** 0x6d2158 (selection cursor), src 0x6cfa30 (stride 0x144), dest 0x6c076e (stride 0x15c)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006d2158

## Behavioral explanation
Room-config field-marshal family, `u8` variant. Reads selection cursor `sel`, copies one byte of
record[`sel`] from source field 0x6cfa30 (stride 0x144) into entry `sel-1` of destination table
0x6c076e (stride 0x15c). Field 0x6cfa30 is the first of the two adjacent bytes in the config
record (paired with 0x6cfa31, copied by sibling 5930).

## Input / output
- Input: implicit selection cursor 0x6d2158. Output: `void`.

## Side effects
- Writes one `u8` at `(sel-1)*0x15c + 0x6c076e`.

## Important branches
None. Helper indexes source with `idx*0x144` (no -1), unlike the string sibling.

## Constants & flags
- `0x144`/`0x15c` strides. Byte field 0x6cfa30.

## Corrected reconstruction
```c
// helper FUN_005c0210
u32 room_copy_u8_6cfa30(u16 idx, u8 *out) {
    *out = *(u8*)((idx & 0xffff) * 0x144 + 0x6cfa30);
    return 0;
}

void room_sel_copy_u8_to_6c076e(void) {
    u16 sel;
    get_selected_id(&sel);
    room_copy_u8_6cfa30(sel, (u8*)((sel - 1) * 0x15c + 0x6c076e));
}
```

## Evidence
- `FUN_005b5860.c`: `FUN_005c0210(uStack_2,(uStack_2-1)*0x15c+0x6c076e);`
- `FUN_005c0210.c`: `*param_2 = *(undefined1*)((param_1&0xffff)*0x144 + 0x6cfa30);`
- Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b5860.c`  — untouched decompiler output.

## Remaining uncertainty
Meaning of the byte field (a mode/flag/count) unknown; not runtime-confirmed.
