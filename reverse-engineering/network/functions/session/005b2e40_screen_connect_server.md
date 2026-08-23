# 0x005b2e40 screen_connect_server

| field | value |
|---|---|
| Original address | 0x005b2e40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b2e40 |
| Resolved name | screen_connect_server |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b24e0
**Callees:** FUN_005af300, FUN_005af310, FUN_005b68e0, FUN_005b6900, FUN_005ba7b0, FUN_005c4ad0, FUN_005c4ae0, FUN_005f42c0, FUN_005f4440, FUN_005f6970, FUN_00619800, FUN_0061e8f0, FUN_0061e9c0, FUN_0061f0d0, FUN_00620d40, FUN_00620d60
**Referenced globals:** 0x7153f0/0x715430 callback pair; 0x618c90 UI list ptr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0xf sub-state; struct+0x45a ready flag

## Behavioral explanation
Screen-8 connect-to-server machine: kicks off the connection (00620d40), polls result (00620d60: 1=ok,-1=fail), and swaps UI callbacks accordingly.

## Notes / uncertainty
Connect-to-server screen SM (obj+0xf, 8 steps): 620d40 start / 620d60 poll (1=ok->advance, -1=fail->step6), 001d3fd0 SN@P socket op, obj+0x45a ready flag. 0x54c0 ctx block meaning unmapped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b2e40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
