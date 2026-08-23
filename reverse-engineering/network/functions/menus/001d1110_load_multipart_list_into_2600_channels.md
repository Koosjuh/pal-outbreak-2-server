# 0x001d1110 load_multipart_list_into_2600_channels

| field | value |
|---|---|
| Original address | 0x001d1110 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d1110 |
| Resolved name | load_multipart_list_into_2600_channels |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728, FUN_00109eb8, FUN_001a79b0, FUN_001cb360, FUN_001cb5f0, FUN_001cbcb0, FUN_001cf2b0
**Referenced globals:** 0x24ce80 offset table; iRam003435bc work base; cRam00343577 offline-mode
**Referenced strings:** 0x24ce90 template; 0x24ceb8/0x24ced0/0x24cef0 templates
**Referenced opcodes:** —
**State vars:** cRam00343577

## Behavioral explanation
Fetches tmpl 0x24ce90, parses and stores 4 sub-records (offsets DAT_0024ce80, channels 0x2600+) via FUN_001a79b0/FUN_001cb5f0, then conditionally fetches a follow-up list (0x24ceb8/0x24cef0) online vs offline.

## Notes / uncertainty
4 sub-slices (DAT_0024ce80) into 0x2600-0x2603; 5th part into 0x2604 with online(mode1,raw)/offline(mode0x10001,decode) branch. Evidence for 0x10000=decode-separately bit. Offline-flag polarity inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d1110.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
