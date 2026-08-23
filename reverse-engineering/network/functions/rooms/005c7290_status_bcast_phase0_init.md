# 0x005c7290 status_bcast_phase0_init

| field | value |
|---|---|
| Original address | 0x005c7290 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c7290 |
| Resolved name | status_bcast_phase0_init |
| Subsystem | rooms |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005c7210
**Callees:** —
**Referenced globals:** 0x6ff2a4/0x6ff2a6 (scratch)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Phase-0 entry of status-broadcast SM: bumps sub-state (+0x20), seeds loop counters, clears 0x6ff2a4/a6.

## Notes / uncertainty
Phase-0 seed: phase 0->1, page/loop reset, clears accumulators 0x6ff2a4/a6. Decompiler truncated the tail (halt_baddata) so additional stores may be missing.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c7290.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
