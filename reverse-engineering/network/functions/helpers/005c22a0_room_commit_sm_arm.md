# 0x005c22a0 room_commit_sm_arm

| field | value |
|---|---|
| Original address | 0x005c22a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c22a0 |
| Resolved name | room_commit_sm_arm |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00600d10
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
8-byte thunk.

## Notes / uncertainty
CORRECTS bad record (was '8-byte thunk'; actually 156B). CORE in-room commit: memset roster 0x6cdbe6(0x460), sets channel flags 0x6ce5ce/cf/d0=1, raises unlock gate 0x6ff2b1=3, arms 3-channel commit pump FUN_005c1c80. Per-channel wire op mapping not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c22a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
