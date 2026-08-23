# struct lobby_state_block  (overlay UI/state block @ 0x6c4b90)

| field | value |
|---|---|
| Proposed name | lobby_state_block |
| Base | 0x006c4b90 |
| Size | 0x54dc (memset by overlay_init_full 0x005ac610) | 
| Confidence | High |

The overlay's master state block. Key fields (many more per the 526 ui / 341 menus records):

| Offset(abs) | Name | Meaning | Conf |
|---|---|---|---|
| 0x6c4b90 | screen_id | current lobby/room sub-screen (lobby_screen_dispatch switch) | Confirmed |
| 0x6c4b9e | lobby_sm | area/room SM state | High |
| 0x6c4b9f | screen_major | create/join SM major sub-state | High |
| 0x6c4ba0 | screen_step | SM step counter | High |
| 0x6c4faa | top_screen | top-menu dispatcher state (menu_top_dispatch) | Confirmed |
| 0x6c4fab | top_substate | top-menu substate | High |
| 0x6c4fbb | pending_tag | pending-op tag (0x11 enter, 0x17 join) | High |
| 0x6cba78 | owner_substate | create ownership SM substate | High |
| 0x6cba7d | op04_complete | op04 accept flag | High |
| 0x6cbc7e | room_mode | 0x10 = roster panel active | Confirmed |
| 0x6ff2b0 | host_flag | 1=creator | Confirmed |
| 0x6ff2b1 | unlock_gate | title/pw/scenario/char unlock | Confirmed |
| 0x6ff2b3/0x6ff2b4 | cur/max | in-room panel current/max (op10 sub-5) | Confirmed |
| 0x6c7c2c | roster_table | 4×0x3b0 drawn roster rows | Confirmed |
| 0x6ca890 | op0a_count | member-list count | Confirmed |

**Evidence:** functions/lobby/005acab0_*.md, functions/menus/005ac8a0_*.md, GLOBALS.md, FACTS.md, SESSION-LOG-2026-07-25.md.
