# 0x00600f50 field_decode_room_field_0762

| field | value |
|---|---|
| Original address | 0x00600f50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00600f50 |
| Resolved name | field_decode_room_field_0762 |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** — (installed as a field-sync decode callback)
**Callees:** FUN_005c01d0 (decode 2-byte field)
**Referenced globals:** room-slot table (stride 0x15c): decode dest 0x6c0762, reset dest 0x6c0606; screen mode cRam006c4b90; active index bRam006c4600
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90 (mode gate), bRam006c4600 (player index)

## Behavioral explanation
Room field-sync decoder for a per-room 2-byte field. On present (tag 0) it decodes the payload into `room_slot[idx-1]` field 0x6c0762 — the `pairA` value the row renderer prints for in-progress/full rooms (roomlist_row_render_cb, `type >= 3` template). On reset (tag nonzero) it zeroes `room_slot[idx]` field 0x6c0606. Suppressed while screen mode == 6.

## Input / output
- `param_1` : `u32*` field descriptor; low byte = presence tag.
- returns `void`.

## Side effects
- tag 0: `FUN_005c01d0(bRam006c4600, &room_slot[idx-1].pairA@0x6c0762)`.
- tag !=0: `*(u16*)&room_slot[idx].field@0x6c0606 = 0`.

## Important branches
- `cRam006c4b90 == 6` → no-op.
- `tag == 0` → decode; else reset.

## Constants & flags
- stride `0x15c`; mode-6 gate shared with the sibling decoders.

## Corrected reconstruction
```c
void field_decode_room_field_0762(u32 *field)
{
    if (g_screen_mode == 6) return;                 // cRam006c4b90
    u8 tag = (u8)*field;
    if (tag == 0)
        decode_u16(g_active_player, &room_slot[g_active_player-1].pairA); // FUN_005c01d0 -> 0x6c0762
    else
        room_slot[g_active_player].field_0606 = 0;   // reset
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_00600f50.c`.
- Decode dest 0x6c0762 = `pairA` read by roomlist_row_render_cb for detailed rooms; stride 0x15c; mode-6 gate. Reset dest 0x6c0606 sits exactly one stride (0x15c) below 0x6c0762. Runtime-unvalidated.

## Remaining uncertainty
- Semantic of the 2-byte value (score? elapsed? player-subcount?) not determinable from code. idx vs idx-1 quirk as in the sibling decoders. Renamed from ..._player_field_0602 to ..._room_field_0762 to match the actual decode address.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00600f50.c`  — untouched decompiler output.
