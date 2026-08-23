# 0x00612fd0 layout_table_render

| field | value |
|---|---|
| Original address | 0x00612fd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00612fd0 |
| Resolved name | layout_table_render |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00612d10
**Callees:** FUN_0060f830, FUN_0060f860, FUN_006146e0, FUN_006147a0
**Referenced globals:** 0x653fb0/0x653fd0 (per-lang layout+count tables); ctx+0x4d (content id)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x4d content id

## Behavioral explanation
Generic table-driven text render: walks a per-language descriptor array (FUN_0060f830 base 0x653fb0, count FUN_0060f860 base 0x653fd0), each record {textid,y,strptr}; auto-centers when textid==-1, blits via FUN_006146e0.

## Notes / uncertainty
Table-driven static text: records {short x/-1, short y, void* str} (8-byte stride) from 0x653fb0[lang][ctx+0x4d], count from 0x653fd0. x==-1 -> auto-center. Record contents not dumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00612fd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
