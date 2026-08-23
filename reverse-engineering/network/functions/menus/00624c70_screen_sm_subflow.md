# 0x00624c70 screen_sm_subflow

| field | value |
|---|---|
| Original address | 0x00624c70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00624c70 |
| Resolved name | screen_sm_subflow |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00622180
**Callees:** FUN_005c80a0, FUN_005c84e0, FUN_005c8810, FUN_005de2a0, FUN_0061d6a0, FUN_0061e910, FUN_0061e940, FUN_0061e960, FUN_0061f0e0, FUN_0061f1a0, FUN_0061f1d0
**Referenced globals:** 0x7152e1 substate; 0x701e18 result; 0x870870 flag; 0x3c9580/0x7152c0 buffers
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam007152e1; cRam00701e18; cRam00870870

## Behavioral explanation
Screen SM driving a sub-flow via FUN_005c80a0/84e0/8810 (poll) and result flag cRam00701e18/cRam00870870; copies selection blocks and returns 1/2/-1/-2.

## Notes / uncertainty
Wraps external 0x5c online sub-flow (FUN_005c80a0/84e0/8810), marshals a 16-byte record between 0x3c9580/0x7152c0/0x870870; returns 0/1/2/-1/-2. Control flow preserved exactly; sub-flow domain (friend/account pick) opaque.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00624c70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
