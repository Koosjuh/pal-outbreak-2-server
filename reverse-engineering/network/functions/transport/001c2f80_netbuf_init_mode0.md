# 0x001c2f80 netbuf_init_mode0

| field | value |
|---|---|
| Original address | 0x001c2f80 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c2f80 |
| Resolved name | netbuf_init_mode0 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00106b60, FUN_0010a050, FUN_0010a4f0, FUN_001c2da0
**Referenced globals:** 0x3435fc heap-base; 0x35ccc0/0x35ccc8/0x35ccb8 buf-ptrs; 0x365df0 =0x702140; 0x365e14
**Referenced strings:** (0x248760 host); (0x248790 host)
**Referenced opcodes:** —
**State vars:** 0x365c20

## Behavioral explanation
Full init for connection mode 0: builds ctx (FUN_001c2da0(0)), allocates 0x3000/0x1000 rx/tx regions off 0x3435fc, loads string tables via func_0x0061c8e0/900/920 and default host strings.

## Notes / uncertainty
Full mode-0 (lobby socket) bring-up: 3 heap regions off 0x3435fc, DNS/host tables via func_0x0061c8e0/900/920, addr-resolve loop (FUN_0010a050). Target addresses 0x702140/0x361a70/0x363a70 roles inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c2f80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
