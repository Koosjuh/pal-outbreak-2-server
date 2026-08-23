# 0x001c0100 dnas_boot_step

| field | value |
|---|---|
| Original address | 0x001c0100 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c0100 |
| Resolved name | dnas_boot_step |
| Subsystem | initialization |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c0090
**Callees:** FUN_001bf580, FUN_001c00e0, FUN_001c04a0, FUN_001c0630, FUN_001c2770, FUN_001ee360
**Referenced globals:** 0x35a6b0 boot-state; 0x35ba98 resolved-addr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x35a6b0

## Behavioral explanation
DNAS/DVD-auth boot state machine: switch on 0x35a6b0 — reset, poll ready (FUN_001c0630), FUN_001ee360, sub-machine FUN_001c2770, finalize FUN_001bf580.

## Notes / uncertainty
Upgraded classified->reconstructed. DNAS/network boot SM on 0x35a6b0 (0 reset,1 auth-poll,2 xport-poll,3 session,4 err,5 ready); returns state; consumes resolved-addr 0x35ba98 at auth-success edge. Uncertainty: the 2->3 transition is NOT in this fn (driven by FUN_001ee360 or a sibling pump); FUN_001c2770 scratch-arg semantics undecoded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c0100.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
