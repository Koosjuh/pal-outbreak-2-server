# 0x00627c90 roster_confirm_reply_cb

| field | value |
|---|---|
| Original address | 0x00627c90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00627c90 |
| Resolved name | roster_confirm_reply_cb |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c4420
**Referenced globals:** 0x6c4fbb req-tag; 0x6c4b90 mode; 0x6c5c44 reply-code; 0x6c5c48 decoded-fields
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fbb; cRam006c5c44

## Behavioral explanation
Reply callback: when request tag 0x24 is outstanding, reads the first reply byte and sets uRam006c5c44 to 1 (fail) or 2 (ok, plus decode via FUN_005c4420).

## Notes / uncertainty
Reply cb for tag 0x24 (guarded by screen!=6): status byte 0 => reply-code 2 + decode fields into 0x6c5c48.., else reply-code 1. Only decoded 0x6c5c4f confirmed consumed; other fields + mode-6 meaning unknown. No callers (installed as pointer).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00627c90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
