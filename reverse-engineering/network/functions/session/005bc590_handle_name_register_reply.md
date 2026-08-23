# 0x005bc590 handle_name_register_reply

| field | value |
|---|---|
| Original address | 0x005bc590 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc590 |
| Resolved name | handle_name_register_reply |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bdf90, FUN_005c7d00, FUN_005c7e30
**Referenced globals:** 0x6fc05a (name reply block); 0x36842c (name registry/hash table); 0x700680 (dup/error latch); 0x7006a7/0x700682 (retry/backoff); 0x6febb4 (local seq/handle)
**Referenced strings:** —
**Referenced opcodes:** 0x0d, 0x0b
**State vars:** cRam00700680

## Behavioral explanation
Name/register reply handler (dispatch codes 0xd and 0xb): sub-type 0 loads a name/id record (0x6fc06a/0x6fc07e + params) and dispatches screen 5; sub-types 1/2 hash a 0x20-byte name against the registry (func_0x0010a338 @0x36842c) and, on miss, latch a duplicate/error state (0x700680) and dispatch error screen 0x2b.

## Notes / uncertainty
Name-register reply (codes 0x0d/0x0b): sub0 loads name record (0x6fc06a/07e) -> screen 5; sub1/2 registry lookup @0x36842c, miss -> dup/error latch 0x700680 + screen 0x2b, hit -> backoff 0x700682=(0x6febb4&0xF)*30. Payload len fields decoded. 0x0b vs 0x0d distinction unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bc590.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
