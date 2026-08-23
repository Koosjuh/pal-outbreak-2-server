# 0x005faa60 password_entry_screen_sm

| field | value |
|---|---|
| Original address | 0x005faa60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005faa60 |
| Resolved name | password_entry_screen_sm |
| Subsystem | menus |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005fa0b0
**Callees:** FUN_005adc80, FUN_005b09b0, FUN_005b14b0, FUN_005b4c80, FUN_005b7fd0, FUN_005b9110, FUN_005fb670, FUN_006345e0, FUN_00634ab0, FUN_00637180, FUN_006371d0
**Referenced globals:** 0x6970a2 input buffer; 0x6c076f slot flag; 0x6c4610/0x6c4618/0x6c4620 input masks; +0x43c/+0x443 flags
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x10 sub-state; +0x16 timer

## Behavioral explanation
Text/password-entry screen SM (buffer @0x6970a2): drives soft-keyboard input, timed prompts and confirm, guarded by connection check.

## Notes / uncertainty
Already fully reconstructed. 10-substate soft-keyboard SM into buffer 0x6970a2. Whether text is password/room-name/search is context-dependent (shared buffer); dialog id 0x19 and masks inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005faa60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
