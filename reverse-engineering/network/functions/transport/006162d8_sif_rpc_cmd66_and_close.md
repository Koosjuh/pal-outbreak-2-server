# 0x006162d8 sif_rpc_cmd66_and_close

| field | value |
|---|---|
| Original address | 0x006162d8 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006162d8 |
| Resolved name | sif_rpc_cmd66_and_close |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060e160
**Callees:** FUN_00616250, FUN_00616b40
**Referenced globals:** 0x654204 (rpc channel-active flag, cleared)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x654204 channel flag

## Behavioral explanation
Higher-level teardown: sends RPC fno 102, releases the RPC guard sema (FUN_00616b40(0)) and clears channel-active flag 0x654204.

## Notes / uncertainty
Session teardown: fires fno 102, BLOCKS on FUN_00616b40(0) (WaitEventFlag+dispatch), clears channel-active flag DAT_00654204. Confirms fno102=close by construction.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006162d8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
