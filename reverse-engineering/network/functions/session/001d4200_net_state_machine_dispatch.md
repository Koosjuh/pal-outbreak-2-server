# 0x001d4200 net_state_machine_dispatch

| field | value |
|---|---|
| Original address | 0x001d4200 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d4200 |
| Resolved name | net_state_machine_dispatch |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** (indirect via 0x24da70 step table)
**Referenced globals:** 0x24da70 step-handler table; 0x36d568 state index
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam0036d568

## Behavioral explanation
Indirect-jump dispatcher: calls the current step handler from the PTR_FUN_0024da70 table indexed by state var cRam0036d568.

## Notes / uncertainty
Raised Medium->High (mechanism). Fn-ptr-table dispatch: calls PTR_FUN_0024da70[cRam0036d568] with ctx 0x36d568 (Ghidra jumptable warning is a plain fn-ptr table). DNAS/session bring-up SM, not SN@P per-packet. Step ordering runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d4200.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
