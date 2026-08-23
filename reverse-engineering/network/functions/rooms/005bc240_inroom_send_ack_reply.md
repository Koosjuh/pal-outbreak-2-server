# 0x005bc240 inroom_evt0a_send_op0b_reply

| field | value |
|---|---|
| Original address | 0x005bc240 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc240 |
| Resolved name | inroom_evt0a_send_op0b_reply |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bba20 (in-room dispatcher, sub-event case 10 / 0x0a)
**Callees:** FUN_005c5f70 (build+send reliable app message 0x0b)
**Referenced globals:** 0x6febec (reply payload word), 0x6febac (SN@P connection/session handle, via callee)
**Referenced strings:** —
**Referenced opcodes:** app 0x0b (message body byte); SN@P reliable flag 0x8000; in-room sub-event 0x0a
**State vars:** —

## Behavioral explanation
Handler for in-room **sub-event 10 (0x0a)**. It captures the current value of the global reply word
0x6febec into a local, then hands it to `FUN_005c5f70`, which builds a 0x304-byte SN@P app message
with body type **0x0b**, copies 4 bytes of that word into the body, and transmits it **reliably**
(flags 0x8000) on the session handle 0x6febac toward the dispatcher-supplied peer `param_1`. Net
effect: the client emits a reliable op-0x0b reply echoing a stored value back to the room/peer.

## Input / output
- Input: `undefined8 param_1` — target peer/handle from the dispatcher (`*(u32*)(disp+8)`).
- Output: `void`. Emits one reliable wire message.

## Side effects
- Sends SN@P reliable app message, body[0]=0x0b, 8-byte length, carrying `*(u32*)0x6febec`.

## Important branches
None in this handler. (No validation of 0x6febec — trusted.)

## Constants & flags
- App message type **0x0b** (`auStack_310[0]=0xb` in the callee).
- SN@P **0x8000** = reliable send flag; length arg 8, count 1.

## Corrected reconstruction
```c
// callee FUN_005c5f70 — build & send a reliable op-0x0b message carrying a 4-byte value
void snap_send_op0b(u32 peer, const u32 *value) {
    u8 body[0x304];
    memset(body, 0, 0x304);
    body[0] = 0x0b;                                   // app message type
    memcpy(body + 4, value, 4);                       // func_0x001069a8
    snap_send(session_handle /*0x6febac*/, 0x8000 /*reliable*/, body, 8, 1, peer); // func_0x001df380
}

// Dispatched by inroom_game_dispatch case 0x0a.
void inroom_evt0a_send_op0b_reply(u32 peer) {
    u32 v = *(u32*)0x6febec;                           // uRam006febec
    snap_send_op0b(peer, &v);
}
```

## Evidence
- `FUN_005bc240.c`: `uStack_4 = uRam006febec; FUN_005c5f70(param_1,&uStack_4);`
- `FUN_005c5f70.c`: `memset(buf,0,0x304); buf[0]=0xb; memcpy(buf+4,param_2,4); snap_send(uRam006febac,0x8000,buf,8,1,param_1);`
- `FUN_005bba20.c`: `case 10: FUN_005bc240(*(undefined4*)(param_1+8));`
- Runtime-unvalidated.

## Remaining uncertainty
Meaning of the echoed word 0x6febec (sequence/handle/vote value) unknown; op-0x0b's role in the
in-room protocol not yet cross-referenced to a wire capture.
