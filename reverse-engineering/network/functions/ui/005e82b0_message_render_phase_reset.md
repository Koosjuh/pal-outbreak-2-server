# 0x005e82b0 message_render_phase_reset

| field | value |
|---|---|
| Original address | 0x005e82b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e82b0 |
| Resolved name | message_render_phase_reset |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005de110
**Callees:** —
**Referenced globals:** uRam007012a8 (render phase byte)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam007012a8/uRam007012a8 (render phase)

## Behavioral explanation
Resets the message-render phase state (uRam007012a8=0) so the next draw starts at phase 0.

## Notes / uncertainty
Renamed from render_state_reset: sets cRam007012a8=0 to restart FUN_005e7e30 at phase 0. Unambiguous; only caller trigger (open vs close) unpinned.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e82b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
