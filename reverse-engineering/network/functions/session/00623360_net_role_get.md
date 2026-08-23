# 0x00623360 net_role_get

| field | value |
|---|---|
| Original address | 0x00623360 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00623360 |
| Resolved name | net_role_apply_flags |
| Subsystem | session |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00622180 (screen dispatcher)
**Callees:** —
**Referenced globals:** cRam003c98a0 role flag; iRam00715298 screen-handler struct ptr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam003c98a0

## Behavioral explanation
Reads the network **role** flag `0x3c98a0` and stamps the derived per-role flags into the screen-handler struct, then returns the role byte. It is the read-side counterpart to `screen_sm_role_negotiate` (0x00620b60), which *writes* `0x3c98a0`. Two role values are distinguished:
- **role == 2:** set `struct+0x12 = 1` and clear `struct+0xc = 0` — the "role 2" configuration (`[inferred]` host/server side).
- **role != 2** (typically 1): set `struct+0xc = 1` — the "role 1" configuration (`[inferred]` join/client side).

In both cases it sets `struct+0x10 = 1` (mark role applied / screen configured) and returns the raw role byte. The resolved name is upgraded from `net_role_get` to **`net_role_apply_flags`** because it not only reads but writes the role-dependent screen flags.

## Input / output
- No params (reads `0x3c98a0`, writes `iRam00715298`).
- **Return** `char`: the role byte `cRam003c98a0` (e.g. 1 or 2).

## Side effects
- role 2: `struct[0x12] = 1`, `struct[0xc] = 0`.
- else: `struct[0xc] = 1`.
- always: `struct[0x10] = 1` (applied flag).

(The raw shows `struct[0xc]` written twice with the same value on each branch — a decompiler artifact / redundant store; behavior is a single assignment.)

## Important branches
- `cRam003c98a0 == 2` → `+0x12=1`, `+0xc=0`.
- `cRam003c98a0 != 2` → `+0xc=1`.

## Constants & flags
- `cRam003c98a0` role enum: `2` (`[inferred]` host/server) vs other/`1` (`[inferred]` join/client). Same flag asserted `=1` by `screen_sm_role_negotiate` (0x00620b60).
- `struct+0x10` — "role applied / screen configured" latch.

## Corrected reconstruction
```c
// Apply role-dependent flags to the screen-handler struct; return the role byte.
char net_role_apply_flags(void)   // struct = iRam00715298
{
    char *s = (char*)iRam00715298;
    char role = g_role /*cRam003c98a0*/;
    if (role == 2) {              // [inferred] host/server
        s[0x12] = 1;
        s[0xc]  = 0;
    } else {                      // [inferred] join/client (role 1)
        s[0xc]  = 1;
    }
    s[0x10] = 1;                  // role applied
    return role;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_00623360.c`.
- `cRam003c98a0` cross-referenced with `screen_sm_role_negotiate` (0x00620b60), which sets it to 1.
- Runtime-unvalidated; role→host/join mapping inferred.

## Remaining uncertainty
- Whether role 2 is host or join (vs role 1) is inferred from the negotiate SM asserting `1` on the default/local path; not confirmed by wire evidence. Meaning of `+0xc`/`+0x12` beyond "role-config bytes" is unresolved.
