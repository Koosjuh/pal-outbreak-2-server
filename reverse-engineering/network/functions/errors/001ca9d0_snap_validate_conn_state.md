# 0x001ca9d0 snap_validate_conn_state

| field | value |
|---|---|
| Original address | 0x001ca9d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ca9d0 |
| Resolved name | snap_check_conn_ready |
| Subsystem | errors |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001caa30, FUN_001caad0
**Callees:** —
**Referenced globals:** 0x25b790 (connection-state code)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x25b790

## Behavioral explanation
Precondition guard read by two transport API entry points (FUN_001caa30, FUN_001caad0). It reads the
global connection-state code `DAT_0025b790` and admits the operation only when the state is one of the
four "connected/active" codes `{0x64, 0x65, 0x66, 0x67}` (decimal 100–103). For any of those it
returns `0xFFFFFFF4` (-12); for anything else it returns `0xFFFFFFF0` (-16). Note both outcomes are
negative error-style codes — this is not a simple 0/-1 gate. The reading that fits the code: `-12` is
the "busy / already in this state, cannot re-do" rejection returned when the connection IS in an
active state, and `-16` is the "wrong state entirely / not-permitted" rejection for any other state.
The caller thus proceeds only when this returns a specific expected code, or maps these to distinct
error surfaces.

## Input / output
- No parameters.
- returns (undefined4): `0xFFFFFFF4` (-12) if `state ∈ {0x64,0x65,0x66,0x67}`, else `0xFFFFFFF0`
  (-16).

## Side effects
- None (read-only on `DAT_0025b790`).

## Important branches
- `state == 0x67 || state == 0x66 || state == 0x65 || state == 0x64` → `uVar1 = 0xFFFFFFF4` (-12).
- otherwise → `uVar1 = 0xFFFFFFF0` (-16).
  (The decompiler expands this as a short-circuit chain that keeps re-assigning `0xFFFFFFF4` at each
  `!=` test, then overwrites with `0xFFFFFFF0` only if all four comparisons fail.)

## Constants & flags
- Connection-state codes `0x64/0x65/0x66/0x67` (100–103) — the "active/connected" band of the SN@P
  connection state enum (`DAT_0025b790`; sits adjacent to the conn pointer at 0x25b78c).
- Error codes: `-12` (0xFFFFFFF4) = busy/in-active-state; `-16` (0xFFFFFFF0) = wrong/invalid state.

## Corrected reconstruction
```c
// Precondition check on the global SN@P connection state. Returns two distinct negative codes.
enum { CONN_ST_A = 0x64, CONN_ST_B = 0x65, CONN_ST_C = 0x66, CONN_ST_D = 0x67 };
#define SNAP_ERR_BUSY        (-12)  /* 0xFFFFFFF4: state is active */
#define SNAP_ERR_BAD_STATE   (-16)  /* 0xFFFFFFF0: state not in active band */

int snap_check_conn_ready(void)
{
    int st = g_conn_state /* DAT_0025b790 */;
    if (st == CONN_ST_A || st == CONN_ST_B || st == CONN_ST_C || st == CONN_ST_D)
        return SNAP_ERR_BUSY;      // -12
    return SNAP_ERR_BAD_STATE;     // -16
}
```

## Evidence
- Raw decompile lines 7–12: the four `!= {0x67,0x66,0x65,0x64}` comparisons defaulting `uVar1` to
  `0xFFFFFFF4`, else `0xFFFFFFF0`.
- Two callers FUN_001caa30 / FUN_001caad0 are transport request entry points that gate on this.
- Runtime-unvalidated; the -12/-16 semantic labels are inferred from the code values, not traced.

## Remaining uncertainty
- The precise meaning each caller assigns to -12 vs. -16 (whether -12 is treated as success-equivalent
  "already connected" or as a hard reject) is not proven without reading the caller dispatch. The
  state-band membership test itself is exact.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ca9d0.c`  — untouched decompiler output.
