# 0x006290e0 charsel_register_send_step

| field | value |
|---|---|
| Original address | 0x006290e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006290e0 |
| Resolved name | charsel_register_send_step |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00628e10
**Callees:** FUN_005b7fd0, FUN_00629a40, FUN_00629d00
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** 0x09
**State vars:** —

## Behavioral explanation
Charsel sub-step that, after its timer expires, rebuilds the widget/render and sends app opcode 0x09 (register) via FUN_005b7fd0 with the chosen slot.

## Notes / uncertainty
op09 register send (sub=1,len=3) on settle-timer underflow; matches PACKET_INDEX 0x09 builder. Server-side slot->charstats mapping is a follow-up message, out of slice.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006290e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
