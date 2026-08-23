# 0x001eb688 list_foreach_locked

| field | value |
|---|---|
| Original address | 0x001eb688 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eb688 |
| Resolved name | list_foreach_locked |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ebe64
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Under the list lock, walks every node calling a visitor callback(node, arg); aborts early if the callback returns nonzero.

## Notes / uncertainty
Locked visitor walk. VERBATIM QUIRK: nonzero visitor return early-exits WITHOUT releasing the lock; only clean end-of-list releases. No resolved callers in slice; whether unbalanced-lock is intentional is unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eb688.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
