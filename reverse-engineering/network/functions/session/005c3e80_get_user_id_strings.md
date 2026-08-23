# 0x005c3e80 get_user_id_strings

| field | value |
|---|---|
| Original address | 0x005c3e80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c3e80 |
| Resolved name | copy_user_identity_strings |
| Subsystem | session |
| Relevance | helper |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b5520, FUN_005b5690
**Callees:** func_0x00109eb8 (string copy)
**Referenced globals:** 0x6fbdac / 0x6fbdbc / 0x6fbdd0 (stored user identity strings)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Optional-copy getter for the three stored user-identity strings. For each of three caller-supplied
destination pointers that is non-null, it copies the corresponding fixed identity string
(`0x6fbdac`, `0x6fbdbc`, `0x6fbdd0`) into it via the string-copy thunk `func_0x00109eb8(dst, src)`.
A null destination pointer means "caller doesn't want this field" and is skipped. The three sources
are contiguous fixed-size buffers: `0x6fbdac`(+0x10)→`0x6fbdbc`(+0x14)→`0x6fbdd0`, i.e. a 16-byte
field then a 20-byte field — consistent with a {name/handle, id/tag, …} identity block populated at
sign-in.

## Input / output
- **Params:** `param_1`, `param_2`, `param_3` (long) — destination buffers for identity field 0/1/2;
  any may be 0 to skip.
- **Return:** void.

## Side effects
- Writes up to three caller buffers with copies of `0x6fbdac / 0x6fbdbc / 0x6fbdd0`. No globals
  written.

## Important branches
- `if (param_1 != 0) copy(param_1, 0x6fbdac);`
- `if (param_2 != 0) copy(param_2, 0x6fbdbc);`
- `if (param_3 != 0) copy(param_3, 0x6fbdd0);`
- Each guard independent; all-null → no-op.

## Constants & flags
- Field base offsets: `0x6fbdac` (field 0), `0x6fbdbc` = +0x10 (field 1), `0x6fbdd0` = +0x24 (field 2).
  Field-0 span 0x10 ≈ 16-char display name.

## Corrected reconstruction
```c
// stored identity block: 0x6fbdac (16B), 0x6fbdbc (20B), 0x6fbdd0 (…)
void copy_user_identity_strings(char *out0 /*param_1*/, char *out1 /*param_2*/, char *out2 /*param_3*/)
{
    if (out0) strcpy(out0, (char*)0x6fbdac); // func_0x00109eb8
    if (out1) strcpy(out1, (char*)0x6fbdbc);
    if (out2) strcpy(out2, (char*)0x6fbdd0);
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005c3e80.c` (size 100). Three guarded
  `func_0x00109eb8(param_n, 0x6fbd..)` calls.
- `func_0x00109eb8` = string/block copy thunk (dst,src ordering matches other call sites).

## Remaining uncertainty
- Exact identity of each field (login handle vs. display name vs. numeric id) is inferred from
  size/adjacency, not proven; hence Medium and the "copy" (not semantic) name.
- Copy length/termination behavior of `func_0x00109eb8` unconfirmed.
- Runtime-unvalidated.
