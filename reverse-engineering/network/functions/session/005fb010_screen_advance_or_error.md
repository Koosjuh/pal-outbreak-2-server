# 0x005fb010 screen_advance_or_error

| field | value |
|---|---|
| Original address | 0x005fb010 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fb010 |
| Resolved name | screen_advance_or_error |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fa0b0
**Callees:** FUN_005fb670
**Referenced globals:** +0xf page; +0x10 sub-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xf/+0x10

## Behavioral explanation
One-step screen advance gated by the connection guard; on disconnect jumps page +0xf to 4 (error).

## Notes / uncertainty
Renamed from screen_advance_if_connected. Guard FUN_005fb670==0 -> page(+0xf)++ else page=4 (error); substate(+0x10)=0 on both. Guard internals + full page map unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fb010.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
