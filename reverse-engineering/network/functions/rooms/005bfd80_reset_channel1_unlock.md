# 0x005bfd80 reset_channel1_unlock

| field | value |
|---|---|
| Original address | 0x005bfd80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bfd80 |
| Resolved name | reset_channel1_unlock |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ad530, FUN_005f8220, FUN_0062d810
**Callees:** FUN_005bf0e0, FUN_005bf180
**Referenced globals:** 0x6ff2b1 scenario/char lock; 0x6ce5cf channel-1 committed (cb ptr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6ff2b1 lock

## Behavioral explanation
Resets scenario/char lock 0x6ff2b1=0, stages+commits channel-1, then invokes the committed channel-1 callback ptr with ok(0).

## Notes / uncertainty
Leave/reset ownership: clears 0x6ff2b1=0, stages+commits channel-1 (FUN_005bf0e0(1)/FUN_005bf180(1)), invokes returned ch-1 cb with ok(0). FUN_005bf180 returning a callable cb inferred from immediate call.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bfd80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
