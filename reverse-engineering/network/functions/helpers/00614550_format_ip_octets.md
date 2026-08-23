# 0x00614550 format_ip_octets

| field | value |
|---|---|
| Original address | 0x00614550 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00614550 |
| Resolved name | format_ip_octets |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006140d0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Formats a dotted string into 4 right-justified 3-char octet groups (IP-address display formatting).

## Notes / uncertainty
Right-justifies dotted string into 4x width-3 octet columns, copies separators, NUL-terminates. tmp[4] overflows if octet >3 digits (never for valid IP).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00614550.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
