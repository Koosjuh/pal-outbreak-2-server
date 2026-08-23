# 0x001c91d0 snap_recv_session_port

| field | value |
|---|---|
| Original address | 0x001c91d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c91d0 |
| Resolved name | snap_recv_session_config |
| Subsystem | session |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (dispatched by the lookup-engine SM as a substate handler)
**Callees:** FUN_00106b60 (memset), FUN_001c3b90 (recv_n bytes), FUN_001c3ab0 (derive/parse u16 from datagram)
**Referenced globals:** 0x35cc70 = 0x3f-byte session-config buffer; 0x35ccb0 = derived session/server port (u16); 0x35ccb3 = "config read" once-flag
**Referenced strings:** —
**Referenced opcodes:** — (reads a directory-server reply body)
**State vars:** obj+0xc phase(major); obj+0xd substate; obj+0xdc error; cRam0035ccb3 once-flag

## Behavioral explanation
On the **first** pass (`cRam0035ccb3 == 0`) this reads the directory server's session-config datagram: it zero-fills the 0x3f-byte buffer at `0x35cc70`, receives `0x3e` bytes into it, then derives a u16 session/server port via `FUN_001c3ab0` and stores it at `0x35ccb0`. On success it advances the SM substate to `0x31` and latches the once-flag `cRam0035ccb3 = 1` so subsequent passes skip the read and just re-arm substate `0x31`. Both failure legs (short read, or a zero derived port) stamp error `-56` (0xffffffc8) and drop the SM into the error phase `7`.

The derived port (`0x35ccb0`) is consumed downstream by the connect step (`FUN_001c9850`) to open the actual session channel — i.e. this handler is the "read where the game session lives" hop of the directory handshake.

## Input / output
- **Param:** `obj` — lookup-engine SM object.
- **Returns:** `undefined8` — always `0` (status is signalled through obj fields, not the return value).

## Side effects
- `memset(0x35cc70, 0, 0x3f)` then `recv 0x3e` bytes into `0x35cc70`.
- `0x35ccb0 = FUN_001c3ab0(obj)` (derived port).
- Success: `obj+0xd = 0x31`, `cRam0035ccb3 = 1`.
- Failure: `obj+0xdc = -56`, `obj+0xc = 7`, cursor block (0xd/0xe/0xf/0x10/0x12/0x14/0x16) cleared.

## Important branches
- `cRam0035ccb3 != 0` → skip read; fall through to set substate 0x31 and re-latch flag.
- `FUN_001c3b90(...) < 1` (short/failed recv) → error -56, phase 7, reset cursors, return.
- `FUN_001c3ab0(obj) == 0` (no/invalid port) → error -56, phase 7, reset cursors, return.
- else → substate 0x31, flag=1.

## Constants & flags
- `0x3e` bytes read into a `0x3f`-byte buffer (1 byte NUL slack).
- `0xffffffc8` = `-56` — config-read failure code.
- major phase `7` — SM error/teardown.
- `cRam0035ccb3` — one-shot: `1` once the config has been read.

## Corrected reconstruction
```c
extern u8   g_cfg_read_done;   // cRam0035ccb3
extern u8   g_session_cfg[0x3f]; // 0x35cc70
extern u16  g_session_port;    // 0x35ccb0

undefined8 snap_recv_session_config(snap_lookup_obj *obj) {
    if (g_cfg_read_done == 0) {
        memset(g_session_cfg, 0, 0x3f);
        if (recv_n(obj, g_session_cfg, 0x3e) < 1) {           // short read
            obj->error = -56; obj->phase = 7; sm_clear_cursors(obj);
            return 0;
        }
        g_session_port = derive_port(obj);                    // FUN_001c3ab0
        if (g_session_port == 0) {                            // invalid port
            obj->error = -56; obj->phase = 7; sm_clear_cursors(obj);
            return 0;
        }
    }
    obj->substate = 0x31;
    g_cfg_read_done = 1;
    return 0;
}
```

## Evidence
- Decompile `FUN_001c91d0.c`: `memset(0x35cc70,0,0x3f)`; `FUN_001c3b90(obj,0x35cc70,0x3e)` recv; `sRam0035ccb0 = FUN_001c3ab0(obj)`; the two `-56`/phase-7 error legs; `obj+0xd = 0x31; cRam0035ccb3 = 1`.
- Prior note: `0x35ccb0` consumed by `FUN_001c9850` (connect) — the port feeds the session-open.
- Runtime-unvalidated.

## Remaining uncertainty
- Exact structure of the 0x3e-byte config record (fields beyond the derived port).
- Whether `FUN_001c3ab0` derives the port purely from the datagram or mixes in local key material (it is the same helper used to seed session keys elsewhere).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c91d0.c`  — untouched decompiler output.
