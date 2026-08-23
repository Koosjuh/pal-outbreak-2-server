param(
    [string]$OutDir = (Join-Path (Split-Path $PSScriptRoot -Parent) 'captures\pktmon')
)

$ErrorActionPreference = 'Stop'
New-Item -ItemType Directory -Force -Path $OutDir | Out-Null

$stopOutput = pktmon stop 2>&1
$stopText = ($stopOutput | Out-String)
if ($LASTEXITCODE -ne 0 -and $stopText -match 'Access is denied') {
    throw "PktMon stop failed. Run PowerShell as Administrator. Output: $stopText"
}

$latestEtl = Get-ChildItem -Path $OutDir -Filter 'pktmon_*.etl' |
    Sort-Object LastWriteTime -Descending |
    Select-Object -First 1

if (-not $latestEtl) {
    Write-Output 'No pktmon ETL found'
    exit 0
}

Write-Output "PktMon capture stopped"
Write-Output "ETL: $($latestEtl.FullName)"

# 2026-05-30: auto-convert to pcapng so downstream tools can parse it.
$pcapPath = [System.IO.Path]::ChangeExtension($latestEtl.FullName, '.pcapng')
$convOutput = pktmon etl2pcap $latestEtl.FullName --out $pcapPath 2>&1
Write-Output "PCAPNG: $pcapPath"
if ($LASTEXITCODE -ne 0) {
    Write-Output "etl2pcap exit=$LASTEXITCODE output=$($convOutput | Out-String)"
} else {
    $size = (Get-Item $pcapPath).Length
    Write-Output "Converted OK ($size bytes)"
    Write-Output "Parse with: node C:\dnas\active\tools\extract_dns_from_pcap.js `"$pcapPath`""
}
