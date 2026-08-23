# 0x001cfa30 libsnap_send_op06_member_join

| field | value |
|---|---|
| Original address | 0x001cfa30 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cfa30 |
| Resolved name | libsnap_send_op06_member_join |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001a0eb0, FUN_001ab460, FUN_001cbc20, FUN_001cce80
**Referenced globals:** 0x4ddba0/0x4de3a8 send buffer; 0x4de3e0 member flag array; cRam00343577 offline-mode; bRam005a9048 channel toggle
**Referenced strings:** —
**Referenced opcodes:** 0x06
**State vars:** cRam00343577; bRam005a9048

## Behavioral explanation
Sends the op06 member JOIN/enter: channel (toggle*0x80+0x1800), alloc tag 6, opens reliable send FUN_001cce80 with packed (p3|p1<<16|p2<<8) and marks member flags at 0x4de3e0; offline path calls FUN_001a0eb0.

## Notes / uncertainty
libsnap app emitter, alloc tag 6=op06: channel toggle*0x80+0x1800, reliable send 0x4ddba0 with key p3|p1<<16|p2<<8, marks member-pending flags 0x4de3e0[0..count]; offline->FUN_001a0eb0. Uncertainty: packed key triple semantics.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cfa30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
