# 0x0062d560 room_screen_init

| field | value |
|---|---|
| Original address | 0x0062d560 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062d560 |
| Resolved name | room_screen_init |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005aec70
**Callees:** FUN_005aec20
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0xe major-state; struct+0xf sub-state; struct+0x443/+0x4b7 host/join flags

## Behavioral explanation
Initializes room-screen state struct: major+0xe=3, sub+0xf=3(host,param2==0) or 2(join); join path also sets +0x443/+0x4b7 flags. Common: +0x45d=2, +0x146b=0.

## Notes / uncertainty
Room-screen init; param_2 selects host(0: +0xf=3) vs join(!=0: +0xf=2, +0x443/+0x4b7=1). Major +0xe=3, common +0x45d=2/+0x146b=0. Host/join labels + flag names inferred from the join-only asymmetry; which caller passes create vs join in FUN_005aec70.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062d560.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
