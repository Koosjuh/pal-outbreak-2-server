# 0x00625670 screen_sm_xfer

| field | value |
|---|---|
| Original address | 0x00625670 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00625670 |
| Resolved name | screen_sm_xfer |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00622180
**Callees:** FUN_0061e7f0, FUN_0061e800, FUN_0061e910, FUN_0061e960, FUN_0061f0e0, FUN_0061f1a0, FUN_0061f1d0, FUN_0061f1f0, FUN_0061f340, FUN_0061f3b0, FUN_0061f470, FUN_0061f600, FUN_0061f680, FUN_0061f760, FUN_00620d40, FUN_00620d60
**Referenced globals:** 0x7152e1 substate; 0x7152e4 timer; 0x7152e6 err/state; 0x86f864 xfer buffer; 0x365df8 src; 0x715478 flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam007152e1; sRam007152e4; sRam007152e6; cRam007152e2

## Behavioral explanation
Large screen state machine wrapping the data-transfer machine (FUN_00620d40/00620d60): sequences transfer, timed prompts, error-code→message mapping (FUN_0061f600), and window fades; returns 1/-1/-2.

## Notes / uncertainty
Large data-transfer screen: request (0x00-0x11)/transfer-run ('2'-'6', engine FUN_00620d40/d60)/result-confirm ('d'-'h'); status code 0x7152e6->msg 0xe/0xf. Full phase ladder + status table captured. Payload domain and some async args inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00625670.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
