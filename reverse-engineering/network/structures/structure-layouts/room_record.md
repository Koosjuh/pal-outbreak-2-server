# struct room_record  (room-list entry)

| field | value |
|---|---|
| Proposed name | room_record |
| Size | 0x28 (op49 SNAP app list) / 0x260 (transport op20 page entry) | 
| Confidence | High |

Two representations. App-level op49 (0x28 stride) and transport-level op20 room-list page (0x260 stride @0x365e20).

## op49 record (0x28)
| Offset | Type | Name | Meaning | Conf |
|---|---|---|---|---|
| +0x00 | char[20] | name | room title | High |
| +0x14 | u32(BE) | current | current players (SNAP_OP49_BE) | High |
| +0x1c | u32(BE) | flags | bit16=locked | High |
| +0x20 | u32(BE) | max | max players | High |
| +0x24 | u32(LE) | handle | server-minted room handle → client 0x6fee68 table → ENTER target | Confirmed |

## op20 transport page record (0x260 @0x365e20, indexed by 0x365e0c)
name(+0x3e), id(+0xf), 8 flag bytes, data(+0xff). See recv_roomlist_entries (0x001c70b0).

**Evidence:** functions/rooms/001c70b0_*.md; FACTS.md op49 fields; G12-op49-fields-RE-2026-07-17.md.
