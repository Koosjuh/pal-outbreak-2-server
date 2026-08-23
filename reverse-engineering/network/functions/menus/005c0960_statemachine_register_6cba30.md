# 0x005c0960 statemachine_register_6cba30

| field | value |
|---|---|
| Original address | 0x005c0960 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0960 |
| Resolved name | room_enter_sm_arm (statemachine_register_6cba30) |
| Subsystem | menus |
| Relevance | **core** (room enter / detail-fetch path) |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005f9280, FUN_005fa190, FUN_005fe8d0, FUN_0062de90 (room-list / room-detail UI)
**Callees:** — (arms async pump `FUN_005c3190`)
**Referenced globals:** 0x6cba54 (SM once-guard); 0x6cba44 (SM room index, u16); 0x6cba30 (pump fnptr ← FUN_005c3190); 0x6cba34 (completion callback ← param_2); 0x6cba50 (SM step)
**Referenced strings:** —
**Referenced opcodes:** the pump issues a room-record fetch/enter over the SN@P conn (`func_0x001de0c0`; op0a member-list / op06 join family)
**State vars:** 0x6cba54 guard, 0x6cba44 index, 0x6cba50 step

## Behavioral explanation
**Arms the room enter / detail-fetch state machine, keyed by a room-list index.** Guarded by the
once-flag 0x6cba54: if not already armed it stores `param_1 & 0xffff` as the target room index at
0x6cba44, installs pump `FUN_005c3190` at 0x6cba30, resets step 0x6cba50 to 0, and stores the
completion callback `param_2` at 0x6cba34. Returns 0 on arm, -1 if already busy.

The pump `FUN_005c3190` branches on host-vs-joiner (`cRam006ff2b0`):
- **joiner** (`0x6ff2b0 == 0`): step0 → step1, zeroes the op0a member-count `0x6ca890`, and issues a
  transport fetch `func_0x001de0c0(uRam006febac, *(index*0x24 + 0x6fee68), 0x5c3370)` — i.e. looks
  up registry-B room record `[index]` (stride 0x24) and requests its detail/enter; step1/ack1 →
  fetches per-area member data (`FUN_005c2f40(1, *(index*0x144 + 0x6cfa18))`).
- **host** (`0x6ff2b0 != 0`): short-circuits to success (step2), calls `FUN_005c2f40(0,0)` and, if
  not yet cached, copies member text into the per-area table at `(index-1)*0x144 + 0x6cfb76`.

Terminal states fire the stored callback with 0x00 (step2) or 0xFF (step0x10).

## Input / output
- **Params:** `param_1` — room index (only low 16 bits used); `param_2` — completion callback.
- **Returns:** `u32` — **0** if armed, **0xFFFFFFFF (-1)** if already armed.

## Side effects
- Writes guard 0x6cba54=1, index 0x6cba44, pump ptr 0x6cba30, step 0x6cba50=0, callback 0x6cba34.
- **Downstream (pump):** clears op0a count 0x6ca890, issues registry-B room fetch on the conn,
  populates per-area member tables (0x6cfa18/0x6cfb76 stride 0x144).

## Important branches
| condition | consequence |
|---|---|
| `cRam006cba54 == 0` (not armed) | arm: index=param_1&0xffff, pump=FUN_005c3190, step=0, cb=param_2; return 0 |
| `cRam006cba54 != 0` (already armed) | return -1 |

## Constants & flags
- `param_1 & 0xffff` — room index masked to u16.
- `0` / `-1` — armed-ok / already-armed.
- Registry-B stride `0x24` at 0x6fee68; per-area member stride `0x144` at 0x6cfa18 / 0x6cfb76;
  host/join discriminator 0x6ff2b0.

## Corrected reconstruction
```c
// Arm the room enter/detail-fetch SM for room-list entry `index`. Returns 0 if armed, -1 if busy.
i32 room_enter_sm_arm(unsigned index /*param_1*/, txn_done_cb done /*param_2*/)
{
    if (g_enter_guard /*0x6cba54*/ != 0)
        return -1;

    g_enter_index /*0x6cba44*/ = (u16)index;
    g_enter_guard = 1;
    g_enter_pump  /*0x6cba30*/ = &room_enter_pump /*FUN_005c3190*/;
    g_enter_step  /*0x6cba50*/ = 0;
    g_enter_done_cb /*0x6cba34*/ = done;
    return 0;
}
```

## Evidence
- Raw decompile: guard test on 0x6cba54; arm block writing 0x6cba44/0x6cba54/0x6cba30(=FUN_005c3190)/
  0x6cba50/0x6cba34; `param_1 & 0xffff`.
- Pump `FUN_005c3190` (read): host/join split on 0x6ff2b0; `func_0x001de0c0(conn, *(idx*0x24+0x6fee68),…)`
  registry-B fetch; `uRam006ca890 = 0` (op0a count reset); per-area 0x144-stride member tables.

## Remaining uncertainty
- Whether the fetch maps to op0a (member-list) vs op06 (join) at the wire is not pinned from this
  record; `FUN_005c2f40` internals not traced here. Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0960.c`  — untouched decompiler output.
