# 0x005bd890 get_local_blob_6cc464

| field | value |
|---|---|
| Original address | 0x005bd890 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bd890 |
| Resolved name | get_local_blob_6cc464 |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b6070
**Callees:** —
**Referenced globals:** 0x6cc464 (local 0xf0 record)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Accessor: copies the 0xf0-byte local record at 0x6cc464 into the caller's buffer.

## Notes / uncertainty
memcpy 0xf0-byte local profile record from 0x6cc464 (3-arg thunk func_0x001069a8); internal record layout undecoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bd890.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
