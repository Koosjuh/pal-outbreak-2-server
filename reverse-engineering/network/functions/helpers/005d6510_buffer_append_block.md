# 0x005d6510 buffer_append_block

| field | value |
|---|---|
| Original address | 0x005d6510 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d6510 |
| Resolved name | buffer_append_block |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005d6560
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Generic helper: memcpy a fixed block to the running buffer pointer and advance it by len-1.

## Notes / uncertainty
Cursor-by-ref string/block append; advance by len-1 leaves cursor on terminator (strcpy-like). copy thunk func_0x001069a8 signature unconfirmed (decompiler dropped src/len stack args).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d6510.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
