# 0x005c4ce0 copy_roomlist_buffer_out

| field | value |
|---|---|
| Original address | 0x005c4ce0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c4ce0 |
| Resolved name | copy_buffer_out_6fc2d8 |
| Subsystem | rooms |
| Relevance | helper |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b5fb0
**Callees:** —
**Referenced globals:** 0x6fc2d8 = source buffer (784 bytes)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Snapshots a fixed 784-byte (0x188 halfwords) buffer from global 0x6fc2d8 into the caller's destination via
the standard unrolled halfword copy loop (same shape as copy_chat_buffer_out / register_room_handler_once).
It is a straight memcpy with no transformation. The single caller FUN_005b5fb0 is a room/lobby UI path, so
0x6fc2d8 is a room-screen scratch/list buffer being handed to the caller for display or further processing.

## Input / output
- `param_1` (undefined1* dst): receives the 784 bytes.
- **returns** void.

## Side effects
- Writes 0x310 (784) bytes to caller's dst; reads 0x6fc2d8[0..784].

## Important branches
- None (fixed-count unrolled copy; loop runs 0x188 iterations of 2 bytes).

## Constants & flags
- 0x188 = 392 halfword iterations → 784 bytes total.
- 0x6fc2d8 = source base.

## Corrected reconstruction
```c
extern u8 g_room_scratch_6fc2d8[784];   // 0x006fc2d8

void copy_buffer_out_6fc2d8(u8 *dst) {
    memcpy(dst, g_room_scratch_6fc2d8, 0x310);   // 784 bytes, decompiled as 0x188 x 2-byte copies
}
```

## Evidence
- Raw decompile: `iVar2 = 0x188; puVar3 = 0x6fc2d8;` two-byte copy loop → 784 bytes.
- Copy idiom identical to other fixed snapshot helpers in the overlay. Runtime-unvalidated.

## Remaining uncertainty
- Exact identity/layout of the 0x6fc2d8 buffer (room-list page vs a display scratch) — name kept address-based
  (`copy_buffer_out_6fc2d8`) rather than asserting "roomlist" without evidence.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c4ce0.c`  — untouched decompiler output.
