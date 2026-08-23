# 0x0062cba0 room_action_confirm_cb_1f

| field | value |
|---|---|
| Original address | 0x0062cba0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062cba0 |
| Resolved name | room_action_confirm_cb_1f |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005be9a0
**Referenced globals:** 0x6c4fbb trigger; 0x6c5c44 mode; 0x6c5c48/4a/4c sel ids; 0x6c45f8/fc/4600 committed ids; 0x6c517c marquee buf
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fbb; cRam006c4b90

## Behavioral explanation
Dialog callback for trigger 0x1f: on confirm (param0==0) sets mode uRam006c5c44=2 and copies selection ids 0x6c5c48/4a/4c into 0x6c45f8/fc/4600; else shows marquee.

## Notes / uncertainty
One-shot dialog-result cb for tag 0x1f (guard screen_id!=6 && pending_tag==0x1f, consumes tag). Confirm->mode0x6c5c44=2 + byte-copy sel triple 0x6c5c48/4a/4c into committed 0x6c45f8/fc/4600; cancel->mode=1+marquee. No captured callers (dispatcher-registered); id byte-widths inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062cba0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
