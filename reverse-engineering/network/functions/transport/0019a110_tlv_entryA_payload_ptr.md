# 0x0019a110 tlv_entryA_payload_ptr

| field | value |
|---|---|
| Original address | 0x0019a110 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_0019a110 |
| Resolved name | tlv_entryA_payload_ptr |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d1740
**Callees:** FUN_0019a070
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Returns entry(FUN_0019a070)+0xc payload pointer, NULL-safe. Which entry/tag A resolves not decompiled here; twin of 0019a1e0.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_0019a110.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
