# 0x001ee3b0 netlink_start

| field | value |
|---|---|
| Original address | 0x001ee3b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee3b0 |
| Resolved name | netlink_start |
| Subsystem | initialization |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c0f40, FUN_001c19e0
**Callees:** FUN_001ef4a0
**Referenced globals:** 0x0037a2a0 started-flag; 0x0037a288 phase
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x0037a288 phase; 0x0037a2a0 started

## Behavioral explanation
Starts the link (FUN_001ef4a0), sets a started flag 0x37a2a0=1 and net phase 0x37a288=1.

## Notes / uncertainty
Bring-up: link_bringup(1ef4a0) then unconditionally set started-flag 0x37a2a0=1 and phase 0->1. Return meaning inferred; no error gate here.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee3b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
