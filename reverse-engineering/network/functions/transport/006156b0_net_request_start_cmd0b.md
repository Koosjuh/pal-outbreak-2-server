# 0x006156b0 net_request_open_stream_cmd0b

| field | value |
|---|---|
| Original address | 0x006156b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006156b0 |
| Resolved name | net_request_open_stream_cmd0b |
| Subsystem | transport |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** — (no in-corpus caller; likely dispatched via table/overlay entry)
**Callees:** FUN_00615670 (net_request_prepare), FUN_00616470 (register handle), FUN_00616518 (close handle)
**Referenced globals:** 0x70d200 (resolver channel); 0x70d240 (request buffer); uRam0070d248 (key field)
**Referenced strings:** —
**Referenced opcodes:** channel command 0x0b (transport-level, not a SN@P app opcode)
**State vars:** uRam0070d248

## Behavioral explanation
Opens a streaming/subscription request on the resolver channel. Given a record descriptor `param_1`:
1. Reject a NULL descriptor with `-0x65` (-101).
2. Register a client handle for the descriptor: `FUN_00616470(param_1, param_2, param_3, 1)`. Fail → return `-1`.
3. `net_request_prepare()` (open channel + clear buffer).
4. Stash the descriptor's leading word as the request key: `uRam0070d248 = *param_1`.
5. Issue channel **command 0x0b**: `func_0x00115c68(0x70d200, 0xb, 0, buf=0x70d240, 0x1000, buf=0x70d240, 0x1000, 0)` — a bidirectional ioctl with 0x1000-byte send/recv windows over the request buffer.
   - On failure (`< 0`): close the handle (`FUN_00616518`), return `-1`.
   - On success: bind the completion callback/context (`func_0x00112730(handle, param_4)`) and return the handle.

Command `0x0b` here is the **channel/socket command**, unrelated to SN@P app-opcode 0x0c "prepare"; do not conflate.

## Input / output
- `param_1` (long) — record/query descriptor pointer (NULL → EINVAL).
- `param_2, param_3` (undefined8) — passed to the handle registrar (params/limits).
- `param_4` (undefined8) — completion callback/context bound on success.
- Return `long`: registered handle (>0) on success; `-0x65` (NULL arg); `-1` (register or command failure).

## Side effects
- Allocates/registers a request handle (`616470`).
- Writes `uRam0070d248` (request key).
- Sends channel command `0x0b` with the 0x70d240 buffer.
- Binds callback context (`112730`) or tears down the handle (`616518`) on failure.

## Important branches
| Condition | Consequence |
|---|---|
| `param_1 == 0` | return -0x65 (EINVAL) |
| `616470(...) < 0` | return -1 (register failed) |
| `115c68(cmd 0xb) < 0` | close handle (616518), return -1 |
| `115c68 >= 0` | bind cb (112730), return handle |

## Constants & flags
- `-0x65` (-101) — NULL-argument error (same code the txn recovery send uses as a selector; here it's an errno-style return).
- `0x0b` — resolver channel command (open stream / long-poll).
- `0x1000` (4096) — send & recv window sizes for the command.

## Corrected reconstruction
```c
long net_request_open_stream_cmd0b(record_desc *desc /*param_1*/,
                                   undefined8 p2, undefined8 p3, void *cb /*param_4*/)
{
    if (desc == NULL) return -0x65;                       // EINVAL

    long h = req_handle_register(desc, p2, p3, 1);        // 616470
    if (h < 0) return -1;

    net_request_prepare();                                // 615670
    g_req_key /*uRam0070d248*/ = *(uint32_t*)desc;

    long r = sys_channel_cmd(RESOLVER /*0x70d200*/, 0x0b, 0,
                             REQBUF /*0x70d240*/, 0x1000,
                             REQBUF, 0x1000, 0);           // 115c68
    if (r < 0) { req_handle_close(h); return -1; }        // 616518

    req_bind_callback(h, cb);                             // 112730
    return h;
}
```

## Evidence
- Symmetric with `net_request_abort_cmd0f` (command 0x0f teardown) on the same channel/buffer → 0x0b = open/start, 0x0f = abort.
- NULL-guard returns the POSIX-ish `-101`.
- **Runtime-unvalidated**; no in-corpus caller. Confidence Medium.

## Remaining uncertainty
Exact meaning of command `0x0b` (subscribe / long-poll / open-stream), and the descriptor layout `param_1`, are unproven. Caller unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006156b0.c`  — untouched decompiler output.
