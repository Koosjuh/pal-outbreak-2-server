# 0x005d71e0 build_req_enter_or_prev

| field | value |
|---|---|
| Original address | 0x005d71e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d71e0 |
| Resolved name | build_req_enter_or_prev |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d09d0
**Callees:** FUN_005d6630, FUN_005d6810
**Referenced globals:** 0x004f588 roomlist head; 0x004f694 txn head; 0x00701018 current room; 0x00701000 pending-req kind
**Referenced strings:** —
**Referenced opcodes:** 0x05, 0x06
**State vars:** uRam00701000

## Behavioral explanation
Like build_req_enter_or_create but using the reverse room iterator (FUN_005d6810): opcode 0x06/state5 if current, else opcode 0x05/state4, subtype 1.

## Notes / uncertainty
Reverse-iterator variant: op06/kind5 if current else op05/kind4 targeting neighbor payload (target+4, unlike 70b0). op05 wire semantics not captured.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d71e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
