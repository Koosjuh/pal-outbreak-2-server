[Environment]::SetEnvironmentVariable(
    "OPENAI_API_KEY",
    $null,
    "User"
)

Write-Host "OPENAI_API_KEY removed."
Write-Host "Restart VS Code."