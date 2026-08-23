# 0x001d0230 build_and_send_list_screen_msg

| field | value |
|---|---|
| Original address | 0x001d0230 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d0230 |
| Resolved name | build_and_send_list_screen_msg |
| Subsystem | roster |
| Relevance | core |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00106b60, FUN_00109728, FUN_001a1750, FUN_001a7b70, FUN_001ab460, FUN_001cb360, FUN_001cbc20, FUN_001cce80
**Referenced globals:** iRam003435bc(work base); cRam00343577(offline flag); uRam0034357a(session id); 0x2ff808/0x301018/0x30101c/0x301100/0x301500 (list buffers)
**Referenced strings:** 0x24cc90, 0x24cca0, 0x24ccc0 (format templates)
**Referenced opcodes:** 0x0a (weak — see uncertainty)
**State vars:** cRam00343577; uRam0034357a

## Behavioral explanation
Constructs a structured list/screen message and dispatches it over channel **0x2400**. It opens the channel (`FUN_001cbc20(0x2400)`), appends a fixed sequence of `(tag, value)` fields (`FUN_001a7b70`), formats two/three text templates into stack buffers (`FUN_00109728`, template ptrs 0x24cc90/0x24cca0/0x24ccc0), allocates a 0x200-byte list node (tag 10, `FUN_001ab460`), and wires up list-buffer pointers in the work region at `iRam003435bc + 0x2ff808…0x301500`. It then branches on the **offline** flag `cRam00343577`: online → reliable broadcast to all peers (`FUN_001cce80(session, -1, buf, 2)`); offline → local fill (`FUN_001a1750`) plus a third template. Finally emits via `FUN_001cb360(buf, node, 0x10001, 0)` and advances the list-buffer pointer to `+0x301500`.

**Attribution caveat:** the "op0a member-list" label rests only on the alloc *tag 10* in `FUN_001ab460(0x200,10)`; no `0x0a` opcode is passed to a transport enqueue here. Channel 0x2400 and `FUN_001cce80/FUN_001cb360` are message/list dispatch, not the op-0x0a request builder that lives in `FUN_001ddee8`. Treat this as a list-screen message builder that *may* correspond to op0a, not a confirmed op0a sender.

## Input / output
- **params** none (void).
- **return** void.
- Reads `cRam00343577` (offline mode), `uRam0034357a` (session id).

## Side effects
- Opens channel 0x2400; appends the field sequence to the channel's current message.
- Allocates a 0x200 list node (tag 10) → stored at `work+0x2ff808`; zeroes `work+0x2ff818`.
- Initializes list-buffer chain: `work+0x301018 = work+0x2ff000`; `+0x301020/+0x301024 = 0`; `+0x30101c = work+0x301100`.
- Online: reliable send to all peers (`FUN_001cce80(session,-1,buf,2)`).
- Offline: local fill (`FUN_001a1750(buf, work+0x2ff000, 0x2400, 0x10002)`) + third template.
- Sends the formatted buffer (`FUN_001cb360(..., 0x10001, 0)`).
- Advances `work+0x30101c` to `work+0x301500`.

## Important branches
- `cRam00343577 == 0` (online) → `FUN_001cce80(session, -1(all peers), work+0x2ff000, 2)`; read node ptr from `+0x30101c`.
- `cRam00343577 != 0` (offline) → `FUN_001a1750(...,0x2400,0x10002)` + `FUN_00109728(buf2, 0x24ccc0, session)`; read node ptr from `+0x30101c`.

## Constants & flags
- `0x2400` = channel/who id (reliable-list channel; who 0x2000 | 0x400). Evidence: `FUN_001cbc20(0x2400)` and reused in `FUN_001a1750`.
- field `(tag,value)` sequence: `(0x15,2)(1,0)(0x12,0)(0x62,1)(0xc,0)(0x66,0)(2,0)(0x12,0)(0,0)` — a UI/list descriptor script; `(0,0)` terminates. Evidence: lines 13-21.
- alloc `(0x200, 10)` — 0x200-byte node, tag/type 10. Evidence: line 28.
- send flags `0x10001` (`FUN_001cb360`), `0x10002` (`FUN_001a1750`), broadcast target `-1` (all). Evidence: lines 41,45.
- templates 0x24cc90/0x24cca0/0x24ccc0. Evidence: lines 24,25,42.

## Corrected reconstruction
```c
void build_and_send_list_screen_msg(void)
{
    char buf_a[32], buf_b[32];
    int  work = g_work_base;                 // iRam003435bc

    channel_open(0x2400);                     // FUN_001cbc20
    // append a fixed (tag,value) descriptor script; (0,0) terminates
    field_append(0x15, 2);  field_append(1, 0);   field_append(0x12, 0);
    field_append(0x62, 1);  field_append(0x0c, 0); field_append(0x66, 0);
    field_append(2, 0);     field_append(0x12, 0); field_append(0, 0);

    memset(buf_b, 0, 0x20);                   // FUN_00106b60
    u16 sid = uRam0034357a;                   // session id
    format_str(buf_b, TMPL_0x24cc90, sid);    // FUN_00109728
    format_str(buf_a, TMPL_0x24cca0, sid);

    void *node = list_node_alloc(0x200, 10);  // FUN_001ab460 (tag 10)
    *(void**)(work + 0x2ff808) = node;
    *(u32*)  (work + 0x2ff818) = 0;
    *(int*)  (work + 0x301018) = work + 0x2ff000;
    *(u32*)  (work + 0x301020) = 0;
    *(u32*)  (work + 0x301024) = 0;
    *(int*)  (work + 0x30101c) = work + 0x301100;

    void *list;
    if (g_offline_flag == 0) {                // cRam00343577 online
        reliable_broadcast(sid, /*all peers*/ -1LL, work + 0x2ff000, 2); // FUN_001cce80
        list = *(void**)(work + 0x30101c);
    } else {                                  // offline
        local_list_fill(buf_b, work + 0x2ff000, 0x2400, 0x10002);        // FUN_001a1750
        format_str(buf_a, TMPL_0x24ccc0, sid);
        list = *(void**)(work + 0x30101c);
    }
    list_send(buf_a, list, 0x10001, 0);       // FUN_001cb360
    *(int*)(work + 0x30101c) = work + 0x301500;
}
```

## Evidence
- Raw decompile lines 12-46 (channel open, field script, template formats, node alloc tag 10, buffer wiring, online/offline fork, send).
- Channel/list dispatch helpers `FUN_001cbc20`/`FUN_001cce80`/`FUN_001cb360` (transport list layer), not the op-0x0a enqueue (`FUN_001e180c`).
- Runtime-unvalidated; op0a attribution is a *weak inference* from alloc tag 10 only.

## Remaining uncertainty
- Whether this is the op-0x0a member-list send at all — the tag-10 link is circumstantial; no `0x0a` opcode reaches a transport enqueue in this function. Downgraded to Medium for that reason.
- Semantics of the `(tag,value)` field script and the list-buffer offsets (0x2ff000/0x301100/0x301500) — treated as an internal UI/list descriptor region, not decoded field-by-field.
- Format-template contents (0x24cc90/a0/c0) not dereferenced.
