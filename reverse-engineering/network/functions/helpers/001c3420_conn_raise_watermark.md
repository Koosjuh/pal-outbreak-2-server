# 0x001c3420 conn_raise_watermark

| field | value |
|---|---|
| Original address | 0x001c3420 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c3420 |
| Resolved name | conn_raise_watermark |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c2da0, FUN_001c4070, FUN_001c9810, FUN_001c9850, FUN_001c9b00
**Callees:** —
**Referenced globals:** 0x35ccb3 clamp-disable; obj+0xe0 watermark
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x35ccb3

## Behavioral explanation
Raises a per-conn watermark field (obj+0xe0) up to param unless global override 0x35ccb3 set — a send-rate/window clamp.

## Notes / uncertainty
Renamed from rate_clamp_max: monotonic RAISE (never lower) of conn+0xe0 toward param unless global freeze 0x35ccb3 set. 5 SN@P transport callers. Exact field semantic (seq vs window) to confirm against snap_connection layout.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c3420.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
