# 0x001c0f40 auth_conn_sm_modeA

| field | value |
|---|---|
| Original address | 0x001c0f40 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c0f40 |
| Resolved name | auth_conn_sm_modeA |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00106b60, FUN_001c0b20, FUN_001c0ca0, FUN_001c0d60, FUN_001c0dc0, FUN_001c0de0, FUN_001c2770, FUN_001ee3b0, FUN_001ee8d0, FUN_001ee900, FUN_001ee9b0, FUN_001ee9d0, FUN_001eea10, FUN_001eeb00, FUN_001eeb50
**Referenced globals:** 0x35c3d8 mode/ctx; 0x35b74c-0x35b74e retry/ttl; 0x35a6dc/0x35a6e0 peer-reply; 0x35cc50 io-ctx; 0x35bec8 src-sel; 0x35ba98
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** *param_2 sm-state; 0x35a6e0 reply-code; 0x35b74c retry

## Behavioral explanation
Large DNAS-auth/connection state machine (states 'd','c',0x00-0x0a): drives connect->handshake->keepalive, builds error codes 0xaa/0xab/0xae/0xaf/0xfb/0xfd/0xfe into out-status, branches on peer reply 0x35a6e0.

## Notes / uncertainty
Verified against raw (446 lines): DNAS direct-connect SM, backoff window 0x35b74c/d/e, peer-reply major/code classification -> DNAS status bytes 0xaa/ab/ae/af/fb/fd/fe. Domain labels for major/code sub-codes inferred from control flow only.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c0f40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
