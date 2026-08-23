# 0x00614b80 clear_modal_busy_flag

| field | value |
|---|---|
| Original address | 0x00614b80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00614b80 |
| Resolved name | clear_modal_busy_flag |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060f910
**Callees:** —
**Referenced globals:** uRam0070d1c8
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam0070d1c8

## Behavioral explanation
Clears uRam0070d1c8 (the modal/busy flag) to 0.

## Notes / uncertainty
Clears modal busy flag uRam0070d1c8=0; reset counterpart to 614ad0 set-site.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00614b80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
