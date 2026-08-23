# 0x005c2250 build_msg_op_d3

| field | value |
|---|---|
| Original address | 0x005c2250 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2250 |
| Resolved name | build_msg_opd3 |
| Subsystem | packets |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005c2120, FUN_005c21c0
**Callees:** FUN_005be9e0 (begin_msg), FUN_005bea10 (end_msg), FUN_005bea80 (finalize_msg)
**Referenced globals:** 0x7018d0 (overlay message-build scratch)
**Referenced strings:** —
**Referenced opcodes:** app 0xd3
**State vars:** —

## Behavioral explanation
Simplest member of the overlay encoder family: a **bodyless op-0xd3 command**. Opens command byte `0xd3`
in build scratch `0x7018d0`, then end + finalize — no fields, no slot selection. A fixed control/signal
message (its two callers `FUN_005c2120`/`FUN_005c21c0` set the context; role otherwise unlabeled in the
current opcode map).

## Input / output
- (no parameters)
- **Returns** `u16`: message handle (`0xd3`).

## Side effects
- Rewrites overlay build scratch `0x7018d0` with a bodyless op-0xd3 message; finalizes for send.

## Important branches
- None — straight-line begin → end → finalize.

## Constants & flags
- `0xd3` — app/overlay command byte (bodyless control message).

## Corrected reconstruction
```c
// Overlay op-0xd3 encoder: bodyless control/signal message.
uint16_t build_msg_opd3(void) {
    uint16_t h = msg_begin(MSG_SCRATCH /*0x7018d0*/, 0xD3);  // FUN_005be9e0
    msg_end(MSG_SCRATCH);                                    // FUN_005bea10
    msg_finalize(MSG_SCRATCH);                               // FUN_005bea80
    return h;                                                // == 0xd3
}
```

## Evidence
- Raw: `uVar1 = FUN_005be9e0(0x7018d0,0xd3); FUN_005bea10(0x7018d0); FUN_005bea80(0x7018d0); return uVar1;`.
- Confidence **Medium** (structure certain; op-0xd3's protocol role unknown). Runtime-unvalidated.

## Remaining uncertainty
- The semantic role of op0xd3 (leave/close/ack/heartbeat?) — infer from callers `FUN_005c2120`/`FUN_005c21c0`
  and any wire capture that shows a 0xd3 command byte.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2250.c`  — untouched decompiler output.
