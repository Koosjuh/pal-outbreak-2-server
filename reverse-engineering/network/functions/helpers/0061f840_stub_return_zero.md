# 0x0061f840 stub_return_zero

| field | value |
|---|---|
| Original address | 0x0061f840 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f840 |
| Resolved name | stub_return_zero |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061f8d0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Constant stub returning 0 (used as an always-false gate by FUN_0061f8d0).

## Notes / uncertainty
Upgraded classified->reconstructed. return 0; used by FUN_0061f8d0 as inverted gate (==0 => run screen-mode dispatch incl. overlay teardown that zeroes 0x71530c). Always-false abort/busy predicate compiled out. Disabled-vs-placeholder ambiguity remains.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f840.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
