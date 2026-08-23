# 0x005c1f30 build_msg_op6e_variant

| field | value |
|---|---|
| Original address | 0x005c1f30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c1f30 |
| Resolved name | build_msg_op6e_variant |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bfa70, FUN_005bfb40
**Callees:** FUN_005be9e0, FUN_005bea10, FUN_005bea30, FUN_005bea80
**Referenced globals:** 0x7018d0 build scratch
**Referenced strings:** —
**Referenced opcodes:** 0x2f, 0x41, 0x6e
**State vars:** —

## Behavioral explanation
Message builder: opcode 0x6e (arg2), 0x41 (arg1), or 0x2f (arg0) into scratch 0x7018d0, append param_2, finalize.

## Notes / uncertainty
Slot-selected create/enter (op6e) encoder: slot 0/1/2 -> op 0x2f/0x41/0x6e, append one field. Same missing-default latent path. Single-field (id-only) variant vs the string-body builder 0x005c1ff0.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c1f30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
