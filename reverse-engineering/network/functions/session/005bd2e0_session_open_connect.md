# 0x005bd2e0 session_open_connect

| field | value |
|---|---|
| Original address | 0x005bd2e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bd2e0 |
| Resolved name | session_open_connect |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b25c0
**Callees:** FUN_005bc860, FUN_005bd250, FUN_005c6d60
**Referenced globals:** 0x6febac (session handle); 0x6cbccc (config copy); 0x6cb98c (init-once flag); 0x86f7f0 (session phase); 0x6cbd0c/0x6cc104 (roster tables); 0x6fc8e8 (8KB reliable buffer); 0x6cb96c (UI callback ptr); 0x6febb8/0x6febc8 (id/name); 0x35b9e0 (saved handle)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006cb98c; cRam0086f7f0

## Behavioral explanation
One-time lobby session bring-up: copies the passed 0x20-byte server config, initializes lobby/registry state (0x6cbccc, 0x6cbd0c/0x6cc104 roster tables, 0x6fc8e8 8KB buffer), resolves the server socket (func_0x001d46ec) and opens the SN@P session via func_0x001db7e8, storing the handle in 0x6febac; on warm restart re-drives via FUN_005c6d60(0x5bcfd0) or reconnect callback 0x5bcee0. Returns 0 on first open, -1 if already up.

## Notes / uncertainty
Top of connect chain. Init-once (0x6cb98c) lobby bring-up: copies 64B config->0x6cbccc, zeros roster/8KB rx buf 0x6fc8e8, resolves IP, registers handlers, opens SN@P session via 0x001db7e8. Warm path re-drives 0x5bcfd0 or arms 0x5bcee0. 0x3c param block layout and 0x001db7e8 trailing args 0xcaf3/0xf0 unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bd2e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
