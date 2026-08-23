# 0x005e60c0 parse_config_block

| field | value |
|---|---|
| Original address | 0x005e60c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e60c0 |
| Resolved name | parse_config_block |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005e7070
**Callees:** FUN_005e5e50, FUN_005ec920
**Referenced globals:** iRam007012a0+0xd964 (cursor), +0xe97e (config bit flags), +0xe980 (server addr string), +0xfbc1/+0xfbc2 (ports); iRam00701068+0x4f8b9 (port/index); DAT_00648090 (charmap), 0x6479f0/0x648190/0x648198/0x6481a0 (key tables/strings)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam007012a0+0xe97e (config flags); iRam00701068+0x4f8b9

## Behavioral explanation
Parses a server '<...>' configuration block: reads key/value tokens, matches keys (via FUN_005ec920/charmap) and stores connection/session parameters — server address string (@+0xe980), port digits (@+0x4f8b9, +0xfbc1/2) and a 10+ bit flag word (@+0xe97e).

## Notes / uncertainty
Parses server '<config>' key/value lines into iRam007012a0 block: 10-bit flag word +0xe97e, server addr string +0xe980, port digits +0xfbc1/+0xfbc2/+0x4f8b9. Key strings (table 0x6479f0) undecoded so per-bit semantics unknown; control flow faithful.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e60c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
