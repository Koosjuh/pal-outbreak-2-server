# 0x001d2970 spawn_character_slot

| field | value |
|---|---|
| Original address | 0x001d2970 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d2970 |
| Resolved name | spawn_character_slot |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001cb360, FUN_001ce6d0, FUN_001d09e0, FUN_001d0a10
**Referenced globals:** 0x4fa6f0 slot-id map; 0x4fe480/0x4fccf0 character slot table (stride 0xc84); 0x3c18b0/0x3c2e80/0x3c3440 def tables
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates one of 6 character/NPC slots at 0x4fe480, loads its data and registers it (FUN_001ce6d0/001d09e0).

## Notes / uncertainty
Instantiates 1 of 6 char slots (0x4fe480 stride 0xc84, occupied byte +1); idempotent per char via 0x4fa6f0 map; primary+conditional secondary asset load. No callers indexed; invocation context unknown. Not network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d2970.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
