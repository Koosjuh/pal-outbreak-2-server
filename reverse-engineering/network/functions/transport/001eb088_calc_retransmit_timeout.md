# 0x001eb088 calc_retransmit_timeout

| field | value |
|---|---|
| Original address | 0x001eb088 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eb088 |
| Resolved name | clamp_retransmit_interval |
| Subsystem | transport |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001e19c4 (reliable-transport tick / RTO update)
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** `*param_1` — the running retransmit interval (RTO), updated in place

## Behavioral explanation
Recomputes a reliable-transport retransmit interval from timestamp deltas and clamps it. It derives a raw
interval by one of three formulas (selected by `param_5` and `param_4`), floors it to `0x11`, caps it to
`32000`, and — if a previous interval exists (`*param_1 > 0`) — limits growth to at most **10×** the prior
value (a backoff cap). The clamped result is stored back into `*param_1`. Units are the transport's tick
counter (interpretation not yet tied to a wall clock).

## Input / output
- `param_1` (int*) — in/out running interval (prior value read, new value written).
- `param_2` (int) — a current timestamp / "now".
- `param_3` (int) — a reference timestamp (send time) — used when `param_5 < 1`.
- `param_4` (int) — an alternate reference (e.g. last-ack time); when nonzero and `param_5 ≥ 1`, the delta
  is `now - param_4`.
- `param_5` (int) — selector/flag (sample-count or "have-ack" indicator).
- Returns void; result in `*param_1`.

## Side effects
- Writes `*param_1`.

## Important branches
- `if (param_5 < 1)` → `t = param_2 - param_3` (base delta, no ack sample).
- `else if (param_4 == 0)` → `t = (param_2 - param_3) + 0x22` (add fixed `0x22` bias when no alt-reference).
- `else` → `t = param_2 - param_4` (delta against the alternate reference).
- `if (t < 0x11) t = 0x11;` — floor.
- `if (32000 < t) t = 32000;` — ceiling.
- `if (0 < *param_1)`: the inner `if (iVar1 == 0) trap(7)` is a dead div-by-zero guard (unreachable under
  `iVar1 > 0`); then `if (10 < t / *param_1) t = *param_1 * 10;` — cap growth to 10× prior.

## Constants & flags
- Floor `0x11` (17), ceiling `32000`, additive bias `0x22` (34), growth cap `10×`.
- `trap(7)` — MIPS integer-divide-by-zero trap, guarded-unreachable artifact.

## Corrected reconstruction
```c
/* Recompute + clamp the reliable-transport retransmit interval (RTO). */
void clamp_retransmit_interval(int *rto, int now, int send_ts, int ack_ts, int have_sample)
{
    int prev = *rto;
    int t;

    if (have_sample < 1)      t = now - send_ts;
    else if (ack_ts == 0)     t = (now - send_ts) + 0x22;   /* +34 bias */
    else                      t = now - ack_ts;

    if (t < 0x11)   t = 0x11;          /* floor  17 */
    if (t > 32000)  t = 32000;         /* ceil 32000 */

    if (prev > 0 && (t / prev) > 10)   /* limit backoff to 10x prior */
        t = prev * 10;

    *rto = t;
}
```

## Evidence
- Raw decompile: three-way delta select on `param_5`/`param_4`, `[0x11, 32000]` clamp, `10×` growth cap on
  the prior `*param_1`. Sole caller `FUN_001e19c4` is a transport tick. Semantics of each timestamp arg are
  inferred from position/usage, not a trace ⇒ **Medium**.

## Remaining uncertainty
- Which concrete conn fields feed `param_2..param_5` (now / send-ts / ack-ts / sample-count) — needs the
  caller `FUN_001e19c4` decode or a PINE read to pin the tick units and confirm the `have_sample` role.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eb088.c`  — untouched decompiler output.
