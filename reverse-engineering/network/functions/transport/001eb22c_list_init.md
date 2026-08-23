# 0x001eb22c list_init

| field | value |
|---|---|
| Original address | 0x001eb22c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eb22c |
| Resolved name | list_init |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d46ec, FUN_001d51e0, FUN_001e1468, FUN_001e1590, FUN_001e2424, FUN_001eb1b0, FUN_001ebed0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Initializes a circular doubly-linked list head (self-referential next/prev, count=0, flags=0) with an optional lock callback at +8, invoking it with cmd 0 (init).

## Notes / uncertainty
Intrusive circular list-head init (next/prev=self, count=0, flags=0, lock_cb@+8 called with cmd0). Full 0x14 field map documented; corroborated by count/flags accessors. Lock-cb command set beyond cmd0 unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eb22c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
