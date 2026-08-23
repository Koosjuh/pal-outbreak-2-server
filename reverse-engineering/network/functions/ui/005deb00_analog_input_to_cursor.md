# 0x005deb00 analog_input_to_cursor

| field | value |
|---|---|
| Original address | 0x005deb00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005deb00 |
| Resolved name | analog_input_to_cursor |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c8810
**Callees:** —
**Referenced globals:** iRam0029a528 (pad/analog input); iRam00701068+0x4f8a0.. (cursor state); DAT_00692d28 (scale const)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701068+0x4f8a0..

## Behavioral explanation
Reads the pad/analog struct (iRam0029a528) and maps stick X/Y magnitudes into direction zones (thresholds 0x28/0x5a/0x7e) plus speed, writing cursor state at +0x4f8a0.

## Notes / uncertainty
UPGRADED from classified; renamed from analog_input_to_pointer. Documented 12-byte cursor block at base+0x4f8a0, 4-level zone quantizer (0x28/0x5a/0x7e), speed nibble = 4 - topnibble(rate*65536/DAT_00692d28). Pad offset physical meanings and DAT_00692d28 value inferred/unread. Non-network.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005deb00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
