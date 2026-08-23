# 0x005f8220 room_leave_confirm_send

| field | value |
|---|---|
| Original address | 0x005f8220 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f8220 |
| Resolved name | room_leave_confirm_send |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005f7800
**Callees:** FUN_005adc80, FUN_005b68e0, FUN_005b6900, FUN_005bfd80
**Referenced globals:** 0x6c45fc; param+0x42b (fade)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0xf

## Behavioral explanation
Small SM on +0xf: on entry sets fade +0x42b=5 and sends a room action request FUN_005bfd80 (cb 0x5f82a0); state 1 spins on FUN_005b6900.

## Notes / uncertainty
Page-4 send/wait SM: step0 sets 0x6c45fc=1, fade +0x42b=5, sends leave request via 005bfd80(alloc 005adc80(1), cb 0x5f82a0=leave-reply handler which re-enters roomlist 005f8b50); step1 polls 005b6900. Exact leave wire op (0x07/0x08) inferred, not observed -> Medium.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f8220.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
