# 0x005bea90 register_room_handler_once

| field | value |
|---|---|
| Original address | 0x005bea90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bea90 |
| Resolved name | register_room_handler_once |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ade20, FUN_005b4a50
**Callees:** —
**Referenced globals:** 0x6cbaf4 install guard (u8); 0x6cbe4a 464-byte handler record; 0x6cbad0 callback ptr (=FUN_005befa0); 0x6cbad4 user param; 0x6cbaf0 (u32, zeroed)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cbaf4 install guard

## Behavioral explanation
One-shot installer for a 464-byte (0xe8 halfwords) room/dispatch handler descriptor. The caller passes a
pointer to a 0x1d0-byte source record and a user param. The function first copies the record onto a local
stack scratch, then — **only if the global install guard 0x6cbaf4 is still clear** — copies the same record
into the persistent global slot at 0x6cbe4a, latches the completion callback pointer 0x6cbad0 = FUN_005befa0,
stores the user param at 0x6cbad4, zeroes 0x6cbaf0, and sets the guard. Idempotent: a second call returns -1
and does nothing. The stack copy is a decompiler artifact of the two-stage halfword copy loop (source →
scratch → global); net effect is source record → 0x6cbe4a.

## Input / output
- `param_1` (undefined1* → record[0x1d0]): source handler descriptor to install.
- `param_2` (undefined4): user param stored at 0x6cbad4 (passed later to the callback).
- **returns** 0 on first install, 0xffffffff (-1) if already installed.

## Side effects
- On first call: writes 0x6cbe4a[0..0x1d0], 0x6cbad0=FUN_005befa0, 0x6cbaf0=0, 0x6cbad4=param_2, 0x6cbaf4=1.
- No packets; pure state registration.

## Important branches
- `cRam006cbaf4 == 0` (guard clear) → perform install, ret 0.
- else → skip install, ret -1 (guard already latched this session).

## Constants & flags
- 0xe8 = 232 halfword iterations = 0x1d0 (464) bytes copied.
- 0x6cbaf4 install-guard: 0 = not yet installed, 1 = installed.

## Corrected reconstruction
```c
// 464-byte handler descriptor installed once per session.
typedef unsigned char handler_record[0x1d0];   // [inferred] exact field layout unknown

extern u8            g_room_handler_installed;  // 0x006cbaf4
extern handler_record g_room_handler;           // 0x006cbe4a
extern void        (*g_room_handler_cb)(void);  // 0x006cbad0
extern u32           g_room_handler_flag;        // 0x006cbaf0
extern u32           g_room_handler_userparam;   // 0x006cbad4

int register_room_handler_once(const handler_record *src, u32 user_param) {
    handler_record scratch;
    memcpy_hw(&scratch, src, 0x1d0);            // stage copy (decompiler-visible; scratch unused after)

    if (g_room_handler_installed != 0)
        return -1;                              // already installed this session

    memcpy_hw(&g_room_handler, &scratch, 0x1d0);
    g_room_handler_installed = 1;
    g_room_handler_cb        = FUN_005befa0;     // completion callback
    g_room_handler_flag      = 0;
    g_room_handler_userparam = user_param;
    return 0;
}
```

## Evidence
- Raw decompile: two unrolled 0xe8-count halfword copy loops; guard/callback stores at 0x6cbaf4/0x6cbad0/
  0x6cbad4/0x6cbaf0; dest 0x6cbe4a.
- Callback target FUN_005befa0 taken by address. Callers FUN_005ade20/FUN_005b4a50 are screen-init paths.
- Runtime-unvalidated.

## Remaining uncertainty
- Semantic content of the 464-byte descriptor (menu/dispatch vtable vs room config) not decoded.
- Whether the guard is ever cleared (re-registration on screen re-entry) — not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bea90.c`  — untouched decompiler output.
