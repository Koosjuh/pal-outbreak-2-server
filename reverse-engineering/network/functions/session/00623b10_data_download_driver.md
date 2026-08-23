# 0x00623b10 data_download_driver

| field | value |
|---|---|
| Original address | 0x00623b10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00623b10 |
| Resolved name | data_download_driver |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00622f40
**Callees:** FUN_00623be0
**Referenced globals:** 0x715298 struct ptr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0x160 driver-state; struct+0x168 mode; struct+0x17c handle

## Behavioral explanation
Thin driver around FUN_00623be0: on first entry starts the transfer (func_0x001bcba0 -> handle at struct+0x17c), then pumps the download SM each frame; returns 1 while active.

## Notes / uncertainty
Outer driver (state +0x160 0/1/2) around download SM FUN_00623be0: state0 gated on mode +0x168==0, opens session 001bcba0(+0x178)->handle +0x17c, pumps 001f4630; state1 pumps SM (0=finished); returns 1 running / 0 done. Transport primitives out-of-overlay.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00623b10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
