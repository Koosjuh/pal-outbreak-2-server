# 0x005e7070 parse_lobby_line_dispatch

| field | value |
|---|---|
| Original address | 0x005e7070 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e7070 |
| Resolved name | parse_lobby_line_dispatch |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005e7a30
**Callees:** FUN_005da430, FUN_005e5f80, FUN_005e60c0, FUN_005e67a0
**Referenced globals:** iRam007012a0+0xd964 (cursor), +0x186 (parse mode), +0x18e (current tag/screen), +0x191 (list id), +0x192, +0x190/399/400; 0x6481b8/d0/e8/f0/0x648200/0x648218 (tag literals), 0x647e30 (control-token table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam007012a0+0x186; iRam007012a0+0x18e; iRam007012a0+0x191

## Behavioral explanation
Top-level lobby text-protocol line parser: recognizes 'M..' message prefixes and '<...>' tags, dispatches to config parse (FUN_005e60c0) or list parse (FUN_005e67a0), and decodes control tokens (FUN_005e5f80) into parser state bytes (+0x186/+0x18e/+0x191/+0x192) driving the current screen.

## Notes / uncertainty
Top-level lobby text-protocol line router: M-header / config-scan(mode1) / token-stream(mode0). Dispatches config (FUN_005e60c0) + list (FUN_005e67a0), sets screen tag +0x18e / list id +0x191 / flags. Control-token alphabet (0x647e30) meanings mostly opaque; flow preserved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e7070.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
