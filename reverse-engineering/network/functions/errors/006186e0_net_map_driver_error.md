# 0x006186e0 net_map_driver_error

| field | value |
|---|---|
| Original address | 0x006186e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006186e0 |
| Resolved name | net_map_driver_error |
| Subsystem | errors |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060f910, FUN_00610580, FUN_00610830, FUN_00611fe0, FUN_00618460, FUN_00618530, FUN_00618600
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Translates raw libnet/transport return codes (-0xfc..-0x100, -1, 0, other) into the overlay's normalized error enum.

## Notes / uncertainty
Pure lookup: raw driver code (-252..-256,-1,0,other) -> normalized enum (-1..-7). Full mapping table verified from short-circuit chain; non-monotonic so it's a hand-authored LUT. Driver-code meanings inferred only.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006186e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
