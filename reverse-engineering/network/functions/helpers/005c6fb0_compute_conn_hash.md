# 0x005c6fb0 compute_conn_hash

| field | value |
|---|---|
| Original address | 0x005c6fb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c6fb0 |
| Resolved name | serialize_id6_field_tag0xe0 |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005c5a10, FUN_005c5ad0
**Callees:** FUN_005be9e0 (builder_begin, tag), FUN_005bea60 (builder_write_bytes), FUN_005bea10 (builder_commit), FUN_005bea80 (builder_finalize)
**Referenced globals:** 0x7018d0 (shared builder/serializer object)
**Referenced strings:** —
**Referenced opcodes:** — (emits a 6-byte ID field into an outgoing descriptor)
**State vars:** —

## Behavioral explanation
Emits a **6-byte identifier field tagged `0xe0`** into the shared builder object at 0x7018d0. The call shape is the builder pattern seen in `emit_builder_obj_tag0xec` (@0x005c4460) — begin(tag) / commit / finalize — with an added `builder_write_bytes(ctx, src, 6)` between begin and commit. So this is NOT a hash/checksum (the prior name was a misread): it serializes a fixed 6-byte token (a MAC/peer address / connection id) as a tagged field. The value returned by `builder_begin` is passed back to the caller (a status/handle), which is why the function has a 16-bit return.

## Input / output
- `param_1` (pointer/value): source of the 6 bytes to serialize (a 6-byte ID buffer).
- returns `undefined2`: the `builder_begin` result (status/handle) — propagated, not a computed hash.

## Side effects
- Mutates builder state at 0x7018d0: opens a `0xe0`-tagged object, writes 6 bytes from `param_1`, commits, finalizes.

## Important branches
None (straight-line builder sequence).

## Constants & flags
- `0xe0` = field/object tag for the 6-byte ID (sibling tags: 0xec empty-obj @0x5c4460, 0xda @0x5c27d0).
- `6` = byte length (matches a 48-bit MAC / peer-address token).

## Corrected reconstruction
```c
extern void *g_builder;                                         // 0x007018d0
extern unsigned short builder_begin(void *ctx, int tag);        // FUN_005be9e0
extern void builder_write_bytes(void *ctx, const void *src, int n); // FUN_005bea60
extern void builder_commit(void *ctx);                          // FUN_005bea10
extern void builder_finalize(void *ctx);                        // FUN_005bea80

// Serialize a 6-byte ID (e.g. peer address) as a tag-0xE0 field into the builder.
unsigned short serialize_id6_field_tag0xe0(const void *id6)
{
    unsigned short st = builder_begin(g_builder, 0xe0);
    builder_write_bytes(g_builder, id6, 6);
    builder_commit(g_builder);
    builder_finalize(g_builder);
    return st;                       // builder_begin's result, propagated
}
```

## Evidence
- Raw decompile: `uVar1 = be9e0(0x7018d0,0xe0); bea60(0x7018d0,param_1,6); bea10(0x7018d0); bea80(0x7018d0); return uVar1;`.
- Builder triad identical to FUN_005c4460 (begin/commit/finalize) — establishes the pattern and refutes the "hash" reading.
- Confidence **Medium**: begin/write/commit/finalize roles are inferred from call shapes, not from reading the be9e0/bea60/bea10/bea80 bodies.

## Remaining uncertainty
- Whether the 6 bytes are a MAC, a connID, or another peer token depends on the two callers (FUN_005c5a10/005c5ad0). The return value's precise meaning (bytes-written vs. status) is unconfirmed. Name changed from the misleading `compute_conn_hash`.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c6fb0.c`  — untouched decompiler output.
