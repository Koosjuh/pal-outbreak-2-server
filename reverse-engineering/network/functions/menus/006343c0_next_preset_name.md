# 0x006343c0 next_preset_name

| field | value |
|---|---|
| Original address | 0x006343c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006343c0 |
| Resolved name | next_preset_name |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006378b0
**Callees:** FUN_00634a40
**Referenced globals:** 0x690cd0 (preset-name pointer table); 0x715b60 (preset index)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715b60

## Behavioral explanation
Copies the next canned preset name from table PTR_DAT_00690cd0[bRam00715b60] into the output, advances the index (wrap at 15); a random/default name picker.

## Notes / uncertainty
Cycles 15 canned preset names from table 0x690cd0[idx] (wrap>14), copies UTF-16 to out + byte-len, commits via FUN_00634a40, returns -1 change-sentinel. Table contents not dumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006343c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
