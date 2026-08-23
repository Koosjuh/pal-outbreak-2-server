# 0x006120a0 recv_slot_state_check

| field | value |
|---|---|
| Original address | 0x006120a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006120a0 |
| Resolved name | recv_slot_state_check |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00610830
**Callees:** FUN_00618230, FUN_00618520
**Referenced globals:** ctx+0x10d8 (dialog obj); ctx+0x10da/0x10db (avail bits)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x10da/0x10db availability

## Behavioral explanation
Like FUN_00612020 but returns -1 on no-recv, else the boolean 'selected slot available' (0/1). Used as a tri-state gate in create case 1.

## Notes / uncertainty
CORRECTED polarity: tri-state -1=wait, 0=slot AVAILABLE, 1=slot UNAVAILABLE (the ^1 inverts; old record read 1 as available). Same avail-bit predicate as 0x00612020.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006120a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
