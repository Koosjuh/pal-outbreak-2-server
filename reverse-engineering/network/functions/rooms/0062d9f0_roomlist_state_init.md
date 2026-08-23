# 0x0062d9f0 roomlist_state_init

| field | value |
|---|---|
| Original address | 0x0062d9f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062d9f0 |
| Resolved name | roomlist_state_init |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062d950
**Callees:** FUN_005b68e0, FUN_005b6900, FUN_005bff20
**Referenced globals:** 0x6c0760 room table (stride 0x15c, 0x1e entries)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0x10 sub-state; struct+0x42b screen-id(=9)

## Behavioral explanation
State2/sub0 init: zero-fills room table 0x6c0760 (0x28c8 bytes) and param+0x9ac (0x1e), seeds 0x1e room-index entries (stride 0x15c), sets screen +0x42b=9 and requests room list via FUN_005bff20(0,0xb7,0x62e9b0).

## Notes / uncertainty
3-step roomlist init: zeroes table 0x6c0760 (30x0x15c), seeds 1-based index tags, requests list via FUN_005bff20(0,0xb7,cb 0x62e9b0). On-wire opcode (op49 vs transport 0x1c/1e/20) behind selector 0xb7 not proven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062d9f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
