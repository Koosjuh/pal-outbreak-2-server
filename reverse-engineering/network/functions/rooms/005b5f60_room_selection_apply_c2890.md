# 0x005b5f60 room_sel_apply_2u16_to_screen

| field | value |
|---|---|
| Original address | 0x005b5f60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b5f60 |
| Resolved name | room_sel_apply_2u16_to_screen |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c0f00 (get_selected_id), FUN_005c2890 (copy 2×u16 @src 0x6cfa2c/2e)
**Referenced globals:** cRam006c4b90 (screen_id — lobby_state_block), 0x6d2158 (selection cursor), src 0x6cfa2c/2e (stride 0x144), dest scalars 0x6c4fe6/0x6c4fe8
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90, uRam006d2158

## Behavioral explanation
Screen-gated variant of the config-marshal family. **Only when the active screen is a room screen**
(`screen_id == 0x04` or `0x0e`) it reads the selection cursor and copies the trailing two `u16`s of
the config record (source 0x6cfa2c, 0x6cfa2e — the pair directly after 58e0's 5-word block) into
two **scalar** globals 0x6c4fe6 / 0x6c4fe8 (not the per-entry 0x15c table). I.e. it promotes the
selected room's last two config words into active-screen state. The callee `FUN_005c2890` also
guards `idx != 0`, so a zero selection is a no-op.

## Input / output
- Input: implicit `screen_id` (0x6c4b90) and selection cursor (0x6d2158).
- Output: `void`.

## Side effects
- Writes `u16` 0x6c4fe6 and `u16` 0x6c4fe8 — but only under the screen gate and non-zero index.

## Important branches
- `screen_id != 0x04 && screen_id != 0x0e` -> return without touching anything (gate: apply only on
  room screens 4/0x0e — see lobby_state_block `screen_id`).
- Inside callee: `idx == 0` -> skip both writes (defensive: no selection).

## Constants & flags
- `0x04`, `0x0e` = room-screen `screen_id` values (lobby_state_block @0x6c4b90).
- `0x144` source stride. Fields 0x6cfa2c / 0x6cfa2e.

## Corrected reconstruction
```c
// helper FUN_005c2890
u32 room_copy_2u16_6cfa2c(u16 idx, u16 *a, u16 *b) {
    if (idx != 0) {                                   // defensive: skip empty selection
        int base = (idx & 0xffff) * 0x144;
        *a = *(u16*)(base + 0x6cfa2c);
        *b = *(u16*)(base + 0x6cfa2e);
    }
    return 0;
}

void room_sel_apply_2u16_to_screen(void) {
    u8 screen = *(u8*)0x6c4b90;                        // lobby_state_block.screen_id
    if (screen == 0x04 || screen == 0x0e) {            // room screens only
        u16 sel;
        get_selected_id(&sel);
        room_copy_2u16_6cfa2c(sel, (u16*)0x6c4fe6, (u16*)0x6c4fe8);
    }
}
```

## Evidence
- `FUN_005b5f60.c`: `if ((cRam006c4b90=='\x04')||(cRam006c4b90=='\x0e')) { FUN_005c0f00(&uStack_2); FUN_005c2890(uStack_2,0x6c4fe6,0x6c4fe8); }`
- `FUN_005c2890.c`: `if (param_1!=0){ ... *param_2=*(u16*)(iVar1+0x6cfa2c); *param_3=*(u16*)(iVar1+0x6cfa2e);}`
- screen_id 0x04/0x0e as room screens: structure-layouts/lobby_state_block.md.
- Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b5f60.c`  — untouched decompiler output.

## Remaining uncertainty
Meaning of 0x6c4fe6/0x6c4fe8 (candidate: current/selected scenario or cursor coordinates) not
confirmed; the two source words complete the 0x6cfa18..2e config sub-record but their roles are
unproven.
