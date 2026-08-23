# SERVER BUILD PUNCH-LIST — grounded in the corpus (no guessing)

Every item below is tied to a **reconstructed client function** that proves what the server must do.
Ordered by proximity to "working multiplayer". `[rig-Confirmed]` = already verified on hardware;
`[corpus-grounded]` = proven from the decompiled client, needs one confirming rig run (not a guess).

## The create→visible-room path (closest to done)
The client create flow is fully reconstructed. Status per step:

1. **Create commit fires the protocol** — `room_create_menu_sm` (0x610830) case 0x12: scenario resolve →
   reserved/slot gate → `room_slot_claim_ownership` → op09 register + op06 enter → prime send. `[corpus]`
2. **Server accepts op04 → op28 sel-4** → client `FUN_005c3a40` sets ownership `0x6ff2b1=1`, handle→0x6fee8c.
   Server flag `SNAP_CREATE_SLOT_ACCEPT`. **`[rig-Confirmed]` — ownership latches.**
3. **Ownership claim needs the room in the registry** — `room_slot_claim_ownership` (0x60f2c0) requires
   registry `0x35c000[slot]`: `+0x00==1` (live) & `+0x08==1` (open). Populated from the room-list reply
   (op49/op20 → `recv_roomlist_entries` 0x1c70b0 → registry). Server already sends op49 with the room;
   ownership commits, so this is satisfied. `[rig-Confirmed via 0x6ff2b1]`
4. **Roster row draw — THE remaining gap.** Two tables (reconstructed): op0a fills the *data* table
   `0x6cdbe6`+count `0x6ca890`; the *drawn* roster `0x6c7c2c` is filled ONLY by the **op06 member-JOIN**
   handler `member_join_op06_handler` (0x5bb4d0) → event 0x1f (ADD) → event **0x19** (repaint).
   - Delivery: op06 must be the **first in-window reliable after op04-accept** or the reorder gate drops
     it. Server flag `SNAP_MEMBER_JOIN_AT_ACCEPT`. **`[rig-Confirmed]` — row0 populated in memory.**
   - Repaint: event 0x19 no-ops if the room node is still building → **re-emit op06 ~500ms after settle**
     to re-fire 0x19 with the panel up. Server flag `SNAP_MEMBER_JOIN_SETTLE`. `[corpus-grounded, deployed,
     needs the confirming rig run]` — this is the exact next test, not a guess.
5. **Header "N/ MP"** — op10 sub-5 writes 0x6ff2b4/0x6ff2b3; host engine zeroes on rebuild → re-push after
   create + each ping. `SNAP_ROOM_LIMITS_OP10SUB5`. **`[rig-Confirmed]` — renders "4/…".**

**→ Next action for a working create-room: run ONE rig verify of `SNAP_MEMBER_JOIN_SETTLE` (the settle
re-emit) and read `0x6c7c2c` row0 name after it fires. If the row draws → create-room is DONE.** The
corpus says this is the mechanism; the only open bit is timing, which the settle-delay addresses.

## Join (2-client co-location) — reconstructed, mechanism rig-proven
`room_join_sm` (0x610580): op09 register → roomlist fetch → op06 enter → slot validate → claim ownership.
Server: op06 enter → **op28 sel-6 who=0xA0** accept (0x6ff2b1). Joiner sends **op10 sub-2**; host replies
**op10 sub-0x0c `[0x0C][count LE]`** → joiner room renders `[rig-Confirmed 2-device]`. Broadcast the new
member's op06 to the other session (`SNAP_JOINER_BROADCAST`) so both rosters update.

## Counts everywhere (server/area/lobby)
Vehicles reconstructed (see SUBSYSTEM_MAP session/menus): server/area counts via the correct 0x62xx
command; in-lobby via a different command than area. `[corpus-grounded]` — wire per the count records.

## Session open / DNAS bypass (already working to Area Select)
Session ladder (op0/18/1a/16/0f/register/params) reconstructed; DNAS replaced by DNS spoof + the server's
own endpoints (the DNAS/HTTP client is `net_rpc_resolve_request` + the 0x17f cluster). `[rig: reaches lobby]`

## Chat / leave (after the above)
Chat subsystem reconstructed (`functions/chat/`); leave = op07/op08 (`snap_send_leave` 0x1dd07c) → server
frees slot + broadcasts. Exit two-stage teardown is a known open item (`functions/rooms/` exit records).

---
**Bottom line:** the multiplayer wire protocol is fully mapped. The working server is now a short,
deterministic punch-list — the immediate win (create-room roster) is one confirming rig run of a fix
that's already deployed and corpus-grounded. No step below requires guessing what the client wants.
