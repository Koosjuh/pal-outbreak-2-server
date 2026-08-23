# 0x005b9110 set_msg_channel_id

| field | value |
|---|---|
| Original address | 0x005b9110 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b9110 |
| Resolved name | set_msg_channel_id |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ad030, FUN_005ad350, FUN_005adbe0, FUN_005ae3e0, FUN_005ae510, FUN_005ae630, FUN_005ae770, FUN_005ae8a0, FUN_005ae9b0, FUN_005b1fa0, FUN_005b20c0, FUN_005b2260, FUN_005b3ed0, FUN_005b47a0, FUN_005b4860, FUN_005f6b00, FUN_005f6d20, FUN_005f7690, FUN_005f82a0, FUN_005f8c20, FUN_005faa60, FUN_005fb060, FUN_005fb270, FUN_005fb670, FUN_005fb860, FUN_005fc0c0, FUN_005fc610, FUN_005fe8d0, FUN_00601420, FUN_00604180, FUN_00606fc0, FUN_00607370, FUN_00607cf0, FUN_00607dc0, FUN_00616bd0, FUN_00619680, FUN_0061ded0, FUN_00628210, FUN_006293f0, FUN_006296a0, FUN_0062a8c0, FUN_0062ab50, FUN_0062b020, FUN_0062bee0, FUN_0062c580, FUN_0062c7b0, FUN_0062c870, FUN_0062cfd0, FUN_0062d8b0, FUN_0062e2a0
**Callees:** —
**Referenced globals:** 0x006c4fcd uRam=msg channel id
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4fcd

## Behavioral explanation
One-line setter: uRam006c4fcd = param (selects which message-channel widgets render this frame).

## Notes / uncertainty
One-line setter uRam006c4fcd=id (current render channel); 51 callers. id namespace defined by callers. Behavior certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b9110.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
