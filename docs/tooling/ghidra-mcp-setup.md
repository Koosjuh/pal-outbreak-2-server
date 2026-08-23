# Ghidra MCP server — live decompiler access for Claude Code

Gives Claude Code **direct, live access to the Ghidra decompiler** (decompile any
function, list xrefs/callers/callees, search symbols, resolve runtime addresses, rename)
instead of grepping stale text dumps in `analysis/`. Built on LaurieWired's
[GhidraMCP](https://github.com/LaurieWired/GhidraMCP) (v1.4).

## What's installed (already done, reusable)
| Piece | Path |
|---|---|
| Downloaded release | `C:\dnas\tools\ghidra-mcp\GhidraMCP-release-1-4\` (`bridge_mcp_ghidra.py` + `GhidraMCP-1-4.zip`) |
| **Extension, patched for Ghidra 12.0.4** | `C:\dnas\tools\ghidra-mcp\GhidraMCP-12.0.4.zip` |
| Python bridge (stdio MCP server) | `…\GhidraMCP-release-1-4\bridge_mcp_ghidra.py` (deps `mcp`,`requests` installed for Python 3.12) |
| Claude Code registration | `.mcp.json` at repo root → server name **`ghidra`**, talks to `http://127.0.0.1:8080/` |

Environment: Ghidra **12.0.4** at `C:\dnas\tools\ghidra\ghidra` (run `ghidraRun.bat`),
Java 21, Python 3.12 (`C:\Program Files\Python312\python.exe`). The release extension
declared `ghidraVersion=11.3.2`; we repatched it to `12.0.4` (GhidraMCP uses stable
decompiler/listing APIs, so the bump normally works — fallback below if not).

## ONE-TIME: install the extension into Ghidra (GUI, you do this)
1. Launch Ghidra (`C:\dnas\tools\ghidra\ghidra\ghidraRun.bat`).
2. Project window → **File → Install Extensions** → **`+`** (Add) → select
   `C:\dnas\tools\ghidra-mcp\GhidraMCP-12.0.4.zip` → OK → tick `GhidraMCP` → OK.
3. **Restart Ghidra** when prompted.
4. Open the program in CodeBrowser (see "which program" below). When prompted to configure
   the new plugin click **Yes**, or enable it via **File → Configure → Developer (or
   Miscellaneous) → check `GhidraMCPPlugin`**. The embedded HTTP server then listens on
   **`127.0.0.1:8080`** whenever a program is open.

### Which program to open
The SLES_533.19 EE analysis lives in the existing projects under
`ghidra-projects/` — primary: `ghidra-projects/legacy/ghidra_pal_ee.gpr` (EE main) and
`ghidra-projects/pal_codex_op48/pal_snap.gpr` (SN@P). Open whichever holds the function
you need (the `0x5bxxxx` overlay + SN@P `0x1dxxxx` are in the EE image).

## EACH SESSION: start order
1. **Start Ghidra**, open the project + the program (CodeBrowser). Leave it open.
2. Verify the HTTP server: `curl http://127.0.0.1:8080/methods` (should return a list of
   GhidraMCP endpoints). If it refuses connection, the plugin isn't enabled / no program
   open.
3. **(Re)start Claude Code** in this repo — it reads `.mcp.json`, spawns the bridge, and
   the `ghidra` MCP tools appear (decompile_function, list_methods, xrefs_to, etc.).
   Check with `/mcp` or by listing tools.

## Verify end-to-end
Ask Claude to `decompile_function` for a known address, e.g. `FUN_005bca90` /
`0x005bca90`. A correct live decompile (matching `analysis/claude-helper-module-full…`)
confirms the whole chain works.

## If the patched 11.3.2 extension won't load on Ghidra 12
Ghidra 12 is a major bump; if the API moved, the plugin may fail to load or some endpoints
error. Then **build GhidraMCP from source against 12.0.4**:
- `git clone https://github.com/LaurieWired/GhidraMCP`, set `GHIDRA_INSTALL_DIR=C:\dnas\tools\ghidra\ghidra`,
  `mvn clean package` → use the freshly built `target/GhidraMCP-*.zip`.
- Or, last resort, keep using the `analysis/` dumps + targeted `analyzeHeadless` scripts
  (`C:\dnas\active\ghidra_scripts\`) for missing functions.

## Why this exists
Reversing the `0x5bxxxx` select→join overlay (see
`docs/reverse-engineering/experiments/overlay-join-statemachine-map-2026-06-11.md`)
requires following callback chains and resolving runtime addresses across functions that
aren't all in the May text dumps. Live decompiler access removes that bottleneck. Reusable
for all future RE on this project.
