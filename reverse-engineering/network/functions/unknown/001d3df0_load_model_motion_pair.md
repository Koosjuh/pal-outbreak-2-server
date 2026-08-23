# 0x001d3df0 load_model_motion_pair

| field | value |
|---|---|
| Original address | 0x001d3df0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d3df0 |
| Resolved name | load_model_motion_pair |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728, FUN_001a0df0, FUN_001cb360
**Referenced globals:** 0x343577 disc flag; 0x3435bc scratch; 0x24d4c0..0x24d560 path fmts
**Referenced strings:** (path fmts @0x24d4c0/e0/500/520/540/560)
**Referenced opcodes:** —
**State vars:** cRam00343577

## Behavioral explanation
Loads two related files (model + motion) and registers each via func_0x00729890/00729d90, then finalizes (0x72b2f0).

## Notes / uncertainty
Loads two files into scratch 0x3435bc, registers via distinct callees 0x729890/0x729d90, finalizes 0x72b2f0 unconditionally. Media-gated; path from 3 id components 0x34357a/7c/7e. model/motion labels inferred. Non-network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d3df0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
