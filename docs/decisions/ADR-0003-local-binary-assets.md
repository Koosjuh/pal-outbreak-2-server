# ADR-0003: Keep large/copyrighted/toolchain assets locally, git-ignored

## Status

Accepted — 2026-06-07.

## Context

Continuing the reverse-engineering effort requires the game disc image, the
extracted ISO, extracted game modules / memory dumps, the KDDI reference tree,
the Ghidra and PCSX2 installs, and the Ghidra project databases. These lived in
the legacy `C:\dnas` workspace, which is being deleted (ADR-0002).

These artifacts (~12.5 GB) cannot be committed to git: they are copyrighted game
data, multi-GB binaries, third-party software, and project databases that embed
imported game code. `AGENTS.md` forbids the *repository* from containing them.
But the owner needs them physically present to keep working.

## Decision

Copy these assets **physically into the working tree but keep them git-ignored**.
Git-ignored files are not part of the tracked repository, so `AGENTS.md`'s
"repository must not contain …" rule is satisfied while the assets remain
available locally. Each tree keeps a single tracked `README.md` documenting what
belongs there; all other contents are ignored.

Local-only (git-ignored) trees and their sources:

| Local path | Source | Notes |
|---|---|---|
| `binaries/original/disc-image/` | `C:\dnas\iso` (`original/`, `extracted/`) | Game ISO + extracted filesystem (~8 GB). |
| `binaries/original/game-modules/` | `C:\dnas\active\tmp\*.bin` | Extracted overlays + RAM/memory dumps. |
| `references/` | `C:\dnas\references` | KDDI architecture reference (~3.2 GB), not SN@P truth. |
| `vendor/ghidra/` | `C:\dnas\tools\ghidra` | Ghidra + EmotionEngine plugin (~848 MB). |
| `vendor/pcsx2/` | `C:\dnas\PCSX2` | PCSX2 install (~113 MB). |
| `ghidra-projects/` | `…\ghidra_pal_codex_op48`, `…\ghidra_nethttp`, `C:\dnas\ghidra_projects` | Project DBs embedding game code (~260 MB). |

`.gitignore` ignores these trees (keeping only the READMEs). Disasm/analysis
scripts stay tracked in `scripts/ghidra/`; their text exports in `exports/ghidra/`.

## Consequences

- The full RE environment (ISO, modules, Ghidra projects + install, emulator,
  references) survives deletion of `C:\dnas` and works from the new repo.
- These ~12.5 GB are **not** backed up by git. They must be backed up separately;
  losing the working tree loses them. The ISO/extracted ISO can be re-created
  from the physical disc; Ghidra projects can be rebuilt from the ISO + scripts.
- Care is required not to force-add ignored paths (`git add -f`) — that would put
  copyrighted/large data into history.
- `AGENTS.md` was adjusted by the owner to permit this local-but-untracked
  arrangement.

## Evidence

- `.gitignore` local-assets block.
- `binaries/README.md`, `references/README.md`, `vendor/README.md`,
  `ghidra-projects/README.md`.
