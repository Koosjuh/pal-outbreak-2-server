# 0x006140d0 render_room_info_panel

| field | value |
|---|---|
| Original address | 0x006140d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006140d0 |
| Resolved name | render_room_info_panel |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00613c30
**Callees:** FUN_0060f880, FUN_0060f8b0, FUN_00614550, FUN_006146e0, FUN_00614870, FUN_00616570
**Referenced globals:** iRam0070d1c0 (+0x13 sel idx, room base +0x1340 stride); 0x654150/0x654160 (fmt strings)
**Referenced strings:** fmt @0x654150; fmt @0x654160
**Referenced opcodes:** —
**State vars:** room struct offs 0x1310 scenario,0x1320/0x1325 flags,0x200/0x300-0x700 fields

## Behavioral explanation
Renders the lobby room detail panel (title/scenario/password/host address fields) from the selected room struct into stacked text elements.

## Notes / uncertainty
Room-info panel: title + mode (strtab map 6/5/3/2->4/3/2/1) + 3-way host-address form (resolved name +0xb00 / single +0x200 / IP octets +0x300-0x500) + 2 trailing fields. Availability gate on +0xb700/+0xc200/+0xc225. 0x44=text x, not opcode. Field semantics partly inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006140d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
