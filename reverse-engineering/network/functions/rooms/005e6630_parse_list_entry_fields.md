# 0x005e6630 parse_list_entry_fields

| field | value |
|---|---|
| Original address | 0x005e6630 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e6630 |
| Resolved name | parse_list_entry_fields |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e67a0
**Callees:** —
**Referenced globals:** 0x874500 (list-entry record table, name @+0xd), 0x874600 (per-entry type/flag word); DAT_00647f90 (byte class table for multibyte)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Parses one comma-separated list entry (name + trailing type digit) into the per-slot record table @0x874500 (0x104-byte stride, indexed by param_1), setting a type code (0/1/2/3) at record+0.

## Notes / uncertainty
Parses CSV list line 'field1,name,typedigit' into record slot @0x874500 (stride 0x104: field1@+0, name@+0xd) + type word @0x874600; Shift-JIS multibyte via DAT_00647f90 bit0; type remap '0'->3/'1'->1/'2'->2/else0. Multibyte trail-store index and '0'->3 remap worth a runtime check; text source set by caller FUN_005e67a0.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e6630.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
