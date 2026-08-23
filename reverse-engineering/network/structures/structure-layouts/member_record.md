# struct member_record  (roster / member-list entry)

| field | value |
|---|---|
| Proposed name | member_record |
| Size | 0x108 (in op28 member-list) / 0x114 relayed |
| Confidence | Confirmed (op06 + op0a share it; rig-verified names/ids) |

Carried by op06 member-JOIN and op28 selector-0x0a member-list; the client renders exactly these bytes.

| Offset | Type | Name | Meaning | Conf |
|---|---|---|---|---|
| +0x00 | char[16] | name | display name (login handle) — drawn in roster row+0x10 | Confirmed |
| +0x10 | u32 | id | member id (BE in op28 list, `(i+1)`); encoded to 8 ASCII digits by FUN_005c50a0 → roster row+0x00 | Confirmed |
| +0x14 | u32 | charstats_len | 0xf0 | High |
| +0x18 | u8[0xf0] | charstats | character stats blob; char-id at +0xc8 (rec+0xe0) | High |

**Readers:** member_join_op06_handler (0x005bb4d0), op0a fill FUN_005c0ae0. **Roster table:** 0x6c7c2c stride 0x3b0 x4.
**Evidence:** functions/roster/005bb4d0_*.md; analysis/G12-identity-vehicle-RE-2026-07-17.md; roster-row-draw-RE-2026-07-25.txt.
