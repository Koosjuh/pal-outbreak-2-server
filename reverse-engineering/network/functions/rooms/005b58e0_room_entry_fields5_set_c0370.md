# 0x005b58e0 room_sel_copy_5u16_to_6c0764

| field | value |
|---|---|
| Original address | 0x005b58e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b58e0 |
| Resolved name | room_sel_copy_5u16_to_6c0764 |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c0f00 (get_selected_id), FUN_005c0370 (copy 5×u16 @src 0x6cfa22..2a)
**Referenced globals:** 0x6d2158 (selection cursor), src 0x6cfa22/24/26/28/2a (stride 0x144), dest 0x6c0764/66/68/6a/6c (stride 0x15c)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006d2158

## Behavioral explanation
Room-config field-marshal family, **five-field** variant. Copies five contiguous `u16` values
(source 0x6cfa22, 0x6cfa24, 0x6cfa26, 0x6cfa28, 0x6cfa2a) of record[`sel`] into five contiguous
`u16` slots (dest 0x6c0764..0x6c076c) of entry `sel-1`. The base index `(sel-1)*0x15c` is computed
once and reused for all five destinations. This block (with sibling 58a0's 0x6cfa1e head and
5f60's trailing 0x6cfa2c/2e pair) forms a 7- or 8-word config sub-record — plausibly the
room-parameter vector (scenario/rules/limits), though semantics are unconfirmed.

## Input / output
- Input: implicit cursor 0x6d2158. Output: `void`.

## Side effects
- Writes five `u16`s at dest base `(sel-1)*0x15c + 0x6c0764` (+0,+2,+4,+6,+8).

## Important branches
None (straight-line, 5 assignments). Source indexed `idx*0x144`.

## Constants & flags
- `0x144`/`0x15c` strides. Fields 0x6cfa22/24/26/28/2a.

## Corrected reconstruction
```c
// helper FUN_005c0370
u32 room_copy_5u16_6cfa22(u16 idx, u16 *a, u16 *b, u16 *c, u16 *d, u16 *e) {
    int base = (idx & 0xffff) * 0x144;
    *a = *(u16*)(base + 0x6cfa22);
    *b = *(u16*)(base + 0x6cfa24);
    *c = *(u16*)(base + 0x6cfa26);
    *d = *(u16*)(base + 0x6cfa28);
    *e = *(u16*)(base + 0x6cfa2a);
    return 0;
}

void room_sel_copy_5u16_to_6c0764(void) {
    u16 sel;
    get_selected_id(&sel);
    int d = (sel - 1) * 0x15c;
    room_copy_5u16_6cfa22(sel,
        (u16*)(d + 0x6c0764), (u16*)(d + 0x6c0766), (u16*)(d + 0x6c0768),
        (u16*)(d + 0x6c076a), (u16*)(d + 0x6c076c));
}
```

## Evidence
- `FUN_005b58e0.c`: `iVar1=(uStack_2-1)*0x15c; FUN_005c0370(uStack_2,iVar1+0x6c0764,...,iVar1+0x6c076c);`
- `FUN_005c0370.c`: five `*(undefined2*)(iVar1 + 0x6cfa22..2a)` reads, `iVar1=(param_1&0xffff)*0x144`.
- Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b58e0.c`  — untouched decompiler output.

## Remaining uncertainty
Individual field meanings within the 5-word block unknown; grouping as a room-parameter vector is
inference, not confirmed.
