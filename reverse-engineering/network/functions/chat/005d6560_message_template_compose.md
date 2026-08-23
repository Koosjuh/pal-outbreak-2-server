# 0x005d6560 message_template_compose

| field | value |
|---|---|
| Original address | 0x005d6560 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d6560 |
| Resolved name | message_template_compose |
| Subsystem | chat |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005d60a0
**Callees:** FUN_005d6510
**Referenced globals:** —
**Referenced strings:** str@0x6430d0 template; str@0x6432d0 template; str@0x643220 footer; str@0x643260 footer
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Composes a fixed-format record: appends template blocks (0x6430d0/0x6432d0) around two variable strings, choosing footer (0x643220/0x643260) by a flag.

## Notes / uncertainty
Serializes a message: appends header template 0x6430d0(0x14c) + param_2 str + mid 0x6432d0(0x18) + param_3 str + footer (param_4==0 ? 0x643220/0x32 : 0x643260/0x69) into a builder handle via FUN_005d6510; vars appended strlen+1. Block order/lengths certain; template text unresolved so mail-body vs wire-payload inferred; builder internals (FUN_005d6510) not fully mapped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d6560.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
