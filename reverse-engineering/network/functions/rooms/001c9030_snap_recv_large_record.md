# 0x001c9030 snap_recv_large_record

| field | value |
|---|---|
| Original address | 0x001c9030 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c9030 |
| Resolved name | snap_recv_large_record |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c3a60, FUN_001c3b90
**Referenced globals:** 0x365dc0=selector; 0x365dc4=subcount; 0x35ccc8=record buf; 0x365dc8/dcc=record ptrs
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iVar2+0xc=topstate; iVar2+0xdc=error

## Behavioral explanation
Reads a selector byte then a 0x13-byte header plus a 0xfeb-byte body into the 0x35ccc8 buffer (large room/scenario record), advancing substate to 0x29.

## Notes / uncertainty
Bulk record ingest to 0x35ccc8: selector1=read 0x13 header + 0xfeb body (0xfff total, body@+0x14), publish ptrs 0x365dc8/dcc; selector0=empty; next 0x29. Header/body internal layout + subcount role undecoded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c9030.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
