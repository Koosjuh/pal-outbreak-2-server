# 0x001cfb30 send_op08_message

| field | value |
|---|---|
| Original address | 0x001cfb30 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cfb30 |
| Resolved name | send_op08_message |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728, FUN_001a1750, FUN_001a7b70, FUN_001ab460, FUN_001cb360, FUN_001cbc20, FUN_001cce80, FUN_001d24c0
**Referenced globals:** 0x404aa0/0x4052a8 buffers; cRam00343577 offline-mode; uRam003435bc work base
**Referenced strings:** 0x24cb80 template; 0x24cb90 template; 0x24cba0 template
**Referenced opcodes:** 0x08
**State vars:** cRam00343577

## Behavioral explanation
Channel 0x2a00, attribute preset (note key0=0x20), alloc tag 8, reliable send FUN_001cce80 (or offline FUN_001a1750), builds tmpl 0x24cb90/0x24cba0 and on success calls FUN_001d24c0.

## Notes / uncertainty
op08 builder: channel 0x2a00, alloc tag 8 (=op08), 8-attr preset (max 0x8000,key0=0x20), online FUN_001cce80 / offline FUN_001a1750, then follow-up FUN_001cb360->FUN_001d24c0. Template strings + follow-up opcode undecoded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cfb30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
