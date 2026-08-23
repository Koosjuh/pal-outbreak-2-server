# 0x001cfc90 send_op07_and_load_table

| field | value |
|---|---|
| Original address | 0x001cfc90 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cfc90 |
| Resolved name | send_op07_and_load_table |
| Subsystem | menus |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_00106b60, FUN_00109728, FUN_001a0df0, FUN_001a7a80, FUN_001a7b70, FUN_001a9050, FUN_001ab460, FUN_001abf00, FUN_001b2470, FUN_001cb360, FUN_001cbc20, FUN_001cce80
**Referenced globals:** 0x3ce2b0/0x3cdc90/0x3cdcb0 parsed tables; uRam0034357a/c/e session ids; sRam003433a8 mode; uRam003434a0 input/abort mask
**Referenced strings:** 0x24cbb0 template; 0x24cbd0 template; 0x24cbf0; 0x24cc10; 0x24cc30; 0x24cc40 (progress/download UI text)
**Referenced opcodes:** 0x07
**State vars:** sRam003433a8; cRam00343577

## Behavioral explanation
Channel 0x2100+, alloc tag 7, reliable send FUN_001cce80/offline FUN_001a0df0 with tmpl 0x24cbb0/0x24cbd0; then parses a large reply into 0x3ce2b0/0x3cdc90/0x3cdcb0 with a progress-UI wait loop for big payloads.

## Notes / uncertainty
Upgraded classified->reconstructed. op07 (channel 0x2100+slot*0x30, tag 7) request key=p1<<16|p2<<8|p3; online FUN_001cce80+FUN_001cb360 / offline FUN_001a0df0; parses 3 tables N*8@0x3ce2b0, M*0xc@0x3cdc90, K*0x30@0x3cdcb0 into work_base+0x200004; cancelable progress screen when K>0x20 or len>0x5000. Uncertainty: table record layouts (scenario/room dataset) not decoded; progress loop likely a confirm screen since transfer completes in the blocking txn.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cfc90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
