param(
    [ValidateSet("install", "status", "test", "rotate")]
    [string]$Command = "status"
)

$ErrorActionPreference = "Stop"

$ScriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$ConfigPath = Join-Path $ScriptDir "openai.json"

function Read-OpenAIConfig {
    if (-not (Test-Path -LiteralPath $ConfigPath)) {
        throw "Missing OpenAI config: $ConfigPath"
    }
    Get-Content -LiteralPath $ConfigPath -Raw | ConvertFrom-Json
}

function Get-OpenAIKeyStatus {
    $userKey = [Environment]::GetEnvironmentVariable("OPENAI_API_KEY", "User")
    $processKey = [Environment]::GetEnvironmentVariable("OPENAI_API_KEY", "Process")
    [pscustomobject]@{
        UserConfigured = -not [string]::IsNullOrWhiteSpace($userKey)
        ProcessAvailable = -not [string]::IsNullOrWhiteSpace($processKey)
    }
}

function Set-OpenAIKey {
    Write-Host ""
    $secureKey = Read-Host "Enter your OpenAI API Key" -AsSecureString
    $ptr = [System.Runtime.InteropServices.Marshal]::SecureStringToBSTR($secureKey)
    try {
        $plainKey = [System.Runtime.InteropServices.Marshal]::PtrToStringBSTR($ptr)
    }
    finally {
        [System.Runtime.InteropServices.Marshal]::ZeroFreeBSTR($ptr)
    }

    if ([string]::IsNullOrWhiteSpace($plainKey)) {
        throw "No API key entered."
    }

    if ($plainKey -notmatch '^sk-[A-Za-z0-9_\-]+$') {
        Write-Warning "The API key does not match the usual OpenAI key prefix/shape."
        $answer = Read-Host "Continue anyway? (y/N)"
        if ($answer -ne "y") {
            throw "Key installation cancelled."
        }
    }

    [Environment]::SetEnvironmentVariable("OPENAI_API_KEY", $plainKey, "User")
    Write-Host "OPENAI_API_KEY saved to the user environment."
    Write-Host "Open a new terminal before using outbreak-tools."
}

function Show-Status {
    $config = Read-OpenAIConfig
    $keyStatus = Get-OpenAIKeyStatus
    $usageLogPath = [System.IO.Path]::GetFullPath((Join-Path (Split-Path -Parent (Split-Path -Parent $ScriptDir)) $config.usage_log))
    [pscustomobject]@{
        ConfigPath = $ConfigPath
        Enabled = [bool]$config.enabled
        Model = $config.model
        Endpoint = $config.endpoint
        MonthlyBudgetUsd = $config.monthly_budget_usd
        StopAtUsd = $config.stop_at_usd
        UsageLog = $config.usage_log
        UsageLogAvailable = (Test-Path -LiteralPath $usageLogPath)
        ErrorLog = $config.error_log
        ApiKeyInUserEnvironment = $keyStatus.UserConfigured
        ApiKeyInCurrentProcess = $keyStatus.ProcessAvailable
    } | ConvertTo-Json -Depth 4
}

function Estimate-RequestCost {
    param(
        [string]$Prompt,
        [int]$MaxOutputTokens,
        $Config
    )
    $inputTokens = [Math]::Max(1, [Math]::Ceiling($Prompt.Length / 4))
    $inputCost = 0.15
    $outputCost = 0.60
    if ($Config.estimated_cost_per_1m_tokens) {
        if ($Config.estimated_cost_per_1m_tokens.input_usd) {
            $inputCost = [double]$Config.estimated_cost_per_1m_tokens.input_usd
        }
        if ($Config.estimated_cost_per_1m_tokens.output_usd) {
            $outputCost = [double]$Config.estimated_cost_per_1m_tokens.output_usd
        }
    }
    (($inputTokens / 1000000.0) * $inputCost) + (($MaxOutputTokens / 1000000.0) * $outputCost)
}

function Test-OpenAI {
    $config = Read-OpenAIConfig
    $keyStatus = Get-OpenAIKeyStatus
    if (-not [bool]$config.enabled) {
        Write-Host "OpenAI is disabled in openai.json. No API request made."
        return
    }
    $apiKey = [Environment]::GetEnvironmentVariable("OPENAI_API_KEY", "Process")
    if ([string]::IsNullOrWhiteSpace($apiKey)) {
        $apiKey = [Environment]::GetEnvironmentVariable("OPENAI_API_KEY", "User")
    }
    if ([string]::IsNullOrWhiteSpace($apiKey)) {
        throw "OPENAI_API_KEY is not configured."
    }

    $prompt = "Reply with exactly OK."
    $maxOutputTokens = 16
    $body = @{
        model = $config.model
        input = $prompt
        max_output_tokens = $maxOutputTokens
    } | ConvertTo-Json -Depth 4
    $headers = @{
        Authorization = "Bearer $apiKey"
        "Content-Type" = "application/json"
    }
    $uri = $config.endpoint
    $sw = [System.Diagnostics.Stopwatch]::StartNew()
    $response = Invoke-RestMethod -Method Post -Uri $uri -Headers $headers -Body $body -TimeoutSec 30
    $sw.Stop()
    $text = $response.output_text
    if ([string]::IsNullOrWhiteSpace($text) -and $response.output) {
        $parts = @()
        foreach ($item in $response.output) {
            foreach ($content in $item.content) {
                if ($content.text) {
                    $parts += $content.text
                }
            }
        }
        $text = ($parts -join "`n")
    }
    [pscustomobject]@{
        Status = "ok"
        Enabled = [bool]$config.enabled
        Model = $config.model
        ResponseText = $text
        LatencyMs = $sw.ElapsedMilliseconds
        EstimatedCostUsd = [Math]::Round((Estimate-RequestCost -Prompt $prompt -MaxOutputTokens $maxOutputTokens -Config $config), 8)
        ApiKeyInUserEnvironment = $keyStatus.UserConfigured
        ApiKeyInCurrentProcess = $keyStatus.ProcessAvailable
    } | ConvertTo-Json -Depth 4
}

Write-Host ""
Write-Host "========================================"
Write-Host " Outbreak Tools - OpenAI Configuration"
Write-Host "========================================"
Write-Host ""

switch ($Command) {
    "install" { Set-OpenAIKey }
    "rotate" { Set-OpenAIKey }
    "status" { Show-Status }
    "test" { Test-OpenAI }
}
