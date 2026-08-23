# 0x0062ba00 task_init_params

| field | value |
|---|---|
| Original address | 0x0062ba00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062ba00 |
| Resolved name | task_init_params |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005f76f0, FUN_005f8d40, FUN_005ff950
**Callees:** —
**Referenced globals:** +0x44c copied to +0x908
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Initializes a task/state record's mode fields (+0xe..+0x11, +0x907..+0x909) based on a mode arg (1 or 2 vs default).

## Notes / uncertainty
Task-record initializer: clears +1, writes phase quartet +0xe..+0x11 by mode (2={3,0,0,0}+carries +0x44c->+0x908 resume block; 1={0,6,0,0}; else zero). Shared by 3 screen-entry fns. Phase-byte and carried-selection semantics not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062ba00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
