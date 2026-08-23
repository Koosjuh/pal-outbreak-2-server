# Runtime Evidence Platform

## Status

Phase 3 adds runtime evidence collection to the existing `outbreak-tools` MCP
server. It is tooling only. It must not modify Resident Evil Outbreak protocol
handling or server behavior.

## Architecture

The runtime platform extends one MCP server:

```text
tools/outbreak_mcp/server.py
```

Runtime modules exposed through MCP tools:

- `debugger`: abstraction layer for pause/resume/step/register/breakpoint tools.
- `pine`: PINE reachability and diagnostic memory-read health checks.
- `runtime_capture`: structured evidence bundles.
- `dev9`: DEV9/PCSX2 log discovery and tailing.
- `savestates`: explicit savestate validation with mutation disabled by default.
- `session`: session fingerprinting.
- `health`: combined readiness checks and failure policy status.

The rest of `outbreak-tools` should call the debugger abstraction, not
PCSX2-specific APIs directly.

## Evidence Hierarchy

Use this reliability order when interpreting observations:

1. PCAP: primary protocol evidence.
2. Runtime debugger/registers.
3. PINE memory.
4. DEV9 logs.
5. Screenshots.
6. Savestates.

Savestates are convenience only. They are never protocol proof.

## Debugger Discovery

`discover_debugger_capabilities` inspects local PCSX2 executable candidates and
their command-line help/version output. It records what was directly observed.

Current expected behavior:

- If a PCSX2 executable is found, the path is reported as Verified.
- If command-line help is readable, supported flags are reported.
- Debugger automation, register access, execution breakpoints, and memory
  breakpoints remain `Unavailable` unless a concrete automation backend is
  proven.

This prevents treating a non-firing breakpoint or missing register read as a
semantic conclusion. It is a tooling capability issue first.

## Phase 4A Debugger Backend Status

Status: `Unavailable` for external debugger automation.

Evidence collected by `debugger_backend_research`:

- Installed executables are present at `C:\Program Files\PCSX2\pcsx2-qt.exe`
  and `vendor/pcsx2/pcsx2-qt.exe`.
- `--help` and `--version` probes did not produce usable command-line
  debugger output in the Phase 3/4A local runtime; they timed out.
- Packaged PCSX2 docs contain license/game-index material, not debugger API
  documentation.
- `C:\Users\<user>\Documents\PCSX2\inis\PCSX2.ini` contains debugger layout and
  debugger settings paths plus PINE settings.
- `C:\Users\<user>\Documents\PCSX2\inis\debuggerlayouts\R5900.json` contains UI
  panes such as `BreakpointView`, `DisassemblyView`, `RegisterView`, and
  `MemoryView`.
- Binary strings in `pcsx2-qt.exe` contain debugger UI classes/actions such as
  `DebuggerWindow`, `DebuggerView`, `RegisterView`, `BreakpointDialog`,
  `BreakpointModel`, `toggleBreakpoint`, `onStepInto`, and `onStepOver`.
- PINE support is proven for memory/status/savestate metadata commands through
  `tools/pine/pine_client.js`, but that client exposes no register or breakpoint
  opcodes.

Conclusion:

- PCSX2 has a manual debugger UI.
- PINE is an IPC/memory channel, not a proven debugger-control backend.
- No GDB, Lua, command-line, socket, named-pipe, or documented debugger IPC
  backend is proven in this repository/runtime.
- GUI automation is not used because it is not explicitly approved and would be
  fragile.

## Manual Debugger Workflow

Use this fallback when debugger automation is unavailable:

1. Run `pcap_timeline` and identify the exact packet question.
2. Run `prepare_manual_debugger_session` for the target symbol.
3. Open the PCSX2 debugger manually.
4. Select the EE/R5900 debugger target.
5. Set an execution breakpoint at the resolved target address.
6. Run until the breakpoint fires.
7. Capture registers `a0`, `v1`, `s0`, `s2`, `pc`, `ra`, and `sp`.
8. Run `validate_manual_debugger_capture` on the pasted values.
9. Run `ingest_debugger_registers` with those values after validation passes.
10. Run `correlate_debugger_capture` with the capture ID and related PCAP.

Manual debugger evidence must be labelled `Manual`, not `Automated`.

Primary Phase 4A target:

- `sub_5bc430` -> `room.cmd0cConsumer_5bc430` (`Inferred`)

Compare target:

- `sub_5bc4a8` -> `room.cmd0cManualCompare_5bc4a8` (`Low` / `Unknown`)

Manual evidence does not justify server changes by itself. It must be correlated
with exact PCAP packets and expected client state transition.

Supported paste format:

```text
capture_id=cmd0c-manual
target=sub_5bc430
pcap=D:/projects/pal-outbreak-2-server/tests/results/.../capture.pcapng
packets=435
pc=0x005bc430
ra=0x00000000
sp=0x00000000
a0=0x00000000
v1=0x00000000
s0=0x00000000
s2=0x00000000
notes=
```

## Health Model

Each runtime source emits reliability metadata:

```json
{
  "source": "PINE",
  "validation": "passed",
  "reliability": "Medium",
  "confidence": "High"
}
```

Classifications:

- `Verified`: directly observed by the tool.
- `Inferred`: derived from observed tool behavior.
- `Unknown`: not proven or unavailable.
- `Assumption`: explicit working assumption.

## Failure Policy

Each MCP server process tracks runtime component failures. If a component fails
twice in one session:

- the component is disabled for that session;
- the reason is included in tool output;
- collection continues with remaining sources;
- the tool must not retry indefinitely;
- the tool must not silently ignore the failure.

This currently applies to PINE, DEV9, debugger, screenshots, and savestates.

## Runtime Capture

`capture_runtime_evidence` combines:

- `session_fingerprint`
- debugger PC/register results if available
- PINE health
- typed snapshot decode if a snapshot path is supplied
- optional screenshot attempt
- latest known PCAP path
- latest known DEV9/PCSX2 log path
- timestamp

The output is structured JSON. It is an evidence bundle, not a protocol
conclusion.

## Savestate Policy

`savestate_health_check` does not save or load by default. Save/load requires:

```json
{
  "allow_mutation": true
}
```

Even when save/load succeeds, networking and protocol behavior must be validated
again with PCAP evidence.

## Workflow

Use runtime evidence only after the packet question is anchored:

1. Run `pcap_timeline`.
2. Identify the unanswered or mis-answered packet.
3. Run `runtime_health_check`.
4. Run `session_fingerprint`.
5. Capture PINE/debugger/DEV9 evidence only for the specific packet/state
   question.
6. Form one hypothesis.
7. Run one intervention per drive, if an intervention is justified.

No proposed server change is valid without an exact PCAP packet, memory state,
and expected client transition.
