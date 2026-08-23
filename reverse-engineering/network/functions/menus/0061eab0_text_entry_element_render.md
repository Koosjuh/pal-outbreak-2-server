# 0x0061eab0 text_entry_element_render

| field | value |
|---|---|
| Original address | 0x0061eab0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061eab0 |
| Resolved name | text_entry_element_render |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00619800
**Callees:** FUN_005b7cd0, FUN_0061cc80, FUN_0061ea50
**Referenced globals:** 0x669c60 (element geometry table); 0x669d10/0x669d18/0x669d20/0x669d30/0x669d40 (fmt/label strings); 0x3c9580; 0x86f820; 0x86f810; 0x715368/0x715344/0x715360 (entered-text buffers)
**Referenced strings:** password mask char '*'; format strings @0x669d10/0x669d40 (page counter)
**Referenced opcodes:** —
**State vars:** 0x7152e0/0x7152e4/0x7152e6/0x7152ea (entry mode/page indices)

## Behavioral explanation
Big draw switch (cases 0..0x15) rendering the on-screen text-entry/keyboard elements: name/password strings (password masked with '*'), page counter, cursor boxes and labels from tables at 0x669c60/0x669d10+.

## Notes / uncertainty
Big switch(id 0..0x15) rendering create-room name/password entry + paged-list UI; geometry table 0x669c60 (8B/entry), palette 0x669c40, x==-1 center sentinel, '*' password mask (case 0xe), page counter+arrows (0x10/0x15). GS extern names + screen mapping inferred; not runtime-validated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061eab0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
