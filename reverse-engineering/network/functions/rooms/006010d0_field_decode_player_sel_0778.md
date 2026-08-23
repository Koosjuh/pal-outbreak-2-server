# 0x006010d0 field_decode_player_sel_0778

| field | value |
|---|---|
| Original address | 0x006010d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006010d0 |
| Resolved name | field_decode_player_sel_0778 |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005adc80, FUN_005c0260
**Referenced globals:** 0x6c0778 per-player field (0x15c stride)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90 mode gate

## Behavioral explanation
Field-sync decoder callback: decodes a per-player 1-byte field into (idx)*0x15c+0x6c0778 via FUN_005c0260, or zeroes it.

## Notes / uncertainty
Decodes per-player 1-byte selection into 0x6c0778 (idx=FUN_005adc80(2)). Type ambiguity: same addr formatted as string/name by row render cb -> record framing unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006010d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
