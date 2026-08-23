# 0x005c02b0 send_register_maxi

| field | value |
|---|---|
| Original address | 0x005c02b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c02b0 |
| Resolved name | send_register_maxi |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe500, FUN_005fe8d0
**Callees:** FUN_005be0a0, FUN_005c1e70
**Referenced globals:** 0x6ca97c/0x6ca97e txn handler-callback slots; 0x6fee68 room record base (*0x24); 0x6febac SN@P conn handle
**Referenced strings:** MAXI
**Referenced opcodes:** 0x7b
**State vars:** —

## Behavioral explanation
Allocates a txn slot, builds a register message (opcode 0x7b via 1e70) and sends a 'MAXI' (0x4d415849) reliable command tied to room record param_1 over the SN@P conn.

## Notes / uncertainty
Allocates a client txn slot, builds app-cmd register selector 0x7b, sends reliable op09 register carrying room handle (from 0x6fee68 table) + ASCII tag 'MAXI' (max-players). App-cmd(0x7018d0) vs op09-wire duality unproven on the wire; runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c02b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
