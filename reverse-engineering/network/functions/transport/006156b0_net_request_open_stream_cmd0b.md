# 0x006156b0 net_request_open_stream_cmd0b

| field | value |
|---|---|
| Original address | 0x006156b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006156b0 |
| Resolved name | net_request_open_stream_cmd0b |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00615670, FUN_00616470, FUN_00616518
**Referenced globals:** 0x70d200; 0x70d240; uRam0070d248
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam0070d248

## Behavioral explanation
Starts an async resolver request: registers handle (616470), resets buffer, stores key *param, issues socket command 0xb; on failure closes (616518).

## Notes / uncertainty
Opens streaming request via channel cmd 0x0b (transport-level, NOT SN@P app 0x0c); NULL->-0x65, register/close handle lifecycle. No in-corpus caller; cmd 0x0b semantics unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006156b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
