# 0x005bd6e0 copy_server_config_in

| field | value |
|---|---|
| Original address | 0x005bd6e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bd6e0 |
| Resolved name | copy_server_config_in |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b25c0
**Callees:** —
**Referenced globals:** 0x6cbe20 (server/config struct)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Copies a 0x24-byte (9 words *4) server/config struct from the caller's buffer into the global config at 0x6cbe20.

## Notes / uncertainty
Copies 0x24-byte (9-word) server config into global 0x6cbe20. Internal field layout of the config undecoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bd6e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
