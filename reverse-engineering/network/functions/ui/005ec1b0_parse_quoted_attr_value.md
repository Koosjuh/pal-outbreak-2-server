# 0x005ec1b0 parse_quoted_attr_value

| field | value |
|---|---|
| Original address | 0x005ec1b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ec1b0 |
| Resolved name | parse_quoted_attr_value |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e8530, FUN_005e8d90, FUN_005e8dc0, FUN_005e8e00, FUN_005e8e40, FUN_005e8e80, FUN_005e8ed0, FUN_005e8f70, FUN_005e8fa0, FUN_005e9190, FUN_005e91c0, FUN_005e92a0, FUN_005e92d0, FUN_005e9300, FUN_005e9330, FUN_005e93c0, FUN_005e94c0, FUN_005e9510, FUN_005e9540, FUN_005e9580, FUN_005e95e0, FUN_005e96a0, FUN_005e96d0, FUN_005e9710, FUN_005e9750, FUN_005e9890, FUN_005e9940, FUN_005e99c0, FUN_005e9b70, FUN_005e9bd0, FUN_005e9ca0, FUN_005e9cd0, FUN_005e9dd0, FUN_005e9f40, FUN_005ea190, FUN_005ea990, FUN_005eaa10, FUN_005eaa70, FUN_005eaad0, FUN_005eab70, FUN_005eabd0, FUN_005eac40, FUN_005eaca0, FUN_005eb300, FUN_005eb350, FUN_005eb3a0, FUN_005eb990, FUN_005eb9f0, FUN_005eba50, FUN_005ebaf0, FUN_005ebb50, FUN_005ebbd0, FUN_005ebc50, FUN_005ebcf0
**Callees:** —
**Referenced globals:** DAT_006491b0 (char-class table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Scans a markup attribute stream for ="..." and copies the quoted value into a bounded buffer, using char-class table 0x6491b0 and handling multibyte (0x80) chars; advances the caller's cursor.

## Notes / uncertainty
Core ="value" tokenizer, 54 callers; SJIS multibyte aware; char-class table 0x6491b0 bit2=terminator. State machine fully recovered.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ec1b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
