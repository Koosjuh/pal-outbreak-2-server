# 0x001d0230 build_and_send_list_screen_msg

| field | value |
|---|---|
| Original address | 0x001d0230 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d0230 |
| Resolved name | build_and_send_list_screen_msg |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00106b60, FUN_00109728, FUN_001a1750, FUN_001a7b70, FUN_001ab460, FUN_001cb360, FUN_001cbc20, FUN_001cce80
**Referenced globals:** 0x2ff808/0x301018/0x30101c list buffers; cRam00343577 offline-mode; uRam0034357a session id
**Referenced strings:** 0x24cc90 template; 0x24cca0 template; 0x24ccc0 template
**Referenced opcodes:** 0x0a
**State vars:** cRam00343577; uRam0034357a

## Behavioral explanation
Channel 0x2400, alloc tag 10, reliable send FUN_001cce80 (offline FUN_001a1750) with tmpl 0x24cc90/0x24cca0/0x24ccc0; wires up list buffers at 0x301018/0x30101c for the member-list reply.

## Notes / uncertainty
Renamed from send_op0a_member_list: the op0a label rested only on alloc tag 10; no 0x0a opcode reaches a transport enqueue. Actually a channel-0x2400 list/screen message builder with online (FUN_001cce80 broadcast -1) vs offline fork. op0a attribution downgraded to weak inference.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d0230.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
