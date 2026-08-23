# 0x005c1ff0 build_msg_op6e_data

| field | value |
|---|---|
| Original address | 0x005c1ff0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c1ff0 |
| Resolved name | build_msg_op6e_data |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005c04f0, FUN_005c05c0
**Callees:** FUN_005be9e0, FUN_005bea10, FUN_005bea30, FUN_005bea60, FUN_005bea80
**Referenced globals:** 0x7018d0 build scratch
**Referenced strings:** —
**Referenced opcodes:** 0x6e
**State vars:** —

## Behavioral explanation
Message builder: opcode 0x6e in scratch 0x7018d0, appends param_1 then a length-prefixed string payload param_2 (strlen via 0x0010a050, bytes via bea60), finalize.

## Notes / uncertainty
op6e encoder with variable string body: begin(0x6e)+append field+strlen(str)+append len-prefixed blob(bea60)+finalize. Create/enter-with-name path. Blob framing + field meaning inferred (append helpers stubbed) -> Medium.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c1ff0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
