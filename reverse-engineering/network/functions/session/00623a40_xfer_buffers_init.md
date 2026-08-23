# 0x00623a40 xfer_buffers_init

| field | value |
|---|---|
| Original address | 0x00623a40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00623a40 |
| Resolved name | xfer_buffers_init |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00622f40
**Callees:** —
**Referenced globals:** 0x715298 struct ptr; 0x3435bc buffer base
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam003435bc

## Behavioral explanation
Initializes the data-download context in the screen struct: clears status bytes and sets three DMA buffer pointers (base iRam003435bc + 0x2ff000/0x31f000/0x33f000).

## Notes / uncertainty
Inits download context in 0x715298: clears SM state (+0x160/+0x161...),+0x164 handle,+0x168=mode, sets 3 transfer buffers at heap base 0x3435bc +0x2ff000/+0x31f000/+0x33f000 (stage/recv/session, 128KiB stride). Raw ends in halt_baddata; possible trailing stores unrecovered. Buffer roles inferred from consumers.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00623a40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
