# 0x0060a650 zfree_wrapper

| field | value |
|---|---|
| Original address | 0x0060a650 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060a650 |
| Resolved name | zfree_wrapper (ZFREE thunk) |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00608ab0 (inflate_blocks_reset), FUN_00608c80 (inflate_blocks)
**Callees:** — (indirect call through z_stream->zfree)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
The zlib `ZFREE` macro compiled into a tiny out-of-line helper: invokes the stream's free callback
`z->zfree(z->opaque, ptr)`. It exists as its own symbol because two call sites free through it. The
"could not recover jumptable / treating indirect jump as call" warning is just the tail-call through
the function pointer at `z+0x2c`.

## Input / output
- **Params:**
  - `undefined8 param_1` — `void *ptr` to free.
  - `int param_2` — `z_streamp z` (zfree at `+0x2c`, opaque at `+0x30`).
- **Return:** none (tail-calls the free callback).

## Side effects
- Calls `(*z->zfree)(z->opaque, ptr)`.

## Important branches
- None.

## Constants & flags
- z_stream `+0x2c` = zfree callback, `+0x30` = opaque.

## Corrected reconstruction
```c
void zfree_wrapper(void *ptr, z_streamp z)
{
    (*z->zfree)(z->opaque, ptr);   // ZFREE(z, ptr)
}
```

## Evidence
- Raw decompile `FUN_0060a650.c`: `(**(code **)(param_2 + 0x2c))(*(undefined4*)(param_2+0x30), param_1);`.
- Same `+0x2c`/`+0x30` callback layout as every other zlib fn in this cluster.

## Remaining uncertainty
- None. The "jumptable not recovered" note is a disassembler artifact of the indirect tail-call, not a
  real switch.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060a650.c`  — untouched decompiler output.
