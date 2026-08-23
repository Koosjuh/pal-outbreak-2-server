# 0x001ca410 snap_lookup_query_sm

| field | value |
|---|---|
| Original address | 0x001ca410 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ca410 |
| Resolved name | snap_lookup_resolve_sm |
| Subsystem | session |
| Relevance | core |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** — (a phased sub-SM of the transfer/lookup engine)
**Callees:** FUN_001c3450 (arm/log marker), FUN_001c08e0 (async name/address resolve, returns -1/0/1)
**Referenced globals:** 0x35bed8 / 0x35bee0 = resolve out-params (resolved address / status); 0x35ccb3 = "session config read" once-flag (shared with 0x001c91d0)
**Referenced strings:** —
**Referenced opcodes:** marker ids 0x62/0x63/0x64 (passed to FUN_001c3450, not wire opcodes)
**State vars:** sm+0x00 mode; sm+0x0c major_phase [byte via idx3]; sm+0x0d phase; sm+0xd8 result_state [idx0x36]; sm+0xdc error [idx0x37]; sm+0xe0 count [idx0x38]

## Behavioral explanation
A three-phase resolver sub-SM (driven by the byte `sm+0xd`) that turns a name into an address before the session can open. It layers on top of `snap_recv_session_config` (0x001c91d0) via the shared once-flag `cRam0035ccb3`.

- **phase 0** (`sm+0xd == 0`): if the session-config has *not* been read yet (`0x35ccb3 == 0`), arm marker `0x62` and advance the phase by 1 or 2 depending on the engine mode `sm+0x00` (modes {0,1,3,7} step +1; modes {2,4,5,6} step +2 — i.e. skip the resolve for modes that already have an address), then clear the low cursors. If the config *has* been read, this SM is done: fully reset (`major_phase=0`, phase/cursors cleared) and hand back to the engine.
- **phase 1** (`sm+0xd == 1`): arm marker `0x63` and call the async resolver `FUN_001c08e0(&sm+0xe, &sm+0x10, 0x35bed8, 0x35bee0)`:
  - `-1` → resolve failed: error `1`, phase 7, teardown.
  - `1` → resolve complete: advance phase (`sm+0xd += 1`).
  - `0` → still pending: stay (retry next tick).
- **phase 2** (`sm+0xd == 2`): arm marker `0x64`; once the attempt/retry counter `sm+0xe0` reaches `100`, latch success: `result_state (sm+0xd8) = 3`, `error (sm+0xdc) = 0`.

The `0x62/0x63/0x64` values are `FUN_001c3450` watchdog/log markers (the same primitive the pump uses to tag its wait states), not wire opcodes.

## Input / output
- **Param:** `sm` — transfer/lookup engine object.
- **Returns:** `undefined8` — always `0`; status via `sm` fields.

## Side effects
- Phase 1 writes the resolver out-params into `0x35bed8`/`0x35bee0` (and `sm+0xe`/`sm+0x10`).
- Phase 0 (config-already-read): full SM reset.
- Phase 2 success: `sm+0xd8 = 3`, `sm+0xdc = 0`.
- Error leg: `sm+0xdc = 1`, `sm+0x0c = 7`, cursors cleared.

## Important branches
- phase 0: `0x35ccb3 == 0` → arm 0x62, step phase by `+1` (modes 0/1/3/7) or `+2` (modes 2/4/5/6); else → full reset.
- phase 1: resolver `-1`→error1/phase7; `1`→phase++; `0`→stay.
- phase 2: `count (sm+0xe0) >= 100` → result_state 3, error 0.

## Constants & flags
- markers `0x62/0x63/0x64` (arm/log tags per phase).
- resolver result contract: `-1`=fail, `0`=pending, `1`=done.
- `100` — phase-2 completion threshold on `sm+0xe0`.
- `result_state = 3` — resolve-complete signal to the parent engine.
- major phase `7` — error/teardown.

## Corrected reconstruction
```c
extern u8  g_cfg_read_done;   // 0x35ccb3 (shared with snap_recv_session_config)
extern u32 g_resolve_addr;    // 0x35bed8
extern u32 g_resolve_stat;    // 0x35bee0

undefined8 snap_lookup_resolve_sm(snap_xfer_sm *sm) {
    switch (sm->phase /*+0xd*/) {
    case 0:
        if (g_cfg_read_done == 0) {
            arm_marker(sm, 0x62, 4);                     // FUN_001c3450
            switch (sm->mode) {                          // +0x00
            case 0: case 1: case 3: case 7: sm->phase += 1; break; // needs resolve
            case 2: case 4: case 5: case 6: sm->phase += 2; break; // skip resolve
            }
            sm->cursor_e = 0; sm->timeout_ctr = 0;       // +0xe, +0x10
        } else {
            sm->phase_major = 0;                         // done: hand back
            sm->phase = 0; sm_clear_cursors(sm);
        }
        break;

    case 1: {
        arm_marker(sm, 0x63, 4);
        long r = resolve_async(&sm->cursor_e, &sm->out10, // FUN_001c08e0
                               &g_resolve_addr, &g_resolve_stat);
        if (r == -1) { sm->error = 1; sm->phase_major = 7; sm_clear_cursors(sm); }
        else if (r == 1) sm->phase += 1;                 // resolved
        /* r == 0: still pending */
        break;
    }

    case 2:
        arm_marker(sm, 0x64, 4);
        if (sm->count /*+0xe0*/ >= 100) {                // settle
            sm->result_state = 3;                        // +0xd8
            sm->error = 0;                               // +0xdc
        }
        break;
    }
    return 0;
}
```

## Evidence
- Decompile `FUN_001ca410.c`: the `cVar1 = *(char*)(puVar3+0xd)` phase switch; phase-2 `FUN_001c3450(...,100,4)` + `99 < puVar3[0x38]` → `puVar3[0x36]=3; puVar3[0x37]=0`; phase-1 `FUN_001c3450(...,99,4)` + `FUN_001c08e0(+0xe,+0x10,0x35bed8,0x35bee0)` with `-1`/`1` handling; phase-0 `cRam0035ccb3==0` fork with the mode-partitioned `+1`/`+2` phase step and the else-branch full reset.
- Shared once-flag `0x35ccb3` cross-referenced to `snap_recv_session_config` (0x001c91d0), which sets it after the config read.
- Runtime-unvalidated; **Medium** confidence (resolver contract and marker semantics inferred).

## Remaining uncertainty
- `FUN_001c08e0` — exact resolve semantics (DNS/name-server vs local table) and the meaning of its two out-params.
- Why phase 2 waits for a *count* of 100 rather than a direct completion signal (likely a fixed poll budget); the counter's increment site is outside this function.
- The mode partition (`+1` vs `+2`) is read directly but the mode→flow mapping is inferred from the pump.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ca410.c`  — untouched decompiler output.
