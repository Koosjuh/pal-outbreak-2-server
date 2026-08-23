# 0x005c3ef0 signin_sm_begin

| field | value |
|---|---|
| Original address | 0x005c3ef0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c3ef0 |
| Resolved name | signin_sm_begin |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062bee0
**Callees:** —
**Referenced globals:** 0x6cbc0c (SM busy flag); 0x6fbe58 (0x201 work buffer); 0x7003fd (credential copy); 0x6cbbe8 (tick fn ptr); 0x6cbbec (completion cb); 0x70047d (mode=0 here)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006cbc0c; uRam0070047d

## Behavioral explanation
Starts the sign-in/auth state machine: guards on 0x6cbc0c, clears the 0x201-byte work area at 0x6fbe58, copies the 0x10-byte credential/id from param1 to 0x7003fd, registers the tick fn (pcRam006cbbe8=FUN_005c40a0) and the completion callback, and enters state 0.

## Notes / uncertainty
Idempotent arm of the auth SM (mode 0): guards 0x6cbc0c, clears 0x201 buf, copies 0x10 cred to 0x7003fd, installs pump FUN_005c40a0. param_2 callback-vs-context and the 0x10 cred layout unverified at runtime.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c3ef0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
