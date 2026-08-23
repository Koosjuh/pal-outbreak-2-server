# 0x001c92d0 snap_xfer_dispatch_by_mode

| field | value |
|---|---|
| Original address | 0x001c92d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c92d0 |
| Resolved name | snap_xfer_dispatch_by_mode |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_001c3a60, FUN_001c3b10, FUN_001c3b90
**Referenced globals:** 0x365dd0=selector; 0x365dd1=10B transfer id; 0x365de1=4B tag; 0x365dec=total len
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** puVar3[0]=topstate; puVar3+0xd=substate; puVar3[0x1c]=total length; puVar3[0x12]=sent offset

## Behavioral explanation
Top-state dispatcher that on state 0/7 reads a 0xe-byte handshake, extracts a 10-byte id (0x365dd1) and 4-byte tag plus two u32 lengths, seeding the data-transfer state; other states just set the next substate.

## Notes / uncertainty
Renamed from snap_init_transfer_ids: it is the engine mode->substate dispatcher; modes 0/7 do the class-gated transfer-id/tag/total handshake (0x365dd1/de1/dec, substate 0x17). Uncertainty: FUN_001c3a60 class contract, second length word meaning.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c92d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
