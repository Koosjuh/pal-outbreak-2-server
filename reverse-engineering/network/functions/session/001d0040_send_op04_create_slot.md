# 0x001d0040 send_op04_create_slot

| field | value |
|---|---|
| Original address | 0x001d0040 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d0040 |
| Resolved name | libsnap_send_op04_create_slot |
| Subsystem | session |
| Relevance | core (create-room registration path) |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (libsnap app-API; the client's op04 create-slot emitter)
**Callees:** FUN_001cbc20 (select_channel), FUN_001a7b70 (set_msg_attr k,v), FUN_001ab460 (alloc_msg tag), FUN_001cce80 (reliable_send online), FUN_00106b60 (memset), FUN_00109728 (format_template), FUN_001a1750 (offline_send), FUN_001cb360 (recv/parse reply), FUN_001069a8 (memcpy)
**Referenced globals:** cRam00343577 = offline flag; uRam0034357a = session id; 0x3f49a8 = alloc handle; 0x3f41a0 = op04 send buffer; 0x3ce308/0x3ce30c/0x3ce310/0x3ce314 = reply list head/ptr/counters; 0x3ce350 = parsed reply record; 0x3ce750 = reply list body; iRam003435bc = work-base (reply scratch @ +0x2ff000)
**Referenced strings:** 0x24cc50, 0x24cc60, 0x24cc80 = format templates
**Referenced opcodes:** 0x04 (create-slot, C->S)
**State vars:** cRam00343577; uRam0034357a

## Behavioral explanation
The libsnap application-layer emitter for **op04 create-slot** — the packet the client sends to register a newly created room's slot. This is the exact function at the center of the create-room registration blocker (host shows 1/0p because the create-registration never commits server-side).

Sequence:
1. `FUN_001cbc20(0x2000)` selects the create channel (`0x2000` = the op04/create channel, who-byte 0x2000 class).
2. Nine `FUN_001a7b70(key, val)` calls stamp the message-attribute template: `(0x15,2) (0x01,0) (0x12,0) (0x62,1) (0x0c,0) (0x66,0) (0x02,0) (0x12,0) (0x00,0)` — the fixed op04 header/preset (reliability, retry, timeout, class fields).
3. `FUN_001ab460(0x400, 4)` reserves a 0x400-byte message with **alloc tag 4** (= wire op04); handle → `0x3f49a8`, `0x3f49b8 = 0`.
4. **Send:** online → `FUN_001cce80(session_id, -1, 0x3f41a0, 2)` (reliable). Offline → build a template into a stack buffer via `FUN_00109728(buf, 0x24cc50, session_id)` then `FUN_001a1750(buf, 0x3f41a0, 0x2000, 0x10002)`.
5. **Reply-list reset:** `0x3ce310 = 0`, `0x3ce314 = 0`, `0x3ce308 = 0x3f41a0` (list head → the send buffer).
6. **Receive+parse reply:** scratch `= iRam003435bc + 0x2ff000`; format the response template `FUN_00109728(buf, 0x24cc60, session_id)` (offline additionally `0x24cc80`); `FUN_001cb360(buf, scratch, 0x10001, 0)` reads/parses the create-slot reply. On success (`!= 0`): `FUN_001069a8(0x3ce350, scratch)` copies the parsed record, and `0x3ce30c = 0x3ce750` publishes the reply-list pointer.

The `0x3ce30c` list pointer being set is the signal that the create-slot reply was accepted and the room record is available; if the server never returns a well-formed op04 reply, `FUN_001cb360` yields 0 and `0x3ce30c` stays unset — matching the observed "create never commits" symptom.

## Input / output
- **Params:** none (reads globals; session id from `uRam0034357a`).
- **Returns:** `void`.

## Side effects
- Selects channel `0x2000`; sets the 9-pair attribute preset.
- Allocates op04 msg (tag 4) → `0x3f49a8`; transmits `0x3f41a0`.
- Resets reply-list `0x3ce308/0x3ce310/0x3ce314`.
- On a valid reply: writes parsed record to `0x3ce350`, sets list ptr `0x3ce30c = 0x3ce750`.

## Important branches
- `cRam00343577 == 0` → online `FUN_001cce80` reliable send.
- else → offline template (`0x24cc50`) + `FUN_001a1750`; response formatting additionally applies template `0x24cc80`.
- `FUN_001cb360(...) != 0` → parse succeeded: copy record, publish list ptr. `== 0` → nothing published (create not committed).

## Constants & flags
- alloc tag `4` = wire op04.
- channel `0x2000` (create class).
- attr preset keys `0x15/0x01/0x12/0x62/0x0c/0x66/0x02/0x00`.
- send mode `2` = reliable; offline flags `0x2000`/`0x10002`, parse flags `0x10001`.
- reply scratch offset `+0x2ff000` from work-base.

## Corrected reconstruction
```c
extern u8   g_offline;         // cRam00343577
extern u32  g_session_id;      // uRam0034357a
extern u8   g_op04_buf[0x400]; // 0x3f41a0
extern void *g_op04_alloc;     // 0x3f49a8
extern u32  g_reply_head, g_reply_c1, g_reply_c2; // 0x3ce308 / 0x3ce310 / 0x3ce314
extern void *g_reply_listptr;  // 0x3ce30c
extern u8   g_reply_record[];  // 0x3ce350
extern int  g_workbase;        // iRam003435bc

void libsnap_send_op04_create_slot(void) {
    u8 tbuf[0x20];

    select_channel(0x2000);                                 // FUN_001cbc20
    set_attr(0x15,2); set_attr(0x01,0); set_attr(0x12,0);   // FUN_001a7b70 x9
    set_attr(0x62,1); set_attr(0x0c,0); set_attr(0x66,0);
    set_attr(0x02,0); set_attr(0x12,0); set_attr(0x00,0);

    g_op04_alloc = alloc_msg(0x400, /*tag=*/4);             // FUN_001ab460 -> op04
    // (alloc2 = 0)

    if (g_offline == 0) {
        reliable_send(g_session_id, -1, g_op04_buf, 2);     // FUN_001cce80
    } else {
        memset(tbuf, 0, 0x20);
        format_template(tbuf, TMPL_24cc50, g_session_id);   // FUN_00109728
        offline_send(tbuf, g_op04_buf, 0x2000, 0x10002);    // FUN_001a1750
    }

    g_reply_c1 = 0; g_reply_c2 = 0; g_reply_head = (u32)g_op04_buf; // 0x3ce308

    void *scratch = (void *)(g_workbase + 0x2ff000);
    memset(tbuf, 0, 0x20);
    format_template(tbuf, TMPL_24cc60, g_session_id);
    if (g_offline) format_template(tbuf, TMPL_24cc80, g_session_id);

    if (recv_parse_reply(tbuf, scratch, 0x10001, 0) != 0) { // FUN_001cb360
        memcpy(g_reply_record, scratch, /*len from tmpl*/); // FUN_001069a8 -> 0x3ce350
        g_reply_listptr = (void *)0x3ce750;                 // publish -> commit
    }
}
```

## Evidence
- Decompile `FUN_001d0040.c`: `FUN_001cbc20(0x2000)`; the nine `FUN_001a7b70(k,v)` attribute pairs; `FUN_001ab460(0x400,4)`→`0x3f49a8`; online `FUN_001cce80(uRam0034357a,-1,0x3f41a0,2)` vs offline `FUN_00109728(buf,0x24cc50,sess)`+`FUN_001a1750(buf,0x3f41a0,0x2000,0x10002)`; reply reset `0x3ce310/0x3ce314=0, 0x3ce308=0x3f41a0`; `iRam003435bc+0x2ff000` scratch; `FUN_00109728(buf,0x24cc60,...)` (+`0x24cc80` offline); `FUN_001cb360(buf,scratch,0x10001,0)`; on nonzero `FUN_001069a8(0x3ce350,scratch)` + `0x3ce30c=0x3ce750`.
- alloc tag 4 ↔ wire op04 (PACKET_INDEX 0x04 builder list includes this addr). Directly relevant to the create-room roster blocker per MEMORY/HANDOFF.
- Runtime-unvalidated.

## Remaining uncertainty
- The exact record length copied to `0x3ce350` (governed by the `0x24cc60` template, not shown here).
- Semantics of the `0x24cc50/60/80` format templates (field order of the create-slot request/reply) — treated as opaque format strings.
- Whether `FUN_001cb360` blocks for the reply or returns immediately (its 0/non-0 contract gates the commit).
- Attribute-preset key meanings (`0x15/0x62/0x66` etc.) are libsnap message-config keys, not decoded here.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d0040.c`  — untouched decompiler output.
