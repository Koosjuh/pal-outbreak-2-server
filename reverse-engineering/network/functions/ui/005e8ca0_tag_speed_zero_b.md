# 0x005e8ca0 tag_speed_zero_b

| field | value |
|---|---|
| Original address | 0x005e8ca0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8ca0 |
| Resolved name | tag_speed_zero_b |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ef0e0
**Referenced globals:** +0x12 / +0x251e (speed); +0xd892/+0xd894
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x12; +0x251e

## Behavioral explanation
Markup tag handler: sets text-speed/delay to 0 (+0x12 / +0x251e) then consumes arg (order swapped vs 0x5e8ba0).

## Notes / uncertainty
Delay=0 then soft-flush (order/flush-kind differ from 8ba0). Write-then-flush likely 'delay next run' vs 8ba0's 'delay closed run' — inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8ca0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
