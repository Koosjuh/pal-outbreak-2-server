# 0x005e7e30 message_render_state_step

| field | value |
|---|---|
| Original address | 0x005e7e30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e7e30 |
| Resolved name | message_render_state_step |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005de170
**Callees:** FUN_005c8ed0, FUN_005d8930, FUN_005d8f90, FUN_005da370, FUN_005da420, FUN_005da500, FUN_005e7710, FUN_005e7a30
**Referenced globals:** iRam007012a0 (render ctx); iRam00701068 (arena; ctx=+0x1a000); cRam007012a8 (phase); 0x648240/44/46 (draw constants)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam007012a8 (render phase 0-4); +0x182/+0x184/+0x10 (window dims); +0x186 (measure-only); +0xe96b (silent flag); +0x18e (portrait id)

## Behavioral explanation
Multi-pass message-box render driver: state machine over cRam007012a8 phases 0-4, sizes window (0x248), runs parse passes and calls draw primitives (window/box/sprite).

## Notes / uncertainty
Message-box render phase machine on cRam007012a8 0..4: init(ctx@arena+0x1a000, w=0x248) -> two measure passes -> draw window/portrait/prompt; portrait switch(+0x18e) code->face. Not network. Callee roles inferred from args; per-frame resumption cadence unverified.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e7e30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
