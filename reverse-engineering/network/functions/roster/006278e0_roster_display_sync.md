# 0x006278e0 roster_display_sync

| field | value |
|---|---|
| Original address | 0x006278e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006278e0 |
| Resolved name | roster_display_sync |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00604180, FUN_00628210, FUN_006296a0
**Callees:** FUN_00604860, FUN_00627860
**Referenced globals:** 0x715500 roster-disp-table; 0x694710 master-id-field
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Reconciles the 0x715500 display table against the incoming master roster (param stride 0x38): drops slots no longer present, compacts, and inserts new 16-byte ids into free slots.

## Notes / uncertainty
Core membership diff: pass1 removes/relocates display rows to match master roster (stride 0x38,id@+0x10); pass2 inserts new members at same index. On create-room roster/count path (callers: join 0x6296a0, member-list 0x628210). Decompiler (iVar+iVar)*4 idiom = stride 0x14. No runtime.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006278e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
