# 0x005eb0f0 markup_element_open_t2

| field | value |
|---|---|
| Original address | 0x005eb0f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eb0f0 |
| Resolved name | markup_element_open_t2 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005eb250, FUN_005ef5b0, FUN_005ef850, FUN_005f0e10
**Referenced globals:** +4 (out len); +0x186 (mode); +0xd894; +0x24f4 (child ptr); +8 (elem kind)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
Type-2 element open: FUN_005f0e10(...,2) begins element, resets out buffer, layout FUN_005ef5b0 + commit FUN_005ef850(2); in non-0xf6 mode links child pointer (+0x24f4) and calls FUN_005eb250.

## Notes / uncertainty
Open kind-2; in render pass (!=0xF6) links child from +0x24f4 and runs FUN_005eb250. Concrete tag for kind-2 unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eb0f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
