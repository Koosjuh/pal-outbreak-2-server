# 0x005c3cf0 dispatch_cb_table_700630

| field | value |
|---|---|
| Original address | 0x005c3cf0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c3cf0 |
| Resolved name | dispatch_cb_table_700630 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c7d00
**Referenced globals:** 0x700630/0x700634 (one-shot callback table, 10 x 8)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Callback demux: scans the 10-entry table at 0x700630 (stride 8) for the key matching *(param1+0xc), and if a handler is registered at +4 clears it and invokes it once (one-shot completion dispatch).

## Notes / uncertainty
One-shot cb demux over 10x{u32 key,code* cb} table @0x700630, keyed on *(reply+0xc); clears cb before invoke. No static caller (registered dynamically).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c3cf0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
