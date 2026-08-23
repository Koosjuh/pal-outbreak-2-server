# 0x00630c10 softkbd_modbits_44

| field | value |
|---|---|
| Original address | 0x00630c10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00630c10 |
| Resolved name | softkbd_modbits_44 |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006314a0
**Callees:** —
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x49f modifier/button bits

## Behavioral explanation
Returns pad modifier bits (+0x49f) masked with 0x44.

## Notes / uncertainty
Returns +0x49f & 0x44 modifier bits. Physical button->bit mapping unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00630c10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
