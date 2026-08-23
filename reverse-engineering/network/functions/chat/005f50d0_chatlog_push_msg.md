# 0x005f50d0 chatlog_push_msg

| field | value |
|---|---|
| Original address | 0x005f50d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f50d0 |
| Resolved name | chatlog_push_msg |
| Subsystem | chat |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b53f0
**Callees:** FUN_005f4e40, FUN_005f5c60
**Referenced globals:** iRam003435d4+0xc8000(chat ring base); +0xc9358(head)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xc9358

## Behavioral explanation
Appends a chat message (sender name, body, color/flag bytes) into the 50-slot log ring, splitting over-length bodies across two entries.

## Notes / uncertainty
Appends a line to head slot: name A(+0x0/16), name B(+0x320/17), msg C(+0x672/66), attr bytes D/E/F/G at +0x1364/0x1396/0x13c8/0x13fa. Gated by FUN_005f5c60 (dedup/registry). Splits over-length SJIS body across two slots (blanks continuation name). Array A vs B roles and FUN_005f5c60 exact semantics uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f50d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
