# 0x006014c0 opresult_handler_tag0x21

| field | value |
|---|---|
| Original address | 0x006014c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006014c0 |
| Resolved name | opresult_handler_tag0x21 |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005be9a0
**Referenced globals:** 0x6c4fbb pending-op tag; 0x6c4b9e page; 0x6c517c error-ctx; 0x6c4ba5 retry timer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fbb op tag

## Behavioral explanation
Deferred op-result handler gated on pending-op tag 0x21: on success advances 6c4b9e page counter; on failure shows error (FUN_005be9a0) and rewinds paging with a retry timer 0x14.

## Notes / uncertainty
Deferred op-result cb gated on pending_tag==0x21; success->lobby_sm++ (advance page), fail->error dialog(0x6c517c)+rewind to page4+retry timer 0x14. Wire op for tag 0x21 unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006014c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
