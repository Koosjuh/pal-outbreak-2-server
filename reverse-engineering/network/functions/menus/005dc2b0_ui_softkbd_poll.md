# 0x005dc2b0 ui_softkbd_poll

| field | value |
|---|---|
| Original address | 0x005dc2b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dc2b0 |
| Resolved name | ui_softkbd_poll |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005dc4b0
**Callees:** FUN_00634ab0, FUN_00636890, FUN_00637180, FUN_006371d0
**Referenced globals:** iRam00701068+0x68e89: OSK edit buffer; uRam003434a8/uRam003434a0: OSK config
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x68e89

## Behavioral explanation
UI software-keyboard poll: runs one OSK step (FUN_00634ab0); returns 0 while editing, or the edit-buffer pointer 0x68e89 on OK (cVar==1) / cancel (cVar==-1, buffer forced to 0xff).

## Notes / uncertainty
One OSK frame; returns 0 editing, buffer ptr on OK(1)/cancel(-1 -> buf[0]=0xff sentinel). Config globals 003434a8/a0 roles unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dc2b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
