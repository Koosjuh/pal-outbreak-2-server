<!-- Copy this for every function record. Filename: functions/<subsystem>/<ADDR8>_<resolved_name>.md
     ADDR8 = 8-hex-digit address with no 0x, e.g. 005bb4d0. resolved_name = snake_case evidence-based name. -->
# <ADDR> <resolved_name>

| field | value |
|---|---|
| Original address | 0x005bb4d0 |
| Binary / overlay | 3.DAT overlay  (or: main-EE SLES_533.19) |
| Module | overlay-3dat  (or: main-ee) |
| Original generated name | FUN_005bb4d0 |
| Resolved name | member_join_op06_handler |
| Subsystem | roster |
| Status | documented |
| Confidence | High |
| Runtime validated | yes/no (trace link) |

**Callers:** FUN_xxxx@0x…, … (from CALLERS line / xrefs_to)
**Callees:** FUN_xxxx@0x…, … (from CALLEES line / xrefs_from)
**Referenced globals:** 0x006cd672 (op06 scratch id-string), … → link to GLOBALS.md
**Referenced structures:** member_record @+0x00 … → link to structures/
**Referenced strings:** "…" @0x… → link to STRINGS.md
**Related packets:** op06 member-JOIN (→ protocols/PACKET_INDEX.md)
**Related menu screens:** in-room (screen 0x6c4b90==4) (→ menus/MENU_INDEX.md)
**Related state-machine states:** roomscr 0x6cbc7e=0x10 (→ STATE_MACHINES.md)

## Behavioral explanation
What the function does in protocol/domain terms — the WHY, not a line restatement.

## Input / output
Parameters (typed, named), return value, meaning.

## Side effects
Globals/structs written, events fired, packets sent, state transitions.

## Important branches
The decision points that matter (gates, bounds checks, error paths) with the condition + consequence.

## Constants & flags
Named enum/bitfield values with evidence (→ CONSTANTS.md / ENUMS.md).

## Corrected reconstruction
```c
// Readable C-like reconstruction: named vars, struct field access, enums.
// Preserve exact control flow where behavior is uncertain; mark inferred [types]/names.
```

## Raw decompilation
Link to the untouched source: `sources/…/FUN_005bb4d0.c`. **Never edit that file.** If the corrected
reconstruction diverges from raw, both are preserved.

## Evidence
Bullet list: decompile lines, xrefs, referenced data, strings, PINE reads, pcap frames, that support
each claim. Tag runtime evidence with the trace path under `traces/`.

## Remaining uncertainty
Open questions → also add to `UNRESOLVED.md` with this function's address.
