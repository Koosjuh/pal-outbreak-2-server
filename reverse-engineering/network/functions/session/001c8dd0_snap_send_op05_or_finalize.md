# 0x001c8dd0 snap_send_op05_or_finalize

| field | value |
|---|---|
| Original address | 0x001c8dd0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c8dd0 |
| Resolved name | snap_send_op05_or_finalize |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_001c3840, FUN_001c3c90, FUN_001ee590
**Referenced globals:** 0x35ccb4=create-in-progress flag
**Referenced strings:** —
**Referenced opcodes:** 0x05
**State vars:** iVar2+0xc=topstate; iVar2+0xd=substate; iVar2+0xdc=error code

## Behavioral explanation
If create-in-progress flag set, finalizes/errors the session; otherwise builds and sends an op-0x05 packet.

## Notes / uncertainty
Already fully reconstructed: forks on create-in-progress flag cRam0035ccb4 -> finalize (obj+0xdc=-1, phase 7) vs emit empty op05. Which create step sets the flag (op26 vs op04) not pinned.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c8dd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
