# AGENTS.md

> **Operating rules now live in `CLAUDE.md`** (reformed 2026-07-04); goals in `GOALS.md`; confirmed
> facts in `FACTS.md` (CURRENT MODEL section). Those are the source of truth — where anything below
> conflicts, they win. The detailed rules below are kept for reference but were largely superseded by
> the concise CLAUDE.md reform (goal-oriented · one goal per session · git why/what · verify-before-met).

## Mission

Restore and document PAL Resident Evil Outbreak File #2 private server behavior in a controlled, auditable, reproducible way.

The primary target client is:

* Resident Evil Outbreak File #2
* PAL version
* SLES_533.19

This repository exists to support protocol research, server implementation, testing, documentation, and evidence tracking.

## Repository Scope

This repository may contain:

* Server source code
* Test code
* Helper scripts
* Protocol notes
* Reproducible test plans
* Findings
* Decision records
* Sanitized logs
* Curated evidence references

This repository must not contain:


* Credentials
* Private keys
* Production secrets

## Required Files to Read Before Work

Before making changes, read:

* `AGENTS.md`
* `README.md`
* `docs/current-status.md`
* `docs/open-questions.md`
* `docs/blocking-issues.md`
* `docs/test-plan.md`

If protocol behavior is being changed, also read:

* `docs/runbooks/packet-analysis-workflow.md`
* Relevant files under `docs/findings/protocol/`
* Relevant decision records under `docs/decisions/`

## Core Working Rules

* Make small, reviewable changes.
* Use Git for every meaningful change.
* If something is needed but you are constrained we must talk and make the decission together for me to remove the constraint or find another way.
* Do not rewrite Git history unless explicitly instructed.
* Do not make broad refactors during active debugging unless explicitly requested.
* Do not delete evidence.
* Do not overwrite findings without preserving the previous conclusion or explaining the change.
* Before modifying protocol behavior, document the current behavior.
* Every code change must have a reason.
* Every protocol claim must have evidence or be explicitly marked as a hypothesis.
* Prefer boring, explicit code over clever abstractions.
* Prefer readable protocol handling over premature optimization.
* Preserve test artifacts.
* Update documentation when discoveries are made.
* Update the changelog for functional or workflow changes.

## Evidence Standard

Every finding must include:

* Date and time
* Client version
* Platform
* Server commit hash
* Network setup
* Test steps
* Observed behavior
* Expected behavior, if known
* Supporting evidence
* Confidence level
* Remaining unknowns

Acceptable evidence includes:

* Packet captures
* Server logs
* Emulator logs
* Real PS2 observations
* Screenshots
* Reproducible test steps
* Code references
* Commit hashes
* Binary offsets, if legally and appropriately documented

## Evidence Classification

Use these labels consistently:

* `Confirmed`: Directly observed and supported by evidence.
* `Likely`: Strongly supported, but not fully proven.
* `Hypothesis`: Plausible explanation requiring validation.
* `Unknown`: Not enough evidence.
* `Blocked`: Cannot currently proceed without missing data, tooling, or access.
* `Rejected`: Previously considered but disproven by evidence.

Do not present `Likely`, `Hypothesis`, or `Unknown` as fact.

## Protocol Reverse Engineering Rules

* Do not invent packet fields.
* Do not invent opcode meanings.
* Do not invent server response meanings.
* Do not infer client intent without evidence.
* Unknown bytes must remain named as `unknown_*` until proven otherwise.
* Use neutral field names until behavior is confirmed.
* Keep raw observations separate from interpretation.
* Treat PAL behavior as authoritative for this project.
* Do not assume NTSC behavior applies to PAL.
* Compare real PS2 behavior and emulator behavior separately.
* Treat timing differences as potentially meaningful.
* Validate protocol assumptions using packet captures and logs.
* If a protocol change is speculative, mark it as experimental.
* If a protocol change fails, document the failure.
* Maintain packet structure notes under `docs/findings/protocol/`.

## Real PS2 vs Emulator Rules

Real PS2 and emulator behavior must be tracked separately.

Every test must state the platform:

* Real PS2
* PCSX2
* XBSX2
* Other emulator, with version

Do not merge findings from different platforms unless evidence shows they behave the same.

If behavior differs between real PS2 and emulator:

* Document both behaviors.
* Do not assume either is wrong.
* Identify where the behavior diverges.
* Capture packet and server log evidence for both.

## Test Requirements

Every test must document:

* Test ID
* Date and time
* Client version
* Platform
* Lobby or server selected
* Network configuration
* Server commit hash
* Steps performed
* Expected result
* Actual result
* Error code or visible behavior
* Evidence files
* Confidence level

Golden tests are tracked in:

* `docs/test-plan.md`

## Documentation Rules

Update documentation as part of the same logical change.

Use these files for project knowledge:

* `docs/current-status.md`: latest verified project state.
* `docs/open-questions.md`: unknowns that still need proof.
* `docs/blocking-issues.md`: issues preventing progress.
* `docs/test-plan.md`: repeatable validation scenarios.
* `docs/findings/protocol/`: protocol findings.
* `docs/findings/client-behavior/`: client-side behavior.
* `docs/findings/emulator-vs-hardware/`: platform comparison.
* `docs/findings/server-behavior/`: server-side behavior.
* `docs/evidence/`: curated supporting material.
* `docs/decisions/`: architectural and research decisions.
* `docs/runbooks/`: repeatable procedures.

Do not use chat history as the only source of truth. Important conclusions must be written into the repository.

## Decision Records

Use an ADR when making a meaningful decision about:

* Architecture
* Protocol interpretation
* Test strategy
* Repository structure
* Tooling
* Long-term working model

ADR files must be stored in:

* `docs/decisions/`

Use this naming pattern:

* `ADR-0001-short-title.md`
* `ADR-0002-short-title.md`

Each ADR should include:

* Status
* Context
* Decision
* Consequences
* Evidence, if applicable

## Git Rules

Use Git as the audit and revert mechanism.

Commit after each logical change.

Recommended commit prefixes:

* `docs:`
* `test:`
* `server:`
* `protocol:`
* `tooling:`
* `fix:`
* `refactor:`
* `chore:`

Commit messages must explain what changed and why.

For protocol changes, include the reason in the commit body.

Example:

```text
protocol: adjust lobby response length

Changed the lobby response length based on emulator packet comparison.

Evidence:
- docs/evidence/pcaps/2026-06-07-emulator-lobby1-error840.pcapng
- docs/findings/protocol/lobby-response-length.md
```

Do not combine unrelated changes in one commit.

## Changelog Rules

Update `CHANGELOG.md` for:

* Functional server changes
* Protocol behavior changes
* Test framework changes
* Documentation structure changes
* Workflow changes

Do not add every tiny typo fix to the changelog.

## Hallucination Control

* If evidence is missing, say evidence is missing.
* If something is unknown, mark it as unknown.
* If something is a hypothesis, label it as hypothesis.
* Do not present guesses as facts.
* Do not invent missing context.
* Do not create fake packet captures, fake logs, fake offsets, fake references, or fake commit hashes.
* Do not claim a test passed unless it was actually run.
* Do not claim real PS2 behavior based only on emulator behavior.
* Do not claim PAL behavior based only on NTSC behavior.
* Prefer `Unknown` over plausible but unverified explanations.
* Cite file paths, packet numbers, log lines, commit hashes, or test IDs whenever possible.

## Token Usage and Context Control

* Before large analysis, summarize the known state.
* Avoid re-reading unchanged files unless necessary.
* Prefer targeted diffs over full-file reviews.
* Prefer concise findings over repeated background context.
* Keep large packet dumps in files, not chat.
* Summarize packet analysis in documentation.
* Do not paste large logs unless required.
* Ask for the specific file, packet range, or test result needed when context is missing.
* Use repository documentation as the working memory.

## Code Quality Rules

* Keep protocol parsing explicit and readable.
* Use clear names for confirmed fields.
* Use `unknown_*` names for unconfirmed fields.
* Add comments only when they explain protocol reasoning or non-obvious behavior.
* Do not hide protocol behavior behind overly generic abstractions.
* Prefer deterministic behavior in tests.
* Avoid broad rewrites during active investigation.
* Preserve existing behavior unless intentionally changing it.
* When changing behavior, document before and after behavior.

## Testing Rules

Before claiming a fix:

* Run the relevant automated tests, if available.
* Run the relevant golden test, if possible.
* Document what was tested.
* Document what was not tested.
* Record the server commit hash.
* Update `docs/current-status.md`.

If a test cannot be run, state why.

## Security and Legal Boundaries

This project is for private interoperability research and preservation-oriented server behavior analysis.

Do not add:

* Production service endpoints
* Instructions for attacking third-party services

Do not include sensitive personal data in logs or documentation.

Sanitize evidence before committing when needed.

## Required Response Style for Agents

When reporting work, use this structure:

```markdown
## Summary

Briefly state what changed or what was found.

## Evidence

List supporting files, logs, packet captures, code references, or test IDs.

## Changes Made

List code or documentation changes.

## Tests Performed

List tests that were actually run.

## Unknowns

List what is still unknown.

## Next Step

Give the single most logical next step.
```

## Definition of Done

A change is not complete unless:

* Code change is committed, if code changed.
* Documentation is updated, if behavior or knowledge changed.
* Changelog is updated, if functionality or workflow changed.
* Tests are run or explicitly marked as not run.
* Evidence is linked or the lack of evidence is stated.
* Open questions and blocking issues are updated if relevant.

## Process Guardian Role

Codex is the process guardian for Claude sessions. The guardian does not replace
Claude's reverse engineering; it verifies that significant actions obey the
project's evidence, Git, deployment, runtime, MCP, and experiment-discipline
rules.

Claude must request a mandatory second opinion after every significant action:

* Reverse engineering conclusions.
* New hypotheses.
* Code modifications.
* Git commits.
* Deployments.
* Rollbacks.
* Recovery attempts.
* Protocol interpretations.
* Runtime explanations.
* Any decision that changes the server.

The reviewer must use `docs/orchestration/PROCESS_GUARDIAN.md` as the checklist.
If the checklist is incomplete, stop and re-anchor before continuing.

Before suggesting manual shell work, check whether `outbreak-tools`, Ghidra MCP,
or another documented tool can answer, deploy, verify, inspect, compare, or
automate the step. Prefer existing MCP and repository tooling when available.

Significant experiments must have exactly one hypothesis, one expected outcome,
one rollback, and one success criterion. Reject stacked experiments and
unrelated cleanup.

## Worktree Disposition Rule

When an agent understands the status of an uncommitted file, it must mark the
file as one of:

* `commit`
* `split`
* `ignore`
* `delete`
* `defer`
* `owner-review`

For each marked file or group, record the reason, evidence/source, intended
logical change or commit title, risk if committed, and risk if deleted or
ignored.

Do not leave understood files as anonymous dirty worktree noise. If the tree is
mixed, produce a grouped disposition plan before committing.

## Emulator Harness Rule

When starting PCSX2 for an emulator test, use the full capture harness by
default:

```powershell
node tests/capture.mjs --case GT-003 --platform emulator --idle <seconds> --watch <watch-file> --force
```

The run must capture or explicitly report missing Wireshark/tshark or dumpcap
PCAP, Pi journal/server logs, PINE sampler output when relevant, DEV9/PCSX2 logs
when network behavior is under review, and `tests/results/<run>/meta.json`.

If the emulator is started manually or outside the harness, classify the result
as incomplete unless equivalent PCAP, logs, runtime samples, and metadata are
captured and linked.

## Pi Runtime Rule

The running server is the Pi at `192.0.2.121`, not this dev repo. Before
claiming a deployment, rollback, baseline, or runtime explanation, verify the Pi
runtime using `docs/runbooks/pi-deployment.md`.

At minimum record the Pi file hash, active `pal-server.service` state, effective
systemd `SNAP_*` environment, and relevant Pi journal excerpt.

## Mandatory Test Gate

Before running a drive test, changing protocol behavior, modifying packet bytes, or changing server state, the agent must write:

```markdown
## Test Gate

Baseline:
Current observation:
Specific unknown:
Hypothesis:
Evidence supporting hypothesis:
Exact change or command:
Expected result:
Alternative result:
What success proves:
What failure proves:
Rollback:
Files/logs that will be captured:
```

If any field is missing, stop.

Do not perform the test.

Do not continue with implementation.

````

## Ghidra MCP Rules

When using Ghidra MCP:

- Do not trust decompiler output alone.
- Always verify critical decompiler conclusions against disassembly.
- Record function address, function name, program/module, and base address.
- Record whether the function is from main ELF, overlay, IRX, or unknown module.
- Mark all inferred function names as provisional unless confirmed by behavior.
- Do not rename functions or variables based on speculation.
- If a function controls a protocol decision, document:
  - Input registers
  - Relevant memory reads/writes
  - Branch condition
  - Output state
  - Caller/callee relationship
- If Capstone, Ghidra, and runtime behavior disagree, runtime behavior wins.
- If Ghidra cannot resolve an overlay correctly, state that clearly and do not treat the decompile as authoritative.

Every RE finding must include:

```markdown
Function:
Address:
Module:
Evidence type:
Relevant branch/state:
Observed effect:
Confidence:
````

```

## State Machine Rules

For lobby/connect work, prioritize state-machine understanding over packet guessing.

Before changing server behavior, identify:

- Which client state machine is active.
- Which state or substate is blocked.
- Which condition advances the state.
- Which condition produces the current error.
- Which memory value proves advancement or failure.

Do not modify packets only because a byte, opcode, or field looks suspicious.

Packet changes must be tied to a specific client branch or state transition.
```

## Live Logging Rule

Every test and RE finding must be logged before starting the next test.

Use:

```text
docs/findings/protocol/SESSION-LOG-YYYY-MM-DD.md
```

Each entry must include:

```markdown
## T<number> - Short title

Time:
Platform:
Server commit:
Change:
Hypothesis:
Expected:
Actual:
Evidence:
Conclusion:
Confidence:
Next impact:
```

Do not batch findings at the end of a long session.

If no log entry is written, do not continue.

```

## Baseline Protection

Before interpreting a result, answer:

- Is this behavior new?
- Was this already known baseline behavior?
- Did the modified code path actually execute?
- Was the change one-shot, cached, skipped, or applied to a different server selection/session?
- Is the result from the modified path or from unchanged fallback behavior?

If this check is missing, the result must be classified as `Unknown`.
```

## Anti-Drift Rule

The agent must stop and re-anchor when any of these occur:

* More than one hypothesis is being pursued at once.
* More than one protocol change is introduced before validation.
* A result is interpreted without baseline comparison.
* A theory is extended after a failed or inconclusive test.
* Findings are only in chat and not in repository documentation.
* The same rejected hypothesis is being rediscovered.

When this happens, write a compact state snapshot:

```markdown
Confirmed:
Rejected:
Unknown:
Current baseline:
Current blocker:
Next valid test:
```

```
```
