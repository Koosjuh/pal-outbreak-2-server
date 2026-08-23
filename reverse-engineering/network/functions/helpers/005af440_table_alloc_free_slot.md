# 0x005af440 table_alloc_free_slot

| field | value |
|---|---|
| Original address | 0x005af440 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005af440 |
| Resolved name | table_alloc_free_slot |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006293f0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Scans an array of up to 30 records (stride 0x38) for the first free slot (first byte == 0) and initializes it (func_0x00109eb8); returns 0 on success, 1 when full.

## Notes / uncertainty
First-fit allocator: 30 records x 0x38 stride, offset-0 byte = in-use tag (0=free); inits via func_0x00109eb8, returns 0=ok/1=full. UI-local pool (caller 0x6293f0), distinct from server member/room registries; record layout undecoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005af440.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
