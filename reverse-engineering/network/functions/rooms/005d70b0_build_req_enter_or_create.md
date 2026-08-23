# 0x005d70b0 build_req_enter_or_create

| field | value |
|---|---|
| Original address | 0x005d70b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d70b0 |
| Resolved name | build_req_enter_or_create |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d0960
**Callees:** FUN_005d6630, FUN_005d67d0
**Referenced globals:** 0x004f588 roomlist head; 0x004f694 txn head; 0x00701018 current room; 0x00701000 pending-req kind
**Referenced strings:** —
**Referenced opcodes:** 0x04, 0x06
**State vars:** uRam00701000; iRam00701018

## Behavioral explanation
Builds a txn-queue record for the current room: opcode 0x06 (enter, if the looked-up room is the current one, state=5) else 0x04 (create-slot, state=3), subtype 1, copying who-bytes 0x108/0x109 from the room.

## Notes / uncertainty
Mints the op04 create-slot vs op06 enter txn (forward iterator): if forward-scan wraps to current room -> op06/kind5 else op04/kind3. This is the create-request mint site (relevant to create-registration blocker). Documented full txn-record layout (+0x104 state, +0x108/9 who, +0x10c op, +0x10d subtype, +0x110 payload).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d70b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
