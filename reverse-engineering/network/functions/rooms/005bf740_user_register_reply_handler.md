# 0x005bf740 user_register_reply_handler

| field | value |
|---|---|
| Original address | 0x005bf740 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bf740 |
| Resolved name | user_register_reply_handler |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bf280, FUN_005c7d00
**Referenced globals:** 0x6cbc35 step-ack; 0x6cbc84 status; 0x6fec18 registry-A id field; 0x6ce5de render struct id
**Referenced strings:** USER (0x55534552)
**Referenced opcodes:** —
**State vars:** 0x6cbc35; 0x6cbc84

## Behavioral explanation
Reply handler for the USER reliable txn: on ok advances SM (0x6cbc35=1); if reply tag==USER stores reply id into registry-A slot (0x6fec18) and render struct 0x6ce5de; on 0x27 sets error.

## Notes / uncertainty
op09 USER register reply cb: ok->step-ack 0x6cbc35=1 and commit assigned id (reply[2]) into registryA[i]+0x14 (0x6fec18) + render 0x6ce5de if tag==USER and lookup hit; 0x27->step-ack 2. Lookup key meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bf740.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
