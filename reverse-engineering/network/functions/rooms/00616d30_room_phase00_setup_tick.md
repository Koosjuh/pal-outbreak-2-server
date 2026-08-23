# 0x00616d30 room_phase00_setup_tick

| field | value |
|---|---|
| Original address | 0x00616d30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00616d30 |
| Resolved name | room_phase00_roster_unpack_tick |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00616c40 (room phase dispatcher)
**Callees:** FUN_005b68e0, FUN_005b6900, FUN_005b8cf0, FUN_005bac60, FUN_005bad10, FUN_005c45b0, FUN_005c4600, FUN_005c6210; libc `func_0x001069a8` (memcpy), `func_0x00109eb8` (string copy)
**Referenced globals:** `uRam007012b0` (0x7012b0 host/self flag byte); `0x874fa0` (shared roster name mirror, 0x10); `uRam00874fd8`/`uRam00874fd9` (shared header bytes)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** obj+0xe major-state (++); obj+0xf minor-state (0..5 SM); obj+0x16 countdown (short); obj+0x97e branch flag; obj+0x990 player-count; obj+0x1f5c net-state buffer

## Behavioral explanation
The room screen's phase-0 (entry) sub-state machine, ticked once per frame by the dispatcher.
It walks minor-state (`obj+0xf`) 0→5. State 0 optionally builds the 4-slot roster widget list
and arms a countdown; state 2 runs the countdown; states 1/3/4 are transient render/setup steps;
state 5 is the **roster commit**: it pulls the freshly-decoded room snapshot out of the +0x1f5c
net-state buffer (via FUN_005c4600), reads the **player count** into obj+0x990, copies the room
name/header mirror to the shared globals, then loops over each present player unpacking their
**name, profile, character-stats blob (0xf0 bytes), char-select id and select word** from the
per-slot area into the roster rows (0x3b0 stride). Finally it re-packs the assembled roster into
the net buffer via FUN_005bad10 and stores the resulting status at obj+0x4a6. This is the
client-side handler that turns the received room/member data into the on-screen roster.

## Input / output
- **Params:** `param_1` — room-scene object pointer.
- **Return:** void.
- **Meaning:** advances the phase-0 SM; on completion the object's roster rows and header are
  populated and the major state (obj+0xe) is bumped so the dispatcher moves to the next phase.

## Side effects
- **State 0:** if `obj+0x97e == 0` → minor jumps straight to 2 (skip roster build); else
  minor = 1, calls FUN_005b68e0 (roster panel prep), builds three parallel 4-entry pointer
  arrays into each player slot (+0x309c, +0x30ac, +0x30c0 at 0x3b0 stride) and passes them to
  `FUN_005c6210(..., 0x6181e0)` (roster widget builder with layout table 0x6181e0). Then
  `obj+0x16 = 0x4c` (76-frame timer) and `FUN_005b8cf0(0x62)` (SE cue 0x62).
- **State 1:** `FUN_005b6900()` (render/advance helper).
- **State 2:** decrement obj+0x16; when < 0, minor++ (→3).
- **State 3:** minor++ (→4); FUN_005b68e0(); `obj+0x42b = 0x1a`; `FUN_005c45b0(0x618090)`
  (second widget/layout build, table 0x618090).
- **State 4:** `FUN_005b6900()`.
- **State 5 (commit):**
  - `obj+0xe += 1` (advance major phase), `obj+0xf = 0` (reset minor for next phase).
  - `FUN_005c4600(&snapshot)` fills a local header block from the decoded room state.
  - `obj+0x990 = snapshot.count` (player count).
  - `uRam007012b0 = snapshot.selfFlag` (0x7012b0 host/self byte).
  - `memcpy(obj+0x53e, snapshot.name16, 0x10)` and `memcpy(0x874fa0, snapshot.name16, 0x10)`
    (room name → object field + shared mirror).
  - per-player loop `i in [0, count)`: from slot `obj + i*0x3b0`
    `strcpy(+0x21dc, name)`, `strcpy(+0x21ec, profile)`, `memcpy(+0x2200, stats, 0xf0)`,
    `*(+0x22f0) = charSelByte[i]`, `*(+0x2308) = selectWord[i]`.
  - copies 13 header bytes from the local snapshot into obj+0x4a4..+0x4b1, sets
    `uRam00874fd8`/`uRam00874fd9`, mirrors obj+0x4a5→obj+0x4a6.
  - `status = FUN_005bad10(obj+0x1f5c, FUN_005bac60(0), obj+0x990, obj+6)`; stores → obj+0x4a6.

## Important branches
- `switch(obj+0xf)` 0..5 (see side effects). The only data-dependent gate is state-0
  `obj+0x97e == 0` (skip-roster-build → minor=2) vs `!= 0` (build roster). The per-player loop
  is bounded by `obj+0x990` (player count, `byte`), so 0..255 but practically ≤4 (slot stride
  matches the 4-slot roster; net buffer holds 4×0x3b0). No explicit clamp on count here — a
  count > 4 would overrun the 4-slot region (potential defect, unvalidated).

## Constants & flags
- minor states: `0`=setup/build, `1`=render, `2`=countdown, `3`=second-build, `4`=render,
  `5`=commit. [High]
- `0x4c` = 76-frame phase-0 timer (obj+0x16). [inferred frames]
- `0x62` = SE cue id (FUN_005b8cf0). [inferred]
- `0x1a` = value written to obj+0x42b before FUN_005c45b0. [meaning unknown]
- `0x6181e0`, `0x618090` = widget/layout tables for FUN_005c6210 / FUN_005c45b0. [High: data addrs]
- `0xf0` = char-stats blob length (matches member_record.charstats). [Confirmed cross-struct]
- `0x3b0` = per-player roster-row stride (matches roster_table 0x6c7c2c stride). [Confirmed]
- Per-slot field offsets: `+0x21dc` name, `+0x21ec` profile, `+0x2200` stats(0xf0),
  `+0x22f0` char-sel byte, `+0x2308` select word; `+0x309c/+0x30ac/+0x30c0` widget anchors. [High]

## Corrected reconstruction
```c
// Phase-0 room SM: build roster widgets, wait, then commit received room+member data to rows.
enum { RP0_SETUP=0, RP0_RENDER1=1, RP0_WAIT=2, RP0_BUILD2=3, RP0_RENDER2=4, RP0_COMMIT=5 };

void room_phase00_roster_unpack_tick(struct room_scene *obj)
{
    switch (obj->minor /*+0xf*/) {
    case RP0_SETUP:
        if (obj->has_roster_97e /*+0x97e*/ == 0) {
            obj->minor = RP0_WAIT;                 // nothing to build → skip to countdown
        } else {
            obj->minor = RP0_SETUP + 1;            // → RENDER1
            FUN_005b68e0();                        // roster panel prep
            int anchorA[4], anchorB[4], anchorC[4];
            for (int i = 0; i < 4; i++) {
                char *slot = (char*)obj + i*0x3b0;
                anchorA[i] = (int)(slot + 0x309c);
                anchorB[i] = (int)(slot + 0x30ac);
                anchorC[i] = (int)(slot + 0x30c0);
            }
            FUN_005c6210(anchorA, 0x6181e0);       // build 4-slot roster widget list
        }
        obj->timer /*+0x16*/ = 0x4c;               // 76-frame timer
        FUN_005b8cf0(0x62);                        // SE cue
        break;

    case RP0_RENDER1:
        FUN_005b6900();
        break;

    case RP0_WAIT:
        if (--obj->timer < 0) obj->minor++;        // → BUILD2
        break;

    case RP0_BUILD2:
        obj->minor++;                              // → RENDER2
        FUN_005b68e0();
        obj->b42b /*+0x42b*/ = 0x1a;
        FUN_005c45b0(0x618090);
        break;

    case RP0_RENDER2:
        FUN_005b6900();
        break;

    case RP0_COMMIT: {
        obj->major++;                              // advance phase
        obj->minor = 0;

        struct room_snapshot snap;                 // [inferred] header + counts
        FUN_005c4600(&snap);
        obj->player_count /*+0x990*/ = snap.count;
        host_self_flag /*0x7012b0*/  = snap.selfFlag;
        memcpy((char*)obj + 0x53e, snap.name16, 0x10);   // room name → object
        memcpy((void*)0x874fa0,    snap.name16, 0x10);   // room name → shared mirror

        for (int i = 0; i < obj->player_count; i++) {
            char *slot = (char*)obj + i*0x3b0;
            strcpy(slot + 0x21dc, snap.player[i].name);
            strcpy(slot + 0x21ec, snap.player[i].profile);
            memcpy(slot + 0x2200, snap.player[i].stats, 0xf0);
            *(char*)(slot + 0x22f0) = snap.player[i].charSel;
            *(u32 *)(slot + 0x2308) = snap.player[i].selectWord;
        }

        // 13 header bytes → obj+0x4a4..+0x4b1 (+ shared 0x874fd8/9), then re-pack
        copy_header_fields(obj, &snap);
        obj->status_4a6 = obj->b4a5;
        obj->status_4a6 = FUN_005bad10((char*)obj + 0x1f5c,
                                       FUN_005bac60(0),
                                       obj->player_count,
                                       obj->b6 /*+0x6 host byte*/);
        break;
    }
    }
}
```

## Evidence
- Raw decompile: `switch(*(char*)(param_1+0xf))` lines 43-120; per-player unpack loop lines
  91-99 (+0x21dc/+0x21ec/+0x2200(0xf0)/+0x22f0/+0x2308); count from `*(byte*)(param_1+0x990)`;
  `FUN_005bad10(param_1+0x1f5c, FUN_005bac60(0), count, *(param_1+6))` lines 116-119.
- Cross-struct: 0xf0 stats length = member_record.charstats; 0x3b0 stride = roster_table 0x6c7c2c.
- Near-identical twin FUN_006173c0 (phase-0x0a) confirms the unpack shape.
- Runtime-unvalidated (no PINE/pcap trace of the commit).

## Remaining uncertainty
- Exact fields inside FUN_005c4600's snapshot and FUN_005bad10's return status not decoded.
- Meaning of obj+0x42b=0x1a and the two widget tables (0x6181e0/0x618090) is not confirmed.
- No clamp on obj+0x990 vs the 4-slot region — overrun risk is a hypothesis, not observed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00616d30.c`  — untouched decompiler output.
