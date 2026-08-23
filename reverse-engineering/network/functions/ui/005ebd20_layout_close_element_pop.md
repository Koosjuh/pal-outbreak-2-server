# 0x005ebd20 layout_close_element_pop

| field | value |
|---|---|
| Original address | 0x005ebd20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ebd20 |
| Resolved name | layout_close_element_pop |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005f0e10, FUN_005f10a0, FUN_005f1570
**Callees:** FUN_005ec100, FUN_005ed160, FUN_005ef0e0, FUN_005ef780, FUN_005f0b20, FUN_005f10a0, FUN_005f2280
**Referenced globals:** iRam007012a0; +0xd892 (element-stack depth); +0xd894 (current element idx); +0x186 (pass flag); +0x182 (max content width)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd892; +0x186

## Behavioral explanation
Pops a nested layout element off the markup stack (+0xd892 depth) and finalizes cell/row box metrics (widths/heights at +0x24xx, min/max into parent), running measure-vs-draw arithmetic.

## Notes / uncertainty
Already fully reconstructed in a prior pass: 992B UI box-model close/pop of a markup element (measure-pass gate +0x186==0xf6, cell stride 0x5c). Thorough corrected C block present. No improvement to make; not net-related. Left as-is.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ebd20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
