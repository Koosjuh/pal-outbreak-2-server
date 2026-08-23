# Server

Migrated from the legacy `C:\dnas\active\server` workspace. Node.js stack that
emulates the PAL Resident Evil Outbreak File #2 online services.

## Running

`start_all.js` launches the whole stack (must be Administrator — privileged
ports). Use `START_SERVERS.bat` (self-elevates) or `node start_all.js`.

Services launched:

| Service | Port | File |
|---|---|---|
| DNS | 53/udp | `dns_server.js` |
| DNAS | 443 | `dnas_server.js` |
| HTTP | 80 | `http_server.js` |
| SN@P | 10127 | `snap_server.js` |
| GAME | 9090/udp | `game_udp_server.js` |
| SNOOP | 38745+ | `snoop_listener.js` |

Helpers: `blowfish.js`, `host_ip.js`, `run_id.js`, `session_store.js`.
Data/config: `accounts.json`, `session_store.json`, `site_content.json`.
`variants/` holds alternate `http_server` implementations (`-Claude`, `-codex`).
`assets/web/` holds the web UI images. `check_router_dns.ps1`,
`start_pktmon_capture.ps1`, `stop_pktmon_capture.ps1`, `RUN_PCSX2_AUTH_TRACE.bat`
are diagnostic/capture helpers.

## DNS

DNS resolution is handled by the **UniFi gateway**, not by `dns_server.js`. The
game hostnames are pointed at this host via UniFi DNS records. `dns_server.js`
will usually fail to bind `:53` (`EADDRINUSE`) because UniFi owns it — that is
expected, not an error. If a hostname does not resolve, fix the record on UniFi.

## Secrets (not tracked)

`certs/` (`server.key`, `server.crt`, `ca-cert.pem`) and `accounts.json` are
**git-ignored** — present on disk for local runs but never committed (per
`AGENTS.md` and `docs/decisions/ADR-0003`). They are disposable, non-production
dev credentials; do not reuse them in production. If you clone this repo fresh,
regenerate `certs/` and create `accounts.json` locally.
