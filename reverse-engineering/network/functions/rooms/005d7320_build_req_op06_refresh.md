# 0x005d7320 build_req_op06_refresh

| field | value |
|---|---|
| Original address | 0x005d7320 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d7320 |
| Resolved name | build_req_op06_refresh |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d0a40
**Callees:** FUN_005d6630, FUN_005d7310
**Referenced globals:** 0x004f694 txn head; 0x00701018 current room; 0x00701010 seq counter; 0x00701000 pending kind
**Referenced strings:** —
**Referenced opcodes:** 0x06
**State vars:** cRam00701010; uRam00701000

## Behavioral explanation
Builds an op06 (enter) txn record for the current room, subtype 1, stamps a fresh sequence byte (cRam00701010++) into +0x108 and who-byte from cur_room_whobytes_ptr; sets pending kind=5.

## Notes / uncertainty
Unconditional op06 refresh on current room; stamps ++send-seq (0x701010) into who-lo = op06 SUB-echo key, kind5. Decompiler mis-attributes +0x109 store to extraout_a0_lo; intended record+0x109.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d7320.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
