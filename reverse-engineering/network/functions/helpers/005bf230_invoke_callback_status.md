# 0x005bf230 invoke_callback_status

| field | value |
|---|---|
| Original address | 0x005bf230 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bf230 |
| Resolved name | invoke_callback_status |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bbe00, FUN_005bc270, FUN_005bdb00, FUN_005bfdd0, FUN_005c0f60, FUN_005c2340, FUN_005c2820, FUN_005c44a0, FUN_005c4d20
**Callees:** —
**Referenced globals:** 0x6cbc84 txn status/abort flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cbc84 status

## Behavioral explanation
If ptr non-null, invokes callback(param) passing 0x00 (ok) or 0xff based on status flag cRam006cbc84.

## Notes / uncertainty
Generic completion dispatcher: null-guarded cb, delivers 0x00 if 0x6cbc84==0 else 0xFF. Behavior unambiguous; full bitfield of 0x6cbc84 not enumerated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bf230.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
