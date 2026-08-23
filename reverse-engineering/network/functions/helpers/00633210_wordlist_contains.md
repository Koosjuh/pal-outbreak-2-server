# 0x00633210 wordlist_contains

| field | value |
|---|---|
| Original address | 0x00633210 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00633210 |
| Resolved name | wordlist_contains |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006331a0
**Callees:** FUN_006332a0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Iterates the packed wordlist, unpacking each 0x10-byte entry and comparing to the given token; returns 1 on match.

## Notes / uncertainty
Prefix test: returns 1 if any unpacked wordlist entry is a memcmp-prefix of token. func_0x0010a338 assumed memcmp.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00633210.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
