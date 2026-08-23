# 0x005c0060 maxi_user_register_reply_handler

| field | value |
|---|---|
| Original address | 0x005c0060 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0060 |
| Resolved name | maxi_user_register_reply_handler |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bdfe0, FUN_005bf2e0, FUN_005c1e70, FUN_005c7d00
**Referenced globals:** 0x6fee8c registry-B key; 0x6fee88 MAXI id; 0x6fee7c USER id; 0x6cfb66 render MAXI; 0x6cfb62 render USER; 0x6cfb6c ready flag; 0x6cbc84 status; 0x6cbc80 result
**Referenced strings:** MAXI (0x4d415849); USER (0x55534552)
**Referenced opcodes:** —
**State vars:** 0x6cfb6c ready flag; 0x6cbc84

## Behavioral explanation
Reply handler for FUN_005bffa0: locates registry-B slot (FUN_005bf2e0), stores key; if tag==MAXI writes id 0x6fee88 + render 0x6cfb66 and sets ready flag 0x6cfb6c=1; if tag==USER writes id 0x6fee7c + render 0x6cfb62; then re-arms UI.

## Notes / uncertainty
Register reply: commits MAXI(0x4d415849)/USER(0x55534552) into registry-B (base 0x6fee68 stride 0x24) + render struct (stride 0x144, 0x6cfb62/66, ready 0x6cfb6c). Prime suspect for 1/0p count if reply never lands. MAXI=max/USER=current inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0060.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
