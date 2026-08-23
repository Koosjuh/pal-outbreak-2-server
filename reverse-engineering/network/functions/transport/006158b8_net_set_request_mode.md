# 0x006158b8 net_set_request_mode

| field | value |
|---|---|
| Original address | 0x006158b8 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006158b8 |
| Resolved name | net_set_request_mode |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0060e060
**Callees:** —
**Referenced globals:** 0x654200 (request mode)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x654200

## Behavioral explanation
Stores param into global mode word ram0x00654200 (later folded into requests as uRam0070d244).

## Notes / uncertainty
Setter: g_req_mode 0x654200 = param, consumed by issue_t2 as 0x70d244. Mode value meaning unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006158b8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
