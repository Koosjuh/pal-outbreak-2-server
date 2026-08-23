# 0x006173c0 room_phase0a_setup_tick

| field | value |
|---|---|
| Original address | 0x006173c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006173c0 |
| Resolved name | room_phase0a_roster_unpack_tick |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00616c40 (room phase dispatcher)
**Callees:** FUN_005b68e0, FUN_005b6900, FUN_005bac60, FUN_005bad10, FUN_005c45b0, FUN_005c4600, FUN_005c6210; `func_0x001069a8` (memcpy), `func_0x00109eb8` (string copy)
**Referenced globals:** `uRam007012b0` (host/self flag); `0x874fa0` (roster name mirror, 0x10); `uRam00874fd8`/`uRam00874fd9`
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** obj+0xe major-state (++); obj+0xf minor-state (0..4); obj+0x97e branch flag; obj+0x990 player-count; obj+0x1f5c net-state buffer

## Behavioral explanation
Second variant of the room roster-unpack phase (dispatcher slot 0x0a). Functionally a twin of
`FUN_00616d30` phase-0: minor-state `obj+0xf` runs 0→4, and on state 4 it performs the same
**roster commit** — pull the decoded room snapshot from the +0x1f5c net buffer (FUN_005c4600),
store player count into obj+0x990, mirror the room name to shared globals, unpack each present
player's name/profile/stats(0xf0)/char-sel/select into the 0x3b0-stride roster rows, then re-pack
via FUN_005bad10 and store status at obj+0x4a6. The differences from 0x616d30 are: (1) no
initial `obj+0x16 = 0x4c` timer / SE cue in state 0; (2) the roster-widget builder uses layout
table **0x6181b0** (vs 0x6181e0); (3) the commit lives in state **4** instead of 5 (this variant
has one fewer intermediate render step). Likely the re-entry / refresh path for the same room
screen (e.g. roster update after a member join/leave) rather than first entry.

## Input / output
- **Params:** `param_1` — room-scene object pointer.
- **Return:** void.
- **Meaning:** ticks the 0x0a phase; on state 4 rebuilds the roster rows from received data and
  advances the major phase.

## Side effects
- **state 0:** if `obj+0x97e == 0` → minor = 2 (skip build); else minor = 1, FUN_005b68e0(),
  build three 4-entry anchor arrays (+0x309c/+0x30ac/+0x30c0 at 0x3b0 stride),
  `FUN_005c6210(anchors, 0x6181b0)`.
- **state 1:** `FUN_005b6900()`.
- **state 2:** minor = 3, FUN_005b68e0(), `obj+0x42b = 0x1a`, `FUN_005c45b0(0x618090)`.
- **state 3:** `FUN_005b6900()`.
- **state 4 (commit):** `obj+0xe++`, `obj+0xf = 0`; `FUN_005c4600(&snap)`;
  `obj+0x990 = snap.count`; `uRam007012b0 = snap.selfFlag`;
  `memcpy(obj+0x53e, snap.name16, 0x10)`, `memcpy(0x874fa0, snap.name16, 0x10)`;
  per-player loop `i<count`: `strcpy(+0x21dc,name)`, `strcpy(+0x21ec,profile)`,
  `memcpy(+0x2200, stats, 0xf0)`, `*(+0x22f0)=charSel`, `*(+0x2308)=selectWord`;
  copy 13 header bytes → obj+0x4a4..+0x4b1 + `0x874fd8`/`0x874fd9`; mirror obj+0x4a5→+0x4a6;
  `obj+0x4a6 = FUN_005bad10(obj+0x1f5c, FUN_005bac60(0), obj+0x990, obj+6)`.

## Important branches
- `if/else if` chain on `obj+0xf` for 4,3,2,1,0 (decompiler order). Data-dependent gate:
  state-0 `obj+0x97e == 0` → skip to state 2. Per-player loop bounded by obj+0x990 (byte count;
  same unclamped-vs-4-slots note as 0x616d30).

## Constants & flags
- minor states `0`=setup/build, `1`=render, `2`=second-build, `3`=render, `4`=commit. [High]
- `0x6181b0` = roster widget layout table for FUN_005c6210 (differs from 0x616d30's 0x6181e0). [High]
- `0x618090` = second widget/layout table (FUN_005c45b0) — same as 0x616d30. [High]
- `0x1a` = obj+0x42b value. [meaning unknown]
- `0xf0` stats length, `0x3b0` roster stride, per-slot field offsets — identical to 0x616d30. [High/Confirmed]

## Corrected reconstruction
```c
// Phase-0x0a: roster refresh/unpack (twin of phase-0, commit in state 4, table 0x6181b0).
enum { RPA_SETUP=0, RPA_RENDER1=1, RPA_BUILD2=2, RPA_RENDER2=3, RPA_COMMIT=4 };

void room_phase0a_roster_unpack_tick(struct room_scene *obj)
{
    switch (obj->minor /*+0xf*/) {
    case RPA_COMMIT: {
        obj->major++; obj->minor = 0;
        struct room_snapshot snap;
        FUN_005c4600(&snap);
        obj->player_count = snap.count;         // +0x990
        host_self_flag    = snap.selfFlag;      // 0x7012b0
        memcpy((char*)obj + 0x53e, snap.name16, 0x10);
        memcpy((void*)0x874fa0,    snap.name16, 0x10);
        for (int i = 0; i < obj->player_count; i++) {
            char *slot = (char*)obj + i*0x3b0;
            strcpy(slot + 0x21dc, snap.player[i].name);
            strcpy(slot + 0x21ec, snap.player[i].profile);
            memcpy(slot + 0x2200, snap.player[i].stats, 0xf0);
            *(char*)(slot + 0x22f0) = snap.player[i].charSel;
            *(u32 *)(slot + 0x2308) = snap.player[i].selectWord;
        }
        copy_header_fields(obj, &snap);          // +0x4a4..+0x4b1, 0x874fd8/9
        obj->status_4a6 = obj->b4a5;
        obj->status_4a6 = FUN_005bad10((char*)obj + 0x1f5c,
                                       FUN_005bac60(0),
                                       obj->player_count, obj->b6);
        break;
    }
    case RPA_RENDER2: FUN_005b6900(); break;
    case RPA_BUILD2:
        obj->minor = RPA_RENDER2;
        FUN_005b68e0(); obj->b42b = 0x1a; FUN_005c45b0(0x618090);
        break;
    case RPA_RENDER1: FUN_005b6900(); break;
    case RPA_SETUP:
        if (obj->has_roster_97e == 0) { obj->minor = RPA_BUILD2; }
        else {
            obj->minor = RPA_RENDER1;
            FUN_005b68e0();
            int a[4], b[4], c[4];
            for (int i = 0; i < 4; i++) {
                char *s = (char*)obj + i*0x3b0;
                a[i]=(int)(s+0x309c); b[i]=(int)(s+0x30ac); c[i]=(int)(s+0x30c0);
            }
            FUN_005c6210(a, 0x6181b0);
        }
        break;
    }
}
```

## Evidence
- Raw decompile lines 42-111: `if (cVar1=='\x04')` commit block identical to 0x616d30 state 5
  (same +0x21dc/+0x21ec/+0x2200(0xf0)/+0x22f0/+0x2308 loop and FUN_005bad10 call), state 0 uses
  `FUN_005c6210(aiStack_690, 0x6181b0)`.
- Diff vs 0x616d30 confirmed by side-by-side: no +0x16=0x4c / FUN_005b8cf0(0x62) in state 0;
  commit in state 4 not 5.
- Runtime-unvalidated.

## Remaining uncertainty
- Whether 0x0a is specifically the "member join/leave refresh" re-entry path vs another room
  screen is inferred from the missing intro timer, not traced.
- Same snapshot/status internals and count-clamp questions as 0x616d30.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006173c0.c`  — untouched decompiler output.
