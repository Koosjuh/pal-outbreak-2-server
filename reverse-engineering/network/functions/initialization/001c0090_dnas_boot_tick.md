# 0x001c0090 dnas_boot_tick

| field | value |
|---|---|
| Original address | 0x001c0090 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c0090 |
| Resolved name | dnas_boot_tick |
| Subsystem | initialization |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c0100
**Referenced globals:** 0x35a279 enable-flag; 0x35a278 last-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x35a279; 0x35a278

## Behavioral explanation
Guarded per-frame tick of the DNAS boot state machine; runs step() only when enable-flag 0x35a279 set, returns current state.

## Notes / uncertainty
Guarded pump: steps FUN_001c0100 only when enable 0x35a279 set, caches state to 0x35a278, returns 0xffffffff sentinel when disabled. Frame-loop caller not in xref set.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c0090.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
