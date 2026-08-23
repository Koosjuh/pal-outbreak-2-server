# outbreak-tools MCP Server

> **Tool set pruned to 18 (2026-07-04)** — the dead debugger/dev9 stubs and the legacy orchestration
> fact-store tools were removed (retired in favor of `FACTS.md`/`GOALS.md`). The **authoritative tool
> list** is `python tools/mcp-status.py` or the MCP `tools/list`. Descriptions below that reference
> removed tools are stale — treat this README as background, not the registry.

`outbreak-tools` is a local stdio MCP server for evidence-first PAL Outbreak 2
protocol investigation. It does not change server behavior. The optional
`second_opinion` tool can call OpenAI only when explicitly enabled in
`tools/outbreak_mcp/openai.json` and `OPENAI_API_KEY` is present in the user
environment.

## Requirements

- Python 3.12 or newer.
- `tshark` on `PATH` for pcap tools. On Windows, the server also checks the
  standard Wireshark install directories under `Program Files`.
- Windows-friendly paths are supported. In MCP JSON examples, use forward slashes.

## Claude MCP Config

Add this server to Claude's MCP configuration:

```json
{
  "mcpServers": {
    "outbreak-tools": {
      "command": "python",
      "args": [
        "D:/projects/pal-outbreak-2-server/tools/outbreak_mcp/server.py"
      ],
      "cwd": "D:/projects/pal-outbreak-2-server"
    }
  }
}
```

## Tools

- `pcap_timeline`: parse UDP `9090` packets with `tshark`, decode the first
  SN@P header bytes, and report payload hashes.
- `extract_opcode_packets`: extract packets matching one SN@P opcode.
- `compare_snapshots`: compare text snapshots from the current snapshot tools.
- `resolve_symbol`: resolve a name or address through `symbols.json`.
- `symbol_audit`: audit symbol metadata, duplicate names/addresses, low-confidence
  references, and typo-prone close addresses.
- `decode_snapshot_symbols`: decode known typed fields from a text snapshot using
  `symbols.json`.
- `query_evidence_graph`: query a sparse graph linking opcodes, functions,
  memory symbols, evidence files, unknowns, and assumptions.
- `drive_compare`: compare two drive artifact directories for pcaps, snapshots,
  logs, opcode sequences, and matching snapshot summaries.
- `evidence_report`: produce a Markdown report separating facts, unknowns,
  inferences, assumptions, and the next observation.
- `second_opinion`: request a stateless OpenAI-backed evidence review for one
  structured hypothesis. It is not a general chat interface and refuses cleanly
  when disabled, over budget, or missing `OPENAI_API_KEY`.
- `get_project_state`, `get_current_milestone`, `get_verified_facts`,
  `get_open_tasks`, `get_recent_commits`, `get_last_validation`,
  `get_open_hypotheses`: read durable orchestration memory.
- `store_fact`, `store_decision`, `store_hypothesis`, `archive_hypothesis`,
  `complete_task`, `record_validation`: append durable memory records.
- `prepare_re_session`, `validate_re_evidence`, `summarize_for_next_session`,
  `agentic_re_step`, `continue_project`: shared Claude/Codex evidence-driven
  RE workflow helpers. `continue_project` reads durable state and recommends
  the next smallest safe action without assuming the current blocker.
- `start_drive_session`, `collect_drive_evidence`,
  `prepare_manual_debugger_drive`, `finalize_drive_report`, `archive_drive`,
  `compare_drive_bundle`: one-command drive workflow automation.
- `ghidra_ps2_plugin_status`: report detectable Ghidra PS2/EE/R5900 support
  status without modifying Ghidra projects.

### Orchestration Layer

Phase 6 adds durable memory and workflow automation under
`docs/orchestration/`. Chat history is not durable project state. Facts,
tasks, decisions, hypotheses, and validation records are append-only JSONL files
with generated Markdown summaries.

The orchestration tools are for Claude and Codex. They enforce the same rules:

- Do not store assumptions as facts.
- Poke-based results are diagnostics, never proof.
- Emulator-only success is not real PS2 success.
- Protocol/server changes require direct packet, debugger, memory, or binary
  evidence.
- Every significant action requires `second_opinion` using
  `docs/orchestration/PROCESS_GUARDIAN.md`; confidence does not waive review.

Start an agentic RE step:

```powershell
python tools/outbreak_mcp/server.py call agentic_re_step "{\"objective\":\"Identify the first unanswered or mis-answered lobby protocol message.\",\"mode\":\"investigate\",\"allow_code_changes\":false}"
```

Resume from durable project state:

```powershell
python tools/outbreak_mcp/server.py call continue_project "{\"objective\":\"Continue PAL lobby investigation\",\"mode\":\"investigate\",\"allow_code_changes\":false}"
```

### AI Consultation Layer

`second_opinion` sends only structured JSON supplied to the tool. The MCP server
constructs the prompt, enforces budget checks, and logs sanitized usage metadata
to `tools/outbreak_mcp/logs/openai_usage.jsonl`. API keys are never stored in
Git, source code, `openai.json`, README, or logs.

Configuration lives in `tools/outbreak_mcp/openai.json`. Secrets do not belong
there. The only supported secret source is the user environment variable
`OPENAI_API_KEY`.

OpenAI setup helper:

```powershell
tools/outbreak_mcp/setup-openai.ps1 status
tools/outbreak_mcp/setup-openai.ps1 install
tools/outbreak_mcp/setup-openai.ps1 test
tools/outbreak_mcp/setup-openai.ps1 rotate
```

Use `tools/outbreak_mcp/remove-openai.ps1` to remove the user environment
variable.

### Runtime Evidence Platform

Phase 3 extends the same `outbreak-tools` server with runtime evidence tools.
These tools degrade explicitly when PCSX2 automation is unavailable. They do not
change server behavior and do not treat runtime state as protocol proof without
PCAP correlation.

Evidence reliability order:

1. PCAP
2. Runtime debugger/registers
3. PINE memory
4. DEV9 logs
5. Screenshots
6. Savestates

Savestates are convenience only and are never protocol proof.

Runtime tools:

- `discover_debugger_capabilities`: inspect local PCSX2 command-line/debugger
  automation evidence.
- `debugger.pause`, `debugger.resume`, `debugger.step`,
  `debugger.step_over`, `debugger.get_pc`, `debugger.get_registers`,
  `debugger.break_exec`, `debugger.break_read`, `debugger.break_write`,
  `debugger.remove_breakpoint`, `debugger.wait_for_break`: debugger abstraction
  tools. They currently return `Unavailable` unless a debugger backend is proven.
- `session_fingerprint`: collect PCSX2/PINE/session metadata with Unknowns kept
  explicit.
- `capture_runtime_evidence`: assemble session, debugger, PINE, snapshot, PCAP,
  screenshot, and DEV9 evidence as structured JSON.
- `pine_health_check`: validate PINE reachability, status, a known address read,
  and a known symbol read.
- `savestate_health_check`: validate savestate workflow only when explicitly
  allowed; save/load is skipped by default.
- `dev9_status`, `dev9_log_tail`, `dev9_collect_logs`: discover and read DEV9 or
  PCSX2 log evidence when available.
- `capture_screenshot`: screenshot abstraction; currently reports unavailable
  unless a proven backend is added.
- `runtime_health_check`: summarize Debugger, PINE, DEV9, PCAP, Savestates, and
  screenshot readiness.
- `load_breakpoint_profile`: load JSON breakpoint profiles from
  `tools/outbreak_mcp/profiles/`.
- `debugger_backend_research`: inspect installed PCSX2 files, user debugger
  layouts, binary strings, config files, and PINE command coverage for a proven
  debugger automation backend.
- `debugger_manual_capture_template`: generate manual PCSX2 debugger breakpoint
  and register capture instructions.
- `prepare_manual_debugger_session`: generate the full one-command manual
  capture package: UI steps, breakpoint address, register list, paste format,
  and latest packet context.
- `validate_manual_debugger_capture`: parse and validate pasted manual register
  text before ingestion.
- `ingest_debugger_registers`: store manually captured register values as JSONL
  evidence.
- `correlate_debugger_capture`: correlate manual debugger evidence with symbols
  and a PCAP timeline.

Each runtime evidence source includes metadata:

```json
{
  "source": "PINE",
  "validation": "passed",
  "reliability": "Medium",
  "confidence": "High"
}
```

Failure policy: if a runtime component fails twice inside one MCP server
session, that component is disabled for the session and the tools continue with
remaining evidence sources.

## Sample MCP Tool Calls

`pcap_timeline`:

```json
{
  "pcap_path": "D:/projects/pal-outbreak-2-server/docs/evidence/pcaps/2026_05_30_14_10_30_WIRESHARK_REALPS2_192_0_2_129.pcapng",
  "udp_port": 9090
}
```

`resolve_symbol`:

```json
{
  "name_or_address": "lobby.state"
}
```

`symbol_audit`:

```json
{
  "category": "snapshot",
  "min_confidence": "Low"
}
```

`query_evidence_graph`:

```json
{
  "query": "opcode 0x0001"
}
```

`drive_compare`:

```json
{
  "drive_a": "D:/projects/pal-outbreak-2-server/tests/results/baseline",
  "drive_b": "D:/projects/pal-outbreak-2-server/tests/results/state"
}
```

`second_opinion`:

```json
{
  "hypothesis": "Opcode 0x000c is related to the room list update.",
  "confidence": "Low",
  "evidence": [
    {
      "source": "pcap_timeline",
      "packet_numbers": [143922, 143924],
      "observation": "Repeated client-to-server opcode 0x000c packets."
    }
  ],
  "question": "What assumption is weakest, and what is the next observation?"
}
```

## Direct Local Testing

List tools:

```powershell
python tools/outbreak_mcp/server.py list-tools
```

Resolve a symbol:

```powershell
python tools/outbreak_mcp/server.py call resolve_symbol "{\"name_or_address\":\"lobby_state\"}"
```

Audit symbols:

```powershell
python tools/outbreak_mcp/server.py call symbol_audit "{}"
```

Decode a snapshot:

```powershell
python tools/outbreak_mcp/server.py call decode_snapshot_symbols "{\"snapshot_path\":\"D:/path/to/snapshot.txt\"}"
```

Query evidence graph:

```powershell
python tools/outbreak_mcp/server.py call query_evidence_graph "{\"query\":\"opcode 0x0001\"}"
```

Runtime health:

```powershell
python tools/outbreak_mcp/server.py call runtime_health_check "{}"
```

Second opinion, disabled-mode graceful failure:

```powershell
python tools/outbreak_mcp/server.py call second_opinion "{\"hypothesis\":\"Opcode 0x000c is related to the room list update.\",\"confidence\":\"Low\",\"evidence\":[{\"source\":\"pcap_timeline\",\"packet_numbers\":[143922],\"observation\":\"client-to-server opcode 0x000c\"}],\"question\":\"What evidence is missing?\"}"
```

Debugger capability discovery:

```powershell
python tools/outbreak_mcp/server.py call discover_debugger_capabilities "{}"
```

PINE health:

```powershell
python tools/outbreak_mcp/server.py call pine_health_check "{\"known_symbol\":\"conn.pointer\"}"
```

Load a breakpoint profile:

```powershell
python tools/outbreak_mcp/server.py call load_breakpoint_profile "{\"name\":\"connecting\"}"
```

Research debugger backend:

```powershell
python tools/outbreak_mcp/server.py call debugger_backend_research "{}"
```

Generate manual debugger capture form:

```powershell
python tools/outbreak_mcp/server.py call debugger_manual_capture_template "{\"target_symbol\":\"sub_5bc430\",\"compare_target\":\"sub_5bc4a8\"}"
```

Prepare manual debugger session:

```powershell
python tools/outbreak_mcp/server.py call prepare_manual_debugger_session "{\"target\":\"sub_5bc430\",\"compare_address\":\"0x005bc4a8\",\"label\":\"cmd0c-manual\"}"
```

Validate pasted register text:

```powershell
python tools/outbreak_mcp/server.py call validate_manual_debugger_capture "{\"pasted_register_capture\":\"capture_id=cmd0c-manual`ntarget=sub_5bc430`npc=0x005bc430`nra=0x00000000`nsp=0x00000000`na0=0x00000000`nv1=0x00000000`ns0=0x00000000`ns2=0x00000000\"}"
```

Ingest manual register evidence:

```powershell
python tools/outbreak_mcp/server.py call ingest_debugger_registers "{\"capture_id\":\"manual-test\",\"target_symbol\":\"sub_5bc430\",\"registers\":{\"pc\":\"0x005bc430\",\"ra\":\"0x00000000\",\"sp\":\"0x00000000\",\"a0\":\"0x00000000\",\"v1\":\"0x00000000\",\"s0\":\"0x00000000\",\"s2\":\"0x00000000\"}}"
```

Run a packet timeline outside Claude:

```powershell
python tools/outbreak_mcp/server.py call pcap_timeline "{\"pcap_path\":\"D:/projects/pal-outbreak-2-server/docs/evidence/pcaps/2026_05_30_14_10_30_WIRESHARK_REALPS2_192_0_2_129.pcapng\",\"udp_port\":9090}"
```

If `tshark` is missing, packet tools fail with an explicit error.
