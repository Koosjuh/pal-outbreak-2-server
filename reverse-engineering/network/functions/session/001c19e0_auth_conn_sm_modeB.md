# 0x001c19e0 auth_conn_sm_modeB

| field | value |
|---|---|
| Original address | 0x001c19e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c19e0 |
| Resolved name | auth_conn_sm_modeB |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c0b20, FUN_001c0ca0, FUN_001c2770, FUN_001ee3b0, FUN_001eedc0, FUN_001eedf0, FUN_001eee30, FUN_001eee60, FUN_001eee90, FUN_001eef00, FUN_001eefb0, FUN_001ef040, FUN_001ef070, FUN_001ef0a0, FUN_001ef0d0, FUN_001ef100, FUN_001ef160
**Referenced globals:** 0x35c3d8 mode/ctx; 0x35b74c-0x35b74e ttl; 0x35a6c0/0x35a6c8 addr; 0x35ba88/0x35ba90/0x35ba98 peer; 0x35bec8 src-sel
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** *param_2 sm-state; 0x35b74c retry

## Behavioral explanation
Second large connection/auth state machine (states 0x00-0x1f incl. matchmaking/query steps): retries with backoff (0x35b74c/e ttl), calls resolver/connect helpers and FUN_001ef0d0/eee60 query polls; emits errors 0xaa-0xad.

## Notes / uncertainty
Already fully reconstructed (raw not independently re-read this pass, but record cites 522-line switch and shares mode-A prologue/backoff). Server-query/matchmaking path; helper op identities (ef040/ef0a0/ef160/eedc0/eee30) inferred from ordering.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c19e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
