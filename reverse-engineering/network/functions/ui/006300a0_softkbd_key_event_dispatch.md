# 0x006300a0 softkbd_key_event_dispatch

| field | value |
|---|---|
| Original address | 0x006300a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006300a0 |
| Resolved name | softkbd_key_event_dispatch |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630010
**Callees:** FUN_00630c90, FUN_00630e40, FUN_00630f20, FUN_00631030, FUN_00631100, FUN_006312c0, FUN_006314a0, FUN_00631720, FUN_00631790, FUN_00631880, FUN_00631ac0, FUN_00631bb0, FUN_00631c80, FUN_00631cf0, FUN_00631d60, FUN_00631e40, FUN_006352e0, FUN_00635b90, FUN_00637210
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x26 active flag; +0x4a4 key code; +0x30 mode; +0x34 field kind; +8 target row/data ptr

## Behavioral explanation
Core soft-keyboard event dispatcher: switches on the current key/event code (+0x4a4) to per-key handlers (arrows, enter, cancel, backspace, layout, char-commit).

## Notes / uncertainty
Central key-code router with accept-gate (ranges + field-kind-gated 0x64) then key->handler ladder; default arm = char commit FUN_006352e0(widget[8]). Key codes are UI actions NOT wire opcodes. Several individual handler roles named by address only, inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006300a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
