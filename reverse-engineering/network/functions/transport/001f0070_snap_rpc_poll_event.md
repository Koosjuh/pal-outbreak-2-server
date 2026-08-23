# 0x001f0070 snap_rpc_poll_event

| field | value |
|---|---|
| Original address | 0x001f0070 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f0070 |
| Resolved name | snap_rpc_poll_event |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001e3a3c
**Callees:** FUN_001069a8, FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
EE inbound SN@P event pump. RPC selector 0x1b refills batch reply (0x1030) into staging @0x37aee8; pops one record {opcode,len,subtype,id,payload}; 0xffff when empty. Record[0] opcode is the app-dispatch value (likely wire opcode). Field map inferred; stride math exact.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f0070.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
