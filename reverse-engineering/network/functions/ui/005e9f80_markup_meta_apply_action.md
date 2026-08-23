# 0x005e9f80 markup_meta_apply_action

| field | value |
|---|---|
| Original address | 0x005e9f80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9f80 |
| Resolved name | markup_meta_apply_action |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005d89d0
**Referenced globals:** +0x1120; +0xe96b (applied guard); +0x186 (render mode); +0x1124; +0x1128
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x1120; +0xe96b; +0x186

## Behavioral explanation
If meta flag set and not already applied (+0xe96b==0), invokes action FUN_005d89d0 with parsed value(+0x1124)+string(+0x1128), gated by mode +0x186.

## Notes / uncertainty
Commits meta directive when matched && !collapsed(+0xe96b); mode fork on +0x186. FUN_005d89d0 installs string @701070+0x3b + timer value*0x1e @701068+0x69014. Buffer purpose (marquee?) unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9f80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
