# Pi Deployment Runbook

The running server is the Raspberry Pi at `192.0.2.121`, not the dev repo.
Claude must treat the Pi runtime as the authority for what clients are actually
using.

## Authorities

- **Dev repo `D:\projects\pal-outbreak-2-server` is the SINGLE SOURCE OF TRUTH for code.**
  `server/*.js` is pinned to LF (`.gitattributes`) so repo md5 == Pi md5. Edit here, deploy
  with `scripts/deploy-pi.ps1`, and the repo always matches the runtime.
- Pi runtime: `/home/<pi-user>/pal-server/`.
- ⚠️ DEPRECATED: `C:\dnas\pal-deploy.git` + `C:\dnas\active\server` (the git-push-hook flow).
  This caused 3-way drift (area-names `snap_server.js` was scp'd to the Pi but never reached
  the deploy-git worktree, so `pi-deploy.ps1` would have clobbered it). Do NOT deploy via it.
  Deploy only from the repo with `scripts/deploy-pi.ps1`.
- SSH target: `<pi-user>@192.0.2.121`.
- SSH key: `C:/Users/<user>/.ssh/pal_pi_ed25519`.
- systemd service: `pal-server.service`.
- Runtime environment: `/etc/systemd/system/pal-server.service.d/*.conf`.

Do not infer deployed code from the dev repo `HEAD` or from
`tests/results/*/meta.json`. Verify Pi file hashes directly.

## Inspect Runtime

```powershell
ssh -i C:/Users/<user>/.ssh/pal_pi_ed25519 <pi-user>@192.0.2.121 "cd ~/pal-server && pwd && md5sum *.js 2>/dev/null; systemctl is-active pal-server; systemctl show pal-server.service -p Environment"
```

Read recent logs:

```powershell
ssh -i C:/Users/<user>/.ssh/pal_pi_ed25519 <pi-user>@192.0.2.121 "sudo journalctl -u pal-server.service --since '10 min ago' --no-pager"
```

Follow logs during a test:

```powershell
ssh -i C:/Users/<user>/.ssh/pal_pi_ed25519 <pi-user>@192.0.2.121 "sudo journalctl -u pal-server.service -f"
```

## Deploy Code

Deploy from the repo (single source of truth). The script backs up the Pi files,
scp's `server/*.js`, verifies repo md5 == Pi md5, `node --check`s, restarts, and
prints the effective env:

```powershell
./scripts/deploy-pi.ps1                 # all server/*.js
./scripts/deploy-pi.ps1 snap_server.js  # specific file(s)
```

Equivalent manual steps (what the script does) — back up the Pi file first, copy,
verify hashes, restart, and verify service state:

```powershell
ssh -i C:/Users/<user>/.ssh/pal_pi_ed25519 <pi-user>@192.0.2.121 "cd ~/pal-server && cp game_udp_server.js game_udp_server.js.bak-$(date +%Y%m%d-%H%M%S)"
scp -i C:/Users/<user>/.ssh/pal_pi_ed25519 C:/path/to/game_udp_server.js <pi-user>@192.0.2.121:/home/<pi-user>/pal-server/game_udp_server.js
ssh -i C:/Users/<user>/.ssh/pal_pi_ed25519 <pi-user>@192.0.2.121 "cd ~/pal-server && md5sum game_udp_server.js && node --check game_udp_server.js && sudo systemctl restart pal-server && systemctl is-active pal-server"
```

## Change Runtime Environment

Runtime flags live in systemd drop-ins. Add or remove a drop-in, reload systemd,
restart, then verify effective environment:

```powershell
ssh -i C:/Users/<user>/.ssh/pal_pi_ed25519 <pi-user>@192.0.2.121 "sudo systemctl daemon-reload && sudo systemctl restart pal-server && systemctl show pal-server.service -p Environment"
```

Rollback means removing the exact drop-in, reloading, restarting, and verifying
the effective environment no longer contains the experimental flag.

## Done Criteria

A deploy, rollback, or recovery claim is not accepted until Claude records:

- Intended deploy source or deploy-git ref.
- Pi file path changed.
- Pre-change backup path.
- Local source hash.
- Pi runtime hash after copy.
- `node --check` result for changed JavaScript.
- `systemctl is-active pal-server` result.
- Effective `SNAP_*` environment.
- Pi journal excerpt showing the restarted server.
