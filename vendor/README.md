# vendor/

Local copies of third-party tooling/installs used for this project.

> **Git-ignored.** Contents are local-only and never committed (large
> third-party software). Only this README is tracked. See
> `docs/decisions/ADR-0003-local-binary-assets.md`.

## Contents (local, not in git)

- `ghidra/` — Ghidra installation plus the `ghidra-emotionengine-reloaded`
  (PS2 EE) plugin, migrated from `C:\dnas\tools\ghidra`.
- `pcsx2/` — PCSX2 emulator install, migrated from `C:\dnas\PCSX2`.

These are upstream tools; prefer reinstalling from source when practical. They
are kept here so the existing RE environment continues to work after the legacy
workspace is removed.
