# 0x005d71a0 roomlist_has_next_fwd

| field | value |
|---|---|
| Original address | 0x005d71a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d71a0 |
| Resolved name | roomlist_has_next_fwd |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d0960
**Callees:** FUN_005d67d0
**Referenced globals:** 0x004f588 roomlist head; 0x00701018 current room
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam00701018

## Behavioral explanation
Predicate: true if the forward room iterator (FUN_005d67d0) from the current room yields a different node (i.e. a next room exists).

## Notes / uncertainty
Predicate: forward iterator (005d67d0) over roomlist head arena+0x4f588 from cursor 0x701018; returns extraout_a1!=lVar1 (next exists). extraout_a1 is a decompiler multi-return artifact; internal a1/v0 pairing inferred but has-next boolean reliable.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d71a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
