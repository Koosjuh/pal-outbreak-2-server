# 0x001ae3e0 measure_text_width

| field | value |
|---|---|
| Original address | 0x001ae3e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ae3e0 |
| Resolved name | measure_text_width |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005cab10, FUN_005e2fa0, FUN_00613600
**Callees:** FUN_0010a050, FUN_001ade00, FUN_001adf30, FUN_001ae1a0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Half/full-width string metric under encoding-mode 0x2a6598==2 (thresholds 0x10/0x80, table via 0x2a6590; 0=full=+2); falls back to FUN_0010a050 otherwise. Units (px vs cell) and glyph decode unconfirmed; tag mis-set.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001ae3e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
