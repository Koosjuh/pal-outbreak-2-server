# 0x001eea10 snap_submit_record_f0330

| field | value |
|---|---|
| Original address | 0x001eea10 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eea10 |
| Resolved name | snap_submit_record_f0330 |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c0f40
**Callees:** FUN_001f0330
**Referenced globals:** 0x37a288 (SNAP state var:=2)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x37a288

## Behavioral explanation
Marshals fields from a caller record (pointer-of-pointer at +4, dwords +0x14/+0x18/+0x1c, +2 of sub-struct, +0xc, byte +6) into FUN_001f0330(1,...) then advances state-machine to 2.

## Notes / uncertainty
Bank-A state-2 entry of the shared SN@P transport txn SM (uRam0037a288). Marshals caller record fields (descriptor+ dwords +0x14/18/1c/0c, byte h+6) into FUN_001f0330(kind=1,...) then sets state=2. FUN_001f0330's built opcode not traced; record field names inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eea10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
