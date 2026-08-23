# 0x001c0230 dnas_module_init

| field | value |
|---|---|
| Original address | 0x001c0230 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c0230 |
| Resolved name | dnas_module_init |
| Subsystem | initialization |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001bf5e0
**Callees:** FUN_00106b60, FUN_0010a4f0
**Referenced globals:** 0x35c3d8 mode-ptr; 0x35b750-0x35b76c str-table; 0x35ba98
**Referenced strings:** PS2_DVD_INIT; (DAT_00248458)
**Referenced opcodes:** —
**State vars:** many 0x35b*/0x35c* DNAS globals

## Behavioral explanation
Zeroes the entire DNAS/DVD state block (0x35b7xx-0x35c3xx), installs default strings/pointers and PS2_DVD_INIT marker.

## Notes / uncertainty
Cold-start of DNAS/DVD block: bulk memset, 0xff-fill of 0x35c000, 4 default-string memcpys + pointer table at 0x35b750, PS2_DVD_INIT marker. Individual string semantics not decoded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c0230.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
