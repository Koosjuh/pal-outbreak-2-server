# 0x005bc050 inroom_set_player_state_2

| field | value |
|---|---|
| Original address | 0x005bc050 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc050 |
| Resolved name | inroom_set_player_state_2 |
| Subsystem | roster |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bba20 (in-room sub-event dispatcher, case 0x10)
**Callees:** FUN_005c5120 (extract member id from a roster record)
**Referenced globals:** 0x6ff70d (in-room player record table, stride 0x114); 0x6ff2b5 (per-slot player-state byte array, stride 1)
**Referenced strings:** —
**Referenced opcodes:** — (server push routed through the in-room sub-event dispatcher)
**State vars:** 0x6ff2b5[slot]

## Behavioral explanation
Byte-for-byte sibling of `FUN_005bbfc0`, invoked under dispatcher case `0x10` instead of case 4. A server push
carries a member id (`param_1`); the function linearly scans the 4-slot in-room player table at `0x6ff70d`
(stride `0x114`), pulls each record's id via `FUN_005c5120`, and on the first match writes state value **2**
into that slot's byte at `0x6ff2b5`. The only difference from case 4 is the value stored (2 vs 1), so the two
handlers implement a two-state per-player toggle (e.g. ready/not-ready or present/left) that the roster row
renderer consults.

## Input / output
- `param_1` (int): member id to locate.
- Returns: void.

## Side effects
- Writes `2` to `*(u8*)(0x6ff2b5 + slot)` for the first matching slot; no-op if no slot matches.

## Important branches
- `iVar1 > 3`: `return` (no match, no change).
- `iStack_4 == param_1`: `break`, store state byte, return.

## Constants & flags
- Stride `0x114` = relayed `member_record` size; slot count `4`.
- State value `2` — the counterpart to `1` written by `FUN_005bbfc0`.

## Corrected reconstruction
```c
// In-room sub-event dispatcher (FUN_005bba20) case 0x10: set player state = 2.
#define INROOM_PLAYER_TABLE   0x6ff70d   // member_record[4], stride 0x114
#define INROOM_PLAYER_STATE   0x6ff2b5   // u8 state[4]
#define ROOM_MAX_PLAYERS      4
#define PLAYER_STATE_2        2          // [inferred] counterpart to PLAYER_STATE_1 = 1

void inroom_set_player_state_2(int member_id)
{
    for (int slot = 0; slot <= ROOM_MAX_PLAYERS - 1; slot++) {
        int rec_id;
        extract_member_id((member_record*)(INROOM_PLAYER_TABLE + slot * 0x114), &rec_id); // FUN_005c5120
        if (rec_id == member_id) {
            *(uint8_t*)(INROOM_PLAYER_STATE + slot) = PLAYER_STATE_2;
            return;
        }
    }
}
```

## Evidence
- Raw decompile `FUN_005bc050.c`: identical scan/match structure to `FUN_005bbfc0`, storing `2`.
- Both functions are the sole writers of the `0x6ff2b5` state array; called from the same dispatcher under
  different sub-selector cases (4 vs 0x10) per the classification of `FUN_005bba20`.
- Runtime-unvalidated: state semantics inferred, not traced.

## Remaining uncertainty
- Meaning of state 2 (not-ready? left? spectator?) and which server push carries case-0x10 ids. Resolve with a
  PINE watch of `0x6ff2b5` while a second player toggles ready / leaves.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bc050.c`  — untouched decompiler output.
