# 0x006332a0 unpack_wordlist_entry

| field | value |
|---|---|
| Original address | 0x006332a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006332a0 |
| Resolved name | unpack_wordlist_entry |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00632d20, FUN_00633210
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Unpacks a variable-length wordlist record (chained 0x10-byte blocks, 0xe payload each, +0x1f==-1 continuation, +0xf length) into a flat NUL-terminated string.

## Notes / uncertainty
Unpacks chained 16-byte records: 14-byte payload/block, byte+0x0f=total length, next block's +0x0f==0xFF = continuation. Returns -1 if cap<len. Source blob at 0x68b6e0 not dumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006332a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
