# 0x001c3f40 put_tlv_blob

| field | value |
|---|---|
| Original address | 0x001c3f40 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c3f40 |
| Resolved name | put_tlv_blob |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c4020
**Callees:** FUN_001069a8, FUN_001c3650, FUN_001c3e10
**Referenced globals:** conn+0x28 hdr; conn+0x2c pkt-base; conn+0x38 cursor; conn+0x4c session-key
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0x38 write-cursor

## Behavioral explanation
Appends a length-prefixed/encoded field: writes 2-byte length then copies+scrambles the blob via FUN_001c3650 using the per-session key at conn+0x4c.

## Notes / uncertainty
Core outbound app-field serializer: emits [u16 BE len+2][u16 BE 15-bit checksum][XOR-scrambled payload] into conn build buffer (base+cursor), cipher keyed by msg-type byte [hdr+5] and session salt (conn+0x4c) via FUN_001c3650. Bounds check omits the 4 prefix bytes (relies on caller slack). Runtime-unvalidated; msg-type byte semantics not fully pinned.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c3f40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
