# 0x0062f3f0 back_exit_ack_handler

| field | value |
|---|---|
| Original address | 0x0062f3f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062f3f0 |
| Resolved name | back_exit_ack_handler |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005f6970
**Referenced globals:** 0x6c4fbb pending-step; 0x6c4ba0/ba1 substates
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4fbb pending-step(==0x19)

## Behavioral explanation
Reply callback (expects cRam006c4fbb==0x19): status 0 clears ba1 and bumps ba0, else FUN_005f6970(4) error.

## Notes / uncertainty
Already fully reconstructed. Back/exit step ack (pending_tag 0x19): success sub_step=0+step++, failure FUN_005f6970(4). Open: which back/exit transition fires it.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062f3f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
