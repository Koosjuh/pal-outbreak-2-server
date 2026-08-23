# 0x005ae310 session_seq_step4_connect

| field | value |
|---|---|
| Original address | 0x005ae310 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ae310 |
| Resolved name | session_seq_step4_connect |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ae130
**Callees:** FUN_005ac380, FUN_005c8810, FUN_00608840, FUN_006235f0
**Referenced globals:** obj +0x993
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Session-seq step 4: calls FUN_005c8810 (connect/handshake) reading its status (-100/-1/1/0); on done/err resets gfx (ac380) [+ thunk 6235f0 on error] and advances cursor.

## Notes / uncertainty
Connect poll step: FUN_005c8810() status -1/1=connected (advance), 0=connecting (poll), -100/other=failure (error thunk 6235f0 + advance). CORRECTS prior note: -100 is the error path, not in-progress.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ae310.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
