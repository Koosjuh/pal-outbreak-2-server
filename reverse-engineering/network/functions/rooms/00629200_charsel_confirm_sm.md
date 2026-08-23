# 0x00629200 charsel_confirm_sm

| field | value |
|---|---|
| Original address | 0x00629200 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00629200 |
| Resolved name | charsel_confirm_sm |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00628e10
**Callees:** FUN_005b0f00, FUN_005b1420, FUN_005b1460, FUN_0062a5c0
**Referenced globals:** param+0x1045 name; param+0x1069 text
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Charsel confirm sub-machine: on button result (+0xc) 0/1/2 either registers the pick (copies name/id, calls FUN_0062a5c0) or backs out; gated by the reliable-send guards FUN_005b1420/1460.

## Notes / uncertainty
Charsel confirm menu SM: nav via FUN_005b0f00, confirm/cancel guards FUN_005b1420/1460. Confirm+choice1 stages name/id (+0xefb/+0xf0b -> +0x1045/+0x1055), clears 0x25B buffers, sets +0x14=1, calls FUN_0062a5c0 (send/register pick). Choices 0/2 route to machines 7/8. FUN_0062a5c0 wire op (likely scenario/cast unlock) not captured.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00629200.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
