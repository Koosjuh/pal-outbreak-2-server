# DATA_STRUCTURES — network state structures

_Index of reconstructed structures. Full layouts in structures/structure-layouts/._

| Structure | What | Layout |
|---|---|---|
| snap_connection | SN@P reliable UDP connection control block (`*(0x25b78c)`) | [layout](structures/structure-layouts/snap_connection.md) |
| member_record | roster/member-list entry (op06/op0a) | [layout](structures/structure-layouts/member_record.md) |
| room_record | room-list entry (op49 0x28 / op20 0x260) | [layout](structures/structure-layouts/room_record.md) |
| lobby_state_block | overlay master UI/state block @0x6c4b90 (0x54dc) | [layout](structures/structure-layouts/lobby_state_block.md) |

More structures (send/reorder pool, screen-object, DNAS ctx) pending — see UNRESOLVED.
