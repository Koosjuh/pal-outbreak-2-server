# ADR-0002: Migrate legacy `C:\dnas` workspace into the canonical repo

## Status

Accepted — 2026-06-07.

## Context

Research and server work historically lived in two legacy locations:

- `C:\dnas`
- `C:\dnas\active` (its own git repo, symlinked into this repo as `.active`, with
  a `.codex` symlink pointing back here)

`D:\projects\pal-outbreak-2-server` is now the single source of truth. The owner
wants the legacy `C:\dnas\active` folder deleted, so every important artifact
must be **physically copied** into this repo (no symlinks), and the repo must be
**organized** (no raw dumps committed verbatim).

Two project constraints were relaxed by the owner during this work and reflected
in `AGENTS.md`: the self-signed **dev server key** (`server.key`) and the
**test `accounts.json`** are required for the emulation/login path and are now
allowed in the repo. (The `Repository Scope` list in `AGENTS.md` still mentions
keys/credentials and should be reconciled with the relaxed `Security Boundaries`
section.)

## Decision

Migrate by category into an organized layout, copying physically and committing
in small logical commits:

- **Server** → `server/` (core stack, `variants/`, `certs/`, `accounts.json`,
  `assets/web/`, run scripts). Dev key/cert tracked via explicit `.gitignore`
  exceptions.
- **Tools** → `tools/` grouped by purpose (`pine`, `disasm`, `dump`, `extract`,
  `search`, `pcap`, `runtime`, `snap`, `codex`).
- **Ghidra** → scripts to `scripts/ghidra/`, text exports to `exports/ghidra/`
  (decompiles already curated in `analysis/` were not duplicated).
- **Findings / handoff** → `docs/findings/` and `handoff/` (originals preserved
  verbatim, including their own confidence labels).
- **Evidence** → `docs/evidence/` (9 real pcaps tracked via exception; traces,
  HTTP responses, and flow photos tracked; `*.log` copied on-disk but untracked
  per policy). Provenance in `docs/evidence/MANIFEST.md`.
- **Superseded material** → `archive/` for provenance (old tooling iterations,
  old server, April research notes, dnas cleanup meta-docs, PCSX2 GPL reference
  snippets).

Excluded entirely (not copied): game ISO (`C:\dnas\iso`, ~8 GB), the KDDI
reference tree (`references`, ~3.2 GB), emulator install (`PCSX2`), Ghidra
installs/projects, game binaries and memory dumps (`disc_*.bin`, `game.bin`,
`nethttp.bin`, mid-gap dumps), `dns_cache.txt` (personal DNS data), and the bulk
raw capture/snapshot soup (~7,300 `.bin` + ~7,700 `.txt`, ~3 GB).

## Consequences

- The repo is now self-contained for server + research work; `C:\dnas\active`
  can be deleted (the `.active` symlink was removed).
- **Anything not migrated will be lost when the legacy workspace is deleted.**
  Excluded raw captures, the full per-session log set, and game/emulator/Ghidra
  installs should be independently backed up first if they may be needed.
- Disposable dev key/cert and test accounts are committed; they must never be
  reused in production.
- Large binary evidence (pcaps, photos) adds ~37 MB to git history; accepted for
  auditability since the project is evidence-driven.
- Some legacy docs predate the `AGENTS.md` evidence standard; their claims retain
  their original confidence labels and are not promoted to `Confirmed`.

## Evidence

- Migration commits on `master` (2026-06-07), prefixed `server:`, `tooling:`,
  `docs:`, `chore:`.
- `docs/evidence/MANIFEST.md` — curated evidence provenance and exclusions.
