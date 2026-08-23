# 0x00603d90 roster_ctx_finish_by_opcode

| field | value |
|---|---|
| Original address | 0x00603d90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00603d90 |
| Resolved name | roster_ctx_finish_by_opcode |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006052f0
**Callees:** FUN_00618b60
**Referenced globals:** ctx+0x907..0x909 (result fields); ctx+0x44c; ctx+0x10b3 (branch flag)
**Referenced strings:** —
**Referenced opcodes:** 0x0c, 0x04
**State vars:** ctx+0 (opcode); ctx+0xe (next state); ctx+1 (busy)

## Behavioral explanation
Terminal transition of the room-context state machine: branches on the context opcode (0x0c prepare / 0x04 create-slot / else) to set the next sub-state (+0xe..0x11) and clears busy flag +1.

## Notes / uncertainty
Terminal commit: picks next sub-state by ctx opcode (0x0c prepare->phase3+sel<-active+refresh; 0x04 create-slot->phase0,f=6; else enter->phase0/4 by flag 0x10b3) + clears busy. Same body as 00603e40 completion. Called by 006052f0 when reply pool still busy. Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00603d90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
