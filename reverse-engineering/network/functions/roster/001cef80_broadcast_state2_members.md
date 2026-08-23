# 0x001cef80 broadcast_state2_members

| field | value |
|---|---|
| Original address | 0x001cef80 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cef80 |
| Resolved name | broadcast_state2_members |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001cbc20, FUN_001ce070, FUN_001cf360
**Referenced globals:** 0x4f83e0 live member array; uRam0034357c array selector
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam0034357c

## Behavioral explanation
On channel 0x1400 (FUN_001cbc20+FUN_001cf360) walks the 0x4f83e0 array (indexed by uRam0034357c) and emits a member op via FUN_001ce070 for each valid entry.

## Notes / uncertainty
Reconcile/announce over 4-slot block (0x4f83e0 + uRam0034357c*0x10); emits per occupied slot (id!=-1) via FUN_001ce070->FUN_001cde00. Guard reduces to id!=-1. Context 0x1400 and state const 3 inferred from position; full arg list to FUN_001cde00 lost in decompile.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cef80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
