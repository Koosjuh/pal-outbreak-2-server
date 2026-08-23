# 0x0062d1b0 build_member_record

| field | value |
|---|---|
| Original address | 0x0062d1b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062d1b0 |
| Resolved name | build_member_record |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062d0f0
**Callees:** FUN_005b1190, FUN_005b14b0, FUN_00627a80, FUN_00627b00
**Referenced globals:** 0x715512 slot-count table; 0x694700 name table; 0x694710 id table; +0x12c2 member buf; +0x44f guard
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Builds the member/registration record: scans the slot-count table (0x715512 stride 0x14) for a free slot, else copies name+id (0x694700/0x694710, stride 0x38) into a 0x25 output record and fires the request (func_0x001b0140(1)).

## Notes / uncertainty
Builds 0x25-byte member record (name@+1, id@+0x11 from 0x694700/0x694710 stride 0x38) after availability scan of 0x715512. FUN_005b14b0 polarity + 0x715512 +8 counter semantics inferred; out[0] tag filled later.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062d1b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
