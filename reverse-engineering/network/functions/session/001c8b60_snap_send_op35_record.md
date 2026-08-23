# 0x001c8b60 snap_send_op35_record

| field | value |
|---|---|
| Original address | 0x001c8b60 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c8b60 |
| Resolved name | snap_send_op35_record |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_001c3840, FUN_001c3c90, FUN_001c3da0, FUN_001c3ea0, FUN_001c4020, FUN_001ee590
**Referenced globals:** 0x365a70=profile/config record base
**Referenced strings:** —
**Referenced opcodes:** 0x35
**State vars:** iVar2+0xd=substate

## Behavioral explanation
Builds and sends the op-0x35 packet serializing a fixed profile/config record from 0x365a70 (byte/u16/u32 fields, 3x(u32,byte,byte), 8x u32), then advances substate to 0x2e.

## Notes / uncertainty
Already fully reconstructed with corrected serializer (0x365a70 profile record, 3x(word+2B)+8xu32, op0x35, +8 hdr, htons len). Semantic meaning of 0x365a70 record (profile vs scenario) and append_word encoding remain layout-only.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c8b60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
