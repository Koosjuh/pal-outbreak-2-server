# 0x00630e40 softkbd_cancel_handler

| field | value |
|---|---|
| Original address | 0x00630e40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00630e40 |
| Resolved name | softkbd_cancel_handler |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006300a0
**Callees:** FUN_00634880
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x2f IME state; +0x26 active; +0x28 dirty; +0x260 IME buffer; +0x2c IME cursor; +0x248 result code

## Behavioral explanation
Handles the cancel/back key (0x29): resets active/dirty/IME state and buffers, posts result code 2.

## Notes / uncertainty
Cancel/back (key 0x29): abort compose / signal close (+0x32=0xFF) / clear IME buf; posts +0x248=2. Consumer of +0x32=0xFF and 1-vs-3 compose-state distinction untraced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00630e40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
