# `tools/loadtest-op48.js` — UDP op48 load-test harness (G11)

Validates whether `server/game_udp_server.js` (UDP port 9090) sustains many
clients each flooding the op48 `named-slot-query` at Area-Select cadence
(~25 Hz), and measures the impact of its per-message synchronous logging
(`log()` = `fs.appendFileSync` + `console.log`, fired ~5x per op48).

No new dependencies — Node core `dgram` only.

## Safety

Default `--host` is `127.0.0.1`. The tool **refuses** to target the live Pi
(`192.0.2.121`) unless `--confirm-live-rig` is also passed — the owner may
be actively using the live rig, and fabricated flood traffic would pollute a
real session. Always validate locally first.

## Run locally

```sh
# terminal 1 — start a local server instance
node server/game_udp_server.js

# terminal 2 — run the load test against it
node tools/loadtest-op48.js --host 127.0.0.1 --port 9090 --clients 20 --rate 25 --secs 10
```

Known current-HEAD issue (2026-07-06, unrelated to this harness): after the
07-04 rollback (`fe63c59`) restored an older `server/game_udp_server.js` /
`server/snap_server.js`, both still `require('../tools/pine_client')`, a path
from before the tools reorg (`3d0ca79`) moved the real file to
`tools/pine/pine_client.js`. The server **will not start** on current HEAD
until that require path is fixed (not fixed here — out of scope for this
harness, flagged for the owner). It was verified during this task's
validation only via a temporary, non-committed shim, then removed.

## Basic usage

```
node tools/loadtest-op48.js --host <ip> --port 9090 --clients <N> --rate <hz> --secs <n> [options]

  --host <ip>          target IP (default 127.0.0.1; Pi requires --confirm-live-rig)
  --port <n>            target UDP port (default 9090)
  --clients <N>          number of virtual UDP clients (default 10)
  --rate <hz>            per-client op48 send rate in Hz (default 25)
  --secs <n>             measurement duration in seconds (default 10)
  --warmup [secs]        discard-stats warmup before measuring (default 1s)
  --grace-ms <n>         post-send drain window before counting drops (default 500;
                         raise for heavy runs — see "Reading results" below)
  --ramp                 step clients 1 -> --clients to find the degradation knee
  --ramp-start <N>       first ramp stage client count (default 1)
  --ramp-factor <n>      multiplicative step per ramp stage (default 2)
  --stage-secs <n>       seconds per ramp stage (default = --secs, min 2)
  --knee-p95-ms <n>      ramp knee: flag first stage with p95 > this (default 50)
  --knee-drop-pct <n>    ramp knee: flag first stage with drop% > this (default 5)
  --confirm-live-rig     required if --host resolves to the live Pi
  --help                 show usage
```

## What it measures

Each virtual client is its own UDP socket sending a real 70-byte op48
`named-slot-query` frame (kind `0xF0`, `msg[3]=0x48`, 2 `NAME` entries — the
same shape as the captured sample in
`analysis/udp9090-named-slot-query-op48.md`), with a unique, incrementing
`request_id` at wire `0x10..0x13`. The server always mirrors that field
verbatim into its 104-byte structured `named-slot-query-reply` (see
`buildAck()` in `game_udp_server.js`), so it doubles as a correlation id for
round-trip latency — no server code changes needed.

Printed per run/stage: clients, total sent, total structured replies
received, reply-rate %, dropped (no reply within the grace window),
sends/sec actually achieved, and p50/p95/p99 latency in ms. A `(diag: ...)`
suffix reports transport-ACK-only counts and unclassified replies, useful for
telling "no reply at all" apart from "reply arrived very late."

## Reading results (validated 2026-07-06, local Windows box, single-server-process)

| clients | target req/s | reply rate (grace=500ms) | p50 latency | p95 latency |
|---|---|---|---|---|
| 2  | 50   | 100%  | 2.8ms    | 4.9–14ms |
| 10 | 250  | 96.5% | 13.1ms   | 652ms    |
| 30 | 750  | 33.0% | 1454ms   | 2796ms   |
| 60 | 1500 | 0% (grace=500ms) / 32.6% (grace=15000ms) | 3189ms (grace=15000ms) | 4298ms |

Latency grows from single-digit ms to multiple **seconds** between 250 and
1500 aggregate req/s on one modest dev box running both the flood client and
the server. Re-running the 60-client case with `--grace-ms 15000` proves
replies keep arriving minutes after the load stops (median ~3.2s, not
infinite) — i.e., this is a **queueing/backlog blowup**, consistent with the
G11 hypothesis that the per-packet synchronous `fs.appendFileSync` +
`console.log` calls (and, additionally observed in this validation, an
**unconditional `fs.writeFileSync` creating a brand-new snapshot file per
inbound op48** at `game_udp_server.js` ~line 1572, even when
`UDP_SNAPSHOTS` is unset and no PINE read ever happens) cannot keep up with
real concurrent-client volume, not a protocol-level limit. These are
single-box numbers (client and server compete for the same CPU/disk) —
useful for relative comparison, not an absolute Pi capacity number. Re-run
against a dedicated server host (or the Pi, with explicit
`--confirm-live-rig`, only when appropriate) for an absolute figure.

## Ramp mode

```sh
node tools/loadtest-op48.js --host 127.0.0.1 --clients 64 --rate 25 --ramp --stage-secs 5
```

Steps client count `1, 2, 4, 8, ... -> 64`, prints one row per stage, and
reports the first stage where p95 latency or drop-% crosses the
`--knee-p95-ms` / `--knee-drop-pct` thresholds — the empirical "knee" where
the server stops keeping up.
