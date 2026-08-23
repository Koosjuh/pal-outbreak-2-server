# 0x005bc430 roster_member_update_and_redraw

| field | value |
|---|---|
| Original address | 0x005bc430 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc430 |
| Resolved name | roster_member_update_and_redraw |
| Subsystem | roster |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (registered/dispatched; classified under dispatch code 0x0a in FUN_005bc860)
**Callees:** FUN_005c7d00 (reply/txn housekeeping); FUN_005bc370 (roster_pack_visible_list); FUN_005c5120 (extract member id); FUN_005bdfe0 (UI redraw/event); func_0x00106b60 (memset); func_0x0010a4f0/func_0x001069a8 (memcpy)
**Referenced globals:** 0x6cdbe6 (raw roster table, stride 0x118); 0x6cd672/0x6cd682/0x6cd696 (scratch name A/name B/blob); 0x6fb746 (visible roster count); 0x70047c (roster-ready gate); 0x6cbc7e/0x6cbc84 (in-room UI status: room_mode / result)
**Referenced strings:** —
**Referenced opcodes:** 0x0a (member-list / member update)
**State vars:** reads cRam0070047c (gate); writes 0x6cbc7e, 0x6cbc84, 0x6fb746

## Behavioral explanation
Applies a single-member update to the already-populated in-room roster and, if the update marks the member as
"drawable", repacks the visible list and refreshes the roster panel. It is gated on `0x70047c` — the
roster-ready flag that `on_reply_member_list_filtered` (`FUN_005c2460`) sets to 1 after the initial full
member list arrives — so this path only runs once the roster exists. It scans the 4 raw slots for the slot
whose stored id matches `param_2[0]` (the incoming member id). On a match it copies the matched slot's two
16-byte name fields into scratch (`0x6cd672`/`0x6cd682`), then copies the incoming variable-length charstats
blob (`param_2[1]` bytes starting at `param_2+2`) into both scratch (`0x6cd696`) and the matched slot's blob
field (`slot*0x118 + 0x6cdc0a`). If the incoming record's flag at `+0xe5` equals 1, it sets `room_mode`
(`0x6cbc7e`) to `0x10` (roster panel active), fires redraw event `0x24`, recomputes the visible count via
`roster_pack_visible_list` into `0x6fb746`, sets `room_mode` again and fires redraw event `0x23` (roster
refresh), then returns.

## Input / output
- `param_1` (undefined8): unused (dispatch arg).
- `param_2` (int*): incoming member update record:
  - `param_2[0]` (u32): member id to match.
  - `param_2[1]` (u32): charstats blob length.
  - `param_2 + 2` (bytes): charstats blob.
  - `*(u8*)(param_2 + 0xe5)`: "redraw / member active" flag.
- Returns: void.

## Side effects
- Scratch: `memset(0x6cd672,0,0x114)` then copies name A/B/blob into `0x6cd672`/`0x6cd682`/`0x6cd696`.
- Roster slot: `memcpy(0x6cdc0a + slot*0x118, blob, len)`.
- On active flag: `0x6cbc84 = 0`, `0x6cbc7e = 0x10`, redraw 0x24, `0x6fb746 = roster_pack_visible_list()`,
  `0x6cbc7e = 0x10`, redraw 0x23; early `return`.

## Important branches
- `cRam0070047c == 0` (roster not yet ready): skip everything, `return` — no update before the list exists.
- Per slot: `extracted_id == param_2[0]` → apply the copies to that slot; otherwise advance `param_2` unchanged
  and continue scanning. (When matched, `param_2` is advanced past id+len to the blob for the copies.)
- `*(u8*)(param_2 + 0xe5) == 1` → repack + double redraw + `return`; if not set, the loop continues to the next
  slot without redrawing.

## Constants & flags
- `0x70047c` roster-ready gate (set by `FUN_005c2460`); must be 1 to proceed.
- `0x6cbc7e` = `room_mode`; `0x10` = "roster panel active" (`lobby_state_block.md`).
- Redraw event codes `0x24` (pre) and `0x23` (roster panel refresh) — same `0x23` used by `FUN_005c2460`.
- Roster stride `0x118`; blob field at `+0x24` (`0x6cdc0a - 0x6cdbe6`); name B at `+0x10` (`0x6cdbf6`).

## Corrected reconstruction
```c
#define RAW_ROSTER      0x6cdbe6   // roster_row[4], stride 0x118
#define SCRATCH_NAME_A  0x6cd672
#define SCRATCH_NAME_B  0x6cd682
#define SCRATCH_BLOB    0x6cd696
#define VIS_COUNT       0x6fb746
#define ROSTER_READY    0x70047c   // set=1 by on_reply_member_list_filtered
#define ROOM_MODE       0x6cbc7e   // 0x10 = roster panel active
#define UI_RESULT       0x6cbc84
#define EVT_ROSTER_PRE  0x24
#define EVT_ROSTER_DRAW 0x23

struct member_update {   // param_2
    /* +0x00 */ uint32_t id;
    /* +0x04 */ uint32_t blob_len;
    /* +0x08 */ uint8_t  blob[];      // charstats; matched via +0x2 word view in raw decomp
    /* +0xe5 */ // uint8_t redraw_flag; (into the incoming buffer)
};

void roster_member_update_and_redraw(void *unused, int *param_2)
{
    txn_housekeeping();                       // FUN_005c7d00
    if (*(uint8_t*)ROSTER_READY == 0)
        return;

    memset((void*)SCRATCH_NAME_A, 0, 0x114);

    for (int s = 0; s < 4; s++) {
        int off = s * 0x118;
        int rec_id;
        extract_member_id((void*)(RAW_ROSTER + off), &rec_id);   // FUN_005c5120
        int  *rec  = param_2;
        if (rec_id == param_2[0]) {
            int   blob_len = param_2[1];
            void *blob     = param_2 + 2;      // param_2 advanced past id+len
            rec = param_2 + 2;

            memcpy((void*)SCRATCH_NAME_A, (void*)(RAW_ROSTER + off + 0x00), 0x10); // name A
            memcpy((void*)SCRATCH_NAME_B, (void*)(RAW_ROSTER + off + 0x10), 0x10); // name B
            memcpy((void*)SCRATCH_BLOB,             blob, blob_len);
            memcpy((void*)(RAW_ROSTER + off + 0x24), blob, blob_len);              // charstats -> slot

            if (*((uint8_t*)param_2 + 0xe5) == 1) {
                *(uint16_t*)UI_RESULT = 0;
                *(uint16_t*)ROOM_MODE = 0x10;
                ui_redraw(EVT_ROSTER_PRE);                         // FUN_005bdfe0(0x24)
                *(uint16_t*)VIS_COUNT = roster_pack_visible_list();// FUN_005bc370
                *(uint16_t*)ROOM_MODE = 0x10;
                ui_redraw(EVT_ROSTER_DRAW);                        // FUN_005bdfe0(0x23)
                return;
            }
        }
        param_2 = rec;
    }
}
```

## Evidence
- Raw decompile `FUN_005bc430.c`: gate `cRam0070047c`, 4-slot scan with `FUN_005c5120`, match on `*param_2`,
  three copies to `0x6cd672/0x6cd682/0x6cd696` + slot `0x6cdc0a`, flag `+0xe5`, `FUN_005bdfe0(0x24)` then
  `uRam006fb746 = FUN_005bc370()` then `FUN_005bdfe0(0x23)`.
- `0x6cbc7e = 0x10` matches `room_mode` "roster panel active" in `lobby_state_block.md`.
- Redraw `0x23` shared with `FUN_005c2460` — the roster-panel refresh event.
- `0x70047c` written =1 by `FUN_005c2460`; this gate ties the single-member update to a prior full list.
- Runtime-unvalidated: the `+0xe5` flag meaning and blob length source are read straight from the incoming
  buffer per the decompile but not confirmed on the wire.

## Remaining uncertainty
- Exact incoming record layout (why the match uses a word view while copies use a byte `+0xe5`) suggests the
  decompiler flattened a struct; the true wire record for this update is not fully separated from the roster
  row. Dispatch registration (code 0x0a via `FUN_005bc860`) is asserted from classification, not re-derived here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bc430.c`  — untouched decompiler output.
