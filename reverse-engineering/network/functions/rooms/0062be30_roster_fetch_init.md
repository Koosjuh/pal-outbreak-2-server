# 0x0062be30 roster_fetch_init

| field | value |
|---|---|
| Original address | 0x0062be30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062be30 |
| Resolved name | roster_fetch_init |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062bda0
**Callees:** FUN_005b8cf0
**Referenced globals:** +0x1460 slot idx; +0x12c2 member buf
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Init/timer step for roster fetch: resets slot index +0x1460, clears +0x12c2 member buffer (0x19e), opens a window (FUN_005b8cf0 id 100) then advances.

## Notes / uncertainty
Two-phase arm(phase0)/settle(phase1) timer step: clears ctx+0x1460 slot idx, memsets 0x19e roster staging buf @ctx+0x12c2, opens window FUN_005b8cf0(100), waits 0x10 ticks then advances task+1. Window/buffer-record semantics inferred, not runtime-proven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062be30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
