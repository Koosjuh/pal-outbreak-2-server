# 0x005c1e70 build_msg_register_variant

| field | value |
|---|---|
| Original address | 0x005c1e70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c1e70 |
| Resolved name | build_msg_register_variant |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bffa0, FUN_005c0060, FUN_005c02b0
**Callees:** FUN_005be9e0, FUN_005bea10, FUN_005bea30, FUN_005bea80
**Referenced globals:** 0x7018d0 build scratch
**Referenced strings:** —
**Referenced opcodes:** 0x35, 0x49, 0x7b
**State vars:** —

## Behavioral explanation
Message builder for the register/enter family: opcode 0x7b (arg2), 0x49 (arg1), or 0x35 (arg0) into scratch 0x7018d0, append param_2, finalize.

## Notes / uncertainty
Slot-selected register/list encoder: slot 0/1/2 -> op 0x35/0x49/0x7b, append one field, finalize. LATENT BUG: no default -> uninitialized return if slot not in {0,1,2}. Slot selects context/service; field encoding stubbed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c1e70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
