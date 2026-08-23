# 0x006153b0 roster_snapshot_publish

| field | value |
|---|---|
| Original address | 0x006153b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006153b0 |
| Resolved name | roster_snapshot_publish |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00610580, FUN_00610830
**Callees:** FUN_0060e440, FUN_0060e660
**Referenced globals:** 0x3c98b0 (register/hash tbl); iRam0070d1c0+0xed0 (65x8 table); 0x3ca2d0 (dest)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0070d1c0+0xed0

## Behavioral explanation
Registers/hashes an entry (0060e440/0060e660 on 0x3c98b0) then copies the 65-entry x8B table at iRam+0xed0 into 0x3ca2d0.

## Notes / uncertainty
Registers key in hash 0x3c98b0 (0060e440/0060e660) then copies 65x8B player table (iRam0070d1c0+0xed0) to snapshot 0x3ca2d0. Per-entry 8-byte record shape and registry semantics undecoded; param_1 type unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006153b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
