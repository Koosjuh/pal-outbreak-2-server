# 0x005ad350 list_entry_select

| field | value |
|---|---|
| Original address | 0x005ad350 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ad350 |
| Resolved name | list_entry_select |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ad030, FUN_005ad680
**Callees:** FUN_005b14b0, FUN_005b8cf0, FUN_005b9110, FUN_005bafc0, FUN_005bb010
**Referenced globals:** 0x6c386e(list A entries); 0x6c45f8(selected); 0x342f30/0x342f31(cur id pair); obj +0x8ec/+0x8ed(chosen id); +0x11/+0x16
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c45f8; cRam00342f30; cRam00342f31

## Behavioral explanation
Entry-select/confirm logic for the list: validates the chosen entry (type byte==3) at index*0x15c in 0x6c386e, reads its id fields (5bafc0/5bb010), records selection into 0x6c45f8; returns 1=accept/-1=reject.

## Notes / uncertainty
Confirm SM on +0x10; validates entry type==3, reads id via 5bafc0/5bb010, commits cRam006c45f8=idx+1 (ret 1) / rejects (ret -1) / animates (ret 0). cRam00342f30/31 current-room pair meaning unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ad350.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
