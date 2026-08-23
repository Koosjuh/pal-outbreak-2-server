# 0x005c8ed0 session_arena_full_reset

| field | value |
|---|---|
| Original address | 0x005c8ed0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c8ed0 |
| Resolved name | session_arena_stream_reset |
| Subsystem | initialization |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** (raw xref list shows none direct — reached indirectly / via table; prior note: FUN_005e7e30)
**Callees:** FUN_005c92d0, FUN_005c9130 (pool free/realloc pair), FUN_005d8b00 (register w/ 0x642c68), FUN_005dd920 (register config/handler entry); libc memset `func_0x00106b60`
**Referenced globals:** 0x701068 (arena); +0x60dd0 (out-stream buf, 0x8000); +0x68dd4 (out-stream write ptr); 0x701070 (main state struct defaults); 0x642c68 (handler/table ptr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Resets the **message/out-stream substate** of the session arena (`iRam00701068`) without the full
context rebuild of `net_session_context_init`. It zeroes several sub-buffers, re-cycles the message pool
via the `FUN_005c92d0`/`FUN_005c9130` free+alloc pair, reinitializes the 0x8000-byte out-stream buffer
at `+0x60dd0` (resetting its write pointer at `+0x68dd4` to base+1 after writing a leading 0), clears a
16-entry ×8-byte table at `+0x68f94` (skipping the first two entries), reapplies default geometry/flags
to the main state struct at `0x701070`, and finally registers four config entries via `FUN_005dd920`
keyed by ids `0x5e/0x5f/0x60/0x63`. This is the "start a fresh outbound message stream" reset.

## Input / output
- **params:** none (void).
- **return:** void.

## Side effects
- `memset` sub-buffers: `arena+0x68e89`(0x100), `arena+0x4f97c`(4), `arena+0x68dd8`(0x50),
  `arena+0x60dd0`(0x8000 out-stream).
- `FUN_005c92d0()` then `FUN_005c9130()` — pool teardown + reallocation.
- Out-stream write ptr: `arena+0x68dd4 = arena+0x60dd0`; writes byte 0 at base; then increments ptr → base+1.
- Loop clears `arena + i*8 + 0x68f94` for `i = 2..0xf` (entries 2..15 of a 16-slot ×8 table).
- `FUN_005d8b00(0x642c68)` — installs/binds a handler or table (`0x642c68`).
- State `0x701070` defaults: `+0x38=0x1e`, `+0x2d=0`, `+0x2a=0`, `+0x2b=0`, `+4=0`, `+8=0`,
  `+0xc=0x248`, `+0x10=0x17c`, `+0x35=0xff`. Also clears `arena+0x68e78`(u16)=0, `arena+0x60dcf`=0.
- `FUN_005dd920` registrations: `(0x60, 0xff000000)`, `(0x5f, 5)`, `(0x5e, 1)`, `(0x63, 0x10000)`.

## Important branches
- Single straight-line reset. The only loop is the fixed `for i = 2 .. 15` table-clear (starts at 2, so
  entries 0 and 1 are preserved — likely reserved/self slots). No conditional/error paths.

## Constants & flags
- `0x8000` — out-stream buffer size at `arena+0x60dd0`; `arena+0x68dd4` = its write cursor.
- Table at `arena+0x68f94`: 16 entries × 8 bytes; entries 0–1 preserved, 2–15 zeroed. `[inferred stride from uVar1*8]`
- State geometry defaults: `+0xc = 0x248` (584), `+0x10 = 0x17c` (380) — likely a width/height or
  rect extent; `+0x38 = 0x1e` (30); `+0x35 = 0xff` (alpha/opaque). `[inferred]`
- `FUN_005dd920` ids: `0x5e, 0x5f, 0x60, 0x63` = registered config/message/timer type ids (NOT wire
  opcodes); values `1, 5, 0xff000000, 0x10000` are their parameters. `[inferred]`

## Corrected reconstruction
```c
// session_arena_stream_reset — reset the outbound message-stream substate of the session arena
void session_arena_stream_reset(void)
{
    char *arena = (char*)g_session_arena;     // iRam00701068

    memset(arena + 0x68e89, 0, 0x100);
    memset(arena + 0x4f97c, 0, 4);
    memset(arena + 0x68dd8, 0, 0x50);

    pool_free();                              // FUN_005c92d0
    pool_alloc();                             // FUN_005c9130

    memset(arena + 0x60dd0, 0, 0x8000);       // out-stream buffer
    *(void**)(arena + 0x68dd4) = arena + 0x60dd0;   // write ptr = base
    *(u8*)(arena + 0x60dd0) = 0;                     // leading 0
    *(char**)(arena + 0x68dd4) += 1;                 // advance past it

    for (uint16_t i = 2; i < 0x10; i++)       // clear table entries 2..15 (0,1 preserved)
        memset(arena + i*8 + 0x68f94, 0, 8);

    install_handler(0x642c68);                // FUN_005d8b00

    char *st = (char*)g_state;                // 0x701070
    st[0x38] = 0x1e;
    st[0x2d] = 0; st[0x2a] = 0; st[0x2b] = 0;
    *(u32*)(st + 4)   = 0;
    *(u32*)(st + 8)   = 0;
    *(u32*)(st + 0xc) = 0x248;                // width/extent [inferred]
    *(u32*)(st + 0x10)= 0x17c;                // height/extent [inferred]
    st[0x35] = 0xff;
    *(u16*)(arena + 0x68e78) = 0;
    *(u8*)(arena + 0x60dcf)  = 0;

    cfg_register(0x60, 0xff000000);           // FUN_005dd920
    cfg_register(0x5f, 5);
    cfg_register(0x5e, 1);
    cfg_register(0x63, 0x10000);
}
```

## Evidence
- Raw decompile `FUN_005c8ed0.c` lines 11-41 (sub-buffer memsets 11-13; pool pair 14-15; out-stream reset
  16-20; table loop 21-24; state defaults 26-34; cfg_register calls 37-40).
- Shares arena offsets (`+0x60dd0` out-stream, `+0x68dd4` write ptr, `0x701070` state) with
  `net_session_context_init` — same session hub.
- Confidence **High** on control flow. Runtime validation pending; geometry defaults and cfg ids inferred.

## Notes / uncertainty
Raw xref table lists no callers (previous classification named `FUN_005e7e30`); likely invoked via a
handler table. `FUN_005dd920`'s registered ids (0x5e–0x63) are config/timer slots, not SN@P wire opcodes.
Name refined `session_arena_full_reset` → `session_arena_stream_reset` (it resets the message-stream
substate, not the whole context).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c8ed0.c`  — untouched decompiler output.
