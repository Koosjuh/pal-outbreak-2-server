# 0x00183fd0 file_size_query

| field | value |
|---|---|
| Original address | 0x00183fd0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_00183fd0 |
| Resolved name | file_size_query |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001cb0e0
**Callees:** FUN_00109ab0, FUN_00109eb8, FUN_0010a050, FUN_0010bca0, FUN_00116cf0, FUN_00116f78, FUN_001170f8, FUN_00129ff8, FUN_0012a010, FUN_00183c80
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Builds path prefix(0x22f6c8)+param_1+suffix(0x22f6d0), open(mode1)/lseek-END/close under a lock; returns file size or 0 if open<0. Prefix/suffix strings not dumped; file layer (CDVD/HDD/host) unidentified; open-mode inferred.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_00183fd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
