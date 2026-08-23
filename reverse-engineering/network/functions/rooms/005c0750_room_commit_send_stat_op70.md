# 0x005c0750 room_commit_send_stat_op70

| field | value |
|---|---|
| Original address | 0x005c0750 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0750 |
| Resolved name | room_commit_send_stat_op70 |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c1c80, FUN_005fada0, FUN_005fb9b0, FUN_005ff760, FUN_0062dc40, FUN_0062e800
**Callees:** FUN_005be0a0, FUN_005bf130, FUN_005c2080
**Referenced globals:** 0x6ff2b1 room state (1->3); 0x6ff2b0 host flag; 0x6ca97c/0x6ca97e txn slots; 0x6febac conn
**Referenced strings:** STAT
**Referenced opcodes:** 0x70
**State vars:** 0x6ff2b1; 0x6ff2b0

## Behavioral explanation
If room-owned flag 0x6ff2b1 set, allocates a txn, advances 0x6ff2b1 to 3, and (if host 0x6ff2b0) sends a 'STAT' field =0x40000000 then op 0x70; otherwise invokes callback and bails.

## Notes / uncertainty
Gated on 0x6ff2b1: if 0 clears slot2+aborts; else advances lock 1->3 (scenario/cast unlock), host-only sends op08 register STAT=0x40000000, then app-cmd 0x70 + op07 commit. Not-owned-path cb pointer is a decompiler $a2 artifact; op70-vs-op07-wire duality open.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0750.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
