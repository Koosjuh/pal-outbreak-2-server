# 0x00626900 session_connect_screen_step

| field | value |
|---|---|
| Original address | 0x00626900 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00626900 |
| Resolved name | session_connect_screen_step |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00622180
**Callees:** FUN_005bd250, FUN_0061e7f0, FUN_0061e800, FUN_0061e910, FUN_0061e960, FUN_0061f0e0, FUN_0061f1a0, FUN_0061f1d0, FUN_0061f1f0, FUN_0061f470, FUN_0061f4b0, FUN_0061f680, FUN_0061f760
**Referenced globals:** 0x35ba98 ip-bytes; 0x35bed8 port/ip2; 0x35b9e0 session-handle; 0x86f820 host-str; 0x86f810 name; 0x35b750
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam007152e1 screen-phase; uRam007152e6 spinner; sRam007152e4 timer; cRam0086f7e0 retry-branch; iRam007152a0 retry-count; sRam007152ea

## Behavioral explanation
Lobby-server connect screen state machine: builds host address from IP bytes and calls session-open FUN_001db7e8, teardown FUN_001d4de0/001dbe60; manages retry count iRam007152a0.

## Notes / uncertainty
Connect-screen SM; opens SN@P session via func_0x001db7e8 (port 0xcaf3), transport start/stop, retry cap 3, returns screen codes 0/1/2/3/-1. UI poller trio (0061e7f0/800/910) semantics inferred; FUN_005bd250 param block not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00626900.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
