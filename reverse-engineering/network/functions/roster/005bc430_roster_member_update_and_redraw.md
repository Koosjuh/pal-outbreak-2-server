# 0x005bc430 roster_member_update_and_redraw

| field | value |
|---|---|
| Original address | 0x005bc430 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc430 |
| Resolved name | roster_member_update_and_redraw |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bc370, FUN_005bdfe0, FUN_005c5120, FUN_005c7d00
**Referenced globals:** 0x6cdbe6 (roster table, stride 0x118); 0x6cd672 (scratch roster entry); 0x6fb746 (visible roster count); 0x70047c (mode flag gate); 0x6cbc7e/0x6cbc84 (UI status)
**Referenced strings:** —
**Referenced opcodes:** 0x0a
**State vars:** cRam0070047c

## Behavioral explanation
Member-list handler (dispatch code 0x0a): scans the 4-entry roster (0x6cdbe6) for the id in the payload, copies the id/name/blob fields into the entry and scratch (0x6cd672), and when the entry's active byte (+0xe5)==1 repacks the visible roster (FUN_005bc370) and fires the roster redraw (FUN_005bdfe0 0x24/0x23).

## Notes / uncertainty
Renamed from *_list: it is a single-member update, not a full fill. Gated on 0x70047c; on +0xe5 flag repacks visible list and fires redraw 0x24 then 0x23. Incoming record layout (word-match vs byte +0xe5) is decompiler-flattened.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bc430.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
