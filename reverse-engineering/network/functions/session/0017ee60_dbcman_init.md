# 0x0017ee60 dbcman_init

| field | value |
|---|---|
| Original address | 0x0017ee60 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_0017ee60 |
| Resolved name | dbcman_init |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0019d3e0
**Callees:** FUN_00114ac8, FUN_00115300, FUN_00115a98, FUN_0017ee08, FUN_0017f0e8, FUN_0017fd00
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
sceDbcMan one-time init: SifInitRpc, bind 3 IOP servers (0x80001300 ctl / 0x131b SendData2 / 0x131c SendData3), require module major ver==3, CreateSema(max0x7f,init1), zero 16-word flag mirror, dbcman_config(fn0x304). Gated by ram0x0022f590. FUN_0017ee08 version-getter not opened.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_0017ee60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
