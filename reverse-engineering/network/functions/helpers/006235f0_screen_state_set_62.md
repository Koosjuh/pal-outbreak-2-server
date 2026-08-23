# 0x006235f0 screen_state_set_62

| field | value |
|---|---|
| Original address | 0x006235f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006235f0 |
| Resolved name | screen_state_set_62 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ae310, FUN_00608300
**Callees:** —
**Referenced globals:** 0x7152e1 screen-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam007152e1

## Behavioral explanation
Sets screen-state byte 0x7152e1 = 0x62 — forces a screen SM into a specific error/abort state.

## Notes / uncertainty
One-line setter: *(u8*)0x7152e1=0x62 forces the shared screen SM into phase 'b' (abort/redirect). No callees; 2 callers. Semantic meaning of phase 0x62 in the dispatch table is unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006235f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
