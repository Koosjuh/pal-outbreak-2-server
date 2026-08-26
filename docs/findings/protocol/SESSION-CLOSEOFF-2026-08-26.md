# Session close-off — 2026-08-26: the multiplayer CORE works

Owner-confirmed milestone. Two consoles (PC/PCSX2 host + real PS2 joiner) now start a game
together, with the RIGHT characters on the splash, and both survive cutscenes and zone changes.

## What was fixed this session (all deployed to the Pi, flags ON, nora-reviewed)

### 1. Solo start — `SNAP_OP10_DROP_SELF` (commits 768c12f3, e8b46d8a, 091213c8)
2-player starts went solo. ROOT (decompile + wire, Confirmed): the host start SM (FUN_005c6500)
loops EVERY seated slot INCLUDING its own seat0 and emits one op-0x10 **sub-3** START per seat,
bundled in a 0x0800-multi datagram. The relay fanned BOTH to the joiner; the joiner ACCEPTs the
first (screen 4/0xe), the accept advances its screen off 4/0xe, and the SECOND sub-3 hits the
REFUSE branch (FUN_005bbf20 else) → accept count never holds at 2 → solo.
FIX: in #onRoomEventRelay drop the frame whose `event.words[0] === this.#endpointToken` **for
sub-3 ONLY** (`OP10_START_SEAT_LOOP_SUBS = {0x03}`). CRITICAL: sub-5/6/7/8 are the payload HANDOFF
(host's own idx/peer-info/charstats, word0==host token, joiner NEEDS them) — the first over-scoped
`{3,5,6,7,9}` starved the joiner (wrong chars + net error), narrowed to `{3}` fixed it.
RE: `analysis/solo-start-refuse-RE-2026-08-26.md`.

### 2. Characters / splash — `SNAP_CHARSTATS_SEED` (commits 7585f4b3, d2956aec, 6defab00)
Splash rendered "Jim"/"Mark" (defaults) because the op-06 member record's rec+0x18 charstats
(0xf0) was sent as zeros; op-0c (char-select) is ACK-ONLY so a peer never learns another's pick.
ROOT chain (Confirmed): splash sub-7 source = `0x700734 ← 0x6ff70d ← seat 0x6c7c2c+0x24 ← op-06
rec+0x18`. The inbound op-0c apply (FUN_005bc430) writes only a DISPLAY table (0x6cdbe6), never the
seat — so a raw op-0c relay (the earlier T25 regression) can NEVER fix the splash (Path B refuted).
Byte-map decompile-Confirmed 1:1: `rec+0x18[0..0xf0) = op0c_body[0..0xf0)`, char-id @+0xc8. Wire:
op-0c precedes the seat op-06 (select-before-join) → no defer.
FIX: capture the 0xf0 char-select op-0c per session (#onRoomQuery, length===0xf0), seed rec+0x18 at
every member-record emit — joiner-own, fanout (joiner→host), roster-to-joiner (host→joiner, via the
table `resolveCharstats` seam), AND the host self-seat sites (reseatSelf + #sendCreateFollowUps,
which had seated characterId:1 = Mark). RE: `analysis/charstats-to-sub7-source-RE-2026-08-26.md`.

### 3. Peer-vanish RESOLVED (observed alongside #2)
Earlier the host DEACTIVATED the joiner peer after a cutscene (savestate: peer[1] active=0,
accumulator zero). This build's savestates show **peer[1] active=1 with an advancing accumulator** →
both characters persist through cutscenes and zone changes; enemies load on both consoles.
Diagnosis: `analysis/ingame-peer-vanish-RE-2026-08-26.md` (server relay was ruled out — it carried
all 1336 game packets losslessly; it was a client-side peer state).

## Deployed flag set on the Pi (192.168.2.121, /etc/pal-server-v2/env)
`SNAP_OP10_DROP_SELF=true`, `SNAP_CHARSTATS_SEED=true`, plus the milestone set
(`SNAP_GAME_RELAY`, `SNAP_HOST_RESEAT`, `SNAP_MEMBER_ID_TOKEN`, `SNAP_ROSTER_TO_JOINER`,
`SNAP_CHANNEL_BIT_ECHO`, `SNAP_COMPLETION_SEQ_ECHO`, `SNAP_EXIT_CLOSE_MIRROR`). Suite 837/0.

## Known bugs still open (Backlog G13–G17)
- **G13 enemy movement** — enemies move only on the host, frozen on the joiner (biggest gap).
- **G14 difficulty** — set EASY still runs VERY HARD (override not propagating to game-start).
- **G15 end-screen character** — results screen shows "Kevin" on BOTH consoles (separate render
  path from the splash).
- **G16 joiner member list** — host's Start▸Member shows the roster, the joiner's is empty.
- **G17 cutscene-skip asymmetry** — one console can skip, the other can't.

## Operational lesson (recorded)
Deploying restarts the Pi, which drops the in-game relay and FREEZES an active game (it froze the
owner's PS2 mid-run). **Deploy only BETWEEN runs.**
