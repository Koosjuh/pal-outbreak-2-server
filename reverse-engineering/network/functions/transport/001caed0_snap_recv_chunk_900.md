# 0x001caed0 snap_recv_chunk_900

| field | value |
|---|---|
| Original address | 0x001caed0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001caed0 |
| Resolved name | snap_recv_chunk_900 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001caf60
**Callees:** FUN_001cab70
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_2+0xc=read cursor; param_2+0x10=write cursor

## Behavioral explanation
Copies up to 900 bytes from the recv ring (via FUN_001cab70) into a descriptor's buffer window (+8/+0xc/+0x10) and advances its read cursor.

## Notes / uncertainty
Clamp-to-900 append into a {base,used,cap} recv descriptor; clear linear-buffer idiom. param_1=0 likely selects default source.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001caed0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
