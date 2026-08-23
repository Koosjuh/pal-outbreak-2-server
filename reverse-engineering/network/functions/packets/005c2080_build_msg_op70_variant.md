# 0x005c2080 build_msg_op70_variant

| field | value |
|---|---|
| Original address | 0x005c2080 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2080 |
| Resolved name | build_msg_op70_variant |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bfe00, FUN_005bfe90, FUN_005c0750
**Callees:** FUN_005be9e0, FUN_005bea10, FUN_005bea80
**Referenced globals:** 0x7018d0 build scratch
**Referenced strings:** —
**Referenced opcodes:** 0x3e, 0x43, 0x70
**State vars:** —

## Behavioral explanation
Message builder: opcode 0x70 (arg2), 0x43 (arg1), or 0x3e (arg0) into scratch 0x7018d0, finalize (no body).

## Notes / uncertainty
Slot-selected BODYLESS op70 (STAT-commit) encoder: slot 0/1/2 -> op 0x3e/0x43/0x70, no field appended, finalize. Caller FUN_005c0750 = STAT-commit send. Same missing-default latent path.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2080.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
