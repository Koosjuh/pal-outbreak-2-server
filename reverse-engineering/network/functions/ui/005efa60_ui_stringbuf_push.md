# 0x005efa60 ui_stringbuf_push

| field | value |
|---|---|
| Original address | 0x005efa60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005efa60 |
| Resolved name | ui_stringbuf_push |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ea900, FUN_005eb7d0
**Callees:** —
**Referenced globals:** +0xd96a 256B record ring; +0xe96a ring index (<0xf); +0x186 render-pass
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xe96a; +0x186

## Behavioral explanation
In draw mode copies a 0x100-byte record into the string/label ring at ctx+0xd96a indexed by counter +0xe96a (cap 0xf).

## Notes / uncertainty
Draw-pass-only push of a 0x100B record onto a 16-slot ring (ctx+0xd96a, depth ctx+0xe96a cap 0x0f). Record content (label vs draw-state) undecoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005efa60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
