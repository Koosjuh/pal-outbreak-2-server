# 0x005f4b70 softkbd_reset

| field | value |
|---|---|
| Original address | 0x005f4b70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f4b70 |
| Resolved name | softkbd_reset |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005acea0, FUN_005b25c0, FUN_005fe500, FUN_005ff830, FUN_005ff8d0, FUN_00601700, FUN_0062c970
**Callees:** FUN_005f52e0
**Referenced globals:** uRam006c50fb(soft-kbd active flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c50fb

## Behavioral explanation
Clears the on-screen-keyboard active flag then tail-calls a (corrupt) routine.

## Notes / uncertainty
UPGRADED: body fully decoded (softkbd_active=0 then tail-call), was mislabeled documented/Low. Rewrote to reconstructed with full corrected block. Name/purpose from 0x6c50fb adjacency to softkbd_update buffer 0x6c50fc; tail callee 0x5f52e0 opaque. No runtime proof -> capped Medium.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f4b70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
