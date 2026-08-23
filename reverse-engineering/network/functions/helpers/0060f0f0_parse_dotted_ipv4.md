# 0x0060f0f0 parse_dotted_ipv4

| field | value |
|---|---|
| Original address | 0x0060f0f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060f0f0 |
| Resolved name | parse_dotted_ipv4 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060e440, FUN_0060e820
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Parses a dotted-decimal string (e.g. "a.b.c.d") into consecutive raw bytes: accumulates *10 per digit, emits a byte on each '.'.

## Notes / uncertainty
Dotted-decimal to raw octet bytes (acc*10+digit, flush on '.'). Generic; IPv4 uses 3 dots. Signed-char acc, no bounds/format validation. Unambiguous idiom.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060f0f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
