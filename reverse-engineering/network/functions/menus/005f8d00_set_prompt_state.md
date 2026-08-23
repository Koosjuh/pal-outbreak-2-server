# 0x005f8d00 set_prompt_state

| field | value |
|---|---|
| Original address | 0x005f8d00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f8d00 |
| Resolved name | set_prompt_state |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f8fc0, FUN_005fa0b0, FUN_005fc2b0, FUN_005fc360, FUN_005fc520, FUN_005fc7c0
**Callees:** —
**Referenced globals:** 0x6c4ba5 (prompt id); 0x6c4b9e; 0x6c4b9f; 0x6c4ba0; 0x6c4ba1
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4b9e; 0x6c4b9f

## Behavioral explanation
Sets the shared prompt/notice globals (0x6c4ba5=param, 0x6c4b9e=4, 0x6c4b9f=1) to raise a modal message.

## Notes / uncertainty
Raises modal prompt: lobby_sm=4/screen_major=1, prompt id -> 0x6c4ba5 (6 callers). (4,1)->prompt-page mapping from lobby_state_block doc; per-id message set by callers.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f8d00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
