# 0x0061e680 ui_ctx_init_blob

| field | value |
|---|---|
| Original address | 0x0061e680 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061e680 |
| Resolved name | ui_ctx_init_blob |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0061d6a0, FUN_0061ded0
**Callees:** —
**Referenced globals:** 0x3c8a90 (7548-byte template blob)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
memcpy of a 0x1d7c-byte template from 0x3c8a90 into param, then two extern init calls — initializes a large UI/context struct.

## Notes / uncertainty
memcpy 0x1d7c(7548)-byte template from 0x3c8a90 into caller ctx buffer, then extern init passes func_0x001f3580 + func_0x001f4ca0(0,buf). Pure UI-context init, no net state. Same listing also holds unrelated thunk_EXT_FUN_001f46e0 stub. Init-primitive semantics + mode-0 arg unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061e680.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
