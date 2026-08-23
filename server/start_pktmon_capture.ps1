param(
    [string]$OutDir = (Join-Path (Split-Path $PSScriptRoot -Parent) 'captures\pktmon')
)

$ErrorActionPreference = 'Stop'
New-Item -ItemType Directory -Force -Path $OutDir | Out-Null

$timestamp = Get-Date -Format 'yyyyMMdd_HHmmss'
$etlPath = Join-Path $OutDir "pktmon_$timestamp.etl"
$metaPath = Join-Path $OutDir "pktmon_$timestamp.txt"

pktmon stop | Out-Null
pktmon filter remove | Out-Null

# 2026-05-30: WIDENED CAPTURE — capture ALL IPv4 + ARP traffic.
# We discovered that press-X attempts a connection to an unknown destination
# (the 612-byte UDP packet seen at PCSX2 timestamp 81486.6 went somewhere we
# don't log). To find what hostname/port it targets, we need every packet —
# DNS queries (even those answered by UniFi at the router), TCP SYN attempts
# to any port, UDP to any port, ICMP replies, ARP. A single IPv4 filter +
# a single ARP filter catches it all. Pktmon ORs filters, so this widens
# capture without missing anything.
pktmon filter add ipv4_all -d IPv4 | Out-Null
pktmon filter add arp_all  -d ARP  | Out-Null

@(
    "started_at=$(Get-Date -Format o)"
    "etl_path=$etlPath"
    "filters=IPv4 + ARP (all-traffic capture)"
    "notes=widened from port-list to catch unknown press-X destination port; press-X uses uRam0035ba98 (4-byte IP) and port arg 0xcaf3=51955 (or whatever's in the lobby-entry struct +0x310)"
    "real_ps2_ip=unknown_specify_in_handoff"
) | Set-Content -Path $metaPath

$startOutput = pktmon start --capture --pkt-size 0 --file-name $etlPath 2>&1
$startText = ($startOutput | Out-String)
if ($LASTEXITCODE -ne 0 -or $startText -match 'Access is denied') {
    throw "PktMon start failed. Run PowerShell as Administrator. Output: $startText"
}

Write-Output "PktMon capture started"
Write-Output "ETL: $etlPath"
Write-Output "META: $metaPath"
