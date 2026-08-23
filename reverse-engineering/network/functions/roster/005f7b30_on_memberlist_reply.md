# 0x005f7b30 on_memberlist_reply

| field | value |
|---|---|
| Original address | 0x005f7b30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f7b30 |
| Resolved name | on_memberlist_reply |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005be9a0, FUN_005bfc40, FUN_005bfc60, FUN_005bfcb0, FUN_005bfcf0
**Referenced globals:** 0x6c4fbb (pending-op type, ==7); 0x6c3030 (member table); 0x6c45fe (member count); 0x6c4ba0; 0x6c4b9f (roster-dirty ctr); 0x6c4b90 (mode)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4fbb; 0x6c45fe; 0x6c4b9f

## Behavioral explanation
Reply/event handler gated on pending-op flag cRam006c4fbb=='\a': on success (result byte 0) fills the member table 0x6c3030 (count uRam006c45fe, stride 0x15c) with per-member id/name/state via FUN_005bfcf0/cb0/c60, bumps the roster-dirty counter 0x6c4b9f.

## Notes / uncertainty
Member-list reply handler gated on pending tag 0x6c4fbb==7; on status 0 fills 0x6c3030 (count 0x6c45fe, stride 0x15c) and bumps roster-dirty 0x6c4b9f (drives rebuild). status 0/1/2 encoding inferred from control flow, not a traced reply.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f7b30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
