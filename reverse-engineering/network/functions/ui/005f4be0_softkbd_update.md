# 0x005f4be0 softkbd_update

| field | value |
|---|---|
| Original address | 0x005f4be0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f4be0 |
| Resolved name | softkbd_update |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f7c80, FUN_005fec30, FUN_005fede0, FUN_00600200, FUN_0062d640
**Callees:** FUN_005b14b0, FUN_005c4af0, FUN_005f4b20, FUN_00632ce0, FUN_00634540, FUN_006345e0, FUN_00634ab0, FUN_00637170, FUN_00637180, FUN_006371d0
**Referenced globals:** 0x6c50fc(text-entry buffer); cRam006c4ba3/ba4(kbd phase); uRam006c4610/18/20(pad masks); uRam006c4b90(commit target)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4ba3; cRam006c4ba4

## Behavioral explanation
On-screen keyboard state machine: pad-driven glyph entry into buffer 0x6c50fc, commits/cancels the typed string.

## Notes / uncertainty
Two-mode text entry: inline toggle (pad 0x100/0x200, bRam006c50fb) + full OSK session (buf 0x6c50fc cap 0x40, commit to uRam006c4b90). Produces local room-name/pw/chat string; no wire encoding. FUN_00634ab0 return codes (0 vs 1 both commit) and 00632ce0 transform (SJIS?) uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f4be0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
