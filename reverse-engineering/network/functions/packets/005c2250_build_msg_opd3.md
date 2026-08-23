# 0x005c2250 build_msg_opd3

| field | value |
|---|---|
| Original address | 0x005c2250 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2250 |
| Resolved name | build_msg_opd3 |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005c2120, FUN_005c21c0
**Callees:** FUN_005be9e0, FUN_005bea10, FUN_005bea80
**Referenced globals:** 0x7018d0 build scratch
**Referenced strings:** —
**Referenced opcodes:** 0xd3
**State vars:** —

## Behavioral explanation
Message builder: opcode 0xd3 in scratch 0x7018d0, finalize (no body).

## Notes / uncertainty
Simplest overlay encoder: bodyless op 0xd3 begin+end+finalize, no params. Protocol role of op0xd3 unknown (control/signal); resolve from callers FUN_005c2120/21c0. Renamed from build_msg_op_d3 -> build_msg_opd3.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2250.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
