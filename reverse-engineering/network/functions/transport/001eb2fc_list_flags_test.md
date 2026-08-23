# 0x001eb2fc list_flags_test

| field | value |
|---|---|
| Original address | 0x001eb2fc |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eb2fc |
| Resolved name | list_flags_test_all |
| Subsystem | transport |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ec1f8 (sub-pool alloc — watermark/latch check), FUN_001ec9e0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** list-head `flags` (+0xe)

## Behavioral explanation
Tests whether **all** bits of `mask` are set in the list-head flags word (+0xe): returns
`(flags & mask) == mask`. In `FUN_001ec1f8` this is the guard that checks the sub-pool high-water /
disable latch before allocating a reliable sub-buffer — the "watermark-latched" bit noted in the transport
model (op49 sub-pool-2 latch). An all-bits-set semantic means it can also test single bits.

## Input / output
- `param_1` (int) — list-head pointer.
- `param_2` (ushort) — bitmask to test.
- Returns `bool` — true iff every bit in `mask` is present in `flags`.

## Side effects
- None (pure read).

## Important branches
- Single expression `(mask & flags) == mask`; no control flow.

## Constants & flags
- Flags word at +0xe. Individual bit meanings live in the pool code (e.g. the sub-pool-2 watermark/disable
  latch tested by `FUN_001ec1f8`).

## Corrected reconstruction
```c
/* True iff ALL bits of mask are set in the list flags. */
bool list_flags_test_all(const list_head *h, uint16_t mask)
{
    return (h->flags & mask) == mask;   /* +0x0e */
}
```

## Evidence
- Raw decompile: `return (param_2 & *(u16*)(param_1 + 0xe)) == param_2;`. Offset agrees with `list_init`;
  paired with `list_flags_set`. Callers are the sub-pool allocator. Runtime-unvalidated.

## Remaining uncertainty
- The concrete bit constants (which bit = watermark latch vs disable) are defined by the pool logic, not
  here — resolve in `FUN_001ec1f8`.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eb2fc.c`  — untouched decompiler output.
