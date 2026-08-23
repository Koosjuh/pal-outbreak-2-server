# 0x001e0ed8 snap_build_op49_roomlist_register

| field | value |
|---|---|
| Original address | 0x001e0ed8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e0ed8 |
| Resolved name | snap_build_op49_addr_register |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d5288 (seg-alloc), FUN_001ed2c0 (payload-reserve), FUN_001ec9e0 (seg-free), FUN_001069a8 (memcpy), FUN_00106b60 (memset), FUN_0010a4f0 (memcpy16), FUN_001e2304 (htonl), FUN_001ebca8 (seg length), FUN_001e180c (frame+enqueue), FUN_001d4d24 (register completion)
**Referenced globals:** 0x0025b78c (`snap_connection*`); 0x0025b790 (errno); conn+0x50c (send-lock); conn+0x520 (pool)
**Referenced opcodes:** 0x49 (room-list / address-register)
**State vars:** conn+0x50c send-lock; DAT_0025b790 errno

## Behavioral explanation
Builds and sends the **reliable op-0x49 registration payload** — a variable-length record set describing up to 32 address/endpoint entries. It first lays down an 8-byte header: `u32 htonl(param_3)` (a key/handle) followed by a 1-byte entry-count (filled in after the loop). It then walks the caller's entry array `param_2` (stride 0xc, terminated by a zero id-word or after 32 entries) and, per entry, reserves a type-sized sub-record and writes `[u32 htonl(id)][u8 type_raw][address]`, where the address encoding depends on the entry type extracted from `entry[+4] >> 5`:
- **type 1** → 0xd bytes: two htonl u32 (e.g. addr+port pair) from `*entry[+8]` and `entry[+8][+4]`.
- **type 2** → 0x15 bytes: memset 16 then 16-byte raw copy (an IPv6/opaque 128-bit blob) from `entry[+8]`.
- **else (default, incl. 0)** → 9 bytes: one htonl u32 from `*entry[+8]`.

After the loop the header count byte is patched, total length is read back, and the frame is enqueued reliable (who `0xb000`) opcode 0x49, registering an op-0x32 completion. This is the client publishing its **candidate address list** (STUN/NAT-style) via op49 — the app-level op49 room-list/register channel.

## Input / output
- `param_1` (int) — channel token; must be 1.
- `param_2` (addr_entry*) — array of up to 32 `{u32 id; u32 flags; void* addr}` records (stride 0xc), zero-id terminated.
- `param_3` (u32) — header key/handle (htonl into payload+0).
- `param_4` — completion-callback context (tag 0x32).
- **return** (u32) — 0 success / 0xFFFFFFFF failure.

## Side effects
- Reserves a 0x2a8-max segment, appends per-entry sub-records; frees on any reserve failure.
- Patches header entry-count byte at payload+4.
- Registers op32 completion (`FUN_001d4d24(1,0x32,param_4)`).
- DAT_0025b790 on failure.

## Important branches
- `chan!=1 || conn==0` → errno 100, -1.
- `+0x50c != 0` → errno 0x66, -1.
- header alloc/reserve fail → (free) errno 0x65, -1.
- per-entry reserve fail → free seg, errno 0x65, **early return -1**.
- loop stops at first zero id-word or 32 entries.
- type dispatch: `(flags>>5)==1` → 0xd; `==2` → 0x15; otherwise → 9. (The decompiler's `(uStack_24<2)||(uStack_24!=2)` collapses to "not 2".)
- enqueue ok → register cb 0x32, return 0; else errno 0x66, -1.

## Constants & flags
- who `0xb000` reliable DATA.
- max entries 0x20; entry stride 0xc; sub-record sizes 0xd / 0x15 / 9.
- header alloc 0x2a8 (worst case 32×0x15 + 8 = 0x2a8).
- type field = `entry.flags >> 5`; type enum {1,2,default}.
- completion tag `0x32`; errno 0x64/0x65/0x66.

## Corrected reconstruction
```c
struct addr_entry { u32 id; u32 flags; void *addr; };   // stride 0xc [inferred]
enum { ADDR_T_PAIR = 1, ADDR_T_IPV6 = 2 };              // (flags>>5)

u32 snap_build_op49_addr_register(int chan, struct addr_entry *entries,
                                  u32 key, void *cb_ctx)
{
    snap_connection *conn = DAT_0025b78c;
    if (chan != 1 || conn == 0)          { DAT_0025b790 = 100;  return -1; }
    if (conn->send_lock /*+0x50c*/ != 0) { DAT_0025b790 = 0x66; return -1; }

    int seg = seg_alloc(conn, 0x2a8);
    if (seg == 0)                        { DAT_0025b790 = 0x65; return -1; }

    u32 *hdr = seg_reserve(seg, 8);
    if (hdr == 0) { seg_free(conn->reliable_pool, seg); DAT_0025b790 = 0x65; return -1; }
    hdr[0] = htonl(key);                       // FUN_001e2304
    // hdr+4 (count byte) patched after loop

    int n = 0;
    for (; n < 0x20 && entries[n].id != 0; n++) {
        u32 type = entries[n].flags >> 5;
        u16 rec_len = (type == ADDR_T_PAIR) ? 0xd : (type == ADDR_T_IPV6) ? 0x15 : 9;

        u8 *rec = seg_reserve(seg, rec_len);
        if (rec == 0) { seg_free(conn->reliable_pool, seg);
                        DAT_0025b790 = 0x65; return -1; }

        *(u32*)rec = htonl(entries[n].id);     // rec+0
        rec[4] = (u8)entries[n].flags;         // rec+4 raw flags byte
        void *a = entries[n].addr;
        if (type == ADDR_T_PAIR) {             // 0xd: two u32
            *(u32*)(rec+5) = htonl(((u32*)a)[0]);
            *(u32*)(rec+9) = htonl(((u32*)a)[1]);
        } else if (type == ADDR_T_IPV6) {      // 0x15: 16 raw bytes
            memset(rec+5, 0, 0x10);
            memcpy16(rec+5, a, 0x10);
        } else {                               // 9: one u32
            *(u32*)(rec+5) = htonl(((u32*)a)[0]);
        }
    }
    ((u8*)hdr)[4] = (u8)n;                      // entry count

    short total = seg_length(seg);             // FUN_001ebca8
    if (frame_enqueue(conn, seg, 0xb000, total - 0x10, 0x49, 0) == 0) {
        register_completion(1, 0x32, cb_ctx);  // FUN_001d4d24
        return 0;
    }
    DAT_0025b790 = 0x66; return -1;
}
```

## Evidence
- Raw: `FUN_001e0ed8.c` (lines 23-90): 0x2a8 alloc; header htonl(param_3)+count byte at `puVar3+1`; 32-entry stride-0xc loop; type=`entry[+4]>>5` dispatch to 0xd/0x15/9; per-type htonl/memset/memcpy16; length `FUN_001ebca8`; enqueue `0xb000/0x49`; completion `0x32`.
- Struct: op49 record fields (BE) in `structure-layouts/room_record.md`; FUN_001e2304 = htonl (BE fields).

## Remaining uncertainty
- Exact semantics of the address types (pair = IPv4+port? IPv6 vs opaque token?) and the `key` (param_3) are not runtime-confirmed. This is the client→server op49 *register/publish*; the server→client op49 *room-list* is a distinct decode path (recv_roomlist_entries 0x001c70b0). Helper names inferred.
