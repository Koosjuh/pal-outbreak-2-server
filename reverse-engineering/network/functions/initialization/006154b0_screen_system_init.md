# 0x006154b0 screen_system_init

| field | value |
|---|---|
| Original address | 0x006154b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006154b0 |
| Resolved name | screen_system_init |
| Subsystem | initialization |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0060f910
**Callees:** —
**Referenced globals:** PTR_DAT_006541bc; PTR_DAT_006541c0; 0x289af0/0x289ae0 (cfg); cRam0034363e; bRam0034359d
**Referenced strings:** s_eefgis_00654188 ("eefgis")
**Referenced opcodes:** —
**State vars:** cRam0034363e; bRam0034359d

## Behavioral explanation
Brings up a screen/subsystem: sequence of graphics/audio/system init calls, then sets HUD pointers and a mode char from string table.

## Notes / uncertainty
~18 opaque init thunks (names placeholder) + mode char '0'/'1' from cRam0034363e and 'eefgis'[bRam0034359d] region/lang selector into 6541bc/6541c0; thunk identities unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006154b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
