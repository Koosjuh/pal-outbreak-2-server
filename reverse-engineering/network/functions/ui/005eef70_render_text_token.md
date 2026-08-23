# 0x005eef70 render_text_token

| field | value |
|---|---|
| Original address | 0x005eef70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eef70 |
| Resolved name | render_text_token |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e8580, FUN_005e8600, FUN_005e8690, FUN_005e86c0, FUN_005e86f0, FUN_005e8720, FUN_005e8d10, FUN_005e8d30, FUN_005e8d60, FUN_005e9490, FUN_005e9910, FUN_005e9a10, FUN_005e9c70, FUN_005e9d20, FUN_005e9d50, FUN_005e9d90, FUN_005ea120, FUN_005ea420, FUN_005ea4a0, FUN_005eee00
**Callees:** FUN_005ec170, FUN_005eea60, FUN_005eeca0, FUN_005f3ac0
**Referenced globals:** iRam007012a0; +0x4 (buf len); +0xd8bc/+0xd8be (cursor); +0xd892 (depth)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd892

## Behavioral explanation
Renders a text token: runs layout_text_run then flush_text_buffer, syncs cursor state, resets the buffer; (block-stack branch delegates to FUN_005f3ac0).

## Notes / uncertainty
Top-level text-token render: layout+emit into root node, snaps live cursor to source pair (+0xd8c0/2), resets buffer; nested (depth!=0) delegates to 0x5f3ac0. emit vs layout split semantics uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eef70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
