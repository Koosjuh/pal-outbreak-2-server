# 0x005bb440 reset_roster_chat_buffers

| field | value |
|---|---|
| Original address | 0x005bb440 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bb440 |
| Resolved name | reset_roster_chat_buffers |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b25c0
**Callees:** —
**Referenced globals:** 0x006ca950/0x006ca958 uRam=counts; 0x006ca968 buffer(0x1000); 0x006cb968 buffer(0x2f8); 0x006ce5c8 buffer(10); 0x006febac buffer(0x1b44); 0x006cc064 buffer(0x9c); 0x006febde uRam
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006ca950; uRam006ca958; uRam006febde

## Behavioral explanation
Zeroes the room/roster/chat state buffers: 0x6ca968 (0x1000), 0x6cb968 (0x2f8), 0x6ce5c8 (10), 0x6febac (0x1b44), 0x6cc064 (0x9c), and clears count globals 0x6ca950/0x6ca958/0x6febde.

## Notes / uncertainty
Zeroes roster/chat/registry state buffers (0x6ca968/0x6cb968/0x6ce5c8/0x6febac/0x6cc064) + count scalars on room init/teardown. Per-buffer semantic labels inferred from adjacency.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bb440.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
