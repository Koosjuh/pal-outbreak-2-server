# 0x006157e8 net_request_result_copy

| field | value |
|---|---|
| Original address | 0x006157e8 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006157e8 |
| Resolved name | net_request_result_copy |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060e060, FUN_0060eba0, FUN_0060ec60, FUN_0060ee80, FUN_0060eff0, FUN_00615a58
**Callees:** —
**Referenced globals:** 0x70d240-0x70d540 (result block)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x70d240

## Behavioral explanation
Copies the completed 0x300-byte request result block (0x70d240..0x70d540) out into the caller's buffer.

## Notes / uncertainty
memcpy of 0x310-byte result block 0x70d240 into caller buffer (unrolled loop + 16B tail, aligned/unaligned specialization only). Result record field layout not decodable here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006157e8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
