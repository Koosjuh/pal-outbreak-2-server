# 0x00637710 kbd_rebuild_layout_ptr

| field | value |
|---|---|
| Original address | 0x00637710 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637710 |
| Resolved name | kbd_rebuild_layout_ptr |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006345e0, FUN_00637140
**Callees:** —
**Referenced globals:** 0x715da8 state struct; 0x6922ac..0x6923ec layout descriptor tables
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x1d page-id; 0x1e active-key; 0x1f key-type; 0x35 flags; 0x08 who-ish field

## Behavioral explanation
Selects the active on-screen keyboard layout: sets *struct = one of many PTR_DAT_006923xx layout tables based on page-id 0x1d and key 0x1e (and a special 0x35/0x1f case).

## Notes / uncertainty
Selects layout ptr +0x00 from page-id +0x1d & key +0x1e: uniform array 0x692220+key*0x14 or named PTR_DAT blocks; page 8/9/10 remaps key3->0xb; type-4 override via +0x35&0xf and mask bit 0x8000. Which glyph set each block renders inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637710.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
