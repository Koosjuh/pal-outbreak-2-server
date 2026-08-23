# 0x001eeb50 snap_get_record_clamped_f04a0

| field | value |
|---|---|
| Original address | 0x001eeb50 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eeb50 |
| Resolved name | snap_get_record_clamped_f04a0 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001bf2e0, FUN_001c0540, FUN_001c0f40, FUN_001c2770, FUN_001ee1e0
**Callees:** FUN_001f04a0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Reads a record via FUN_001f04a0 and, on success, copies it out clamping two enum fields (0-9 and 0-0xd) into the caller's struct.

## Notes / uncertainty
Reads record via FUN_001f04a0, copies out with two enum clamps: catA[0..9] fallback 8, catB[0..0xd] fallback 0xb. a/b word-swap on store is faithful. Enum domains unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eeb50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
