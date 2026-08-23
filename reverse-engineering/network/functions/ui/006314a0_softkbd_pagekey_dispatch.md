# 0x006314a0 softkbd_pagekey_dispatch

| field | value |
|---|---|
| Original address | 0x006314a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006314a0 |
| Resolved name | softkbd_pagekey_dispatch |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_006300a0
**Callees:** FUN_00630c10, FUN_00630c70, FUN_006313a0, FUN_00631560, FUN_00631670
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x4a flags; +0x49f modifier bits; +0x248 result code

## Behavioral explanation
Sub-dispatcher for page/mode keys 0x3a-0x45: routes to layout-page-select, grid-reset, or space/confirm based on key and modifier bits.

## Notes / uncertainty
Sub-dispatch for keys 0x3a-0x45 (key in a0): 0x3d space/confirm, 0x3a-0x3c page-select, jump-mode->006313a0, else blocked(5). Two guard predicates (00630c10 busy / 00630c70 mode) meaning inferred from usage.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006314a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
