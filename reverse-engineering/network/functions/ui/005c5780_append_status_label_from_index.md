# 0x005c5780 append_status_label_from_index

| field | value |
|---|---|
| Original address | 0x005c5780 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c5780 |
| Resolved name | append_status_label_from_index |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c5810
**Callees:** FUN_005c7ff0
**Referenced globals:** 0x6fbe58 status-text-buf
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Maps a small state index (0..5) to string-id (0xb..0x10), resolves the string via FUN_005c7ff0 and appends it to status buffer 0x6fbe58.

## Notes / uncertainty
Renamed set_->append_ (strcat not overwrite): idx 0..5 -> string-id 0xb..0x10, resolve via FUN_005c7ff0, append to 0x6fbe58; out-of-range=no-op. String texts not dumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c5780.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
