# binaries/

Original (and, if ever needed, patched) binary source artifacts.

> **Git-ignored.** Everything under `original/` and `patched/` is local-only and
> never committed (copyrighted game data + large files). Only this README is
> tracked. See `docs/decisions/ADR-0003-local-binary-assets.md`.

## Layout (local, not in git)

- `original/disc-image/original/` — the game ISO (`Resident Evil Outbreak File #2`, PAL, `SLES_533.19`).
- `original/disc-image/extracted/` — the extracted ISO filesystem.
- `original/game-modules/` — extracted overlay modules and runtime/RAM dumps used
  in reverse engineering (`ntgui.bin`, `netwk.bin`, `nethttp.bin`, `game.bin`,
  `disc_*.bin`, `ram_*`, `mid_gap_*`, `sles_gap.bin`, etc.).

Migrated from `C:\dnas\iso` and `C:\dnas\active\tmp` on 2026-06-07.
`patched/` is normally unused (no ISO/game patching is allowed by this project).
