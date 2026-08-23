#!/usr/bin/env pwsh
# deploy-pi.ps1 - SINGLE SOURCE OF TRUTH deploy: repo server/*.js -> Pi runtime.
#
# The repo's server/ is the authority. This script scp's the server .js files to
# the Pi, backs up the previous files, verifies md5 (repo == Pi), restarts the
# service, and prints the effective SNAP_* environment. It deliberately does NOT
# use C:\dnas\pal-deploy.git (the legacy push-hook flow that caused 3-way drift).
#
# Usage:
#   ./scripts/deploy-pi.ps1                 # deploy all server/*.js
#   ./scripts/deploy-pi.ps1 snap_server.js  # deploy specific file(s)
#
# After deploy, confirm repo md5 == Pi md5 in the output. Runtime FLAGS live in
# systemd drop-ins on the Pi (/etc/systemd/system/pal-server.service.d/*.conf) -
# see docs/runbooks/pi-deployment.md.

$ErrorActionPreference = 'Stop'
$repo = Split-Path -Parent $PSScriptRoot
$srv  = Join-Path $repo 'server'
# Rig-specific settings — override via environment (see docs/runbooks/pi-deployment.md).
$piUser = if ($env:PAL_PI_USER) { $env:PAL_PI_USER } else { 'pi' }
$piHost = if ($env:PAL_PI_HOST) { $env:PAL_PI_HOST } else { '192.0.2.121' }
$key  = if ($env:PAL_PI_SSH_KEY) { $env:PAL_PI_SSH_KEY } else { "$HOME/.ssh/pal_pi_ed25519" }
$pi   = "$piUser@$piHost"
$dst  = if ($env:PAL_PI_DST) { $env:PAL_PI_DST } else { "/home/$piUser/pal-server" }

$files = if ($args.Count) { $args } else { Get-ChildItem "$srv\*.js" | ForEach-Object Name }
Write-Host "Deploying to ${pi}:${dst}" -ForegroundColor Cyan
Write-Host ("Files: " + ($files -join ', '))

# 1) syntax-check locally
foreach ($f in $files) { node --check (Join-Path $srv $f); if ($LASTEXITCODE) { throw "node --check failed: $f" } }

# 2) backup current Pi files (timestamped)
$ts = Get-Date -Format 'yyyyMMdd-HHmmss'
$bk = ($files | ForEach-Object { "cp -f $_ $_.bak-$ts 2>/dev/null" }) -join ' ; '
ssh -i $key $pi "cd $dst && $bk && echo backed-up $ts"

# 3) copy
foreach ($f in $files) { scp -i $key (Join-Path $srv $f) "${pi}:${dst}/$f" }

# 4) verify md5 (repo == Pi), node --check on Pi, restart, show state
$names = $files -join ' '
Write-Host "=== repo md5 ===" -ForegroundColor Cyan
foreach ($f in $files) { (Get-FileHash -Algorithm MD5 (Join-Path $srv $f)).Hash.ToLower() + "  $f" }
Write-Host "=== Pi md5 + restart ===" -ForegroundColor Cyan
ssh -i $key $pi "cd $dst && md5sum $names && for f in $names; do node --check \$f || exit 1; done && sudo systemctl restart pal-server && sleep 1 && systemctl is-active pal-server"
Write-Host "=== effective SNAP_* env ===" -ForegroundColor Cyan
ssh -i $key $pi "systemctl show pal-server.service -p Environment | tr ' ' '\n' | grep -E 'SNAP_|SERVER_HOST_IP' | sort"
Write-Host "Done. Confirm repo md5 == Pi md5 above." -ForegroundColor Green
