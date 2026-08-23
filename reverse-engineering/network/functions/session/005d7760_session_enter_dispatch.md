# 0x005d7760 session_enter_dispatch

| field | value |
|---|---|
| Original address | 0x005d7760 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d7760 |
| Resolved name | session_enter_dispatch |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d7e00
**Callees:** FUN_005d6a50, FUN_005d6a70, FUN_005d6b40, FUN_005d6c10, FUN_005d6c90, FUN_005df780
**Referenced globals:** 0x004f370 session pool head
**Referenced strings:** —
**Referenced opcodes:** 0x04, 0x05, 0x06
**State vars:** node+0x104 state

## Behavioral explanation
Given a request key and subtype, finds/creates a session-pool node (0x4f370): for enter/create (4/5) checks slot via FUN_005d6a50, for 6 rejects if occupied, else allocates a fresh session node (evicting the oldest) and sets its state to 3 (in-progress).

## Notes / uncertainty
op06/op04 accept core: resolve-or-create node in pool arena+0x4f370, mode-4 remaps subtype 1->2, subtype 6 rejects if occupied, evicts on full; sets node state 2/3. FUN_005d6a50 a2 return convention is a decompiler artifact.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d7760.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
