# 0x00631a30 softkbd_grid_nav_special_mode

| field | value |
|---|---|
| Original address | 0x00631a30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631a30 |
| Resolved name | softkbd_grid_nav_special_mode |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00630c90, FUN_00631ac0, FUN_00631bb0, FUN_00631c80, FUN_00631cf0, FUN_00636890
**Callees:** —
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x30 mode; +0x2f IME state; +0x4a flags; +0x1f field state; +0x35 flags

## Behavioral explanation
Predicate: is key-grid navigation currently allowed (mode/IME/lock gates on +0x30/+0x2f/+0x4a/+0x1f/+0x35)? returns 1/0.

## Notes / uncertainty
Renamed from grid_nav_allowed. Predicate: returns 1 only for special field modes (+0x1f==4 with (+0x35&0xf)==0, or ==5) while idle+unlocked; exact truth table decoded. Return POLARITY (enable special-nav vs block grid) is caller-dependent and unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631a30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
