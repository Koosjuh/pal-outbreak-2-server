# 0x001e3ba8 socket_select

| field | value |
|---|---|
| Original address | 0x001e3ba8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e3ba8 |
| Resolved name | socket_select |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d72a8
**Callees:** FUN_001e3a3c, FUN_001e4bec, FUN_001eb2d4
**Referenced globals:** PTR_0025b798 table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** state 0x7f/0xff4/0xff6; slot+2 type

## Behavioral explanation
select(): scans read/write fd bitmasks (param_2/param_3) over up to 0x40 sockets, pumps state (e4bec) and the RX demux (e3a3c), counts ready descriptors and clears not-ready bits.

## Notes / uncertainty
select() over PTR_0025b798 table (0x24 stride, cap 0x40); pumps rx demux once (bVar1) + per-socket service e4bec; counts ready, clears not-ready bits. State codes 0x7f/0xff4/0xff6 labels inferred, not runtime-validated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e3ba8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
