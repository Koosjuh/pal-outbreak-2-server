# 0x001d4de0 snap_session_close

| field | value |
|---|---|
| Original address | 0x001d4de0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d4de0 |
| Resolved name | snap_conn_destroy |
| Subsystem | session |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (public teardown API; inverse of snap_conn_create)
**Callees:** FUN_001e3f98 (close socket), FUN_001e1dd0 (transport subsys teardown)
**Referenced globals:** 0x0025b78c = current-connection ptr (cleared here)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** DAT_0025b78c

## Behavioral explanation
The transport connection **destructor** — the inverse of `snap_conn_create` (0x001d46ec). Guarded so it only acts when called with the sentinel `param_1 == 1` and a live connection is published (`DAT_0025b78c != 0`). It closes the socket (`FUN_001e3f98(*conn)` — the socket fd is stored at `conn+0x00`), tears down the transport subsystem (`FUN_001e1dd0`), and nulls the global connection pointer so no further transport code touches freed state. A bad guard (wrong param or no connection) returns `-1` and does nothing.

Note it frees the socket + subsystem but the guard/return contract implies the conn struct's own free happens in `FUN_001e1dd0` or a later step; this function's job is the ordered shutdown + pointer clear.

## Input / output
- **Param:** `param_1` (int) — must be `1` (API-shape sentinel, mirrors the `snap_close` wrapper convention seen on op02).
- **Returns:** `undefined4` — `0` on success, `-1` (0xffffffff) if the guard fails.

## Side effects
- `FUN_001e3f98(conn->sock)` — closes the UDP socket.
- `FUN_001e1dd0()` — transport subsystem teardown.
- `DAT_0025b78c = 0` — clears the current-connection global.

## Important branches
- `param_1 == 1 && DAT_0025b78c != 0` → close + teardown + clear, return 0.
- else → return -1 (no-op).

## Constants & flags
- sentinel `param_1 == 1`.
- `-1` (0xffffffff) = guard-failed / no-op result.

## Corrected reconstruction
```c
extern snap_connection *g_conn;   // DAT_0025b78c

undefined4 snap_conn_destroy(int which) {
    if (which == 1 && g_conn != 0) {
        close_socket(g_conn->sock);   // FUN_001e3f98(*conn) — fd @ conn+0x00
        transport_subsys_teardown();  // FUN_001e1dd0
        g_conn = 0;
        return 0;
    }
    return -1;
}
```

## Evidence
- Decompile `FUN_001d4de0.c`: `(param_1 == 1) && (DAT_0025b78c != 0)` guard; `FUN_001e3f98(*DAT_0025b78c)` (dereferences conn to get the socket fd at +0x00, matching `snap_conn_create` `*puVar1 = socket`); `FUN_001e1dd0()`; `DAT_0025b78c = 0`; else `0xffffffff`.
- Pairs with `snap_conn_create` (0x001d46ec) which published `DAT_0025b78c` and set `*conn = socket`.
- Runtime-unvalidated.

## Remaining uncertainty
- Whether `FUN_001e1dd0` also frees the 0x624 conn block and its sub-pools, or only the subsystem singletons.
- The `param_1 == 1` sentinel's full meaning (likely an API-version/mode selector as with `snap_close`).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d4de0.c`  — untouched decompiler output.
