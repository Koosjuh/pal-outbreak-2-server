param(
    [string]$Hypothesis = "The OpenAI-backed second_opinion MCP path can execute an end-to-end review in this shell.",
    [string]$Question = "Does this direct call prove the second_opinion tool can reach OpenAI and return a structured review?"
)

$ErrorActionPreference = "Stop"

$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$repoRoot = Split-Path -Parent (Split-Path -Parent $scriptDir)

$env:PYTHONPATH = if ([string]::IsNullOrWhiteSpace($env:PYTHONPATH)) {
    $repoRoot
}
else {
    "$repoRoot;$env:PYTHONPATH"
}

$payload = @{
    hypothesis = $Hypothesis
    confidence = "High"
    evidence = @(
        @{
            source = "tools/outbreak_mcp/test-second-opinion.ps1"
            observation = "This script imports tools.outbreak_mcp.server.call_tool and directly calls call_tool('second_opinion', payload) in the current shell."
        }
        @{
            source = "setup-openai.ps1 test"
            observation = "OpenAI test returned OK with OPENAI_API_KEY visible in the current process before this direct call."
        }
    )
    question = $Question
} | ConvertTo-Json -Compress -Depth 6

$env:OUTBREAK_SECOND_OPINION_PAYLOAD = $payload

Push-Location $repoRoot
try {
    @'
import json
import os

from tools.outbreak_mcp.server import call_tool

payload = json.loads(os.environ["OUTBREAK_SECOND_OPINION_PAYLOAD"])
result = call_tool("second_opinion", payload)
required_keys = {
    "agreement",
    "confidence",
    "unsupported_assumptions",
    "alternative_explanations",
    "missing_evidence",
    "recommended_next_observation",
    "notes",
    "source_metadata",
}
metadata = result.get("source_metadata", {})
schema_ok = required_keys.issubset(result.keys())
local_validation = {
    "schema_keys_present": sorted(required_keys.intersection(result.keys())),
    "schema_ok": schema_ok,
    "openai_validation_passed": metadata.get("validation") == "passed",
    "source": metadata.get("source"),
    "second_opinion_operational": bool(schema_ok and metadata.get("validation") == "passed"),
}

print(json.dumps({
    "local_validation": local_validation,
    "second_opinion_result": result,
}, indent=2))
'@ | python -
}
finally {
    Pop-Location
    Remove-Item Env:\OUTBREAK_SECOND_OPINION_PAYLOAD -ErrorAction SilentlyContinue
}
