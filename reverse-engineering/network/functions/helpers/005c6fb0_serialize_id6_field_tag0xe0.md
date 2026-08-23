# 0x005c6fb0 serialize_id6_field_tag0xe0

| field | value |
|---|---|
| Original address | 0x005c6fb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c6fb0 |
| Resolved name | serialize_id6_field_tag0xe0 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005c5a10, FUN_005c5ad0
**Callees:** FUN_005be9e0, FUN_005bea10, FUN_005bea60, FUN_005bea80
**Referenced globals:** 0x7018d0 hash-ctx
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Computes a 16-bit hash/checksum over 6 bytes of the input using accumulator context 0x7018d0 (init/update/finalize helpers).

## Notes / uncertainty
Renamed from compute_conn_hash (misread): begin(0xe0)/write 6 bytes/commit/finalize builder into 0x7018d0 — serializes a 6-byte ID (MAC/peer token), not a hash. Builder roles inferred; 6-byte meaning owned by callers.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c6fb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
