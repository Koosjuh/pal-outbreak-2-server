# 0x001e180c snap_packet_enqueue_send

| field | value |
|---|---|
| Original address | 0x001e180c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e180c |
| Resolved name | snap_packet_enqueue_send |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d6ee0, FUN_001d9b6c, FUN_001db7e8, FUN_001dbd0c, FUN_001dbefc, FUN_001dc0b8, FUN_001dc310, FUN_001dc508, FUN_001dc804, FUN_001dc9fc, FUN_001dcbf4, FUN_001dcdfc, FUN_001dd07c, FUN_001dd1dc, FUN_001dd33c, FUN_001dd5f8, FUN_001dd840, FUN_001dda88, FUN_001ddc60, FUN_001ddda0, FUN_001ddee8, FUN_001de0c0, FUN_001de298, FUN_001de470, FUN_001de648, FUN_001de840, FUN_001de9e8, FUN_001ded08, FUN_001df044, FUN_001df1d8, FUN_001df380, FUN_001df66c, FUN_001df9a8, FUN_001dfad0, FUN_001dfbf8, FUN_001dfda0, FUN_001dff7c, FUN_001e0188, FUN_001e05c8, FUN_001e0774, FUN_001e094c, FUN_001e0ed8
**Callees:** FUN_001eb3b8, FUN_001ebbd0, FUN_001ebca8, FUN_001ed524
**Referenced globals:** conn+0x50c busy-guard; conn+0x44 src id; conn+0xc unreliable-seq; conn+0x60 TX pool
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0x50c guard; conn+0xc tx-seq

## Behavioral explanation
Core send-path packet finalizer: validates body length, stamps who-byte(+0x2c with len&0x3ff), opcode/flags(+0x2e), src(+0x30); if unreliable assigns seq conn+0xc, if reliable(0x8000) marks retransmit(0x8001); enqueues onto the conn TX list (conn+0x60).

## Notes / uncertainty
Generic send finalizer for ~40 op-builders: guarded by send-lock conn+0x50c (stuck value drops every app send -> relevant to create/G2 stall); stamps +0x2c flags|len&0x3ff, +0x2e opcode word (subSel<<8|opcode), +0x30 src; unreliable seq from conn+0xc / reliable 0x8001+retry 0x11; enqueues conn+0x60. Returns 0x27 on lock or length mismatch.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e180c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
