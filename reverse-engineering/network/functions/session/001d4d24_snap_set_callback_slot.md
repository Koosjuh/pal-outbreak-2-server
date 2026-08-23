# 0x001d4d24 snap_set_callback_slot

| field | value |
|---|---|
| Original address | 0x001d4d24 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d4d24 |
| Resolved name | snap_set_callback_slot |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001cadc0, FUN_001db7e8, FUN_001dbefc, FUN_001dc0b8, FUN_001dc310, FUN_001dc508, FUN_001dc804, FUN_001dc9fc, FUN_001dcbf4, FUN_001dcdfc, FUN_001dd07c, FUN_001dd1dc, FUN_001dd33c, FUN_001dd5f8, FUN_001dd840, FUN_001dda88, FUN_001ddc60, FUN_001ddda0, FUN_001ddee8, FUN_001de0c0, FUN_001de298, FUN_001de470, FUN_001de648, FUN_001dfda0, FUN_001dff7c, FUN_001e0188, FUN_001e0358, FUN_001e0428, FUN_001e04f8, FUN_001e094c, FUN_001e0ed8
**Callees:** —
**Referenced globals:** 0x0025b78c conn-ptr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0x548 callback table

## Behavioral explanation
When conn is live, swaps in a new handler/callback pointer at conn+0x548+idx*4 and returns the previous one.

## Notes / uncertainty
Swaps conn+0x548+idx*4 handler ptr, returns previous; guard param1==1. 31 opcode-send callers. No bounds check; table length unknown; return 0 ambiguous with NULL prev.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d4d24.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
