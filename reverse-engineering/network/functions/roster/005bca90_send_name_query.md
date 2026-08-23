# 0x005bca90 send_name_query

| field | value |
|---|---|
| Original address | 0x005bca90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bca90 |
| Resolved name | send_name_query |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bdf90, FUN_005c4f40, FUN_005c4fd0, FUN_005c7e30, FUN_005c7f20
**Referenced globals:** 0x6febac (connection handle); 0x86f7f8 (accumulator reset); 0x6febb4 (local seq); 0x6cc440/0x6cc450 (local name/id); 0x639e68/0x639e78 (string tables); 0x86f820 (local id)
**Referenced strings:** NAME (0x4e414d45 tag)
**Referenced opcodes:** 0x48
**State vars:** —

## Behavioral explanation
Builds and sends a 'NAME' query request: on sub-type 0 assembles a request struct tagged 0x4e414d45 ('NAME') carrying local name (FUN_005c4f40) and id (FUN_005c4fd0) and transmits via func_0x001e094c with completion callback FUN_005bc990; sub-type '\'' renders an error dialog.

## Notes / uncertainty
Builds/sends op48 'NAME' (tag 0x4e414d45) request, callback 0x5bc990; resets accumulator. Error path's func_0x00109728(buf,table,idx) uses index as length — likely mis-typed table lookup.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bca90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
