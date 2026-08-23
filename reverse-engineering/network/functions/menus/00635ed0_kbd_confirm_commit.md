# 0x00635ed0 kbd_confirm_commit

| field | value |
|---|---|
| Original address | 0x00635ed0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00635ed0 |
| Resolved name | kbd_confirm_commit |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630c90, FUN_00633470, FUN_00634ab0
**Callees:** FUN_00631ff0
**Referenced globals:** 0x715da8 state struct
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x260 preedit-len; 0x44 buffer-flag; 0x32 exit-code; 0x4c text-len; 0x248 status

## Behavioral explanation
Confirm/OK handler: if preedit(0x260) empty, checks buffer state 0x44/0x4c and sets exit-code 0x32=1 with status; else flushes preedit via FUN_00631ff0.

## Notes / uncertainty
Confirm: first Enter finalizes preedit (+0x260) status1; else exit-code +0x32=1, reject empty (5) else accept (1). +0x44 sign-tested pending flag inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00635ed0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
