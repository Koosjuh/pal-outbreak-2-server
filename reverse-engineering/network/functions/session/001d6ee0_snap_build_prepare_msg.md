# 0x001d6ee0 snap_build_prepare_msg

| field | value |
|---|---|
| Original address | 0x001d6ee0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d6ee0 |
| Resolved name | snap_build_prepare_msg |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d7104
**Callees:** FUN_001d507c, FUN_001d533c, FUN_001e180c, FUN_001eabc0, FUN_001eac0c, FUN_001ead70, FUN_001eaddc, FUN_001ed2c0, FUN_001ed74c
**Referenced globals:** —
**Referenced strings:** MR (tag 0x4d52); LC (tag 0x4c43)
**Referenced opcodes:** —
**State vars:** conn+0x88 token; conn+0x510/0x518 MR/LC values

## Behavioral explanation
Builds the connection prepare/establish control message: resets seq state, byteswaps the token at conn+0x88, allocates a 0x36c buffer, emits 'MR'/'LC' TLV fields, and queues it with who-selector 0x3000.

## Notes / uncertainty
Transport PREPARE/establish (who 0x3000): records peer sid/port, bswaps token+0x88, acquires node, reserves body(span=token+0x128)+TLV, emits MR(0x4d52,+0x518)/LC(0x4c43,+0x510) TLVs, queues reliable. Guarded on node!=0 && reserve checks. Uncertainty: token/0x128 meaning; MR/LC offset cross.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d6ee0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
