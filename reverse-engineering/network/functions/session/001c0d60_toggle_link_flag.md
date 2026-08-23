# 0x001c0d60 toggle_link_flag

| field | value |
|---|---|
| Original address | 0x001c0d60 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c0d60 |
| Resolved name | toggle_link_flag |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c0f40
**Callees:** —
**Referenced globals:** 0x35bec0 gate; 0x35cc18 link-flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x35cc18; 0x35bec0

## Behavioral explanation
Two-state toggle of link flag 0x35cc18 gated on 0x35bec0; returns 0 on successful transition else -1.

## Notes / uncertainty
Raised Medium->High. Edge-triggered one-shot toggle of link flag 0x35cc18 gated by 0x35bec0: gate set consumes 1->0, gate clear raises 0->1; ret 0 success / -1 mismatch. Protocol phase meaning inferred from connect-SM caller.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c0d60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
