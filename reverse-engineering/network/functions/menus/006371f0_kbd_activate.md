# 0x006371f0 kbd_activate

| field | value |
|---|---|
| Original address | 0x006371f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006371f0 |
| Resolved name | kbd_activate |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006345e0, FUN_00634ab0
**Callees:** —
**Referenced globals:** 0x715da8 state struct
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x30 active; 0x26 confirm

## Behavioral explanation
Setter: activates the keyboard (0x30=1) and clears confirm flag (0x26=0) — the 'open/enter text entry' entrypoint.

## Notes / uncertainty
Open transition: active +0x30=1, confirm +0x26=0. Exact inverse of 637210. Whether +0x26 is boolean vs result-code unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006371f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
