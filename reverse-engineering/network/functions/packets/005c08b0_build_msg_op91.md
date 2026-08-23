# 0x005c08b0 build_msg_op91

| field | value |
|---|---|
| Original address | 0x005c08b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c08b0 |
| Resolved name | build_msg_op91 |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005c28f0, FUN_005c29c0
**Callees:** FUN_005be9e0, FUN_005bea10, FUN_005bea40, FUN_005bea80
**Referenced globals:** 0x7018d0 message-build scratch
**Referenced strings:** —
**Referenced opcodes:** 0x91
**State vars:** —

## Behavioral explanation
Message builder: starts a message with opcode 0x91 in scratch 0x7018d0, appends param_1 (bea40), then finalizes (bea10/bea80).

## Notes / uncertainty
Overlay encoder: begin(0x91)+append_field(bea40)+end+finalize on scratch 0x7018d0. Append helpers are opaque size-8 thunks so field wire-encoding unrecoverable -> Medium; structure certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c08b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
