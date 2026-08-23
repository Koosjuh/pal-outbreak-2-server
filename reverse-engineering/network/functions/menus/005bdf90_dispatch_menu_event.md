# 0x005bdf90 dispatch_menu_event

| field | value |
|---|---|
| Original address | 0x005bdf90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bdf90 |
| Resolved name | dispatch_menu_event |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bbc20, FUN_005bbf20, FUN_005bc2a0, FUN_005bc2f0, FUN_005bc590, FUN_005bc790, FUN_005bc990, FUN_005bca90, FUN_005bcfd0, FUN_005bdfe0, FUN_005be330, FUN_005c4580, FUN_005c4af0, FUN_005c5460, FUN_005c56a0, FUN_005c7d40
**Callees:** —
**Referenced globals:** 0x6ca8a0 menu-event callback table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Dispatches a menu/UI event: looks up the callback at 0x6ca8a0[id&0xffff] and invokes it with a {op=1,id} 2-byte struct.

## Notes / uncertainty
Central UI-event fan-out: invokes 0x6ca8a0[id&0xffff] with msg {kind=1,id}, no-op if null; 16 callers. '1' is a message-kind byte not a wire opcode. Full id->handler map open.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bdf90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
