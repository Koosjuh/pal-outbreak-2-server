# 0x005b53f0 cmd_handler_05_room_update

| field | value |
|---|---|
| Original address | 0x005b53f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b53f0 |
| Resolved name | roster_record_apply_filtered |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (installed by FUN_005b25c0 as selector-5 handler via FUN_005bdf70(5,0x5b53f0))
**Callees:** FUN_005c4b90 (decode/pop next pushed record), FUN_005f50d0 (apply record)
**Referenced globals:** 0x6c4b90 cRam006c4b90 (current screen/mode); 0x6c7c2c roster slot table (4 × 0x3b0, byte0=occupied); 0x6c7c3c per-slot name (+0x10 in slot)
**Referenced strings:** —
**Referenced opcodes:** — (selector-5 registered handler; consumes server room/roster push records)
**State vars:** cRam006c4b90 screen/mode gate; record type byte `cStack_c`

## Behavioral explanation
Registered **selector-5** handler: the server-to-client room/roster *record apply* path. It pops one decoded record from the push queue (`FUN_005c4b90` fills a stack record: 16-byte header, 20-byte name/key, 256-byte body, then a 1-byte record **type** and 3 flag bytes), then gates it by the current screen mode `cRam006c4b90` before applying it via `FUN_005f50d0`.

Type-0 records apply unconditionally. Otherwise the record must match the current screen: mode 4 accepts only type-4 records, mode 0xc only type-0xc, modes 2 and 0xe accept anything except type-4. For the in-room modes (4/0xc) it additionally requires the record's name (the 20-byte key) to match a **seated roster slot** — it scans the 4-slot table at 0x6c7c2c (stride 0x3b0, occupied byte at +0, name at +0x10 / abs 0x6c7c3c) and only applies when a name matches (`func_0x00109d70` == 0). Records whose name matches no seated player are dropped. This is the mechanism that keeps room/roster updates scoped to the currently-displayed room and to known members — directly relevant to why a freshly-created room with no committed roster shows no player rows (nothing matches the seated-slot scan).

## Input / output
- No params (reads globals + the decode buffer). Returns `void`.
- Consumes exactly one queued record per call.

## Side effects
- `FUN_005f50d0(hdr, name, body256, type, f0, f1, f2)` applies the record (updates room/roster/player UI state). No globals written directly here beyond what the callees touch.

## Important branches
- **type == 0** → apply immediately (`goto APPLY`).
- **mode == 4** → apply only if type == 4, else drop.
- **mode == 0xc** → apply only if type == 0xc, else drop.
- **mode == 2 or 0xe** → drop if type == 4, else apply.
- **any other mode** → drop (return).
- **modes 4/0xc that passed the type gate** → require name match against a seated slot; apply on first match, drop if none.

## Constants & flags
- `cRam006c4b90` screen/mode: `2`,`0xe` = lobby/area-list screens (broad apply); `4`,`0xc` = in-room/in-scenario screens (member-scoped apply).
- Record type byte mirrors the mode namespace (`0`=global, `4`/`0xc`=room-scoped).
- Roster slot: `+0x00` occupied flag, `+0x10` (abs 0x6c7c3c) name; stride `0x3b0`; 4 slots.

## Corrected reconstruction
```c
extern char g_screen_mode;   // cRam006c4b90 (lobby_state_block screen_id)

// roster slots @0x6c7c2c, stride 0x3b0
#define ROSTER_OCCUPIED(i) (*(char *)((i) * 0x3b0 + 0x6c7c2c))
#define ROSTER_NAME(i)     ((char *)((i) * 0x3b0 + 0x6c7c3c))   // slot+0x10

void roster_record_apply_filtered(void) {
    struct {
        uint8_t hdr[16];     // auStack_130
        uint8_t name[20];    // auStack_120 (match key)
        uint8_t body[256];   // auStack_10c
        char    type;        // cStack_c
        uint8_t f0, f1, f2;  // uStack_b/a/9
    } rec;

    FUN_005c4b90(&rec);                 // decode/pop next pushed record

    if (rec.type == 0)
        goto APPLY;                     // type-0: global, always apply

    switch (g_screen_mode) {
    case 4:                             // in-room
        if (rec.type != 4) return;
        break;
    case 0xc:                           // in-scenario
        if (rec.type != 0xc) return;
        break;
    case 2:                             // lobby/area
    case 0xe:
        if (rec.type == 4) return;
        goto APPLY;                     // broad apply, no seated-slot scan
    default:
        return;                         // unrelated screen: drop
    }

    // modes 4 / 0xc: only apply if the record names a seated member
    for (int i = 0; i < 4; i++) {
        if (ROSTER_OCCUPIED(i) != 0 &&
            func_0x00109d70(ROSTER_NAME(i), rec.name) == 0)   // name match
            goto APPLY;
    }
    return;                             // no seated member matched -> drop

APPLY:
    FUN_005f50d0(&rec, rec.name, rec.body, rec.type, rec.f0, rec.f1, rec.f2);
}
```

## Evidence
- Raw decompile `FUN_005b53f0.c` (mode switch on `cRam006c4b90`, 4-iteration `0x3b0`-stride scan, `func_0x00109d70` name compare).
- 0x6c7c2c roster table (4×0x3b0) and 0x6c4b90 screen_id from GLOBALS.md / lobby_state_block.md / member_record.md.
- Installed as selector-5 per FUN_005b25c0 (lobby_init_and_register_handlers).
- Runtime-unvalidated.

## Remaining uncertainty
- The precise semantic difference between record types 4 and 0xc (in-room vs in-scenario) is inferred from the mode pairing.
- `FUN_005c4b90` field boundaries taken from the stack layout; the 20-byte "name" key vs 16-byte header split is structural inference.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b53f0.c`  — untouched decompiler output.
