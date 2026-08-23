# 0x005f5c60 name_registry_insert

| field | value |
|---|---|
| Original address | 0x005f5c60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f5c60 |
| Resolved name | name_registry_insert |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f50d0
**Callees:** —
**Referenced globals:** 0x695d60(name registry, 100*0x30); 0x6c69cc(self-name compare); uRam006c4fb0(recency counter)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x695d88/8c (per-entry recency/flag)

## Behavioral explanation
Interns a (name,id) pair into a 100-entry local registry (0x695d60, stride 0x30); LRU-evicts the least-recently-used free slot when full.

## Notes / uncertainty
Interns (id,name) into 100-slot registry 0x695d60 (stride 0x30), skips self (0x6c69cc), LRU-evicts on full. Eviction path writes recency/status via 0x695d58+victim*0x30 — likely decompiler off-by-one vs id/name write to victim-1; confirm on trace.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f5c60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
