# 0x006155c8 net_resolver_open

| field | value |
|---|---|
| Original address | 0x006155c8 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006155c8 |
| Resolved name | net_resolver_open |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00615670
**Callees:** —
**Referenced globals:** 0x70d200 (resolver/socket handle); iRam0070d224 (ready); DAT_00654204 (opened latch)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** DAT_00654204; iRam0070d224

## Behavioral explanation
Opens/initializes the network resolver handle at 0x70d200 (retrying until iRam0070d224 ready), latching DAT_00654204 once open.

## Notes / uncertainty
Lazy one-shot open of aux resolver channel 0x70d200 (proto 0x80001101), latch DAT_00654204, busy-wait retry until ready field 0x70d224. Channel purpose (DNAS/matchmaking/DB) unproven; distinct from SN@P game socket.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006155c8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
