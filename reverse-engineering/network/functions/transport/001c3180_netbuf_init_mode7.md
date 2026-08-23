# 0x001c3180 netbuf_init_mode7

| field | value |
|---|---|
| Original address | 0x001c3180 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c3180 |
| Resolved name | netbuf_init_mode7 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00106b60, FUN_001c2da0
**Referenced globals:** 0x3435fc heap-base; 0x35ccc8/0x35ccb8 buf-ptrs; 0x365df0 =0x702140
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Init for connection mode 7: FUN_001c2da0(7) then allocate rx/tx (0x3000/0x1000) off heap 0x3435fc and set buffer pointers.

## Notes / uncertainty
Leaner mode-7 (room/game socket) variant: 2 heap regions, no DNS/resolve loop, same handler wiring. lobby-vs-room role distinction inferred from DNS-skip.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c3180.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
