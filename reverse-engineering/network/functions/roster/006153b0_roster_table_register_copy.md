# 0x006153b0 roster_table_register_copy

| field | value |
|---|---|
| Original address | 0x006153b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006153b0 |
| Resolved name | roster_snapshot_publish |
| Subsystem | roster |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00610580, FUN_00610830
**Callees:** FUN_0060e440 (register/insert into hash), FUN_0060e660 (post-register fixup)
**Referenced globals:** hash/registry @0x3c98b0; source player table iRam0070d1c0+0xed0 (65 × 8 bytes); publish target @0x3ca2d0
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0070d1c0+0xed0

## Behavioral explanation
Registers a player/roster key into the `0x3c98b0` hash/registry (FUN_0060e440 with a zeroed status
byte, then FUN_0060e660 fixup) and then **publishes a snapshot** of the 65-entry × 8-byte player
table (at `*(iRam0070d1c0) + 0xed0`) into the fixed buffer at `0x3ca2d0`. The copy is an unrolled
2-word-per-iteration loop over 0x41 (65) entries = 0x208 bytes. This makes the current roster/player
table available to the renderer at a stable address after each registry mutation.

## Input / output
- `param_1` (undefined8): the key/record to register (16-byte id or player descriptor) passed to
  FUN_0060e440/FUN_0060e660.
- **return** void.

## Side effects
- `FUN_0060e440(0x3c98b0, key, &statusByte=0)` — inserts/updates the registry entry.
- `FUN_0060e660(0x3c98b0, key)` — registry post-insert fixup (rehash/link).
- Copies 65×8 bytes from `iRam0070d1c0 + 0xed0` → `0x3ca2d0` (roster snapshot for rendering).

## Important branches
- No conditional branches; a fixed 0x41-count unrolled `do/while` copy (`iVar2` from 0x41 down to 0).
- Copy reads two u32 per step (`puVar4[0]`, `puVar4[1]`) and writes them to `puVar3[0]`, `puVar3[1]`,
  advancing both by 2 words → 65 records of 8 bytes each.

## Constants & flags
- `0x3c98b0` — player/roster registry (hash) base.
- `iRam0070d1c0 + 0xed0` — live source table (65 entries × 8 bytes).
- `0x3ca2d0` — published snapshot destination.
- `0x41` — 65 entries; `8` — per-entry size (2 × u32).

## Corrected reconstruction
```c
// Register `key` in the roster registry, then publish the 65-entry player table snapshot.
void roster_snapshot_publish(void *key) {
    u8 status = 0;
    FUN_0060e440((void*)0x3c98b0, key, &status);   // insert/update registry
    FUN_0060e660((void*)0x3c98b0, key);            // rehash/link fixup

    u32 *dst = (u32*)0x3ca2d0;
    u32 *src = (u32*)(iRam0070d1c0 + 0xed0);        // live player table
    for (int i = 0x41; i > 0; i--) {                // 65 × 8 bytes
        dst[0] = src[0];
        dst[1] = src[1];
        src += 2; dst += 2;
    }
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_006153b0.c`.
- The `iRam0070d1c0 + 0xed0` 65-slot table is also referenced by FUN_006140d0 / FUN_00615430 /
  FUN_00615470 (roster-adjacent block).

## Remaining uncertainty
Per-entry 8-byte record shape (id-hash + index? handle + flags?) is not decoded; FUN_0060e440/
FUN_0060e660 registry semantics are inferred from call shape. `param_1`'s exact type unconfirmed →
Medium.
