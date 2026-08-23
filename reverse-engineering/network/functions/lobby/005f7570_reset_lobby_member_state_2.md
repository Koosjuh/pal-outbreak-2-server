# 0x005f7570 reset_lobby_member_state_2

| field | value |
|---|---|
| Original address | 0x005f7570 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f7570 |
| Resolved name | reset_lobby_member_state_2 |
| Subsystem | lobby |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062c970
**Callees:** FUN_005aec20, FUN_005af120
**Referenced globals:** 0x6c4b90 (screen state); 0x6c3030 (member table); 0x6c5490; 0x6c45fc; 0x6c4600
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4b90

## Behavioral explanation
Byte-identical to FUN_005f74d0 (mode=2, clears member table 0x6c3030 + 0x6c5490), invoked from a different caller path.

## Notes / uncertainty
Byte-identical twin of 0x005f74d0; only the caller differs (FUN_0062c970 vs overlay teardown). Duplicate reset entry point; same open questions.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f7570.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
