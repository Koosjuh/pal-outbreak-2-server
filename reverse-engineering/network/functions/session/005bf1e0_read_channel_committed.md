# 0x005bf1e0 read_channel_committed

| field | value |
|---|---|
| Original address | 0x005bf1e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bf1e0 |
| Resolved name | read_channel_committed |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bb4d0, FUN_005bb670, FUN_005bb8e0, FUN_005bb980, FUN_005bbc20, FUN_005bbe00, FUN_005bbea0, FUN_005be330, FUN_005bf470, FUN_005bf830, FUN_005c14a0, FUN_005c1770, FUN_005c1c80, FUN_005c2f40, FUN_005c3190, FUN_005c3490, FUN_005c3a40, FUN_005c3b10, FUN_005c44a0, FUN_005c4600, FUN_005c4bd0, FUN_005c7320, FUN_005c7420, FUN_005c75d0
**Callees:** —
**Referenced globals:** 0x6ce5ce ch0; 0x6ce5cf ch1; 0x6ce5d0 ch2
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6ce5ce; 0x6ce5cf; 0x6ce5d0

## Behavioral explanation
Reads committed per-channel value (0x6ce5ce/cf/d0) for channel 0/1/2; returns 0xffff for invalid channel.

## Notes / uncertainty
Hot getter (24 callers): returns committed[ch] zero-extended, else 0xffff sentinel. Per-caller interpretation of byte not enumerated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bf1e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
