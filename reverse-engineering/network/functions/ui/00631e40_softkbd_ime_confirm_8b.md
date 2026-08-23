# 0x00631e40 softkbd_ime_confirm_8b

| field | value |
|---|---|
| Original address | 0x00631e40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631e40 |
| Resolved name | softkbd_ime_confirm_8b |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_006300a0, FUN_00631d60
**Callees:** FUN_00631ff0, FUN_00633430, FUN_006343b0
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x260 IME buffer; +0x2f IME state; +0x4a flags; +0x248 result code

## Behavioral explanation
IME confirm key (0x8b): if a composition exists, commits it (via IME-commit or convert-commit) and posts result 1.

## Notes / uncertainty
Commit composition when non-empty; sets result +0x248=1; commit (FUN_00631ff0) vs finalize (FUN_00633430). FUN_006343b0 predicate inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631e40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
