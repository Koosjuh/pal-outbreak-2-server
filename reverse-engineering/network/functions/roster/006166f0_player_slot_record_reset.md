# 0x006166f0 player_slot_record_reset

| field | value |
|---|---|
| Original address | 0x006166f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006166f0 |
| Resolved name | player_slot_record_reset |
| Subsystem | roster |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060e250, FUN_0060e590, FUN_0060ed40, FUN_0060eff0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x1318 id=-1; +0x1324 count=4; +0x1328 flag=0xff

## Behavioral explanation
Zeroes a 0x1340-byte record then stamps the +0x1300..+0x1328 sub-block with 0xff/0xffffffff sentinels and byte defaults (id=-1, count=4) — resets a player/slot roster entry.

## Notes / uncertainty
Clears 0x1340-byte per-player slot record then stamps +0x1300 sentinel block (id=-1, capacity=4, 0xff colour/status). Field semantics of the +0x1300 sub-block (colour vs tag; six 0xffffffff dwords) inferred; roster-vs-generic-entity classification unproven. No runtime.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006166f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
