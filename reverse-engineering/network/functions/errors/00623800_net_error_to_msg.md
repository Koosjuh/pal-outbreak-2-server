# 0x00623800 net_error_to_msg

| field | value |
|---|---|
| Original address | 0x00623800 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00623800 |
| Resolved name | net_error_to_msg |
| Subsystem | errors |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_006231b0
**Callees:** FUN_0061e7f0, FUN_0061f0e0, FUN_0061f1d0, FUN_0061f4b0, FUN_0061f600
**Referenced globals:** 0x715298 struct ptr; 0x35b74f error code
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam0035b74f

## Behavioral explanation
Waits on link (e7f0) then maps a link/network error code (cRam0035b74f, values -0x56..-2) to a message/sound id passed to FUN_0061f600.

## Notes / uncertainty
Error dialog: settle->confirm->map signed net error code 0x35b74f (-0x56..-2) to message id (1..12) via FUN_0061f600. Full code->msg table captured. Message id->text not resolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00623800.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
