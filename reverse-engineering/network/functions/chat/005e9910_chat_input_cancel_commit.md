# 0x005e9910 chat_input_cancel_commit

| field | value |
|---|---|
| Original address | 0x005e9910 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9910 |
| Resolved name | chat_input_cancel_commit |
| Subsystem | chat |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005eef70
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x17f (msg mode)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x17f

## Behavioral explanation
Clears message-mode cfg+0x17f=0 and applies arg via FUN_005eef70.

## Notes / uncertainty
Compose-widget cancel/close: clears input-mode byte cfg+0x17f=0, forwards entry to FUN_005eef70 (no trim). No static callers (UI callback table). param_2 type and FUN_005eef70 final action undecoded. Renamed from chat_reset_mode_0x17f to reflect the cancel-commit role paired with 0x5e9a10.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9910.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
