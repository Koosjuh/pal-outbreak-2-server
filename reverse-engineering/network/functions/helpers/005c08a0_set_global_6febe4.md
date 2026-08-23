# 0x005c08a0 set_global_6febe4

| field | value |
|---|---|
| Original address | 0x005c08a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c08a0 |
| Resolved name | set_create_flags_6febe4 (set_global_6febe4) |
| Subsystem | helpers |
| Relevance | support (create/enter path) |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b5d20, FUN_005f99c0 (room create action), FUN_0062de90 (room-list action dispatcher)
**Callees:** —
**Referenced globals:** 0x6febe4 (`uRam006febe4`) — create-request flag/selector word consumed by the create pump
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6febe4

## Behavioral explanation
Setter: stores `param_1` into global 0x6febe4 and returns 0. This word is **read by the create-slot
pump `FUN_005c3490`**, which both OR-composes selector bits into it
(`uRam006febe4 = uVar9<<8 | … | uRam006febe4`) and uses it to size the transport send
(`func_0x001dc508(…, uRam006febe4 << 1, …)`). Two of the three callers (0x5f99c0, 0x62de90) are the
same UI actions that arm the create SM via `statemachine_register_6cba7c`, so this call seeds the
create-request flags/selector immediately before the SM is armed.

## Input / output
- **Params:** `param_1` — create-request flag/selector value (u32; low bits used as a send-length
  multiplier and selector seed). **Returns:** `undefined8` 0.

## Side effects
- Writes global 0x6febe4. No other state.

## Important branches
- None.

## Constants & flags
- 0x6febe4 feeds `uRam006febe4 << 1` as a byte-count into the create send, and its high bits
  (`<<8`) become selector flags in the pump — so it is a packed **{count, selector-flags}** word.

## Corrected reconstruction
```c
// Seed the create-request flag/selector word consumed by the create pump (FUN_005c3490).
u64 set_create_flags_6febe4(u32 flags /*param_1*/)
{
    g_create_flags /*0x6febe4*/ = flags;
    return 0;
}
```

## Evidence
- Raw decompile: `uRam006febe4 = param_1; return 0;`.
- Pump `FUN_005c3490` reads/updates 0x6febe4 (selector OR + `<<1` send length), and the two shared
  callers also arm the create SM — establishing this as create-request seeding, not an unrelated
  global.

## Remaining uncertainty
- Exact bitfield layout of the flags word not mapped; the third caller FUN_005b5d20 context not
  traced. Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c08a0.c`  — untouched decompiler output.
