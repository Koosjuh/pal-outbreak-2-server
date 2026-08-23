# 0x006378b0 kbd_commit_preedit_to_buffer

| field | value |
|---|---|
| Original address | 0x006378b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006378b0 |
| Resolved name | kbd_commit_preedit_to_buffer |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00635f80, FUN_00636f90
**Callees:** FUN_00631ff0, FUN_006320f0, FUN_00634160, FUN_006343c0, FUN_00637da0
**Referenced globals:** 0x715da8 state struct; 0x715bb0 format scratch
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x35 overflow-flags; 0x2a text-len; 0x4c text-buffer; 0x3a encoder arg

## Behavioral explanation
Finalizes IME preedit: validates length via 006343c0, recomputes buffer length 0x2a, formats and appends the composed string into text buffer 0x4c; sets overflow flag 0x35 on failure.

## Notes / uncertainty
IME commit: validate/measure (6343c0, <0 sets overflow +0x35|=0xf), refresh len +0x2a, encode (637da0->0x715bb0) and append into buffer +0x4c with enc-arg +0x3a. Callee contracts inferred from dataflow.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006378b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
