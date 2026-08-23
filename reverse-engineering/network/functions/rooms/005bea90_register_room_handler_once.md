# 0x005bea90 register_room_handler_once

| field | value |
|---|---|
| Original address | 0x005bea90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bea90 |
| Resolved name | register_room_handler_once |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ade20, FUN_005b4a50
**Callees:** —
**Referenced globals:** 0x6cbaf4 install guard; 0x6cbe4a 464-byte record; 0x6cbad0 callback ptr; 0x6cbad4 user param
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cbaf4 install guard

## Behavioral explanation
Copies a 464-byte record from the caller onto the stack, and (if cRam006cbaf4 unset) into global 0x6cbe4a, latching completion callback FUN_005befa0 and a user param — installs a large room/session data descriptor.

## Notes / uncertainty
One-shot install of a 464-byte handler record into 0x6cbe4a + callback FUN_005befa0, guarded by 0x6cbaf4 (ret -1 if already set). Stack copy is a decompiler artifact of the src->global halfword copy. Semantic content of the 464-byte descriptor undecoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bea90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
