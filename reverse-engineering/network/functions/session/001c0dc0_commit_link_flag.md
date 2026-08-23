# 0x001c0dc0 commit_link_flag

| field | value |
|---|---|
| Original address | 0x001c0dc0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c0dc0 |
| Resolved name | commit_link_flag |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c0f40
**Callees:** —
**Referenced globals:** 0x35bec0; 0x35cc18
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x35bec0; 0x35cc18

## Behavioral explanation
Copies link flag 0x35cc18 into 0x35bec0 (commit current link state).

## Notes / uncertainty
One-line commit: copies link flag 0x35cc18 into gate 0x35bec0 that toggle_link_flag reads; returns 0. Fully determined.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c0dc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
