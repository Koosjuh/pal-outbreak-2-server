# 0x005bbfc0 inroom_set_player_state_1

| field | value |
|---|---|
| Original address | 0x005bbfc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bbfc0 |
| Resolved name | inroom_set_player_state_1 |
| Subsystem | roster |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bba20 (in-room sub-event dispatcher, case 4)
**Callees:** FUN_005c5120 (extract member id from a roster record)
**Referenced globals:** 0x6ff70d (in-room player record table, stride 0x114); 0x6ff2b5 (per-slot player-state byte array, stride 1)
**Referenced strings:** —
**Referenced opcodes:** — (server push routed through the in-room sub-event dispatcher)
**State vars:** 0x6ff2b5[slot]

## Behavioral explanation
In-room sub-event handler (dispatcher case 4). A server push carries a single member id (`param_1`). The
function scans the 4-slot in-room player table at `0x6ff70d` (stride `0x114`), asks `FUN_005c5120` to pull
the stored id out of each record, and on the first id that matches the pushed id it writes state value **1**
into that slot's byte in the parallel per-slot state array at `0x6ff2b5`. This is one of a matched pair with
`FUN_005bc050`, which writes state **2** for the same table under dispatcher case `0x10`; together they toggle
a two-valued per-player status (e.g. ready / not-ready, or joined / left) that the in-room roster panel reads
when drawing each row. No packet is sent; this is purely a local state mutation driven by an inbound push.

## Input / output
- `param_1` (int): the member id to locate (the id field the server pushed).
- Returns: void.

## Side effects
- Writes `1` to `*(u8*)(0x6ff2b5 + slot)` for the first slot whose record id equals `param_1`.
- If no slot matches, nothing is written (silent no-op).

## Important branches
- `iVar1 > 3` (all 4 slots scanned, no match): `return` — no state change.
- `iStack_4 == param_1` (id match): `break` out of the scan, then set the state byte and return.
- Loop is a linear scan of slots 0..3; first match wins.

## Constants & flags
- Table stride `0x114` = relayed `member_record` size (see `member_record.md`, "0x114 relayed").
- Slot count `4` = max players per room.
- State value `1` — paired with `2` from `FUN_005bc050`; exact semantics (ready vs left) not runtime-confirmed.

## Corrected reconstruction
```c
// In-room sub-event dispatcher (FUN_005bba20) case 4: set player state = 1.
#define INROOM_PLAYER_TABLE   0x6ff70d   // member_record[4], stride 0x114 (relayed layout)
#define INROOM_PLAYER_STATE   0x6ff2b5   // u8 state[4], parallel to the table
#define ROOM_MAX_PLAYERS      4
#define PLAYER_STATE_1        1          // [inferred] "ready"/"present" — paired with _2 = 2

void inroom_set_player_state_1(int member_id)
{
    for (int slot = 0; slot <= ROOM_MAX_PLAYERS - 1; slot++) {
        int rec_id;
        extract_member_id((member_record*)(INROOM_PLAYER_TABLE + slot * 0x114), &rec_id); // FUN_005c5120
        if (rec_id == member_id) {
            *(uint8_t*)(INROOM_PLAYER_STATE + slot) = PLAYER_STATE_1;
            return;
        }
    }
    // no matching slot -> no-op
}
```

## Evidence
- Raw decompile `FUN_005bbfc0.c`: 4-iteration scan, `FUN_005c5120(i*0x114+0x6ff70d,&iStack_4)`, match test `iStack_4 == param_1`, store `*(0x6ff2b5+i)=1`.
- Table stride `0x114` matches the relayed `member_record` size documented in `structure-layouts/member_record.md`.
- Sibling `FUN_005bc050` is byte-identical except it stores `2`; both are the only writers of `0x6ff2b5`.
- Runtime-unvalidated: the ready/left meaning of state 1 vs 2 is inferred from pairing, not from a rig trace.

## Remaining uncertainty
- Whether state 1 means "ready", "present", or another flag; needs a PINE read of `0x6ff2b5` across a
  join/ready toggle. The dispatcher opcode/sub-selector that routes to case 4 vs 0x10 is defined in
  `FUN_005bba20` (not in this set).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bbfc0.c`  — untouched decompiler output.
