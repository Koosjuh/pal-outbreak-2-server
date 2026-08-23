# 0x005ada90 roster_list_B_populate_cb

| field | value |
|---|---|
| Original address | 0x005ada90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ada90 |
| Resolved name | roster_list_B_populate_cb |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005be9a0, FUN_005bfc40, FUN_005bfcb0, FUN_005bfcf0, FUN_005bfd30
**Referenced globals:** 0x6c3030(list B dest); 0x6c303e(type); 0x6c3032/0x6c3089(fields); 0x6c45fe(count); 0x6c4fbb(pending); 0x6c4ba0/0x6c4b9f
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fbb; cRam006c4b90

## Behavioral explanation
Async reply callback (pending fbb==7): unpacks a received list into second array 0x6c3030, writing index+fields (5bfcf0/5bfcb0/5bfd30) for uRam006c45fe entries; error path shows box.

## Notes / uncertainty
Twin of list-A, pending tag==7, array 0x6c3030 stride 0x15c (3 field getters). Notably sets result 0x6c4ba0=0 on BOTH success and error (A sets 1 on error) — possibly best-effort/non-blocking. Identity of B unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ada90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
