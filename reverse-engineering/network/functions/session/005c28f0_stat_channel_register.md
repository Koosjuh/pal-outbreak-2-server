# 0x005c28f0 stat_channel_register

| field | value |
|---|---|
| Original address | 0x005c28f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c28f0 |
| Resolved name | stat_channel_register |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c6500, FUN_0062dc40
**Callees:** FUN_005be0a0, FUN_005c08b0
**Referenced globals:** 0x6ca97c/0x6ca97e (channel-handle table, stride 0x20); 0x6febe4 (conn flags); 0x6febac (conn/session ptr)
**Referenced strings:** STAT (0x53544154)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates a channel slot (be0a0), stores a key (c08b0), and opens a 'STAT' transport channel via 0x1dd33c with flag 0x40000000; records the returned handles in the 0x20-stride table at 0x6ca97c.

## Notes / uncertainty
Opens 'STAT' (0x53544154) SN@P named channel via 0x001dd33c, reply cb=app_reply_cb_state2. Allocs task slot, writes key (+0x14) and txn handle (+0x16). payload=((flags&0x0f000000)<<1)|0x40000000. Underlies 0x70 STAT guard. Flag-bit meaning unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c28f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
