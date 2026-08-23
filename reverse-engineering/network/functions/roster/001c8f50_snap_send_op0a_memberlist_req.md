# 0x001c8f50 snap_send_op0a_memberlist_req

| field | value |
|---|---|
| Original address | 0x001c8f50 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c8f50 |
| Resolved name | snap_send_op0a_memberlist_req |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_00106b60, FUN_001c3590, FUN_001c3840, FUN_001c3c90, FUN_001c3da0, FUN_001c4020, FUN_001ee590
**Referenced globals:** 0x35ba00=encode key/ctx; 0x35b9f0=source field
**Referenced strings:** —
**Referenced opcodes:** 0x0a
**State vars:** iVar2+0xd=substate

## Behavioral explanation
Builds and sends the op-0x0a member-list request (subtype byte 1) with a 0x100-byte encoded field from 0x35b9f0, advancing substate to 0x35.

## Notes / uncertainty
Rewrote from classified->reconstructed. op0a request: header(0x0a,sub1)+u8 1+0x100 encoded field (encoder 0x35b9f0 under key 0x35ba00, len 0xff); success -> substate 0x35. Byte-identical send idiom to confirmed op24 sender 0x001c85c0. Uncertainty: exact 0x35b9f0 blob contents.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c8f50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
