# 0x005bcee0 session_connect_established_cb

| field | value |
|---|---|
| Original address | 0x005bcee0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bcee0 |
| Resolved name | session_connect_established_cb |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bcc30, FUN_005bdc70
**Referenced globals:** 0x6cc440/0x6cc450 (local name/id); 0x86f820 (local id); 0x639e78 (name template); 0x6cb96c (UI callback ptr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Connection-established callback: starts the RTT probe (FUN_005bcc30) then, on either result code (0 or '\''), refreshes local name/id (0x6cc440/0x6cc450 from 0x639e78/0x86f820), stamps a UI type byte and calls FUN_005bdc70 to advance the session.

## Notes / uncertainty
Connect-established completion cb; republishes local identity (0x6cc440/0x6cc450 from 0x639e78/0x86f820), fires UI notify kind=2, advances. Both status branches (0x00 OK / 0x27 NG) identical. Notify-kind semantics inferred; strcpy/memcpy libcalls confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bcee0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
