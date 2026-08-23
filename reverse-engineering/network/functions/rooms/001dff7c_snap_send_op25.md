# 0x001dff7c snap_send_op25

| field | value |
|---|---|
| Original address | 0x001dff7c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dff7c |
| Resolved name | snap_send_op25_name2int |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d5288 (seg-alloc), FUN_001ed2c0 (payload-reserve), FUN_0010a4f0 (memcpy 16B), FUN_001e180c (frame+enqueue), FUN_001d4d24 (register completion)
**Referenced globals:** 0x0025b78c (`snap_connection*`); 0x0025b790 (errno); conn+0x50c (send-lock)
**Referenced opcodes:** 0x25 (reliable name+2-int request)
**State vars:** conn+0x50c send-lock; DAT_0025b790 errno

## Behavioral explanation
Sends a **reliable** fixed-size (0x18-byte) op-0x25 request whose body is a 16-byte name/handle field followed by two big-endian u32 params. Enqueues with who = `0xb000` (reliable DATA class) and opcode 0x25, then registers an op-0x29 completion callback (tag **0x29**, arg param_5). The 0x18 body = `char name[16]` + `u32 a` + `u32 b`. Given op25 sits just below op26(prepare)/op2b(enter) in the room-setup band and carries a name + two integers, this is a **reliable room/slot request keyed by name** (exact role not runtime-confirmed).

## Input / output
- `param_1` (int) — channel token; must be 1.
- `param_2` (void*) — 16-byte name/handle source (copied raw).
- `param_3` (u32) — first param, htonl into body+0x10.
- `param_4` (u32) — second param, htonl into body+0x14.
- `param_5` — completion-callback context (tag 0x29).
- **return** (u32) — 0 success / 0xFFFFFFFF failure.

## Side effects
- Reserves an 0x18-byte segment; DAT_0025b790 on failure.
- On enqueue success registers a pending op29 completion (`FUN_001d4d24(1,0x29,param_5)`).

## Important branches
- `chan!=1 || conn==0` → errno 100, -1.
- `+0x50c != 0` → errno 0x66, -1.
- alloc fail → errno 0x65, -1.
- **No null-check** on `FUN_001ed2c0` return (used unconditionally).
- enqueue ok → register cb 0x29, return 0; else errno 0x66, -1.

## Constants & flags
- who `0xb000` = reliable(0x8000) | 0x2000 | DATA(0x1000).
- completion tag `0x29`.
- fixed body 0x18 = 16 (name) + 4 + 4.
- errno 0x64/0x65/0x66.

## Corrected reconstruction
```c
struct op25_body {          // 0x18 bytes on wire
    char name[16];          // param_2, raw 16-byte copy
    u32  a;                 // htonl(param_3)
    u32  b;                 // htonl(param_4)
};

u32 snap_send_op25_name2int(int chan, const void *name16, u32 a, u32 b, void *cb_ctx)
{
    snap_connection *conn = DAT_0025b78c;
    if (chan != 1 || conn == 0)          { DAT_0025b790 = 100;  return -1; }
    if (conn->send_lock /*+0x50c*/ != 0) { DAT_0025b790 = 0x66; return -1; }

    int seg = seg_alloc(conn, 0x18);
    if (seg == 0)                        { DAT_0025b790 = 0x65; return -1; }

    struct op25_body *b_ = seg_reserve(seg, 0x18);   // NOTE: not null-checked
    memcpy16(b_->name, name16, 0x10);                // FUN_0010a4f0
    b_->a = htonl(a);
    b_->b = htonl(b);

    if (frame_enqueue(conn, seg, 0xb000, 0x18, 0x25, 0) == 0) {
        register_completion(1, 0x29, cb_ctx);        // FUN_001d4d24
        return 0;
    }
    DAT_0025b790 = 0x66; return -1;
}
```

## Evidence
- Raw: `FUN_001dff7c.c` (lines 14-36): alloc 0x18, `FUN_0010a4f0(body,param_2,0x10)`, two htonl at +0x10/+0x14, `FUN_001e180c(...,0xb000,0x18,0x25,0)`, then `FUN_001d4d24(1,0x29,param_5)`.

## Remaining uncertainty
- Precise op25 role (which room/slot request) and the meaning of the two u32 params are not runtime-confirmed. Missing reserve null-check may be a decompiler artifact. Helper names inferred.
