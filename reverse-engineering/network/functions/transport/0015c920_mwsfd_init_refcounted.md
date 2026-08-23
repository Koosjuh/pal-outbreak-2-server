# 0x0015c920 mwsfd_init_refcounted

| field | value |
|---|---|
| Original address | 0x0015c920 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_0015c920 |
| Resolved name | mwsfd_init_refcounted |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Low |
| Runtime validated | no |

**Callers:** FUN_001cb070
**Callees:** FUN_001107b0, FUN_00110be8, FUN_00111298, FUN_00128468, FUN_0013b750, FUN_0013b818, FUN_0013d540, FUN_0013da78, FUN_0013e2a0, FUN_0015ca98, FUN_0015cae0, FUN_0015cc18, FUN_0015cd70, FUN_0015cdc0, FUN_0015ed80, FUN_00161700, FUN_001619d0, FUN_00162688
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Refcounted one-time init of 'MWSFD_PS2EE_Ver_2_88_Build_Jul_2_2002' middleware; publishes banner, runs init chain guarded by DAT_0022d9d0==0, computes ms timeout (sec*1000*0.5), registers periodic worker 0x15c908. Sub-init purposes and library identity undecoded — init skeleton only.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_0015c920.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Low**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
