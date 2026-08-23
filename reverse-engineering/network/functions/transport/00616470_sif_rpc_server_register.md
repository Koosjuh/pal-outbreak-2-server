# 0x00616470 sif_rpc_server_register

| field | value |
|---|---|
| Original address | 0x00616470 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00616470 |
| Resolved name | sif_rpc_server_register |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006156b0
**Callees:** —
**Referenced globals:** 0x70f2c0 (handler ptr); 0x70f2c8 (handler ptr fno 0x0d)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x70f2c0/0x70f2c8 handler table

## Behavioral explanation
Creates the RPC service thread (entry FUN_00616400) and stashes two caller-supplied handler function pointers into 0x70f2c0/0x70f2c8.

## Notes / uncertainty
Installs 2 dispatch handlers (0x70f2c0/0x70f2c8) + spawns RPC service thread FUN_00616400; ee_thread param mapping (param_2/3/4=stack/size/prio, gp=0x263770) is inferred from struct order; unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00616470.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
