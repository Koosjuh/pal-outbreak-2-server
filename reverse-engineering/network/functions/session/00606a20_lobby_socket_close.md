# 0x00606a20 lobby_socket_close

| field | value |
|---|---|
| Original address | 0x00606a20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606a20 |
| Resolved name | lobby_socket_close |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f4040
**Callees:** —
**Referenced globals:** uRam0035a6f4 (socket)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Closes the lobby socket (func_0x001ee650/680 on handle 0x35a6f4) and returns 2 (abort/closed sentinel).

## Notes / uncertainty
Shutdown-then-destroy of socket at 0x35a6f4 (value to 001ee650, address to 001ee680); returns SM sentinel 2. Meaning of '2' inferred from caller family FUN_005f4040.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00606a20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
