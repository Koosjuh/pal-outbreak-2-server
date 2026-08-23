# 0x0062e5b0 room_member_join_gate

| field | value |
|---|---|
| Original address | 0x0062e5b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062e5b0 |
| Resolved name | room_member_join_gate |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062e3c0
**Callees:** FUN_005b09b0, FUN_005b14b0, FUN_005c4580, FUN_0062f890
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0x456 member count (<4 gate); struct+0x444/+0x445 accept flags; struct+0x10 sub-state

## Behavioral explanation
Member-join gate (struct+0x10): checks room member count at +0x456 against 4 (full-room check) and drives join/enter, advancing +0xf to 2 (enter) on success; builds slot UI via FUN_0062f890.

## Notes / uncertainty
Already fully reconstructed. In-room join gate enforcing 4-player cap (+0x456<4), transitions major-state +0xf=2 on accept; param_2=reply-pending guard. Open: where +0x456 is populated (op0a/op28).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062e5b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
