# 0x005d7cf0 fill_send_descriptor

| field | value |
|---|---|
| Original address | 0x005d7cf0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d7cf0 |
| Resolved name | fill_send_descriptor |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d7e00, FUN_005d7f80
**Callees:** FUN_005df780
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Populates a ~0x36-byte send descriptor (type byte=1, addr/port/len fields, retransmit flag) from parameters; field +0x18 (retry len) is zeroed except in modes '\x02'/'\x03' (unreliable/addressed).

## Notes / uncertainty
Populates ~0x36B send descriptor; retransmit-len (+0x18) gated to modes 0x02/0x03 (reliable) via FUN_005df780, else 0; ack tag +0x2c (1 no-ack/2 ack). Individual numbered-field roles not disambiguated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d7cf0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
