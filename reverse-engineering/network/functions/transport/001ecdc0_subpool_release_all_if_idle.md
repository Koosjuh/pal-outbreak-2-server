# 0x001ecdc0 subpool_release_all_if_idle

| field | value |
|---|---|
| Original address | 0x001ecdc0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ecdc0 |
| Resolved name | subpool_release_all_if_idle |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d46ec
**Callees:** FUN_001e2010, FUN_001eb2d4, FUN_001eb434, FUN_001ee024
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0x5c/+0x62/+0x68 base seq; conn+0x14 / conn+0x28 sub-channel bases

## Behavioral explanation
If all three channels' computed seq (FUN_001eb2d4) equals stored base at +0x5c/+0x62/+0x68, drains each queue (FUN_001eb434) processing+freeing entries via FUN_001ee024, then releases conn; else returns 0xffffe0c1 (-7999).

## Notes / uncertainty
Idle-gated pool teardown: only when all 3 tiers' depth==fill count (nothing outstanding) does it drain+free every buffer (ee024) and free the header (e2010); else -7999 busy. Nested decompiler loops are just 3 sequential drains sharing -0x1b56. Rename from 'flush_channels_if_synced'.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ecdc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
