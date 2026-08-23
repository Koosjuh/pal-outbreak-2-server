# 0x005b9150 message_render_cb

| field | value |
|---|---|
| Original address | 0x005b9150 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b9150 |
| Resolved name | message_render_cb |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005b9120, FUN_005bacf0, FUN_005bb380, FUN_00618c20, FUN_0062fd30, FUN_0062fea0
**Referenced globals:** 0x006c5508 uRam=blink/toggle counter; 0x006c5b40 cRam=2nd-name present flag; 0x006c5048 uRam; 0x006c5b30/0x006c5b40 name buffers; 0x639d60/0x639d68/0x639d70 sprintf fmt strings
**Referenced strings:** 0x639d60; 0x639d68; 0x639d70 (printf format templates)
**Referenced opcodes:** —
**State vars:** uRam006c5508; cRam006c5b40

## Behavioral explanation
Large message/dialog render callback (~4KB): dispatches on the +2 type byte to many layout branches (centered text, name+score, ranking, blink via uRam006c5508), formatting strings with sprintf and measuring width for centering.

## Notes / uncertainty
4KB message/scoreboard renderer; dispatch on +2 layout type (name/score/ranking/blink via uRam006c5508). Unrelated to net (no room/roster globals, no opcodes). Per-type pixel math and payload struct offsets only partially generalized.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b9150.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
