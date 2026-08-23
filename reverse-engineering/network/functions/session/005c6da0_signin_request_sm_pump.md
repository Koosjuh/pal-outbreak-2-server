# 0x005c6da0 signin_request_sm_pump

| field | value |
|---|---|
| Original address | 0x005c6da0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c6da0 |
| Resolved name | signin_request_sm_pump |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** 0x700480 login-req-struct; 0x6cc064.. user-config; 0x86f820/0x86f848/0x86f850/0x86f858 session-ids; 0x6cbbb8 phase; 0x6cbbbc active
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006cbbb8 phase; cRam006cbbbc active

## Behavioral explanation
Sign-in/login request state machine: phase 0 assembles a login request struct at 0x700480 from user-config fields (0x6cc0xx) and issues an async call; polls result (3=continue,4=done) then fires completion cb.

## Notes / uncertainty
3-phase DNAS/login-style pump: assemble 0x4c req at 0x700480 from 0x6cc0xx cfg + 0x86f8xx session ids, submit/poll/free via 0x001c3340/3380/33f0 (status 3=advance,4=done). login_req field meanings not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c6da0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
