# 0x005b41b0 roomjoin_state3_create

| field | value |
|---|---|
| Original address | 0x005b41b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b41b0 |
| Resolved name | create_room_entry_sm |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3c30
**Callees:** FUN_005b45f0, FUN_005b47a0, FUN_005b4860, FUN_005b4c80, FUN_005b7fd0, FUN_005ba570, FUN_005ba7b0, FUN_00618b60
**Referenced globals:** 0x6c4630 cRam006c4630 (room-count / slot-taken flag); 0x6c4674 room-meta/player table (stride 0x14, byte0=occupied); 0x6c4a84 selected-room name scratch
**Referenced strings:** —
**Referenced opcodes:** submits request tags 0x16/0x17 (create name/password widgets) via FUN_005b7fd0
**State vars:** widget+1 phase; widget+2 subphase; widget+3 timer/retry ctr; widget+7 room slot idx; screen+0x43c confirm_result

## Behavioral explanation
The client-side **create-room name/password entry + submit** state machine, one node of the join/create screen SM driven by FUN_005b3c30. `param_2` is the widget's own state block; `param_1` is the owning screen struct whose `+0x43c` field is the *confirm result* the child prompts write back (-1 = cancel, 0 = OK, 1 = pending/retry).

A 7-phase machine (`widget[1]` = phase 0..6). Phase 0 inits; phase 1 waits for a 10-row list widget (`FUN_005b45f0(...,10)`). Phase 2 tests the target room slot (`g_room_meta[idx].occupied` at 0x6c4674) against the room-count/slot-taken flag `cRam006c4630`: an empty slot with count==0 raises a prompt and returns busy; an occupied slot advances to the name-entry phase (3). Phases 3 and 4 run the two text-entry sub-flows — phase 3 builds request-tag **0x17**, phase 4 builds request-tag **0x16** — each with sub-states {0=open prompt, 1=keyboard tick, 2=evaluate confirm_result, 3=list re-tick}. Phases 5/6 are guarded re-entry gates that bounce back to phase 4 once the slot frees. This is the create-room front-end that ultimately drives the op04 create-slot / registration path; it never emits op04 itself — it collects name/password and submits UI request tags 0x16/0x17.

## Input / output
- `param_1` (int): screen struct base. Field `+0x43c` = confirm_result byte (shared with the join path).
- `param_2` (void*): widget state block (`w`). `w[0]` reset marker, `w[1]` phase, `w[2]` subphase, `w[3]` timer, `w[7]` room slot index.
- Return `undefined4`: `0xFFFFFFFF` = still running (default); `1` = target room slot occupied (abort/hold, phases 5/6); `0xFFFFFFFF` also on the busy-prompt path in phase 2.

## Side effects
- Writes `screen+0x43c` (=1 when opening a prompt).
- Copies selected room name `g_room_meta[idx]` → scratch `0x6c4a84` (phase 3, result==0).
- UI: `FUN_00618b60` (SFX/refresh), `FUN_005b4c80(3)`, `FUN_005ba570(0x20)` (build prompt), `FUN_005ba7b0` (teardown/commit).
- Submits app request via `FUN_005b7fd0(tag, 1, screen+0x43c, 2)` with tag 0x17 (phase 3) / 0x16 (phase 4).

## Important branches
- **phase 2, slot empty & count==0** → open busy prompt (`sub=1`), SFX, `return -1` (hold).
- **phase 2, slot empty & count!=0** → full reset (`w[0]=w[1]=w[2]=0`) — abandon.
- **phase 2, slot occupied** → advance to phase 3 (name entry).
- **phase 3/4 sub==2, confirm_result==-1 or 1** → cancel/retry (reset or bounce to phase 0).
- **phase 3 sub==2, confirm_result==0** → phase 5 + copy room name to scratch.
- **phase 4 sub==2, confirm_result==0** → phase 6.
- **phase 4 sub==2, confirm_result<1 (i.e. -1)** → hard reset to phase 0.
- **phase 5/6 sub==0, slot occupied** → `return 1` (someone else took it); else arm confirm tick, on completion `phase=4`.

## Constants & flags
- `screen+0x43c` confirm_result: `-1`=cancel, `0`=OK, `1`=pending/retry.
- Request tags `0x16`/`0x17`: create-room password/name prompt widgets (submitted via FUN_005b7fd0).
- `FUN_005b45f0(w,10)`: list widget tick, 10 rows.

## Corrected reconstruction
```c
// screen+0x43c: confirm result written by the child prompts (-1 cancel / 0 ok / 1 retry)
enum { CONF_CANCEL = -1, CONF_OK = 0, CONF_RETRY = 1 };

// room-meta / player table @0x6c4674, stride 0x14, byte0 = slot occupied
#define ROOM_META(idx)  (*(char *)((idx) * 0x14 + 0x6c4674))
extern char g_room_count_flag;   // cRam006c4630  (0 => no rooms / slot free)

typedef struct {
    uint8_t reset_marker; // +0
    uint8_t phase;        // +1
    uint8_t sub;          // +2
    uint8_t timer;        // +3
    uint8_t _pad[3];
    uint8_t room_idx;     // +7
} create_widget_t;

undefined4 create_room_entry_sm(int screen, create_widget_t *w /*param_2*/) {
    switch (w->phase) {
    case 0: // init
        w->phase++; w->timer = 0; w->sub = 0;
        break;

    case 1: // wait for the 10-row list widget
        if (FUN_005b45f0(w, 10) != 0) { w->phase++; w->timer = 0; w->sub = 0; }
        break;

    case 2:
        if (w->sub == 0) {
            if (ROOM_META(w->room_idx) == 0) {           // target slot empty
                if (g_room_count_flag == 0) {            // no room yet -> busy prompt
                    w->sub = 1; w->timer = 0;
                    FUN_00618b60(); FUN_005ba7b0();
                    return 0xffffffff;
                }
                w->reset_marker = 0; w->phase = 0; w->sub = 0; // abandon
            } else {
                w->phase = 3; w->sub = 0; w->timer = 0;  // slot present -> name entry
            }
        } else if (FUN_005b47a0(w) != 0) {               // prompt confirm tick
            w->phase = 0; w->sub = 0;
        }
        break;

    case 3: // NAME entry (request tag 0x17)
        if (w->sub == 2) {
            char r = *(char *)(screen + 0x43c);
            if (r == CONF_CANCEL || r == CONF_RETRY) {
                if (g_room_count_flag == 0) { w->phase = 0; w->sub = 0; }
                else { w->reset_marker = 0; w->phase = 0; w->sub = 0; }
            } else if (r == CONF_OK) {
                w->phase = 5; w->sub = 0;
                func_0x00109eb8(0x6c4a84, ROOM_META_PTR(w->room_idx)); // copy room name
            }
        } else if (w->sub == 1) {
            if (FUN_005b4860() != 0) w->sub++;            // keyboard tick
        } else if (w->sub == 0) {
            w->sub = 1; w->timer = 0;
            *(char *)(screen + 0x43c) = 1;
            FUN_00618b60(); FUN_005b4c80(3); FUN_005ba570(0x20);
            FUN_005b7fd0(0x17, 1, screen + 0x43c, 2);     // submit NAME prompt
            FUN_005ba7b0();
        }
        break;

    case 4: // PASSWORD entry (request tag 0x16)
        if (w->sub == 3) {
            if (FUN_005b45f0(w, 10) != 0) { w->sub = 0; w->timer = 0; }
        } else if (w->sub == 2) {
            char r = *(char *)(screen + 0x43c);
            if (r == 0)      { w->phase = 6; w->sub = 0; w->timer = 0; }
            else if (r < 1)  { w->reset_marker = 0; w->phase = 0; }   // r == -1
            else             { w->sub = 3; w->timer = 0; }            // r == 1 retry
        } else if (w->sub == 1) {
            if (FUN_005b4860() != 0) w->sub++;
        } else if (w->sub == 0) {
            w->sub = 1; w->timer = 0;
            FUN_00618b60(); FUN_005b4c80(3); FUN_005ba570(0x20);
            *(char *)(screen + 0x43c) = 1;
            FUN_005b7fd0(0x16, 1, screen + 0x43c, 2);     // submit PASSWORD prompt
            FUN_005ba7b0();
        }
        break;

    case 5:
    case 6: // guarded re-entry: hold if the slot got taken, else confirm -> phase 4
        if (w->sub == 0) {
            if (ROOM_META(w->room_idx) != 0) return 1;    // occupied by someone else
            w->sub = 1; w->timer = 0;
        } else if (FUN_005b47a0(w) != 0) {
            w->phase = 4; w->sub = 0;
        }
        break;
    }
    return 0xffffffff;
}
```

## Evidence
- Raw decompile `FUN_005b41b0.c` (switch on `puVar3[1]`, sub on `puVar3[2]`).
- Caller FUN_005b3c30 = the create/join screen SM; callee FUN_005b7fd0 is the shared app-request submit (also used for op09/op11/op23 elsewhere — PACKET_INDEX), here with widget tags 0x16/0x17.
- Globals 0x6c4674 (room-meta stride 0x14) and 0x6c4630 from GLOBALS.md.
- Runtime-unvalidated (no trace of tags 0x16/0x17 on the wire yet).

## Remaining uncertainty
- Exact wire effect of request tags 0x16 vs 0x17 (which is name vs password) is inferred from ordering; not wire-confirmed.
- `FUN_005b47a0` / `FUN_005b45f0` return semantics (confirm vs list-ready) inferred from usage.
- `screen+0x43c` sign convention (`<1` vs `==-1`) preserved exactly but not runtime-checked.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b41b0.c`  — untouched decompiler output.
