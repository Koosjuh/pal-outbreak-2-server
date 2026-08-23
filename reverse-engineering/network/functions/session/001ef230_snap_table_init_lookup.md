# 0x001ef230 snap_table_init_lookup

| field | value |
|---|---|
| Original address | 0x001ef230 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef230 |
| Resolved name | snap_table_init_lookup |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c0ca0
**Callees:** FUN_001f0df0
**Referenced globals:** 0x37a278 (latch guard:=0); 0x37a280 (cache:=0); 0x37a2b0 (record table base, stride 0x30c)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x37a278; 0x37a280

## Behavioral explanation
Resets latch guard/cache (0x37a278/0x37a280=0), inits table region via FUN_001f0df0(0x37a2b0,4), and returns the entry at index*0x30c into 0x37a2b0 through *param_2.

## Notes / uncertainty
Zeroes the FUN_001ef1c0 once-latch (a278/a280), inits 0x37a2b0 table via FUN_001f0df0(base,4), returns entry[index] leading word (stride 0x30c=780). Entry layout + '4' arg meaning unknown; key read happens post-init regardless of status.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef230.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
