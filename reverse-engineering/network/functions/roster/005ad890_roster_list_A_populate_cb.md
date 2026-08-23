# 0x005ad890 roster_list_A_populate_cb

| field | value |
|---|---|
| Original address | 0x005ad890 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ad890 |
| Resolved name | roster_list_A_populate_cb |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005be9a0, FUN_005bf3a0, FUN_005bf3c0, FUN_005bf940, FUN_005bf9e0, FUN_005bfa20
**Referenced globals:** 0x6c3860(list A dest); 0x6c386e(type); 0x6c3862/0x6c3878/0x6c38b9(fields); 0x6c45fa(count); 0x6c4fbb(pending); 0x6c4ba0/0x6c4b9f
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fbb; cRam006c4b90

## Behavioral explanation
Async reply callback (pending flag fbb==3): on success unpacks a received list into array 0x6c3860, writing index + fields (5bf9e0/5bf940/5bf3c0/5bfa20) for uRam006c45fa entries; on failure shows error.

## Notes / uncertainty
Async list-A reply cb, pending tag 0x6c4fbb==3; status 0=ok/2=pending/else=error. Fills array 0x6c3860 stride 0x15c (4 field getters), sets result 0x6c4ba0 (0 ok/1 err), advances SM step 0x6c4b9f. Which list (rooms vs area) unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ad890.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
