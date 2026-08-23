# 0x00615430 restore_room_config_form (was roster_table_restore)

| field | value |
|---|---|
| Original address | 0x00615430 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00615430 |
| Resolved name | restore_room_config_form |
| Subsystem | rooms |
| Relevance | helper |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

> Name refined: the destination `iRam0070d1c0+0xed0` is the room-create **config/form working area** (the fields `pack_room_config_globals` reads: +0xed0/+0xed4/+0xed6/+0xed8/+0xfd8), not a roster. This restores a saved 520-byte form snapshot; the inverse writer is `FUN_00615470`.

**Callers:** FUN_0060f910, FUN_00610830 (room_create_menu_sm)
**Callees:** — (inline word-copy)
**Referenced globals:** 0x3c9594 (source snapshot/template); iRam0070d1c0+0xed0 (destination form area)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0070d1c0+0xed0 room-config form

## Behavioral explanation
Copies a fixed 520-byte block (65 iterations × 8 bytes) from `0x3c9594` into the room-config working form at `iRam0070d1c0+0xed0`. The loop copies two 32-bit words per iteration. This restores a previously-saved (or template) room-create form so the create/edit screen re-opens with the last-entered values; `FUN_00615470` performs the matching backup in the opposite direction.

## Input / output
- No parameters. Returns `void`.

## Side effects
- Overwrites `iRam0070d1c0+0xed0 .. +0x2d7` (520 bytes) with the contents of `0x3c9594`.

## Important branches
- None — a straight `do/while` count-down copy (`iVar2` from 0x41 down through 0, 65 iterations).

## Constants & flags
- Iteration count `0x41` (65); per-iteration `8` bytes → total `520` (0x208) bytes.

## Corrected reconstruction
```c
// Restore the 520-byte room-create config form from its snapshot/template.
void restore_room_config_form(void) {
    uint32_t *src = (uint32_t*)0x3c9594;
    uint32_t *dst = (uint32_t*)((char*)iRam0070d1c0 + 0xed0);
    for (int i = 0x41; i > 0; i--) {   // 65 iterations, 8 bytes each
        dst[0] = src[0];
        dst[1] = src[1];
        src += 2;
        dst += 2;
    }
}
```

## Evidence
- Raw: `FUN_00615430.c` (64 bytes) — iteration count and 8-byte stride exact.
- Destination `+0xed0` is the same working area read by `pack_room_config_globals` (0x006150b0), tying it to the room-create form rather than a roster.
- Paired inverse: `FUN_00615470` (backup).

## Remaining uncertainty
- Whether `0x3c9594` is a persistent last-used snapshot vs a static default template is unresolved (near `0x3c9580` link buffer per GLOBALS). Field layout of the 520-byte form not fully enumerated. Name change is inferential; confidence Medium. Not runtime-validated.
