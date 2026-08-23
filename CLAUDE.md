# CLAUDE.md — PAL Outbreak 2 operating rules

Reproduce the original PAL Resident Evil Outbreak File #2 (SLES-53319) SN@P/PAL lobby protocol on a
private server — **server-side only. Never modify the client or ISO.** Live server = Raspberry Pi at
`192.0.2.121`. Long-term goal: recreate the JP Bioserver behavior, translated to SN@P/PAL.

_(The previous, much longer rules are in git history. This version keeps what matters and drops
ceremony that was never actually followed.)_

---

## How we work (the workflow)
1. **Goal-oriented.** `GOALS.md` is the north star. Pick ONE goal and drive it to done. Don't scatter.
2. **One goal per session.** When a goal is confirmed MET, the session ends — start fresh for the next.
   A bloated session is where mistakes come from; keep context small and sharp.
3. **Git is the source of truth + history — always rollback-able.** Commit EVERY change with **why +
   what** (and the goal it serves); never leave a working change uncommitted. Before any risky or
   deployable change, know the last-good commit, and if it regresses, `git revert`/`git checkout`
   straight back to it. We must NEVER be in a state where we changed something, it regressed, and we
   can't get back. The repo — not chat — is the record.
   **Before rolling back, ground the target: revert to the last *validated* good commit (check
   `GOALS.md`/`FACTS.md`/the morning report), NOT the first tag named "golden".** Overshooting a
   rollback discards validated work. (2026-07-04: a session rolled back past the validated 07-03 state
   `d3dacf3` to the older 07-02 golden `0ff7227` and lost Free-first + all-10 areas + back-nav.)
4. **Verify before "met".** NEVER self-declare a goal met. When you believe it is, **run `nora` to
   confirm it's grounded + validated, then ask the owner to confirm on the rig.** Only their
   confirmation flips it to MET. A regression re-opens the goal.
5. **Offload to subagents to stay small.** Push self-contained work to an agent so the goal-session
   doesn't bloat (bloat → mistakes): `snap-re` deep decompile · `james` tooling · `nora` review ·
   `scribe` docs. Don't build tooling or run deep traces inline in the goal-session.

## The four discipline rules (these are the failures that cost us — do not repeat them)
1. **Ground before output.** Before acting or claiming ANYTHING, read the current state: `GOALS.md`,
   `FACTS.md` (the CURRENT MODEL section), and the live rig via `node tools/rig-doctor.js`. Nearly
   every bad turn was producing output without first checking what is actually true.
2. **Validate locally before the Pi.** Prove a hypothesis in the emulator's memory (PINE read/poke)
   BEFORE deploying to the Pi. A poke is a diagnostic, never the fix. The Pi deploy is the FINAL
   confirmation, not the iteration loop — the deploy→reconnect churn is what pressured us into guessing.
3. **No guessing — evidence only.** Every change ties to evidence: a decompile line, a PINE read, or
   the Bioserver reference. If you lack the ground truth, GET it (read it) — do not poke a guessed
   value. If blocked or unsure, call `second_opinion` EARLY, not after hours of thrash
   (`python tools/outbreak_mcp/server.py call second_opinion <json>`, or the MCP tool).
4. **Say what's true.** No victory laps, no "I'll stop doing X" announcements — only validated results.
   If a test failed, say so with the evidence. If a step was skipped, say that.

## Corpus methodology (permanent engineering standard, 2026-08-07)
The xref tooling is a **discovery** mechanism, not a proof of absence. It is a linear sweep with no
control flow, and it has demonstrably missed writers.
- "found N writers" is valid. **"exactly N", "the only caller", "no reference found" and
  "unreachable" are NOT** — each needs control-flow-aware verification before it becomes fact.
- Always consider indirect calls, jump tables, pointer dispatch, register clobbering and **MIPS delay
  slots** (the instruction after a `jal` runs BEFORE the callee) before promoting a conclusion.
- **When an implementation decision depends on exclusivity or absence, do targeted deeper analysis of
  that specific path first.** If you cannot, the claim is Likely at best and the code must not rely on it.
- **The corpus is living.** On finding a wrong annotation, an incomplete xref, a mistaken assumption or
  a better explanation: verify it, correct the corpus document, record what changed and why, keep the
  old conclusion marked SUPERSEDED rather than rewriting history, update dependent specs and open
  questions, then continue. Every investigation leaves the corpus more accurate than it found it.
- Incremental only — fix what current work touches. Never a repo-wide corpus rewrite.
Full standard: `docs/CORPUS-METHODOLOGY.md`.

## Sources of truth
- `GOALS.md` — goals + status (verify-before-met / re-open-on-regression).
- `GOLDENS.md` — the record of known states (commit + md5 + flags + rig-confirmation). Read it BEFORE
  saying "restore to X". A doc that says "VALIDATED" is not a golden; only this file's CONFIRMED list is.
- `FACTS.md` — confirmed facts; the **CURRENT MODEL** section (top) wins over the archived history.
- `docs/findings/protocol/LOBBY-UNIFIED-ARCHITECTURE-RE-2026-07-03.md` — the technical lobby model.
- Evidence ranking (higher wins): runtime behavior > memory (PINE) > wire (pcap) > decompile > notes > hypotheses.

## Tools
- **Rig ops:** `node tools/rig-launch.js` (clean persistent PCSX2 + PINE), `tools/rig-doctor.js`
  (health — run before trusting the rig), `tools/create-dump.js` (labeled scenario/create state).
- **Local validation:** PINE via `tools/pine/pine_client.js` / `tools/scenario_probe.js`. **Clear
  zombie clients first** — they hog PINE's single slot and cause "connection refused".
- **Subagents** (spawn for self-contained work — keeps the goal-session small): `snap-re` (opus,
  read-only) deep decompile traces (`analysis/*.txt`); `james` (sonnet) build/fix tooling — don't
  build tools in the goal-session; `nora` (opus, read-only) review before commit / before asking the
  owner to confirm MET; `scribe` (sonnet) update `FACTS.md`/`GOALS.md` after a confirmed finding.
- **Wire specs:** Kaitai — encode framing as executable specs that fail loud + generate parsers
  (`docs/specs/kaitai/*.ksy`, compiler in `vendor/kaitai/`, `kaitai_compile` MCP tool). Wireshark Lua
  dissector `tools/wireshark/pal_snap.lua` (`install_lua_dissector` MCP tool) → decoded capture fields.
- **Reference:** JP Bioserver source in `references/bioserver/` — the application protocol the PAL
  client speaks (only the transport differs). Ground truth for WHAT the client expects.
- **MCP:** `ghidra` (LaurieWired) + `outbreak-tools` (second_opinion, PINE, opcodes). `/mcp` to reconnect.
- **Deploy:** `scripts/deploy-pi.ps1`; read `docs/runbooks/pi-deployment.md` before touching the Pi.

## Rig gotchas (learned the hard way)
- `rig-launch.js` launches a **clean-named ISO hardlink** (`C:\dnas\iso\ob2.iso`) because the real
  filename's `#`/`()`/spaces mangle through the launch arg chain (PCSX2 says "does not exist").
- Independent (`spawn` detached) launch **persists**; harness `--poke` exits and kills PCSX2; the
  sampler mode hogs PINE. A physical PS4/DS controller enumerates as SDL-0 when no virtual pad runs.
- PINE binds ~60s after boot; it accepts one client at a time.

## Constraints & classification
- Server + protocol + instrumentation only. No ISO patching, no client mods, no permanent memory
  patches presented as solutions (pokes are diagnostics). Never present an assumption as a fact.
- Classify reasoning explicitly: **Observation** (evidence) / **Inference** / **Hypothesis** /
  **Conclusion** (requires supporting evidence).
- Never suggest pausing or checkpointing for reasoning — the owner decides when to stop.
