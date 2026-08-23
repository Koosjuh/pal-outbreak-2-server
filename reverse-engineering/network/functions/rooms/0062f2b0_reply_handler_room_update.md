# 0x0062f2b0 selected_room_update_handler

| field | value |
|---|---|
| Original address | 0x0062f2b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062f2b0 |
| Resolved name | selected_room_update_handler |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (reply callback, registered by room_join_sequence e440 case2 / FUN_005bffa0)
**Callees:** FUN_005c01d0 (refresh room name field)
**Referenced globals:** 0x6c4b90 screen_id; 0x6c4600 selected_room (byte); 0x6c0762 per-room name field; 0x6c0606 per-room field; 0x6c4ba0 screen_step
**Referenced strings:** —
**Referenced opcodes:** room join/update reply
**State vars:** guard `screen_id == 0x0e`

## Behavioral explanation
Handler run **while on screen 0x0e** (an in-room / join-transition screen). The guard is unusual: `screen_id != 6 && screen_id == 0x0e` — the `!=6` is vacuously true given `==0x0e`, so effectively "only on screen 0x0e". It always bumps `screen_step += 1`, then, based on status of `param_1[0]`:
- **status == 0**: refresh the selected room's name field — writes `selected_room` into the `(selected_room-1)*0x15c + 0x6c0762` slot via FUN_005c01d0 (re-fetch the entry for the room just acted on; note the −1 makes this 1-based→0-based indexed).
- **status != 0**: zero the selected room's `0x6c0606` field (`selected_room*0x15c + 0x6c0606 = 0`) — clears a per-room field (using 0-based `selected_room` here, without the −1), likely an availability/valid flag reset on failure.

## Input / output
- `param_1`: `u32* reply` — `[0]` low byte = status. Void; output via globals.
- Reads `selected_room` (0x6c4600, a byte).

## Side effects
- Always: `screen_step++`.
- Success: rewrites room-name field at `(selected_room-1)*0x15c+0x6c0762`.
- Failure: `*(u16*)(selected_room*0x15c + 0x6c0606) = 0`.

## Important branches
- `screen_id != 0x0e` → return.
- `status==0` → refresh entry name.
- `status!=0` → zero the 0x6c0606 field.

## Constants & flags
- `screen_id (0x6c4b90) == 0x0e` — in-room/join-transition screen.
- Stride 0x15c matches the room table (0x6c0760 family); 0x6c0762 = name field, 0x6c0606 = a separate per-room field in a parallel table (base 0x6c0606, note lower than 0x6c0760).

## Corrected reconstruction
```c
void selected_room_update_handler(u32 *reply) {
    if (screen_id != 0x0e) return;                 // in-room/join screen only
    u8 status = (u8)reply[0];
    u8 sel = selected_room;                        // 0x6c4600 (byte)
    screen_step++;
    if (status == 0) {
        // re-fetch just the acted-on room's name (0-based (sel-1))
        get_room_name(sel, (u16*)((sel-1)*0x15c + 0x6c0762));   // FUN_005c01d0
    } else {
        *(u16*)(sel*0x15c + 0x6c0606) = 0;         // clear per-room field on failure
    }
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_0062f2b0.c`.
- Stride 0x15c and field 0x6c0762 tie to the room table populated by 0x0062e9b0 (name at +0x02 → 0x6c0762). The `(sel-1)` vs `sel` indexing asymmetry is present in the raw and preserved.
- Registered by room_join_sequence (e440 case2).
- Runtime-unvalidated.

## Remaining uncertainty
- The `(sel-1)` vs `sel` indexing difference between the two branches, and the meaning of the parallel table at 0x6c0606, are unresolved — likely a source-level quirk but not traced. Whether `selected_room` is truly 1-based is uncertain given the mixed use.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062f2b0.c`  — untouched decompiler output.
