# 0x005e9440 apply_addr_0x101c_guarded

| field | value |
|---|---|
| Original address | 0x005e9440 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9440 |
| Resolved name | apply_addr_0x101c_guarded |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005d9d70
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x186 (guard); cfg+0xe96b (guard); cfg+0x101c (str); cfg+0x111c (flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x186; cfg+0xe96b; cfg+0x111c

## Behavioral explanation
If guards cfg+0x186==0 && cfg+0xe96b==0, applies FUN_005d9d70(cfg+0x101c, flag cfg+0x111c).

## Notes / uncertainty
Guarded commit of parsed address/config (ctx 0x7012a0 +0x101c, flag +0x111c) into net layer via FUN_005d9d70 when +0x186==0 && +0xe96b==0. No in-corpus caller; content of +0x101c inferred from callee -> Medium.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9440.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
