# 0x00617910 modeB_state2_timeout_tick

| field | value |
|---|---|
| Original address | 0x00617910 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00617910 |
| Resolved name | modeB_state2_timeout_tick |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006177d0
**Callees:** FUN_005af300, FUN_005b14b0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x16 up-counter; +0xe major-state

## Behavioral explanation
type-0x0b scene state-2: increments +0x16 timer, advances on timeout (>=300 ticks, or >0x4b once FUN_005b14b0(0x210) signals ready).

## Notes / uncertainty
TIMEOUT_WAIT: up-counter, exit on hard cap (>299) OR early-ready (>75 && poll FUN_005b14b0(0x210)). Exact guard recovered; 0x210 resource identity unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00617910.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
