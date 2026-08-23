# 0x005da4b0 ui_post_event

| field | value |
|---|---|
| Original address | 0x005da4b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005da4b0 |
| Resolved name | ui_post_event |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005da500
**Callees:** —
**Referenced globals:** iRam00701068+0x68e85: UI event code; iRam00701068+0x68e86; iRam00701078+1/+2: interaction bytes
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x68e85; 0x68e86

## Behavioral explanation
UI event poster: writes event code +0x68e85 and constant 2 at +0x68e86, plus interaction bytes +0x78[2]=arg, +0x78[1]=3.

## Notes / uncertainty
Emits (event,status) pairs into event-block 0x68e85/86 and interaction-block 0x78. Event-code semantics inferred from caller; case-3 single-arg leaves arg indeterminate.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005da4b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
