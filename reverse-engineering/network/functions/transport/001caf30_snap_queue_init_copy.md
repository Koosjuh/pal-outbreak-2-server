# 0x001caf30 snap_queue_init_copy

| field | value |
|---|---|
| Original address | 0x001caf30 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001caf30 |
| Resolved name | snap_queue_init_copy |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001bf180
**Referenced globals:** 0x35a690=queue; 0x35a290=queue template
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Initializes the 0x35a690 send/recv queue by copying a 0x400-byte template from 0x35a290 (FUN_001bf180).

## Notes / uncertainty
memcpy 0x400 template 0x35a290 -> live queue 0x35a690; 'empty template' vs 'saved snapshot' is inference, no caller recorded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001caf30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
