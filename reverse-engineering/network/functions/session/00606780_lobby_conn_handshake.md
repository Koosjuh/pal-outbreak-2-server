# 0x00606780 lobby_conn_handshake

| field | value |
|---|---|
| Original address | 0x00606780 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606780 |
| Resolved name | lobby_conn_handshake |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006063c0
**Callees:** FUN_005be9f0, FUN_005bea00, FUN_005bea10, FUN_005bea50, FUN_00605d60
**Referenced globals:** uRam0035a6f4 (socket); 0x7018c0/0x7012c0 (recv buf); 0x7018d0 (tx packet); 0x8710f1 (id const); uRam0035b723 (error code); sRam0070cdc8 (state)
**Referenced strings:** @0x8710f1
**Referenced opcodes:** —
**State vars:** sRam0070cdc8

## Behavioral explanation
State-4 handshake: reads a framed reply (FUN_00605d60) expecting magic 0x1031, builds a response packet with the packet-writer (FUN_005be9f0/bea00/bea50/bea10 — type 0x1031, echoes bytes +6/+7), sends it (func_0x001ee590), advances on full send else errors to 99 (code 5).

## Notes / uncertainty
State-4 lobby handshake: recv frame, match magic 0x1031, build 0x1031 reply echoing server port bytes + address, send header(0xc)+body. 0x1031 is TCP lobby-transport magic, NOT a SN@P app opcode.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00606780.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
