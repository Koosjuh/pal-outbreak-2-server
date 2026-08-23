# 0x00607260 roomquery_state1_handler

| field | value |
|---|---|
| Original address | 0x00607260 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00607260 |
| Resolved name | roomquery_state1_handler |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00606cf0
**Callees:** FUN_005af2f0, FUN_00606fa0, FUN_00607a10, FUN_00618b60
**Referenced globals:** 0x00874f35 phase; 0x008744f8 room-count; 0x006c5490 txn-block; 0x006c5494 flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00874f35; cRam008744f8

## Behavioral explanation
State-1: if room-count==1 takes shortcut, else advances step, seeds txn-block 6c5490 and kicks 00607a10 retry with a 10-tick delay; infinite-loop trap if phase 874f35 mismatched.

## Notes / uncertainty
Phase-guarded (0/1/2 ok, 3 forbidden -> while(true) hang). room_count==1 fast-path to substate5; else seed query block 0x6c5490 + dispatch txn + sound. Whether 0x8744f8 is count vs mode, and phase semantics, unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00607260.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
