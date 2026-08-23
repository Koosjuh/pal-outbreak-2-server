# 0x0060ef20 roomlist_query_open

| field | value |
|---|---|
| Original address | 0x0060ef20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060ef20 |
| Resolved name | roomlist_query_open |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006101d0, FUN_00610580, FUN_00610830
**Callees:** FUN_0060eaa0, FUN_0060eba0, FUN_0060ec60, FUN_0060eff0
**Referenced globals:** ctx+0x19ae0/0x19ae4 (conn/select)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x19ae4 selected mode

## Behavioral explanation
Snapshots the conn arg (+0x19ae4=+0x19ae0) then probes modes 1,2,0 via FUN_0060eaa0/FUN_0060eba0 until one yields >0 results; on success runs FUN_0060eff0 to fetch. Returns fetch result or 0.

## Notes / uncertainty
Priority scan of list modes 1->2->0, first with count>=1 fetched via 0060eff0; else 0. Bucket meanings (op49 selector per mode) inferred, need pcap.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060ef20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
