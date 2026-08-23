# 0x005d6a10 node_flag_set_clear

| field | value |
|---|---|
| Original address | 0x005d6a10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d6a10 |
| Resolved name | node_flag_set_clear |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d74a0, FUN_005d7b60
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** node+1 flags

## Behavioral explanation
Generic helper: sets or clears mask bits in the node flag byte at +1 based on a boolean.

## Notes / uncertainty
set/clear mask on flags byte @ object+0x01 (distinct small object, NOT the pool_node). Bit meanings caller-defined.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d6a10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
