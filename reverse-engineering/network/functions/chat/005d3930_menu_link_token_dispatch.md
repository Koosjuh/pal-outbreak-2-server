# 0x005d3930 menu_link_token_dispatch

| field | value |
|---|---|
| Original address | 0x005d3930 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d3930 |
| Resolved name | menu_link_token_dispatch |
| Subsystem | chat |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005d1e80
**Callees:** FUN_005cf5f0, FUN_005d09d0, FUN_005d59f0, FUN_005d5a40, FUN_005d5b60, FUN_005d5c20, FUN_005d5cc0, FUN_005d74a0, FUN_005d7540, FUN_005dedf0
**Referenced globals:** 0x701068+0x5ffc0 entity array; 0x701088 profile buffer; 0x701070+0x2e screen id; 0x701068+0x68e85; 0x701078+1/2 state; 0x701068+0x60dc9 counter
**Referenced strings:** str@0x642e30; str@0x642e40; str@0x642e50; str@0x642e60; str@0x642e80; str@0x642ec0; str@0x642ee0; str@0x642f00; str@0x642f20; str@0x642f40; str@0x642d80; str@0x642f60; str@0x642f78; str@0x642ea0
**Referenced opcodes:** —
**State vars:** 0x701070+0x2e; 0x701070+0x38/0x3a

## Behavioral explanation
Parses the selected entry's text (+0x60) against many literal command tokens (strcmp/strstr) and drives the matching menu/chat action; also copies profile blocks.

## Notes / uncertainty
RENAMED from chat_command_token_handler: BBS/mail selected-link dispatcher. Reads widget[sel]->cmd (+0x60) from 500-slot array 701068+0x5ffc0, strncmp-cascades ~12 tokens (0x642exx) gated by screen mode 701070+0x2e (8=compose,0xa=board): page-nav (701e18 1/2 + FUN_005d5b60), next-screen tuple (68e85=7/8/9/10), field extract, profile save/restore memcpy 0x1d0@0x870f10, submit (FUN_005d7540 field-keys), '#' anchor scan->cursor xy, url open (FUN_005dedf0). Control flow + offsets certain; token KEYWORD TEXT unresolved (biggest lever) so per-token names inferred; 68e85 tuple values unmapped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d3930.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
