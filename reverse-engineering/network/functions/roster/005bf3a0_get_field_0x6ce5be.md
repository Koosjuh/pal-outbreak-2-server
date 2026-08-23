# 0x005bf3a0 get_field_0x6ce5be

| field | value |
|---|---|
| Original address | 0x005bf3a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bf3a0 |
| Resolved name | get_field_0x6ce5be_u16 |
| Subsystem | roster |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ad890 (registry/room render query)
**Callees:** —
**Referenced globals:** 0x6ce5be (single u16, not indexed)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Reads one 16-bit global at 0x6ce5be into the caller's out-pointer. Unlike its siblings this accessor
is **not indexed** — it exposes a single scalar rather than a per-entry field. 0x6ce5be sits inside
the 0x144-stride registry render region (it is base 0x6ce49a + 0x124), so it is plausibly a header/
count scalar preceding or within entry 0 of that region, surfaced to the room render query
`FUN_005ad890`.

## Input / output
- `param_1` (u16* out) — destination; receives the u16 at 0x6ce5be.
- Returns 0 (constant).

## Side effects
Writes `*out`. No global mutation.

## Important branches
None — single load/store.

## Constants & flags
- `0x6ce5be` — the read address (u16). Within the 0x144-stride registry region (0x6ce49a + 0x124).

## Corrected reconstruction
```c
int get_field_0x6ce5be_u16(u16 *out) {
    *out = *(u16 *)0x6ce5be;   // uRam006ce5be
    return 0;
}
```

## Evidence
- Raw decompile: `*param_1 = uRam006ce5be; return 0;`.
- Address adjacency to the 0x6ce49a/0x6ce5f2 registry family (0x144 stride).
- Runtime-unvalidated (static only).

## Remaining uncertainty
- Semantic label (count vs flag vs entry-0 field) unknown; not runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bf3a0.c`  — untouched decompiler output.
