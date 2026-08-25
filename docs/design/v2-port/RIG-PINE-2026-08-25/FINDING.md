# Live PINE game-start read (2026-08-25) — the seating is SOLVED; joiner REFUSES the start

## The live transition (host = emulator, PINE sampler 0.4s)
```
08:21:45 screen=4 count=1                                   (host alone in the room)
08:21:57 screen=4 count=2  SEAT0=test123 id=00000001  SEAT1=real id=02f807d0
08:22:30 screen=5 count=1 accepts=01020000                 (after Start)
08:22:39 screen=1 (in-game; globals repurposed)
```

## What it proves
- **SNAP_HOST_RESEAT WORKED.** Pre-start (08:21:57): BOTH seated in 0x6c7c2c — host test123 at
  slot 0 (id 00000001), joiner "real" at slot 1 (id 0x02f807d0 = host token, the memberId fix).
  count = 2. The seating/roster problem (T15-T22) is CLOSED.
- **The joiner REFUSES the start.** At Start (08:22:30): 0x6ff2b5 = 01 02 00 00 → slot0(host)=1
  ACCEPTED (pre-set), slot1(joiner)=**2 = REFUSED** (0x6ff2b5 code: 0 pending / 1 accepted (sub-4) /
  2 refused (sub-0x10)). count recomputes to 1 → 0x6ff2b3 < 2 → SOLO shortcut → the joiner never
  gets its barrier 0x6ff2af → "standing by" until the ~147s watchdog.

## Root cause (corpus, Confirmed) — FUN_005bbf20 (the joiner's sub-3 receiver)
```c
if (cRam006ff2b1 == 1) {                 // in-room render flag (passed)
  reset 0x6ff2b2/af, clear 0x6fb758..
  if (cRam006c4b90 == 4 || == 0xe)  FUN_005c5c10(param);  // sub-4 ACCEPT
  else                              FUN_005c5c70(param);  // sub-0x10 REFUSE (0x300 zeros)
}
```
The joiner sends ACCEPT iff its screen 0x6c4b90 is 4 or 0xe (in-room) when the host's sub-3
arrives. The joiner refused → its screen was NOT 4/0xe at that instant. So the last blocker is a
JOINER SCREEN-STATE / timing gap: the host's Start reaches the joiner while the joiner is on some
other screen (candidate: a character/scenario sub-screen, or mid-transition), so it declines.

## Cross-reference
- **openSNAP:** its start/relay model has the server relay the host's start to members and each
  peer respond; it has no character-select screen gate (Auto Modellista) so no direct analogue to
  the 4/0xe condition — but the principle "a peer must be in the joinable state to accept the
  start" is universal. The relay itself is proven working (172 relayed=1 game packets, T22).
- **Corpus:** FUN_005bbf20 accept/refuse (this doc), FUN_005c5c10 sub-4 accept sender, FUN_005c5c70
  sub-0x10 refuse sender, analysis/op10-gamechannel-blobs-RE-2026-08-24.md (sub-3/4/0x10),
  analysis/seated-slot-roster-RE-2026-08-25.md (the accept scan / 0x6ff2b5).

## Next read (decisive)
Run with **PC = JOINER** so PINE can read the joiner's 0x6c4b90 (screen) + 0x6ff2b1 at the
instant the host's sub-3 arrives — that names the exact screen the joiner is on when it refuses,
and whether the fix is server-side timing (delay/re-send sub-3) or a joiner state we must drive.
