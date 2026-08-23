# 0x001c91d0 snap_recv_session_config

| field | value |
|---|---|
| Original address | 0x001c91d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c91d0 |
| Resolved name | snap_recv_session_config |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00106b60, FUN_001c3ab0, FUN_001c3b90
**Referenced globals:** 0x35cc70=session record buf; 0x35ccb0=assigned port; 0x35ccb3=once-flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iVar2+0xc=topstate; iVar2+0xdc=error; 0x35ccb3=done flag

## Behavioral explanation
On first pass reads a 0x3e-byte record into 0x35cc70 and a u16 server port into 0x35ccb0 (used later to open the TCP connection), then advances to substate 0x31.

## Notes / uncertainty
Already fully reconstructed (name improved from _port to _config in record): once-flag cRam0035ccb3 gated read of 0x3e bytes into 0x35cc70, derive port -> 0x35ccb0, -56/phase-7 on failure. Full 0x3e-byte config layout beyond port unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c91d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
