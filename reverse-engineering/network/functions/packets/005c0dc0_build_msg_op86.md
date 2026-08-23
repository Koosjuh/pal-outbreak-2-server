# 0x005c0dc0 build_msg_op86

| field | value |
|---|---|
| Original address | 0x005c0dc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0dc0 |
| Resolved name | build_msg_op86 |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005c0a00, FUN_005c0ae0
**Callees:** FUN_005be9e0, FUN_005bea10, FUN_005bea30, FUN_005bea80
**Referenced globals:** 0x7018d0 build scratch
**Referenced strings:** —
**Referenced opcodes:** 0x86
**State vars:** —

## Behavioral explanation
Message builder: starts a message with opcode 0x86 in scratch 0x7018d0, appends param_1, finalizes.

## Notes / uncertainty
Overlay encoder begin(0x86)+append(bea30)+end+finalize. Caller FUN_005c0ae0 = op0a member-list fill, so op0x86 drives roster/member-list refresh. Field encoding stubbed -> Medium.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0dc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
