# 0x001cf570 send_area_member_update_aux

| field | value |
|---|---|
| Original address | 0x001cf570 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cf570 |
| Resolved name | prepare_area_member_update_aux |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001cf3e0
**Callees:** FUN_001a7b70, FUN_001ab460
**Referenced globals:** 0x3bfcec per-area enable table (stride 0x14); 0x4288f0 per-conn active flag; 0x4290fc per-conn buffer ptr; 0x42910c per-conn counter — all indexed by conn slot (stride 0x824)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Prepares the secondary ("aux") send channel for an area member-update, per connection. `param_1` is the connection object (index at `+3`); `param_2` is the area/channel id. It first clears the per-conn active flag, then — only if the area is enabled in the table at `0x3bfcec[area]` — programs the transport packet-attribute template (eight `FUN_001a7b70(key,val)` writes, the standard reliable-send preset), marks the per-conn slot active, allocates a `0x20`-byte send buffer (FUN_001ab460), stores its pointer, and zeroes the per-conn counter. Unlike its sibling FUN_001cf6a0 it does **not** immediately emit — it only stages the buffer; the actual send is issued elsewhere (the caller / the paired primary channel).

## Input / output
- `param_1` (`snap_connection*`) — connection index byte at `+3` selects the per-conn slot (`slot = conn[3] * 0x824`).
- `param_2` (u32, low byte = area id) — indexes the enable table.
- Returns `void`.

## Side effects
- `*(u8*)(0x4288f0 + slot) = 0` (clear), then `= 1` if enabled.
- `FUN_001a7b70(...)` ×8 — set pending-packet attributes (reliable preset).
- `*(u32*)(0x4290fc + slot) = FUN_001ab460(0x20)` (alloc 0x20-byte buffer, store ptr).
- `*(u32*)(0x42910c + slot) = 0` (reset counter).

## Important branches
- `*(int*)(0x3bfcec + (area&0xff)*0x14) == 0` → area not enabled → leave flag cleared, do nothing else.
- else → program attributes, mark active, alloc buffer.

## Constants & flags
- Per-conn slot stride `0x824` (`= (0x208+1)*4`); parallel arrays: active flag `0x4288f0`, buffer ptr `0x4290fc`, counter `0x42910c`.
- Enable table `0x3bfcec`, stride `0x14`, indexed by area.
- Attribute preset (shared with FUN_001cf6a0): `0x15=2`, `1=0x800`, `0x12=0x8000` (reliable bit), `0x62=1`, `0xc=0`, `0x66=1`, `2=0`, `0=0` (terminator). Buffer size `0x20`.

## Corrected reconstruction
```c
// slot base arrays indexed by conn->index (+3), stride 0x824
void prepare_area_member_update_aux(snap_connection *conn, uint32_t area)
{
    int slot = conn->index /*+3*/ * 0x824;

    *(uint8_t *)(0x4288f0 + slot) = 0;                 // aux active = false

    if (*(int *)(0x3bfcec + (area & 0xff) * 0x14) != 0) {   // area enabled?
        // reliable-send attribute preset
        FUN_001a7b70(0x15, 2);
        FUN_001a7b70(1,    0x800);
        FUN_001a7b70(0x12, 0x8000);   // reliable bit
        FUN_001a7b70(0x62, 1);
        FUN_001a7b70(0xc,  0);
        FUN_001a7b70(0x66, 1);
        FUN_001a7b70(2,    0);
        FUN_001a7b70(0,    0);        // terminator

        *(uint8_t  *)(0x4288f0 + slot) = 1;
        *(uint32_t *)(0x4290fc + slot) = FUN_001ab460(0x20);  // alloc 0x20 buffer
        *(uint32_t *)(0x42910c + slot) = 0;
    }
}
```

## Evidence
- Raw decompile `FUN_001cf570.c`: slot index `((u8)(param_1+3)*0x208 + (u8)(param_1+3))*4` = `conn[3]*0x824`; enable gate `*(int*)((param_2&0xff)*0x14 + 0x3bfcec)`; identical `FUN_001a7b70` preset to FUN_001cf6a0/FUN_001d0400; `FUN_001ab460(0x20)` alloc into `0x4290fc`.
- Caller FUN_001cf3e0 (area member-update path).
- Runtime-unvalidated. Medium: attribute-key semantics inferred.

## Remaining uncertainty
- `FUN_001a7b70(key,val)` attribute keys (`0x15/1/0x12/0x62/0xc/0x66/2/0`) map to transport header/framing fields but the exact field per key is not decoded (only `0x12=0x8000` inferred = reliable bit).
- Why this one stages but does not emit (vs FUN_001cf6a0 which calls FUN_001cd010) — presumably the caller emits both channels together; unconfirmed.
- Which app/transport opcode the eventual send carries.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cf570.c`  — untouched decompiler output.
