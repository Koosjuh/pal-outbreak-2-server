# 0x005f8fc0 roomlist_cursor_sm

| field | value |
|---|---|
| Original address | 0x005f8fc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f8fc0 |
| Resolved name | roomlist_cursor_sm |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f8e20
**Callees:** FUN_005b1190, FUN_005b14b0, FUN_005f8c20, FUN_005f8d00
**Referenced globals:** 0x6c0760 (room-list table); 0x6c076e (entry status); 0x6c4600 (selected room); 0x649850 (prompt-id map); param+0x448/+0x449 (page/idx)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0x448; param+0x449; 0x6c4600

## Behavioral explanation
SM on +0xf: moves the cursor over room-list entries (FUN_005b1190 over page/index +0x448/+0x449), reads the entry status byte at 0x6c076e — cases 1/3 select a room and transition into join (sets +0xe), default raises a prompt (FUN_005f8d00).

## Notes / uncertainty
Room-browser cursor/select SM: step0 grid-nav + confirm(0x10)/cancel(0x200); step1 reads entry status 0x6c076e -> status1 join route(+0xe=3), status3 create route(+0xe=2), default prompt via 0x649850 map. Latches selection to 0x6c4600. Status codes other than 1/3 not fully decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f8fc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
