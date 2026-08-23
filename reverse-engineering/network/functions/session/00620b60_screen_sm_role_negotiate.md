# 0x00620b60 screen_sm_role_negotiate

| field | value |
|---|---|
| Original address | 0x00620b60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00620b60 |
| Resolved name | screen_sm_role_negotiate |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00622180
**Callees:** FUN_0061d6a0, FUN_0061e910, FUN_0061e940, FUN_0061e960, FUN_0061ea20, FUN_0061f0d0, FUN_0061f1a0, FUN_0061f1d0, FUN_0061f970, FUN_0061f9d0
**Referenced globals:** 0x7152e1 substate; 0x3c98a0 role flag; 0x715308 link flag; 0x7152e4 timer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam007152e1; cRam003c98a0; cRam00715308

## Behavioral explanation
Switch-based screen SM gated on network-role flag cRam003c98a0 and poll FUN_0061d6a0; steps through connect/teardown; returns 1 done.

## Notes / uncertainty
Screen SM (states 0-7 over cRam007152e1) that asserts role flag 0x3c98a0=1 and runs connect->handshake(d6a0)->teardown; state0 fast-paths to 6 if role==1 && link==0; state7 returns 1 done. Poll-code semantics (d6a0 -1/1) and role 1-vs-2 host/join mapping inferred; states 3/4 are pass-through delays.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00620b60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
