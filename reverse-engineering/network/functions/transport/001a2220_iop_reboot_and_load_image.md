# 0x001a2220 iop_reboot_and_load_image

| field | value |
|---|---|
| Original address | 0x001a2220 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001a2220 |
| Resolved name | iop_reboot_and_load_image |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00195e00
**Callees:** FUN_001010a8, FUN_00101c38, FUN_00115300, FUN_00116cb8, FUN_00116cf0, FUN_00116f78, FUN_001170f8, FUN_00117330, FUN_00119aa8, FUN_00119b30, FUN_00119c98, FUN_0011a188, FUN_0011aed8, FUN_0011af28, FUN_0012a748, FUN_00183c90, FUN_001a21c0, FUN_001b4930
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Canonical PS2 IOP-reload: stop/reset SIF+RPC, spin init handshakes, open IOP image (0x244ef0), size+DMA to 0x1000000 (sceSifSetDma/DmaStat), relocate iRam01000004 words @0x1000008 stride8, start DAT_00244e30 module table (stride3,-1 term; id==10 special FUN_0012a748). Module identities & alloc source unconfirmed.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001a2220.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
