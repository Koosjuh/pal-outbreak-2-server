# 0x005bffa0 start_maxi_user_register_txn

| field | value |
|---|---|
| Original address | 0x005bffa0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bffa0 |
| Resolved name | start_registerB_user_txn |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe500, FUN_005fe8d0, FUN_0062e440 (room-list / member machines)
**Callees:** FUN_005be0a0 (alloc request-table slot), FUN_005c1e70 (build op0x7b selector)
**Referenced globals:** 0x6ca97c req-table selector (stride 0x20); 0x6ca97e req-table txn id; registry-B 0x6fee68 (stride 0x24, +0 room handle/id)
**Referenced strings:** `USER` (0x55534552)
**Referenced opcodes:** 0x09 (USER register, via func_0x001dd5f8 unreliable); 0x7b selector (FUN_005c1e70)
**State vars:** —

## Behavioral explanation
Initiates a **USER register** transaction keyed off **registry-B** (the room-handle registry, 30 × 0x24 @0x6fee68). Same launcher shape as `start_enter_txn`/`start_leave_txn`: allocate a request-table slot (`FUN_005be0a0`; -1 = abort), build the op0x7b selector (`FUN_005c1e70(2, param_1)`), then send an **op09 USER register** (unreliable variant `func_0x001dd5f8`) carrying the registry-B entry's id (`*(u32*)((param_1&0xffff)*0x24 + 0x6fee68)`) and the `"USER"` tag, with reply cb `0x5c0060`. Records the selector + txn id into the request table (stride 0x20) and returns the slot index. Distinct from the room_stat_register_sm USER send: that one keys off registry-A and uses the reliable op09; this one keys off registry-B (a selected room-list handle) and the unreliable op09 — the register issued when acting on a room chosen from the list.

## Input / output
- `param_1` (u32): registry-B index (low 16 bits) → keys the room handle/id.
- `param_2` (u32): allocation context/key for `FUN_005be0a0`.
- Returns `long`: allocated request-slot index, or `-1` if the table is full.

## Side effects
- `reqTable[slot].selector (0x6ca97c) = op7b selector`.
- `reqTable[slot].txnId (0x6ca97e) = ` id returned by the op09 send.
- Emits **op09 USER register** (unreliable) with the registry-B id; arms cb `0x5c0060`.

## Important branches
- **FUN_005be0a0 == -1** → return -1, send nothing.
- **else** → build selector + send + record txn, return slot index.

## Constants & flags
- Request table stride `0x20` (selector 0x6ca97c, txn 0x6ca97e).
- Registry-B stride `0x24`, room handle/id at `+0` (base 0x6fee68).
- Tag `"USER"` = 0x55534552.
- `func_0x001dd5f8` = snap_send_op09_unrel (op09, who 0xa000, two htonl u32).
- `FUN_005c1e70(2, …)` = op0x7b selector.

## Corrected reconstruction
```c
// registry-B (room handles): base 0x6fee68, stride 0x24
#define REGB_ID(idx) (*(uint32_t *)(((idx) & 0xffff) * 0x24 + 0x6fee68))

long start_registerB_user_txn(uint32_t regBIndex /*param_1*/, uint32_t allocKey /*param_2*/) {
    long slot = FUN_005be0a0(1, 0, allocKey);       // alloc request slot
    if (slot == -1) return -1;

    uint16_t sel = FUN_005c1e70(2, regBIndex);       // op7b selector
    int base = (int)slot * 0x20;
    *(uint16_t *)(base + 0x6ca97c) = sel;

    uint16_t txn = func_0x001dd5f8(uRam006febac, REGB_ID(regBIndex),
                                   0x55534552 /*USER*/, 0x5c0060 /*reply cb*/); // op09
    *(uint16_t *)(base + 0x6ca97e) = txn;
    return slot;
}
```

## Evidence
- Raw decompile `FUN_005bffa0.c`.
- `func_0x001dd5f8` = snap_send_op09_unrel (op09, PACKET_INDEX 0x09); `FUN_005c1e70` = op0x7b builder (PACKET_INDEX 0x7b); tag 0x55534552 = "USER".
- Registry-B (0x6fee68, 30×0x24) from GLOBALS.md; request-table stride 0x20 shared with the enter/leave launchers.
- Runtime-unvalidated.

## Remaining uncertainty
- Original generated label "maxi" is unexplained by the decompile (no MAXI tag appears — only USER); renamed to `start_registerB_user_txn` to reflect the registry-B USER register. Confirm the caller context (which room-list action triggers it) with a trace.
- Reliable (registry-A, 0x5bfa70/5bf470) vs unreliable (registry-B, here) op09 USER split is observed but its protocol rationale is not yet pinned.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bffa0.c`  — untouched decompiler output.
