# 0x001c0020 dnas_boot_init

| field | value |
|---|---|
| Original address | 0x001c0020 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c0020 |
| Resolved name | dnas_boot_init |
| Subsystem | initialization |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c00f0
**Referenced globals:** 0x35a27a init-flag; 0x35a279 enable-flag; 0x35a280 =-1; 0x35a278 =2
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x35a279 sm-enable; 0x35a6b0 boot-state

## Behavioral explanation
Seeds DNAS/DVD-auth boot flags (0x35a278-0x35a280) then arms the boot state machine via set_boot_state(0).

## Notes / uncertainty
Already full: seeds enable=1, result=0xffffffff, lastState=2, arms via set_boot_state. Consistent with newly-read step machine FUN_001c0100.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c0020.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
