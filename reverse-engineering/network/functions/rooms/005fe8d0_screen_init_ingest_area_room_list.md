# 0x005fe8d0 screen_init_ingest_area_room_list

| field | value |
|---|---|
| Original address | 0x005fe8d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fe8d0 |
| Resolved name | roomlist_screen_init_and_ingest_sm |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe730 (screen tick/dispatch)
**Callees:** FUN_005adc80 (get current room ordinal, kind=2), func_0x00106b60 (memset), FUN_005b68e0 (arm/reset field-sync), FUN_005c0250/005c02b0/005c0a00/005bffa0/005c0f60/005c2820/005c0850/005c0960 (register per-field reply decoder callbacks), FUN_005b8cf0 (reliable send, sel 0x76), FUN_005b6900 (poll pending), FUN_005c0f20 (pull parsed list into buffer), func_0x00109eb8 (strcpy), FUN_005b9110 (overlay rebuild 0x4c)
**Referenced globals:** 0x6c0760 room table (30×0x15c=0x28c8); 0x6970a0 room-detail buffer (0x29555); 0x6970f4 entry count; 0x6970f6.. per-entry name/detail records (0x14a8 stride); 0x6c0778/0x6c076f current-room name/flag
**Referenced strings:** —
**Referenced opcodes:** 0x76 (FUN_005b8cf0 send selector) [inferred]
**State vars:** param_1+0x10 step; +0x16 timer; +0xf substate; +0x42b overlay id; +0x97d ready flag

## Behavioral explanation
Per-frame state machine for the room-list / room-detail screen. It (case 0) wipes and seeds the
30-slot room table at 0x6c0760, registers the family of per-field reply decoders (the FUN_006010xx /
FUN_00600xxx callbacks, including field_decode_room_counts 0x601170), fires the list request, then
(cases 3–5) waits on a timer and ingests the server's reply — a count-prefixed array of per-entry
records (name + flags + a nested inner name list) — into the 0x6970xx room-detail buffer, and finally
(case 6) latches the screen ready and rebuilds the overlay.

`FUN_005adc80(2)` returns the current room **ordinal** (1-based); slot address = `(ordinal-1)*0x15c +
0x6c0760`. The 0x15c stride and 30-entry count match room_record's transport-page representation.

## Input / output
- `param_1` : `screen_ctx*` — the screen/overlay context; fields at +0xf/+0x10/+0x16/+0x42b/+0x97d.
- returns `void`.

## Side effects
- **case 0:** step→1; `memset(0x6c0760,0,0x28c8)`; `memset(0x6970a0,0,0x29555)`; seeds 30 slots with
  1-based short ids at slot+0; arms field-sync (FUN_005b68e0); registers 7 field decoders; timer
  (+0x16)=0x10; sends selector 0x76 (FUN_005b8cf0).
- **case 1/2:** step++ (idle advance).
- **case 3:** timer--; when it underflows (<0): step++, re-arm field-sync, overlay id (+0x42b)=0x16,
  register the extra decoder FUN_005c0960(ctx,0x601260).
- **case 4:** FUN_005b6900() — poll for the pending reply.
- **case 5:** step++; FUN_005c0f20 pulls the parsed reply into a stack buffer; copies header
  (0x6970a0/a1 flags, 0x6970f4 entry count); loops entryCount times copying each record (name via
  strcpy to +0x6970f6, flag bytes +0x137/138/139/13a) and an inner loop of sub-entries (0x41 stride
  name strings to +0x69715d), stride 0x14a8 per record.
- **case 6:** substate (+0xf)=4, step=0, ready (+0x97d)=1; strcpy current room name 0x6c0778[slot]→
  0x6970b2, flag 0x6c076f[slot]→0x6970f2; overlay rebuild FUN_005b9110(0x4c).

## Important branches
- `switch(step /*+0x10*/)` 0..6 as above; unlisted values fall through (no-op).
- case 3 gate: `--timer < 0` before advancing — a fixed dwell before the request is considered timed
  out / ready to ingest.
- case 5 inner loop bounded by per-record sub-count `*(record+0x697137)` (nested member/name list).

## Constants & flags
- room table 0x6c0760: 30 slots × 0x15c (0x28c8). detail buffer 0x6970a0: 0x29555 bytes.
- per-entry record stride 0x14a8 (dest) / 0x14a5 (src); inner name stride 0x41; sub-count at +0x137.
- timer seed 0x10; overlay ids 0x16 / 0x4c; send selector 0x76 [inferred].

## Corrected reconstruction
```c
// Room-list / room-detail screen SM. param_1 = screen ctx.
void roomlist_screen_init_and_ingest_sm(screen_ctx *sc)
{
    uint16_t ord = FUN_005adc80(2);             // current room ordinal (1-based)

    switch (sc->step /*+0x10*/) {
    case 0:
        sc->step++;
        memset((void*)0x6c0760, 0, 0x28c8);      // 30 room slots
        memset((void*)0x6970a0, 0, 0x29555);     // room-detail buffer
        for (int i = 0; i < 30; i++)             // seed 1-based short ids
            *(int16_t*)(0x6c0760 + i*0x15c) = (int16_t)(i + 1);
        arm_field_sync();                        // FUN_005b68e0
        register_field_decoder(ord, decode_room_hdr_0x6010d0);
        register_field_decoder(ord, field_decode_room_counts /*0x601170*/);
        register_field_decoder(ord, decode_0x600de0);
        register_field_decoder(ord, decode_0x600f50);
        register_field_decoder(ord, decode_0x600ff0);
        register_field_decoder(ord, decode_0x601060);
        register_field_decoder(ord, decode_0x600e90);
        sc->timer /*+0x16*/ = 0x10;
        reliable_send(0x76);                     // FUN_005b8cf0 (list request) [inferred op]
        break;
    case 1: case 2:
        sc->step++;                              // idle advance
        break;
    case 3:
        if (--sc->timer < 0) {
            sc->step++;
            arm_field_sync();
            sc->overlay_id /*+0x42b*/ = 0x16;
            register_field_decoder(ord, decode_0x601260);
        }
        break;
    case 4:
        poll_pending_reply();                    // FUN_005b6900
        break;
    case 5: {
        sc->step++;
        parsed_list buf;
        FUN_005c0f20(ord, &buf);                 // pull reply
        *(uint8_t*)0x6970a0 = buf.flag0;
        *(uint8_t*)0x6970a1 = buf.flag1;
        uint8_t n = buf.count; *(uint8_t*)0x6970f4 = n;
        for (int i = 0; i < n; i++) {
            uint8_t *rec = (uint8_t*)(0x6970f6 + i*0x14a8);
            strcpy((char*)rec, buf.records[i].name);              // +0x6970f6
            rec[0x42] = buf.records[i].b0;   // +0x697138
            rec[0x41] = buf.records[i].sub_count; // +0x697137
            rec[0x43] = rec[0x44] = buf.records[i].b2; // +0x697139/13a
            for (int j = 0; j < rec[0x41]; j++)                  // inner names
                strcpy((char*)(rec + j*0x41 + 0x67), buf.records[i].subnames[j]); // +0x69715d
        }
        break;
    }
    case 6:
        sc->substate /*+0xf*/ = 4;
        sc->step = 0;
        sc->ready /*+0x97d*/ = 1;
        strcpy((char*)0x6970b2, (char*)(0x6c0778 + (ord-1)*0x15c)); // room name
        *(uint8_t*)0x6970f2 = *(uint8_t*)(0x6c076f + (ord-1)*0x15c); // flag
        overlay_rebuild(0x4c);                   // FUN_005b9110
        break;
    }
}
```

## Evidence
- `sources/overlays/overlay-3dat-decompile/FUN_005fe8d0.c` — full switch, memsets, decoder
  registrations, case-5 nested ingest loop, case-6 finalize.
- room_record.md (0x260/0x15c transport page); GLOBALS.md 0x6c0760 (0x28c8 room table), 0x6970a0/f4,
  0x6c0778/076f. field_decode_room_counts (0x601170) confirms the registered-callback nature.

## Remaining uncertainty
- FUN_005adc80(2)'s exact semantics (room ordinal vs. registration handle) and the 0x76 send selector
  are inferred, not wire-confirmed. The parsed_list layout in case 5 is reconstructed from the copy
  offsets, not a struct definition. Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fe8d0.c`  — untouched decompiler output.
