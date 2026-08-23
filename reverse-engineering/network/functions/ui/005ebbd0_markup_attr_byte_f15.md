# 0x005ebbd0 markup_attr_byte_f15

| field | value |
|---|---|
| Original address | 0x005ebbd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ebbd0 |
| Resolved name | markup_attr_byte_f15 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0, FUN_005ec650
**Referenced globals:** iRam007012a0 (UI ctx base); +0x186 (pass flag); +0xf15 (attr int slot)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186 (measure/-10 vs draw pass)

## Behavioral explanation
Markup attribute handler: extracts a token (parse_quoted_attr_value), and on the measure pass parses it as a decimal int into UI ctx +0xf15 (clamped).

## Notes / uncertainty
Renamed from _int_ to _byte_: store/compare are single-byte. Twin of 0x5ebb50 -> +0xf15, same 1->0 clamp.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ebbd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
