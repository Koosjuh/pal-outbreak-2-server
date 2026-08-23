# ghidra-projects/

Ghidra project databases for this RE effort.

> **Git-ignored.** The `.gpr` / `.rep` databases are local-only and never
> committed: they embed the imported (copyrighted) game code and are large.
> Only this README is tracked. See
> `docs/decisions/ADR-0003-local-binary-assets.md`.

## Contents (local, not in git)

- `pal_codex_op48/` — main PAL SN@P analysis project (`pal_snap.gpr`,
  `pal_snap_ee.gpr`), migrated from `C:\dnas\active\ghidra_pal_codex_op48`.
- `nethttp/` — nethttp overlay project (`nethttp.gpr`), from
  `C:\dnas\active\ghidra_nethttp`.
- `legacy/` — earlier project DBs from `C:\dnas\ghidra_projects`.

The analysis **scripts** that drive these projects are tracked in
`scripts/ghidra/`; their text **exports** are in `exports/ghidra/`. The repo
also already tracks a couple of small fresh projects (`ghidra_op48_fresh/`,
`scratch/`); large/game-bearing databases belong here instead.
