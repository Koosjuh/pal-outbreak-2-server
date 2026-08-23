# 0x005be9e0 vtable_register_identity

| field | value |
|---|---|
| Original address | 0x005be9e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005be9e0 |
| Resolved name | msgbuilder_begin_record (tag pass-through) |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bda80, FUN_005bdeb0, FUN_005bdef0, FUN_005beba0, FUN_005bec80, FUN_005becf0, FUN_005bed60, FUN_005bedd0, FUN_005bee40, FUN_005bee90, FUN_005bef00, FUN_005c08b0, FUN_005c0dc0, FUN_005c1e70, FUN_005c1f30, FUN_005c1ff0, FUN_005c2080, FUN_005c2250, FUN_005c27d0, FUN_005c4460, FUN_005c6fb0
**Callees:** —
**Referenced globals:** 0x7018d0 (message/record builder object, passed as arg1)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Leading primitive of the 0x7018d0 message/record-builder method family. Every register and
menu-label wrapper opens with `FUN_005be9e0(0x7018d0, <tag>)`. The compiled body is an 8-byte
leaf that returns its **second** argument unchanged (`move v0,a1; jr ra`) — i.e. it echoes the
record/type tag back to the caller. In `FUN_005beba0` the returned tag is what the caller then
stores into the object-type dispatch table (`0x6ca97e`, 0x20 stride). In this PAL build the
call performs no write to the builder object; it is an identity/tag pass-through ("begin record
with tag N, yield N").

## Input / output
- **Params:** `arg1` = builder object pointer (always `0x7018d0`); `arg2` = record/type tag
  (e.g. 0x1a, 0xad, 0xaf, 0xb0, 0xb1, …).
- **Returns:** `arg2` (the tag), zero-extended.

## Side effects
None observable in this build (leaf, no stores). The *tag it returns* is consumed by the caller
(register wrappers write it into the 0x6ca97e type table).

## Important branches
None. Straight-line identity return.

## Constants & flags
Tag values are supplied by callers, not this function. Observed tags: `0x1a`, `0xad`
(register wrappers); `0xaf`,`0xb0`,`0xb1` (menu-label builders).

## Corrected reconstruction
```c
// Opens a builder record and yields its tag. Body is a pure identity in this build:
// the "write tag into *builder" step is not present (8-byte leaf), so callers rely only
// on the returned tag.  [inferred] builder_obj type; return semantics are certain.
uint16_t msgbuilder_begin_record(void *builder_obj /*=0x7018d0*/, uint16_t tag)
{
    (void)builder_obj;
    return tag;          // move v0,a1 ; jr ra
}
```

## Evidence
- Raw decompile: `undefined8 FUN_005be9e0(undefined8 p1, undefined8 p2){ return p2; }` — 8 bytes.
- Callsites: `FUN_005bdeb0` → `be9e0(0x7018d0,0x1a)`; `FUN_005beba0` → `uVar1=be9e0(0x7018d0,0xad)`
  then caller stores `uVar1` to `lVar2*0x20 + 0x6ca97e`; menu builders → `be9e0(0x7018d0,0xaf/0xb0/0xb1)`.
- 21 callers, all passing `0x7018d0` as arg1 → confirms arg1 = the shared builder object.

## Remaining uncertainty
Whether the real design intends a store into the builder (overridden elsewhere). Here the
behavior is a certain identity; only the "record open" intent is inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005be9e0.c`  — untouched decompiler output.
