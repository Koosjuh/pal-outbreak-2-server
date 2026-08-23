# 0x005b6ea0 markup_read_tag_token

| field | value |
|---|---|
| Original address | 0x005b6ea0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b6ea0 |
| Resolved name | markup_read_tag_token |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b7270
**Callees:** FUN_005b7f00
**Referenced globals:** 0x6ca2e0 (tag buffer); pcRam006ca87c (parse cursor); 0x638ec0 (default token); uRam006ca881 (parser error state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006ca881; pcRam006ca87c

## Behavioral explanation
Copy the next markup tag token (up to 0x1e chars, terminated by '>') from cursor 0x6ca87c into buffer 0x6ca2e0; on malformed token fall back to default string 0x638ec0 and set error state.

## Notes / uncertainty
Reads <...> token into 0x6ca2e0; on malformed/>0x19 substitutes default token 0x638ec0 and sets status 2. Default-token string not dumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b6ea0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
