# 0x001e5234 blowfish_key_schedule

| field | value |
|---|---|
| Original address | 0x001e5234 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e5234 |
| Resolved name | blowfish_key_schedule |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001e5538, FUN_001e56c8, FUN_001ea8e8
**Callees:** FUN_001e4fd8
**Referenced globals:** 0x259730 P-init const; 0x259778 S-box init const; ctx
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Blowfish key setup: loads default S-boxes (DAT_00259778) and P-array (DAT_00259730) into ctx, XORs the key into P, then re-encrypts the P/S tables in place with e4fd8.

## Notes / uncertainty
Standard Blowfish key expansion; S-init DAT_00259778, P-init DAT_00259730, cyclic-key XOR, 521 self-encryptions. Exact init constants not dumped (assumed standard pi constants).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e5234.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
