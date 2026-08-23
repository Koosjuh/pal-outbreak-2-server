# 0x005dc4b0 ui_softkbd_commit_field

| field | value |
|---|---|
| Original address | 0x005dc4b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dc4b0 |
| Resolved name | ui_softkbd_commit_field |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005dc2b0, FUN_005dfee0
**Referenced globals:** iRam00701068+0x68e89: OSK buffer; iRam00701068+0x5ffc0: item list; iRam00701078+0x20: selected index; iRam00701088: text-field block; iRam00701068+0x68e84/0x68e86/0x68e83
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x68e84; 0x68e86; 0x20

## Behavioral explanation
UI text-entry commit handler: polls the OSK (FUN_005dc2b0); on cancel resets UI flags, on OK copies the typed chars into the selected list item's buffer (+100) and, for entry-type 4, parses a leading numeric code (0-9) to route the value into typed fields in iRam00701088 (name/password/number slots).

## Notes / uncertainty
Commits typed text into selected item buffer + routes via parsed 2-char code into iRam00701088 room-form field slots (name/pw/number). NO packet emitted here. Slot->semantic (which is title vs pw vs count) labels inferred, offsets firm.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dc4b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
