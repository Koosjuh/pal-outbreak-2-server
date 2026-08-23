# 0x005bc790 handle_name_reply_simple

| field | value |
|---|---|
| Original address | 0x005bc790 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc790 |
| Resolved name | handle_name_reply_simple |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bdf90, FUN_005c7d00
**Referenced globals:** 0x6fc05a (name reply block); 0x36842c (name registry/hash table)
**Referenced strings:** —
**Referenced opcodes:** 0x0e
**State vars:** —

## Behavioral explanation
Name reply handler (dispatch code 0xe): sub-type 0 loads the name/id record (0x6fc06a/0x6fc07e) and dispatches screen 5; otherwise hashes the 0x20-byte name into the registry (0x36842c) without the error-latch logic of FUN_005bc590.

## Notes / uncertainty
Simplified name-reply (code 0x0e): sub0 loads name record -> screen 5; else fire-and-forget registry touch @0x36842c (result discarded, no error latch). Reduced sibling of 005bc590.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bc790.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
