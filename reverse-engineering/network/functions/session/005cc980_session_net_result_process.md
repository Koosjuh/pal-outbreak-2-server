# 0x005cc980 session_net_result_process

| field | value |
|---|---|
| Original address | 0x005cc980 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005cc980 |
| Resolved name | session_net_result_process |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c9690, FUN_005ca1a0
**Callees:** FUN_005d59f0, FUN_005d5cc0, FUN_005d6390, FUN_005d7410, FUN_005d8340
**Referenced globals:** 0x701068+0x4f97c result queue; 0x701068+0x68dd0 current msg id; 0x701068+0x60dcc result code; 0x701068+0x60dcd retry ct; 0x701068+0x60dcb busy; 0x701070+0x30/0x34/0x39 flags
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701068+0x60dcc; 0x701068+0x60dcb; 0x701070+0x30; 0x701070+0x39

## Behavioral explanation
Dequeues a server result record from the 0x4f97c queue (FUN_005d8340) and switches on its subtype byte to set session state and return a code (-2/-1/1/2) driving the create/join/enter handshake; records current msg id at 0x68dd0.

## Notes / uncertainty
Central create/join reply processor: dequeues via FUN_005d8340, 12-case switch on record subtype -> returns 0/1/2/-1/-2 accept/deny codes. case-2 name-compare polarity (self-is-owner) preserved verbatim, needs runtime trace.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005cc980.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
