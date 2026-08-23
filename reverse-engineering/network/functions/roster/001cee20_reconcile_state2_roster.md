# 0x001cee20 reconcile_state2_roster

| field | value |
|---|---|
| Original address | 0x001cee20 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cee20 |
| Resolved name | reconcile_state2_roster |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00106b60, FUN_001cd500, FUN_001cd620, FUN_001cda90, FUN_001ceda0
**Referenced globals:** 0x4f83e0 live member array; uRam00343582 array selector
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam00343582

## Behavioral explanation
Diffs the state-2 snapshot (via FUN_001ceda0) against the live array at 0x4f83e0 (indexed by uRam00343582) and applies leaves via FUN_001cda90/FUN_001cd500/FUN_001cd620.

## Notes / uncertainty
Rewrote to full reconstruction. State-2 teardown-only counterpart of ce970 (add side = FUN_001cef80): snapshot (ceda0, state==2) diffed against live array 0x4f83e0[selector 0x343582]; survivors->cache release (cda90 (4,2)) + tex-entry mark (cd500 *=1) + leave notify (cd620). No re-register half, no suppress gate. cd620 a3 arg register-obscured (left symbolic); live-array row bounds trust-the-raw.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cee20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
