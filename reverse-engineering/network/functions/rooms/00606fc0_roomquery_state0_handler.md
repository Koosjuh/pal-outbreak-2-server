# 0x00606fc0 roomquery_fetch_sm

| field | value |
|---|---|
| Original address | 0x00606fc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606fc0 |
| Resolved name | roomquery_fetch_sm |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00606cf0
**Callees:** FUN_005af2f0, FUN_005af300, FUN_005b8cf0, FUN_005b9110, FUN_005c78e0, FUN_005c7900, FUN_005c79d0, FUN_005c7a00, FUN_005c7ba0, FUN_005c7bd0, FUN_00606e40, FUN_00606f60, FUN_00606fa0, FUN_00607a10, FUN_00618b60
**Referenced globals:** 0x00874f35 phase; 0x00870868 substep; 0x008744f8 room-count; 0x0070c000 room-record array (0x158 stride); 0x00874f3c selected-room name (0x10); 0x006c5490 txn/list scratch (0x20); 0x003c8a80 conn-mode flag
**Referenced strings:** —
**Referenced opcodes:** — (drives the op1c/op20 room-list fetch via FUN_005c78e0/7900/7a00 helpers)
**State vars:** cRam00874f35 (session phase); cRam00870868 (abnormal-phase substep); bRam008744f8 (room count); record[0]=major, record[1]=sub, record[+4]=short timer

## Behavioral explanation
Per-tick driver for the lobby room-list *fetch* screen. It first checks the global session phase `cRam00874f35`: the normal path runs only when the phase is one of the "connected/browsing" values {0,1,2}; phase 3 (or any out-of-range value) diverts to an abnormal-phase teardown/retry driven by `cRam00870868`. On the normal path it runs a 4-state sub-machine (`record[1]`): start the list request, poll for completion, copy the returned room records into the display array `0x70c000` (stride `0x158`, count `bRam008744f8`), and either auto-select (≤1 room) or hand off to state 3 (multi-room, wait a settling timer). It is the sibling of `roomquery_state3_select` (0x00607370); both are dispatched from `FUN_00606cf0`.

## Input / output
- **param_1** — pointer to the query txn/record block: `record[0]`=major state, `record[1]`=sub-state (0..3), `*(short*)(record+4)`=countdown timer.
- **return** — void.

## Side effects
- Writes `record[0]`, `record[1]`, `record+4` (state/timer transitions).
- `uRam003c8a80 = 1` in the abnormal-phase substep-1 branch (sets conn-mode flag).
- `FUN_005c7ba0(&bRam008744f8)` loads the room count; `FUN_005c7bd0(i+1, i*0x158+0x70c000)` copies each returned record into the display array.
- `memcpy(0x874f3c, 0x70c048, 0x10)` latches the single/first room's name (0x70c048 = record[0]+0x48).
- Opens dialog `0x51` (`FUN_005b8cf0`), closes dialog `0x4c` (`FUN_005b9110`); plays jingles via `FUN_005af2f0/005af300`.
- `FUN_005c78e0()` starts the request; `FUN_005c79d0(sel)` selects a room; `FUN_00618b60()`+`memset(0x6c5490,0,0x20)`+`FUN_00607a10(0x6c5490)` reset the list scratch.

## Important branches
- **phase == 3 OR phase ∉ {0,1,2}** → abnormal handling on `cRam00870868`: substep 0 → teardown (`FUN_00606e40`)+jingle; substep 1 → set `uRam003c8a80=1`, advance to substep 2; substep 2 → teardown+jingle again. (Retry/abort of the fetch when the session left the browse phase.)
- **sub == 0** (init) → play SE, reset scratch, open dialog 0x51, start request `FUN_005c78e0`, `record[1]++`; **falls through** into the sub==1 poll.
- **sub == 1** (poll) → `FUN_005c7900()`: `-1` = failed → `FUN_00606fa0(rec,2)` + close dialog 0x4c; `1` = ready → load count, copy all records; if `count < 2` latch name + `record[1]++` + auto-select(1); else `record[1]=3`, timer=8.
- **sub == 2** (secondary poll) → `FUN_005c7a00()`: `-1` → `FUN_00606f60`; `1` → `FUN_00606e40`.
- **sub == 3** (settle timer) → decrement `record+4`; when it goes negative reset scratch and rebuild list (`FUN_00607a10`), then `record[0]=2, record[1]=0`.
- **sub == other** → return (no-op).

## Constants & flags
- `cRam00874f35` phase: `{0,1,2}`=browse-normal, `3`=disconnected/left → abnormal path (matches `0x874f35` "lobby/room mode" in GLOBALS).
- Room record stride `0x158` @ `0x70c000`; name field at record+`0x48` (→ `0x874f3c` selected-name); count `bRam008744f8`.
- Dialog ids `0x51` (open, "querying"), `0x4c` (close).
- Poll returns `-1`=error, `0`=pending, `1`=ready (shared with `FUN_005c7900/005c7a00`).

## Corrected reconstruction
```c
// record layout (param_1): [0]=major, [1]=sub, +4: s16 timer
void roomquery_fetch_sm(RoomQueryRec *record /*param_1*/)
{
    // Normal browse phase is 0..2; phase 3 or garbage => abnormal teardown/retry
    if (g_session_phase /*0x874f35*/ == 3 ||
        (g_session_phase != 2 && g_session_phase != 1 && g_session_phase != 0)) {
        switch (g_query_abort_step /*0x870868*/) {
        case 0: roomquery_teardown();          /*00606e40*/ play_jingle(0,1); break; // 005af300
        case 1: g_conn_mode /*0x3c8a80*/ = 1;  g_query_abort_step = 2;          break;
        case 2: roomquery_teardown();          play_jingle(0,1);                break;
        }
        return;
    }

    switch (record->sub /*[1]*/) {
    case 3: // settle timer, then finalize the (multi-room) list
        if (--record->timer /*+4*/ < 0) {
            list_reset();                       // 00618b60
            memset(&g_list_scratch /*0x6c5490*/, 0, 0x20);
            list_rebuild(&g_list_scratch);      // 00607a10
            record->major = 2; record->sub = 0;
        }
        break;

    case 2: { // secondary poll
        long r = roomquery_poll_b();            // 005c7a00
        if (r == -1)      roomquery_retry();    // 00606f60
        else if (r == 1)  roomquery_teardown(); // 00606e40
        break;
    }

    default:
        if (record->sub != 1) {
            if (record->sub != 0) return;
            // case 0: begin the room-list request
            play_se(0);                         // 005af2f0
            list_reset();                       // 00618b60
            dialog_open(0x51);                  // 005b8cf0 "querying rooms"
            roomquery_start_request();          // 005c78e0 -> op1c/op20
            record->sub++;                      // -> 1, fall through
        }
        // case 1: poll for the reply
        long r = roomquery_poll_a();            // 005c7900
        if (r == -1) {
            roomquery_fail(record, 2);          // 00606fa0
            dialog_close(0x4c);                 // 005b9110
        } else if (r == 1) {
            roomquery_read_count(&g_room_count /*0x8744f8*/); // 005c7ba0
            for (int i = 0; i < (int)(u8)g_room_count; i++)
                roomquery_copy_record((i + 1) & 0xffff, i*0x158 + 0x70c000); // 005c7bd0
            if (g_room_count < 2) {
                memcpy(&g_selected_room_name /*0x874f3c*/, (void*)0x70c048, 0x10); // record0+0x48
                record->sub++;
                roomquery_select(1);            // 005c79d0
            } else {
                record->sub = 3;                // multi-room: let the user pick
                record->timer = 8;
            }
        }
        break;
    }
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_00606fc0.c` (control flow preserved exactly above).
- Globals corroborated by GLOBALS.md: `0x874f35` lobby/room mode; `0x8744f8` room-count; `0x3c8a80` conn-mode; `0x6c5490`-adjacent txn scratch.
- Sibling `0x00607370` shares `FUN_005c7a00/00607a10/00606e40/00606f60` — same fetch subsystem.

## Remaining uncertainty
- Exact polarity/meaning of `FUN_005c7900` vs `FUN_005c7a00` (two poll entrypoints) not runtime-confirmed; both treated as `-1/0/1`.
- `0x70c000` record internal layout beyond name@+0x48 not fully mapped.
- Not runtime-validated (no PINE/pcap trace).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00606fc0.c`  — untouched decompiler output.
