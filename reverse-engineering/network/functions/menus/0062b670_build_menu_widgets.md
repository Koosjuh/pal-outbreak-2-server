# 0x0062b670 build_menu_widgets

| field | value |
|---|---|
| Original address | 0x0062b670 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062b670 |
| Resolved name | build_menu_widgets |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062a680, FUN_0062aeb0
**Callees:** FUN_005ba570, FUN_005ba7b0, FUN_00618b60, FUN_00618ba0
**Referenced globals:** 0x66aec0 widget-list table; 0x66aeb0 coord table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Walks a widget-descriptor table (PTR_DAT_0066aec0[sel], sentinel <0), allocs 0xd-type UI task nodes and fills id/coords (from 0x66aeb0) and owner ptr.

## Notes / uncertainty
Instantiates clickable-widget set from static descriptor list 0x66aec0[sel] (6-short records, sentinel id<0); allocs type-0xd nodes, fills id/param/owner/coords (coord tables 0x66aeb0/2). Twin of cd20. Descriptor packing and node-0xd struct semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062b670.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
