# 0x005bdd90 init_input_handler_set

| field | value |
|---|---|
| Original address | 0x005bdd90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bdd90 |
| Resolved name | init_input_handler_set |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b3790
**Callees:** —
**Referenced globals:** 0x6cbacc init-guard flag; 0x6fc184 0x154 block; 0x6fe8e8/e9 count+data; 0x6cbaac callback ptr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cbacc guard; 0x6fc184/0x6fe8e8 count

## Behavioral explanation
Gated init (cRam006cbacc): zeroes a 0x154 block, clamps count param to 1, copies count bytes into 0x6fe8e9, stores a completion callback and invokes it.

## Notes / uncertainty
One-shot local input-device set init guarded by 0x6cbacc; clamps count to 1, copies device ids to 0x6fe8e9, stores+invokes completion cb (param_3@0x6cbaac). Guard never set non-zero in this fn (busy asserted externally); 0x154 block layout undecoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bdd90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
