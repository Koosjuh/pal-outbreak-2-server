# 0x005c3370 scenario_member_scan_reply_cb

| field | value |
|---|---|
| Original address | 0x005c3370 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c3370 |
| Resolved name | scenario_member_scan_reply_cb |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c7d00
**Referenced globals:** 0x6ca890 (member/roster count); 0x7005d0 (copied member record); 0x6cba55 (SM reply flag)
**Referenced strings:** —
**Referenced opcodes:** 0x0a
**State vars:** cRam006ca890; uRam006cba55

## Behavioral explanation
Reply handler for the member/roster list: on status 0x00 walks the variable-length member array (count at +8), copies each active member's 8-word block to 0x7005d0, increments the member counter 0x6ca890, and signals the SM (0x6cba55=1); status 0x27 signals failure (=2).

## Notes / uncertainty
Renamed: targeted scan (not roster draw). Extracts 16 bytes at blob+0xdd when flag blob+0xdc set, into single global 0x7005d0; signals SM 0x6cba55=1/2. Flag/field offsets inferred from stack-overflow layout (hence Medium).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c3370.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
