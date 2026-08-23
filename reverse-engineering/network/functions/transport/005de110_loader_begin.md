# 0x005de110 loader_begin

| field | value |
|---|---|
| Original address | 0x005de110 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005de110 |
| Resolved name | loader_begin |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c8db0, FUN_005c9900
**Callees:** FUN_005e82b0
**Referenced globals:** cRam00701060 (loader state); uRam00701048 (bytes/progress); uRam00701050 (request handle)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00701060 (0 idle / 1 busy)

## Behavioral explanation
Starts an async resource-fetch: if idle, calls FUN_005e82b0 (open), latches cRam00701060=1 (busy) and stores the request handle in uRam00701050.

## Notes / uncertainty
One-shot async fetch start (DNAS/HTTP-style overlay loader, NOT SN@P): guard busy 0x701060, open FUN_005e82b0, latch busy + handle 0x701050. Exact fetch purpose (FUN_005e82b0) undecoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005de110.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
