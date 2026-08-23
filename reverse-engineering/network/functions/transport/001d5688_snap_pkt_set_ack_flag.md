# 0x001d5688 snap_pkt_set_ack_flag

| field | value |
|---|---|
| Original address | 0x001d5688 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d5688 |
| Resolved name | snap_pkt_set_ack_flag |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d6468
**Callees:** FUN_001e2304, FUN_001e234c, FUN_001e23dc, FUN_001ebb90
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** pkt+0x2c who/flags (0x4000=ack set)

## Behavioral explanation
Marks a packet as carrying an ack: sets the 0x4000 bit in the who/flags word at +0x2c and stores the ack seq at +0x38 (endian-aware depending on packet residency).

## Notes / uncertainty
Sets 0x4000 ACK-present bit in pkt+0x2c and ack seq at pkt+0x38, endian-aware via FUN_001ebb90 residency probe.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d5688.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
