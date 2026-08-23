# 0x005f47a0 intro_timer_check

| field | value |
|---|---|
| Original address | 0x005f47a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f47a0 |
| Resolved name | intro_timer_check |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f3f50
**Callees:** —
**Referenced globals:** iRam00701f30; uRam00701f28
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701f30

## Behavioral explanation
Intro timer gate: resets or advances the attract sequence based on the active flag.

## Notes / uncertainty
Per-frame poll: inactive->clear counter, active->tick (003acce0). Whether tick expiry drives an upstream transition not traced. No net.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f47a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
