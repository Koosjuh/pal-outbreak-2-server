# 0x00637570 kbd_keycell_lookup_checked

| field | value |
|---|---|
| Original address | 0x00637570 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637570 |
| Resolved name | kbd_keycell_lookup_checked |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00637430, FUN_006375d0
**Callees:** —
**Referenced globals:** 0x715da8 state struct; 0x692450 key→cell table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x20 disabled-key bitmask

## Behavioral explanation
Maps a key value via DAT_00692450 to a cell index, returning -1 if unmapped or if that key is disabled in bitmask 0x20.

## Notes / uncertainty
Maps key via table 0x692450 to cell index; returns -1 if unmapped (negative entry) or cell disabled in mask +0x20. Table contents not dumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637570.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
