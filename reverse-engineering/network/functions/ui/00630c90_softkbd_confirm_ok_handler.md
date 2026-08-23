# 0x00630c90 softkbd_confirm_ok_handler

| field | value |
|---|---|
| Original address | 0x00630c90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00630c90 |
| Resolved name | softkbd_confirm_ok_handler |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_006300a0
**Callees:** FUN_00631a30, FUN_006320f0, FUN_00632330, FUN_00634160, FUN_00634460, FUN_00635ab0, FUN_00635ed0, FUN_00636f90, FUN_00637140, FUN_00637da0
**Referenced globals:** iRam00715da8 (widget state); 0x715bb0 (scratch text buffer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x36 IME-active; +0x1f field state; +0x2a cursor; +0x4c buffer; +0x248 result code; +8 field descriptor ptr

## Behavioral explanation
Handles the OK/confirm key (0x28/0x58): validates the entered text, handles IME-active vs plain fields, formats the result, and posts a result code.

## Notes / uncertainty
OK/confirm (key 0x28/0x58): IME-commit or validate-then-accept via field descriptor widget[8]; result codes +0x248 5=empty/1=stay. Descriptor +2/+3/+4 semantics and accept-callee outcomes inferred; string not transmitted here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00630c90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
