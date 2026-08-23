# 0x005b2bc0 screen_lobby_entry

| field | value |
|---|---|
| Original address | 0x005b2bc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b2bc0 |
| Resolved name | screen_lobby_entry |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b24e0
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005af2f0, FUN_005af300, FUN_005af310, FUN_005b2aa0, FUN_005b68e0, FUN_005ba7b0, FUN_005bda60, FUN_005f6970, FUN_0062fea0
**Referenced globals:** 0x874f35 mode
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0xf sub-state; struct+0x5190 pw-present flag; struct+0x5194 password buffer; struct+0x16 timer

## Behavioral explanation
Screen-2 lobby-entry machine: gated by can_enter_lobby_for_mode, handles the password buffer (+0x5194, 0x300 bytes) and submits entry (0x5b9060 sel 0x14), with fade transitions.

## Notes / uncertainty
8-step entry SM (ctx+0xf): gate→fade→submit→wait-reply→fade-out→handoff. Submits 0x300-byte blob ctx+0x5194 via selector 0x14 (networked path) or local memcpy (entry_mode==0); polls reply selector 0x10. entry_mode domain meaning (host vs password-join) and fade helper names inferred; Medium confidence.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b2bc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
