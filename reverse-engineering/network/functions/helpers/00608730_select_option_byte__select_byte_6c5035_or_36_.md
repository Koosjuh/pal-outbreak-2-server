# 0x00608730 select_option_byte (select_byte_6c5035_or_36)

| field | value |
|---|---|
| Original address | 0x00608730 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00608730 |
| Resolved name | select_option_byte (select_byte_6c5035_or_36) |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f4480
**Callees:** —
**Referenced globals:** 0x006c5034 flag; 0x006c5035 val; 0x006c5036 val
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c5034

## Behavioral explanation
Returns 6c5036 normally, or 6c5035 when flag 6c5034 is set.

## Notes / uncertainty
Returns default 0x6c5036, or alt 0x6c5035 when flag 0x6c5034 set. Which setting the 3 bytes encode is unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00608730.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
