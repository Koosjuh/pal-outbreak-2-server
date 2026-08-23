# 0x005f62e0 build_roster_display_list

| field | value |
|---|---|
| Original address | 0x005f62e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f62e0 |
| Resolved name | build_roster_display_list |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f5fe0
**Callees:** FUN_005b7fd0, FUN_005ba570, FUN_005ba7b0, FUN_00618b60, FUN_00618ba0
**Referenced globals:** 0x649720 (member-column x-coord table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+8 (member count, clamped to 7)

## Behavioral explanation
Allocates display/task entries (FUN_00618ba0) for the member roster: header rows (IDs 0x13a/0x13b), up to 7 member name rows (ID 0x6c with per-member draw cb FUN_005f6790) plus footer rows (0x6d/0x6e cb FUN_005f6610).

## Notes / uncertainty
Builds lobby member-list display panel: 2 headers, up to 7 member rows (draw cb=005f6790), 2 footers; fires FUN_005b7fd0(0x22,...) only when count!=0. Label ids (0x13a/0x13b/0x6c/0x6d/0x6e) are UI ids not wire ops; whether 0x22 arg is wire op 0x22 or internal task id unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f62e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
