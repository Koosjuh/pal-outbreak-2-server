# 0x005c4460 register_ui_obj_0xec

| field | value |
|---|---|
| Original address | 0x005c4460 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c4460 |
| Resolved name | emit_builder_obj_tag0xec |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ae630
**Callees:** FUN_005be9e0 (begin/open, tag), FUN_005bea10 (mix/commit), FUN_005bea80 (finalize/close)
**Referenced globals:** 0x7018d0 (shared builder/serializer object)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Emits a single **field-less object of tag `0xec`** into the shared builder object at 0x7018d0. It runs the standard three-call builder sequence used across the overlay: begin(tag) -> commit -> finalize, with no data-append step (contrast `serialize_id6_field` @0x005c6fb0, which inserts a `bea60(...,6)` data write between begin and commit). Because it carries no payload, this registers/marks an empty tagged object — a UI/menu element or a protocol descriptor slot whose presence (tag 0xec) is the whole meaning.

## Input / output
- no parameters.
- returns void (the begin() return value is discarded here).

## Side effects
- Mutates the builder state at 0x7018d0: opens object tag 0xec, commits, finalizes. Net effect is one tagged, empty object appended to whatever 0x7018d0 accumulates.

## Important branches
None (straight-line triad).

## Constants & flags
- `0xec` = object/field tag for this element. (Sibling FUN_005c27d0 uses tag `0xda`; `serialize_id6_field` uses `0xe0` — a family of 1-byte tags into the same builder.)

## Corrected reconstruction
```c
extern void *g_builder;                 // 0x007018d0 shared builder/serializer ctx

extern unsigned short builder_begin (void *ctx, int tag);           // FUN_005be9e0
extern void           builder_commit(void *ctx);                    // FUN_005bea10
extern void           builder_finalize(void *ctx);                  // FUN_005bea80

// Append one empty object with tag 0xEC to the shared builder.
void emit_builder_obj_tag0xec(void)
{
    builder_begin(g_builder, 0xec);     // return discarded
    builder_commit(g_builder);
    builder_finalize(g_builder);
}
```

## Evidence
- Raw decompile: exactly `be9e0(0x7018d0,0xec); bea10(0x7018d0); bea80(0x7018d0);`.
- Triad shape matches `serialize_id6_field` @0x005c6fb0 (same begin/commit/finalize, plus a data write) — establishing the builder pattern.
- Confidence **Medium**: the begin/commit/finalize roles are inferred from the two call shapes, not from reading FUN_005be9e0/bea10/bea80 bodies.

## Remaining uncertainty
- Whether 0x7018d0 emits UI geometry vs. a wire descriptor, and the exact meaning of tag 0xec, are unproven. Rename from the old "register_ui_obj_0xec" reflects the builder interpretation but keeps the tag.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c4460.c`  — untouched decompiler output.
