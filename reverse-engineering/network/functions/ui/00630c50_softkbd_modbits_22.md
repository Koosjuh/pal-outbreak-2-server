# 0x00630c50 softkbd_modbits_22

| field | value |
|---|---|
| Original address | 0x00630c50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00630c50 |
| Resolved name | softkbd_modbits_22 |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630420, FUN_00630f20, FUN_006313a0, FUN_00631d60
**Callees:** —
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x49f modifier bits

## Behavioral explanation
Returns pad modifier bits (+0x49f) masked with 0x22.

## Notes / uncertainty
Returns +0x49f & 0x22; feeds layout parity in 0x630420. 4 callers. Button mapping unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00630c50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
