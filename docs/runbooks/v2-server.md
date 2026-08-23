# Running the composed V2 server

The V2 server is one ordinary Node.js process. No native modules, no build step,
no bundler: persistence uses the built-in `node:sqlite`, so a checkout plus a
Node runtime is the whole dependency list. Nothing in it is platform-specific,
so 64-bit Raspberry Pi OS needs no native build - but see the runtime
requirement below, which is currently NOT satisfied on the Pi.

**Replacing V1 is permitted** (owner, 2026-08-03): a restorable V1 backup exists,
so V2 may take over the Pi rather than only running beside it. Even so, install it
under its own service name and data directory. Verify the V1 backup is present and
restorable BEFORE switching, and record that check - the backup is what makes this
reversible, so an unverified backup means an irreversible change.

## Requirements

- **Node.js 22.5 or newer**, because persistence imports `node:sqlite`. It is
  behind `--experimental-sqlite` until it became unflagged (Node 22.13 / 23.4),
  so on 22.5-22.12 the process must be started with that flag. Node 20 CANNOT
  run this server.

  **Outstanding deployment prerequisite:** `server-v2/audit/REFERENCE_ACCOUNT_STORAGE.md`
  records the Pi running Node 20.19.2. Upgrading that runtime, or replacing the
  storage layer, is a prerequisite for any Pi deployment, and neither this server
  nor this runbook has been executed on the Pi. Treat every statement here about
  Pi behaviour as untested until it has.
- A writable data directory. The SQLite database and its WAL live there.
- For DNAS: the operator's certificate, CA certificate, private key and packet
  directory. Without them, start with `PAL_V2_ENABLE_DNAS=false`.
- For DNS on port 53: either run as root (not recommended) or grant the
  capability, see the systemd unit below.

## The one command

From the repository root:

```sh
PAL_V2_MASTER_KEY="$(openssl rand -base64 32)" \
PAL_V2_DATA_DIR=/var/lib/pal-server-v2 \
PAL_V2_SELF_HOST=192.0.2.121 \
PAL_V2_SNAP_HOST=192.0.2.121 \
PAL_V2_DIRECTORY_FILE=/etc/pal-server-v2/directory.json \
PAL_V2_LOBBY_NAME='PAL V2' \
PAL_V2_DNS_RECORDS='snap01.capcom.client.sf.yav4.com=192.0.2.121' \
PAL_V2_DNAS_CERT=/etc/pal-server-v2/dnas/server.crt \
PAL_V2_DNAS_CA_CERT=/etc/pal-server-v2/dnas/ca.crt \
PAL_V2_DNAS_KEY=/etc/pal-server-v2/dnas/server.key \
PAL_V2_DNAS_PACKET_DIR=/etc/pal-server-v2/dnas/packets \
node server-v2/bin/pal-server-v2.js
```

Generate the master key **once** and keep it: it seals the reversible
compatibility secret at rest, and losing it means losing every stored account
secret. It never belongs in the repository.

For a first local run against PCSX2 with only the lobby path, DNS and DNAS can be
turned off and the emulator pointed straight at the host:

```sh
PAL_V2_MASTER_KEY="$(openssl rand -base64 32)" \
PAL_V2_DATA_DIR=./.v2-data \
PAL_V2_SELF_HOST=192.0.2.121 \
PAL_V2_SNAP_HOST=192.0.2.121 \
PAL_V2_DIRECTORY_FILE=server-v2/config/directory.example.json \
PAL_V2_LOBBY_NAME='PAL V2' \
PAL_V2_ENABLE_DNS=false \
PAL_V2_ENABLE_DNAS=false \
PAL_V2_LOG_LEVEL=debug \
node server-v2/bin/pal-server-v2.js
```

Copy `server-v2/config/directory.example.json` somewhere writable and edit it
before serving anything real. Its `provenance` must be `operator`; a file marked
`test-fixture` is refused at startup by design.

## Configuration

Required:

| Variable | Meaning |
|---|---|
| `PAL_V2_MASTER_KEY` | Base64 32-byte key sealing compatibility secrets at rest |
| `PAL_V2_DATA_DIR` | Writable directory for the SQLite database |
| `PAL_V2_SELF_HOST` | Address the client should use for this server's own HTTP links |
| `PAL_V2_SNAP_HOST` | Address advertised to the client for the SN@P endpoint |
| `PAL_V2_DIRECTORY_FILE` | Operator-authored directory document |
| `PAL_V2_LOBBY_NAME` | Display name in the `lbs.jsp` response |

Optional: `PAL_V2_BIND_HOST` (default `0.0.0.0`), `PAL_V2_LOG_LEVEL`
(`debug|info|warn|error`), `PAL_V2_HTTP_PORT` (80), `PAL_V2_TCP_PORT` (10127),
`PAL_V2_SNAP_PORT` (10127), `PAL_V2_DESCRIPTIVE_HEX`, `PAL_V2_WELCOME_MESSAGE`,
`PAL_V2_ENABLE_DNS` (true), `PAL_V2_DNS_PORT` (53), `PAL_V2_DNS_RECORDS`,
`PAL_V2_ENABLE_DNAS` (true), `PAL_V2_DNAS_PORT` (443), `PAL_V2_DNAS_CERT`,
`PAL_V2_DNAS_CA_CERT`, `PAL_V2_DNAS_KEY`, `PAL_V2_DNAS_PACKET_DIR`,
`PAL_V2_ENABLE_UDP_REGISTER` (true), `PAL_V2_UDP_REGISTER_PORT` (9090),
`PAL_V2_UDP_BIND_ADDRESS`, `PAL_V2_DYNAMIC_DNAS_TOKEN` (false).

SN@P dispatch flags (booleans; note several default **ON** — their rollback is
setting them `false`, so they must be visible here):
`SNAP_JOIN_LADDER` (**true** — the op-0x06 room-ENTER join ladder through the
slot-allocator guards plus the op-0x10 sub-0x0C join-confirm; set `false` to
restore every pre-ladder byte), `SNAP_OP10_RELAY` (**true** — the op-0x10
room-scoped except-sender relay; set `false` to disable),
`SNAP_OP0A_COUNT0` (**true** — answer op-0x0a with July V1's 12-byte count-0
body; `false` restores the count-1 reply that starved both RS1 consoles),
`SNAP_MEMBER_INFO` (**true** — the V1 member-info supply channel: op-28
sel-0x0a roster records with every op-0x0c completion plus op-0x10 sub-1
player-info pushes; `false` restores the RS1 build's silence),
`SNAP_COUNT_PUSH` (**true** — re-broadcast the op-0x09 USER area count to the
area's sessions on every area enter/leave, the JP `broadcastAreaPlayerCnt`
analogue; `false` stops every unsolicited op-0x09),
`SNAP_APP_KEEPALIVE` (**true** — every 30 s per established session, an
op-0x10 who-0xA000 push with app-payload byte 0x00: the pure reset for the
lobby overlay's ~145.7 s application-liveness watchdog, which op-0x40 never
reaches — without it an idle client probes with op-0x14, hears nothing, and
self-closes with the voluntary op-0x02 (`ROOM-WATCHDOG-RE.md`); `false` stops
every push, byte-identical otherwise),
`SNAP_CREATE_CONFIG` (**true** — answer the TCP create-config rows
0x6407..0x6504 after the ladder completes; wire-inert until the client sends
one there), `SNAP_LOBBY_BUTTONS` (**true** — answer
RANKINGS/GETINFO/BUDDYLIST/CHECKBUDDY post-ladder per the bioserver
reference; wire-inert until the client sends one),
`SNAP_RULE_MASKS_AUTHENTIC` (**true** — serve the create-screen rule bytes of
`docs/design/v2-port/RULES-MASK-RE.md` §6.2 in the area blob: both
`+0x16c`/`+0x1a8` parameter blocks `F3 E2` plus the per-area group-1 rule
rows, `+0x16b = 0x03` for title/password, `+0x03 = 0xFF` for the full 8-cast,
`+0x04..0x13 = 0xFF` extra-cast permission, and `+0x14`/`+0x18` = the full
`0x7FF` scenario ring on enabled areas, under version OBAREA-V5 (OBAREA-V6
when `SNAP_OPTION_LABELS` is also on — the flags are independent). This is
what makes rules/cast/scenario selectable on the create screen; `false`
restores the previous all-red blob byte-identically under its previous
version. Power-cycle the console after flipping it — a cached version match
silently skips the re-fetch),
`SNAP_OPTION_LABELS` (false — serve the area blob's `+0x12fc` option-label
table as zero records, version OBAREA-V4 (V6 with the rule bytes); kept off
by default because it changes an 11-slice bulk transfer the rig confirmed
byte-for-byte and must be the only variable of the run that turns it on),
`SNAP_ROOMFLAGS_PUBLISH` (false — publish the engine's authored room status in
the op-0x49 record flags word `+0x1c`), `SNAP_GAME_BEACON_ECHO` (false —
proven fatal on the rig, RS1-A; leave off for owner-facing runs),
`SNAP_GAME_BEACON_RELAY` (false), `SNAP_EXIT_CLOSE_MIRROR` (false),
`SNAP_COMPLETION_SEQ_ECHO` (false).

### `PAL_V2_DYNAMIC_DNAS_TOKEN` - an experiment, off by default

V2 replays canned DNAS replies, and one record in them carries the 32-byte
platform-session token the client later presents as `?DNAS=` and inside `0x1007`.
Because the asset is static, **every console receives the identical value**, so it
identifies nobody (T27, OQ-022).

With this set, each DNAS reply is COPIED and only those 32 bytes are replaced with
`crypto.randomBytes`. The asset on disk is never modified; every other byte,
including the record tag and length, is passed through untouched. Each issued
token is logged as `platform-token-issued`, so a rig run can be correlated
against whatever the client presents afterwards.

**Why it is off by default.** The client never validates the token
(`0x35ba00` is write-only on its side), but whether the DNAS reply carries an
integrity check over that field is UNKNOWN. If enabling this breaks DNAS, set it
back to `false` - nothing else depends on it, and the corrected session model does
not require it.

### The UDP register bind address is not optional in the usual sense

`PAL_V2_UDP_BIND_ADDRESS` must be the **specific IPv4 address the client dials**,
never a wildcard and never a hostname. It defaults to `PAL_V2_SNAP_HOST` only when
that is itself an IPv4 address; otherwise startup fails with an explanation.

This is not fussiness. `FUN_001d72a8` discards any datagram whose source IP:port
do not exactly match the `serverIP:9090` the client registered against, so on a
multi-homed host a `0.0.0.0` bind can answer from a different source address and
the client silently ignores a perfectly correct reply. It presents as broken
crypto. `PAL_V2_BIND_HOST` (default `0.0.0.0`) governs the other listeners and is
deliberately NOT used for this one.

### Port 9090 conflicts with V1

V1's `game_udp_server.js` binds UDP 9090 too, and only one process may hold it.
Startup is all-or-nothing: if the register service cannot bind, every already-started
listener is rolled back and the process exits non-zero. So V1 must be stopped before
V2 starts, exactly as for ports 53/80/443/10127. Set
`PAL_V2_ENABLE_UDP_REGISTER=false` to run V2 without the register service.

A port of `0` means "let the kernel choose", which is what the integration tests
use. Configuration is validated in full before any socket opens: every problem is
reported at once and the process exits `78` without binding anything.

## Startup, shutdown and failure

Listeners bind in a fixed order: TCP 10127, HTTP, DNAS, DNS. If any enabled
listener fails to bind, every listener already up is closed again and the process
exits non-zero. There is no partially-serving state — a server reachable on DNS
but not on TCP would send the client somewhere that cannot answer.

`SIGINT` and `SIGTERM` stop listeners in reverse order and close the database
last. An uncaught exception or unhandled rejection is logged, shuts the process
down, and exits non-zero so the supervisor restarts it cleanly.

Logs are one JSON object per line on stdout, which journald captures directly.

## systemd

Install to `/etc/systemd/system/pal-server-v2.service`, with the environment in
`/etc/pal-server-v2/env` (mode `0600`, owned by root — it holds the master key):

```ini
[Unit]
Description=PAL Outbreak File #2 server V2
After=network-online.target
Wants=network-online.target

[Service]
Type=simple
User=pal
Group=pal
WorkingDirectory=/opt/pal-server-v2
EnvironmentFile=/etc/pal-server-v2/env
ExecStart=/usr/bin/node /opt/pal-server-v2/server-v2/bin/pal-server-v2.js
Restart=always
RestartSec=2
KillSignal=SIGTERM
TimeoutStopSec=15

# Port 53 and 443 without running as root.
AmbientCapabilities=CAP_NET_BIND_SERVICE
CapabilityBoundingSet=CAP_NET_BIND_SERVICE
NoNewPrivileges=true
PrivateTmp=true
ProtectSystem=strict
ProtectHome=true
ReadWritePaths=/var/lib/pal-server-v2
StateDirectory=pal-server-v2

[Install]
WantedBy=multi-user.target
```

```sh
sudo systemctl daemon-reload
sudo systemctl enable --now pal-server-v2
journalctl -u pal-server-v2 -f -o cat | jq .
```

`Restart=always` plus a non-zero exit on any startup or runtime failure is the
whole supervision story: the process never tries to limp along degraded.

## Before deploying to the Pi

Upgrade the Pi's Node runtime first: the recorded version cannot run this server
(see Requirements). Then follow `docs/runbooks/pi-deployment.md` — verify and
record the V1 image backup, hashes, service definition and journal, since that
backup is the rollback path. Install V2 into its own directory under its own
service. Do not repurpose `scripts/deploy-pi.ps1`, which deploys V1's
`server/*.js`.

## What this does not do yet

The composed server is ready to receive a first real client; it is not a complete
lobby server.

- Connection purpose on TCP 10127 is a temporary heuristic. The evidence says
  purpose follows the first client frame, and the service's resolver runs before
  those bytes arrive, so every connection is treated as lobby initialization. A
  connection that opens with something else is refused, not mis-served.
- The captured server sends `0x6001` first on both connections. V2 does not.
- A second, `0x1007`-less connection is not implemented.
- `0x6501` is answered with mode 0 because mode 1 needs `0x6503`, which is not
  implemented. The captured sessions took mode 1. See OQ-016.
- UDP 9090 registration, rooms, chat, roster and gameplay are not composed.
- **The captured HTTP flow is not complete.** The capture shows the client
  posting to `/mhweb/enterareas` and `/mhweb/lbs_info`; V2 implements neither and
  routes to `/mhweb/lbs.jsp` instead. A real client may therefore stall in the
  browser flow before it ever opens TCP 10127. This is pre-existing, not
  introduced by the composition, but it is the most likely first divergence and
  is why "ready to receive a first real client" is a starting point rather than a
  guarantee that one gets through.
