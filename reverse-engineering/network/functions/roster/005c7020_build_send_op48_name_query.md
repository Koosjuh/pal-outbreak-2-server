# 0x005c7020 build_send_op48_name_query

| field | value |
|---|---|
| Original address | 0x005c7020 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c7020 |
| Resolved name | build_send_op48_name_query |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005af1a0
**Callees:** FUN_005c3e50, FUN_005c4f40, FUN_005c4fd0
**Referenced globals:** 0x6febac (conn/session ptr); 0x700638 (reply-ctx)
**Referenced strings:** NAME
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Builds a NAME app-message carrying two name strings and sends it reliably, registering reply handler FUN_005c70e0.

## Notes / uncertainty
Renamed from build_send_name_register_msg: builds an op48 name-query (func_0x001e094c) with two 'NAME'(0x4e414d45) TLVs {tag,field(0x44/0x46),ptr} from local names (0x365d20 + suffix 0x6405b0/b8) and registers reply cb 0x005c70e0 (ctx 0x700638). Field words 0x44/0x46 and args 0xa/0x5c3cf0 meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c7020.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
