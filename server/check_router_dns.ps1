param(
    [string[]]$Servers = @('192.0.2.1', '192.0.2.53')
)

$ErrorActionPreference = 'Stop'

$Names = @(
    'gate1.eu.dnas.playstation.org',
    'stage6.sega.com',
    'app01.reo.capcom.sf.yav4.com',
    'snap01.capcom.client.sf.yav4.com'
)

$OutDir = Join-Path (Split-Path $PSScriptRoot -Parent) 'captures\dns_probe'
New-Item -ItemType Directory -Force -Path $OutDir | Out-Null

$timestamp = Get-Date -Format 'yyyyMMdd_HHmmss'
$reportPath = Join-Path $OutDir "dns_probe_$timestamp.txt"

function Write-Report {
    param([string]$Line)
    $Line | Tee-Object -FilePath $reportPath -Append
}

Write-Report "DNS probe started: $(Get-Date -Format o)"
Write-Report "Servers: $($Servers -join ', ')"
Write-Report ''

foreach ($server in $Servers) {
    Write-Report ('=' * 72)
    Write-Report "Server: $server"

    $pingOk = $false
    try {
        $pingOk = Test-Connection -ComputerName $server -Count 1 -Quiet
        Write-Report "Ping: $pingOk"
    } catch {
        Write-Report "Ping error: $($_.Exception.Message)"
    }

    foreach ($name in $Names) {
        Write-Report ''
        Write-Report "Query: $name"
        try {
            $answers = Resolve-DnsName -Name $name -Server $server -Type A -DnsOnly -ErrorAction Stop
            $aRecords = $answers | Where-Object { $_.Type -eq 'A' }

            if ($aRecords) {
                foreach ($record in $aRecords) {
                    Write-Report "A: $($record.IPAddress)"
                }
            } else {
                Write-Report 'No A records returned'
                $answers | ForEach-Object {
                    Write-Report ("Raw: " + ($_ | Out-String).Trim())
                }
            }
        } catch {
            Write-Report "Resolve error: $($_.Exception.Message)"
        }
    }

    Write-Report ''
}

Write-Report "DNS probe finished: $(Get-Date -Format o)"
Write-Report "Report: $reportPath"
