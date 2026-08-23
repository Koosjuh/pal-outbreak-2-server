# 0x005d81b0 build_html_error_page

| field | value |
|---|---|
| Original address | 0x005d81b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d81b0 |
| Resolved name | build_html_error_page |
| Subsystem | errors |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d8340
**Callees:** FUN_005de330
**Referenced globals:** 0x00643360/64/68/6c/70/74 HTML fragment ptrs
**Referenced strings:** <html><head><title>; </title></head><body><h2>; </h2><hr>; </body></html>
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Assembles an HTML page ('<html><head><title>' ... '</title></head><body><h2>' ... '</h2><hr>' + list rows + '</body></html>') from a null-terminated array of strings and localized labels (FUN_005de330).

## Notes / uncertainty
HTML page builder via strcpy+cursor advance; NULL-terminated lines[] loop; localized title/heading via FUN_005de330(cat 9). Latent overflow (no capacity check). Separator/post-list literal text (DAT_0064336c/70) and memset length unread.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d81b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
