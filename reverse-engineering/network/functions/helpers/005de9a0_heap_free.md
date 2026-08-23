# 0x005de9a0 heap_free

| field | value |
|---|---|
| Original address | 0x005de9a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005de9a0 |
| Resolved name | heap_free |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005dea10
**Callees:** —
**Referenced globals:** iRam00701068+0x4db70/+0x4f364
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Unlinks the block whose payload addr (+4) equals param from the heap list and zeroes its descriptor.

## Notes / uncertainty
Already reconstructed; find-by-addr, unlink prev->next, zero descriptor (size=0 reclaims slot), silent no-op on foreign ptr. No coalescing (gaps recovered by alloc arithmetic).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005de9a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
