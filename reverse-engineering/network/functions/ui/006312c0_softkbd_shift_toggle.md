# 0x006312c0 softkbd_shift_toggle

| field | value |
|---|---|
| Original address | 0x006312c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006312c0 |
| Resolved name | softkbd_shift_toggle |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006300a0
**Callees:** FUN_00631ff0, FUN_00637140, FUN_00637540, FUN_00637690
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x1e layout page; +0x20 charset caps; +0x2f IME state; +0x248 result code

## Behavioral explanation
Shift/mode toggle key (0x02): flips the layout index +0x1e between base/shifted pages honoring charset caps; commits any pending IME.

## Notes / uncertainty
Shift key (0x02): toggle base<->shifted page (0/0x07/0x0f) honoring caps; finalizes conversion if IME state==2. Page identities unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006312c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
