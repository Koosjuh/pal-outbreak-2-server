# 0x00616b40 sif_rpc_guard_release

| field | value |
|---|---|
| Original address | 0x00616b40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00616b40 |
| Resolved name | sif_rpc_guard_release |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006157e0, FUN_00615a58, FUN_006162d8
**Callees:** FUN_00616a58
**Referenced globals:** 0x654208 (rpc guard sema handle)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x654208 sema

## Behavioral explanation
Releases the RPC guard sema: param 0 = SignalSema then delete; param 1 = PollSema then delete; returns status.

## Notes / uncertainty
mode0=SignalSema+delete->0; mode1=PollSema, delete+0 if acquired else 1; -1 if uninit, -101 invalid mode; PollSema !=-1==acquired assumed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00616b40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
