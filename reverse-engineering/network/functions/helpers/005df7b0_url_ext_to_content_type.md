# 0x005df7b0 url_ext_to_content_type

| field | value |
|---|---|
| Original address | 0x005df7b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005df7b0 |
| Resolved name | url_ext_to_content_type |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d76b0, FUN_005d7a30
**Callees:** FUN_005dee60, FUN_005deee0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Maps a URL's file extension to a content type: HTM/HTML->1, PNG->2, BMP->3, MMBIN->4, else 0 (case-insensitive).

## Notes / uncertainty
Case-insensitive extension sniff: PNG=2,BMP=3,HTM/HTML=1,MMBBIN=4,else 0. NOTE: 6-char branch matches chars M,M,B,B,I,N = 'MMBBIN' (corrected from prior 'MMBIN'). Locators FUN_005dee60/deee0 + extraout regs inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005df7b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
