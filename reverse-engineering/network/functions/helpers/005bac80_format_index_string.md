# 0x005bac80 format_index_string

| field | value |
|---|---|
| Original address | 0x005bac80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bac80 |
| Resolved name | format_index_string |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b3790, FUN_005fbbf0, FUN_005fcba0, FUN_005fcc70, FUN_005fd630, FUN_005fd9e0, FUN_005fe140, FUN_00602700, FUN_00605a90
**Callees:** —
**Referenced globals:** 0x006ca260 output string buffer; 0x639e50 fmt string
**Referenced strings:** 0x639e50
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
If param<0x0c, looks up a value via func_0x001b6f50(param) and sprintf's it into buffer 0x6ca260 with fmt 0x639e50, returning the buffer; else returns 0.

## Notes / uncertainty
idx<12 -> lookup(func_0x001b6f50)+sprintf into static buf 0x6ca260 (fmt 0x639e50), else NULL. Signed compare, no lower guard. Lookup/format semantics not dumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bac80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
