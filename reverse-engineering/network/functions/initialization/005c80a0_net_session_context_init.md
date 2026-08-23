# 0x005c80a0 net_session_context_init

| field | value |
|---|---|
| Original address | 0x005c80a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c80a0 |
| Resolved name | net_session_context_init |
| Subsystem | initialization |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ae260, FUN_006076c0, FUN_00608300, FUN_006088b0, FUN_00624c70
**Callees:** FUN_005ca8f0, FUN_005d6d50, FUN_005da780, FUN_005de0f0, FUN_005dfcf0, FUN_005e02e0, FUN_0061f8d0, FUN_00634550
**Referenced globals:** 0x701068 (session arena base); 0x701070/0x701078/0x701080/0x701088 (sub-struct ptrs); 0x701f20 (already-init flag); 0x700fe8/0x700ff0; 0x34359d (language); 0x715da8
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701f20

## Behavioral explanation
Full init/reset of the large network-session context (iRam00701068 arena): zeroes sub-structs, sets defaults/flags, seeds host-vs-join mode (param_1), and calls sub-inits incl. FUN_00634550(language).

## Notes / uncertainty
Already fully reconstructed. Warm/cold split on 0x701f20; role byte state+0x36 = host(1)/join(0). Many arena flag-byte meanings (0x60dc4..0x60dcf) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c80a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
