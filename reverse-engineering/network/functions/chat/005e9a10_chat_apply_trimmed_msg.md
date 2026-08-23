# 0x005e9a10 chat_apply_trimmed_msg

| field | value |
|---|---|
| Original address | 0x005e9a10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9a10 |
| Resolved name | chat_apply_trimmed_msg |
| Subsystem | chat |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005eef70
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x17f (msg mode)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x17f

## Behavioral explanation
Right-trims trailing spaces from the message arg, applies it (FUN_005eef70), resets mode 0x17f=0.

## Notes / uncertainty
Compose-widget OK-commit: right-trims trailing ASCII spaces in place, applies via FUN_005eef70, clears cfg+0x17f=0. Loop/trim logic unambiguous. Only remaining gap is what FUN_005eef70 does downstream (queue vs echo).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9a10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
