# 0x001e094c snap_send_op48_name_query

| field | value |
|---|---|
| Original address | 0x001e094c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e094c |
| Resolved name | snap_send_op48_name_query |
| Subsystem | roster |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_00106b60, FUN_0010a4f0, FUN_001d4d24, FUN_001d5288, FUN_001e180c, FUN_001e2304, FUN_001ebca8, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520
**Referenced strings:** —
**Referenced opcodes:** 0x48 (who 0xb000)
**State vars:** conn+0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
Builds and sends the SN@P op-0x48 **name/roster query** — the "name-loop" packet that floods during create-room. It reserves an 8-byte header (request id + entry count), then walks up to **32** entries from a caller-supplied descriptor array (stride 0xc) and appends a variable-length record per entry keyed by an entry *kind* (bits `flags >> 5`). Total length is computed from the built message (`FUN_001ebca8`), then enqueued with who **0xb000** and opcode **0x48**; completion callback **0x31**.

Per entry the wire record is: `htonl(id)` (4) + `kind_byte` (1) + a kind-dependent body:
- **kind 1** → two u32 (`htonl(body[0])`, `htonl(body[1])`), record length 0xd (13).
- **kind 2** → 16-byte address/GUID copied verbatim (memset-then-copy), record length 0x15 (21).
- **other** → one u32 (`htonl(body[0])`), record length 9.

## Input / output
- `param_1` (int) — channel selector; must == 1 else errno 100.
- `param_2` (int) — pointer to the entry descriptor array. Each element (stride 0xc): `[+0]=id` (u32), `[+4]=flags` (u32; `kind = flags>>5`, low byte also copied to the wire kind field), `[+8]=body ptr` (kind-dependent). Array terminates at the first element whose `[+0]` id is 0, or at 32 entries.
- `param_3` (undefined4) — request id, byteswapped into the header word.
- `param_4` (undefined4) — completion context.
- **return**: `0` on enqueue success, `0xffffffff` otherwise.

## Side effects
- Allocs a message sized **0x2a8** max (`FUN_001d5288`), reserves the 8-byte header (`FUN_001ed2c0`) then one slice per entry.
- Any mid-loop reserve failure frees the whole message (`FUN_001ec9e0(conn+0x520,msg)`), sets errno 0x65, returns -1.
- Writes entry count byte at header+4 (`*(u8*)(hdr+4) = i`).
- On success registers completion cb **0x31**.
- Emits one reliable op-0x48 segment.

## Important branches
- `param_1 != 1 || conn == 0` → errno **0x64**, -1.
- `conn+0x50c != 0` → errno **0x66**, -1.
- message alloc == 0 → errno **0x65**, -1.
- header reserve == 0 → free msg, errno **0x65**, -1.
- entry loop: continue while `i < 0x20` **and** `*(descriptor[i].id) != 0`.
- per-entry kind select (`kind = flags>>5`): `==1` → len 0xd; `==2` → len 0x15; else → len 9. (The decompiler's `(kind<2)||(kind!=2)` idiom is the "not exactly 2" default branch.)
- per-entry reserve == 0 → free msg, errno **0x65**, return -1 (early).
- final enqueue `FUN_001e180c != 0` → errno **0x66**, -1; `== 0` → cb 0x31, return 0.

## Constants & flags
- `0x2a8` = max message size (8 header + 32 × up to 0x15). Evidence: `FUN_001d5288` size arg.
- `0xb000` who-word (reliable|0x2000|DATA); `0x48` opcode; length passed to enqueue = `total_len - 0x10` (subtracts the 16-byte transport frame). Evidence: line 82.
- kind→len: `1→0xd`, `2→0x15`, `default→9`. Evidence: lines 41-49 (length pre-calc) and 62-78 (body build) agree.
- `FUN_001e2304` = htonl/byteswap ([inferred] from usage on ids/request id).
- cb **0x31**; errno {0x64,0x65,0x66}.

## Corrected reconstruction
```c
typedef struct {           // param_2 descriptor element, stride 0xc
    u32   id;              // +0  (0 terminates the array)
    u32   flags;          // +4  kind = flags >> 5; low byte copied to wire
    void *body;           // +8  kind-dependent payload source
} name_query_desc;         // [inferred field names]

enum { NQ_KIND_PAIR = 1,   // two u32 body   -> record 0x0d
       NQ_KIND_ADDR = 2 }; // 16-byte body   -> record 0x15
                           // default: one u32 body -> record 0x09

u32 snap_send_op48_name_query(int channel /*p1*/, name_query_desc *entries /*p2*/,
                              u32 request_id /*p3*/, void *user_ctx /*p4*/)
{
    snap_connection *conn = g_snap_conn;
    if (channel != 1 || conn == NULL) { g_snap_errno = SNAP_ERR_STATE; return -1; }
    if (conn->send_lock != 0)         { g_snap_errno = SNAP_ERR_BUSY;  return -1; }

    void *msg = snap_msg_alloc(conn, 0x2a8);
    if (msg == NULL)                  { g_snap_errno = SNAP_ERR_ALLOC; return -1; }

    u32 *hdr = snap_msg_reserve(msg, 8);           // header: [0]=req id, [4]=count byte
    if (hdr == NULL) { snap_pool_free(conn->reliable_pool, msg);
                       g_snap_errno = SNAP_ERR_ALLOC; return -1; }
    hdr[0] = htonl(request_id);                     // FUN_001e2304

    int i;
    for (i = 0; i < 32 && entries[i].id != 0; i++) {
        u32 kind = entries[i].flags >> 5;
        u16 reclen = (kind == NQ_KIND_PAIR) ? 0x0d
                   : (kind == NQ_KIND_ADDR) ? 0x15 : 0x09;

        u8 *rec = snap_msg_reserve(msg, reclen);
        if (rec == NULL) { snap_pool_free(conn->reliable_pool, msg);
                           g_snap_errno = SNAP_ERR_ALLOC; return -1; }

        u32 be_id = htonl(entries[i].id);
        memcpy(rec, &be_id, 4);                     // FUN_001069a8
        rec[4] = (u8)entries[i].flags;              // raw kind byte
        u8 *body = rec + 5;

        if (kind == NQ_KIND_PAIR) {                 // two u32
            u32 a = htonl(((u32*)entries[i].body)[0]); memcpy(body,     &a, 4);
            u32 b = htonl(((u32*)entries[i].body)[1]); memcpy(rec + 9,  &b, 4);
        } else if (kind != NQ_KIND_ADDR) {          // default: one u32
            u32 a = htonl(((u32*)entries[i].body)[0]); memcpy(body,     &a, 4);
        } else {                                    // kind 2: 16-byte addr verbatim
            memset(body, 0, 0x10);                  // FUN_00106b60
            memcpy(body, entries[i].body, 0x10);    // FUN_0010a4f0
        }
    }
    *((u8*)hdr + 4) = (u8)i;                         // entry count

    short total = snap_msg_len(msg);                // FUN_001ebca8
    long rc = snap_enqueue(conn, msg, 0xb000, total - 0x10, 0x48, 0);
    if (rc == 0) { snap_register_completion(1, 0x31, user_ctx); return 0; }  // cb 0x31
    g_snap_errno = SNAP_ERR_BUSY; return -1;
}
```

## Evidence
- Raw decompile lines 21-102: guard/alloc (21-34), header id (36-37), 32-entry loop (38-79), kind length select (41-49), body build kind1/default/addr (62-78), count byte (80), length + enqueue `(...,0xb000,sVar1-0x10,0x48,0)` (81-82), cb `0x31` (84).
- Matches MEMORY note "1828 op48 name-loop" during create-room (name-query flood).
- Runtime-unvalidated (no live decode of the op48 reply mapped to this builder yet).

## Remaining uncertainty
- Meaning of kind 1 (two u32) vs default (one u32) vs kind-2 (16-byte addr) at the app level — likely (member-id, aux-id) pair vs plain id vs socket address. Not runtime-confirmed.
- `flags>>5` field semantics beyond selecting the record shape.
