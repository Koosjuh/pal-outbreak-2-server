# Session close-off — 2026-08-26 (evening): G13 enemy sync MET

Owner-confirmed goal. Two consoles now fight the SAME enemies: they move and attack on
BOTH screens (they downed the owner's character on the real PS2). One env flag, zero code
changes. First v2 golden: `g13-enemy-sync-2026-08-26` (GOLDENS.md, tagged).

## The fix — `SNAP_GAME_BEACON_RELAY=true` (config-only; commits 5274cd6a..4ffe06db)

ROOT (decompile + wire + journal, Confirmed): the game sends TWO transport classes on
op-0x0F. The reliable class (wire 0xA0) is the player stream — already relayed by
`SNAP_GAME_RELAY`, which is why movement synced. The UNRELIABLE class (wire 0x20) was
routed by `#onGameChannel` → `#onGameBeacon` and CONSUMED — the server dropped 100% of it
(431/364/86 frames sent across three captures, 0 forwarded; the deployed build's journal:
3215 beacon lines, all relayed:0). That class carries:
1. the **1 Hz peer keepalive** `(peerIdx<<12)|0` — its loss starves the client's 31 s
   peer-timeout sweep (`FUN_001beb90`; the lastActivity stamp is in the DELAY SLOT of the
   len==0 branch @001bede0, so a zero-length keepalive DOES refresh it; no re-activation
   once active=0) — the 08-26-morning peer-vanish root;
2. the **id-0x0008 ENTITY records** (16.16 coords, owner-peer byte, sparse ~5.5 s
   corrections) — per-entity OWNER-replicated enemy/object state. The joiner never
   received the host-owned enemies' records → enemies frozen on the joiner.

FIX = flip the EXISTING flag: room-scoped byte-identical fan-out except the sender (the
seam was already length-safe: decode strips the low-10 length bits, encode restamps). An
entity-record replay test was added (real 68-byte frame from the wire); suite 838/0.
`SNAP_GAME_BEACON_ECHO` stays 0 — proven fatal (RS1-A). The relay must NEVER rewrite the
slot nibble in the message header (it routes the receiver's peer apply).

RE: `analysis/g13-enemy-sync-RE-2026-08-26.md` (+A1 delay-slot proof, A2 census, A3 role
correction). Session log: `SESSION-LOG-2026-08-26-G13.md` T1–T14. nora: fix review
GROUNDED-WITH-CAVEATS; MET review MET-READY-WITH-CAVEATS, all pre-stamp items done.

## The run that proved it (2026-08-26 ~11:36–11:43 UTC, 2-console)

Relay ≈100% both directions (joiner 81→83 delivered, host 70→72; Pi relay latency p50
1.3 ms; outbound seqs strictly monotonic — no silent-discard trigger). The remote peer
held active=1 on the host's table all run. Owner: enemies moved and attacked on the real
PS2 (joiner) — "a bit flakey, but they ended up downing my char." Evidence:
`captures/v2-live/{g13-run1.pcap,g13-journal.log,g13-watch-run1.log}`; savestates 6–9.

## ⚠ Corrections this session made to the corpus (do not re-import the old labels)

- **The IP↔console mapping in the 08-25 docs was INVERTED.** ARP MAC ground truth:
  PCSX2 emulator = **.248** (MSI NIC, login test123) = room creator = peer0 = HOST this
  run; real PS2 = **.129** (Sony OUI 00-13-15, login "real") = joiner = peer1. Check the
  keepalive slot nibble per capture before trusting any older doc's role labels.
- Enemies are NOT host-authoritative-by-role and NOT seeded lockstep: ownership is
  per-entity (this run they were host-owned; the +11 owner byte says whose they are).
- The >31 s peer-vanish silence control was NOT achieved (max reliable gap 16.4 s), so
  the vanish "did not reproduce" — it is not yet proven "beaten". Open on its own item.

## Deployed state on the Pi (192.168.2.121)

The validated env is now TRACKED: `deploy/pal-server-v2.env.conf` (secrets as
placeholders). Flags: the milestone set + `SNAP_GAME_BEACON_RELAY=true`, `ECHO=0`.
Pi src = repo (56/58 files md5-identical; 2 diffs are this session's comment-only doc
edits, behavior-identical). Golden + rollback: `GOLDENS.md` `g13-enemy-sync-2026-08-26`.

## Known bugs still open (GOALS.md)

- **G14 difficulty** — EASY selected, VERY HARD in effect (one zombie downed both players
  this run). The create optionsWord / rules-carrier family. ⭐ next session.
- **G6 friend list / find users** — NEW EVIDENCE parked (T13): both consoles wedge on an
  unanswered reliable **op-0x25 (40 B, "no handler")**; plus the op-0x49 (59 B) buddy
  lookup retransmit burst. Journals: `captures/v2-live/g6-*.log`. An unanswered reliable
  query holds the send slot → the whole screen loses functionality.
- **G15 end-screen character** (Kevin on both), **G16 joiner member list empty**,
  **G17 cutscene-skip asymmetry** (this run: emulator could not skip, PS2 could).
- G13 follow-ups that do NOT re-open it: flaky movement = client ~5.5 s correction
  cadence (server zero-loss; needs the zero-xref client record-dispatcher RE
  FUN_001bd840/001bd940/001bf800); reverse-direction (joiner-owned) replication
  unexercised (n=1); the >31 s vanish control run.

## Operational lessons (recorded)

- **Never leave logs/pcaps on the Pi** (owner directive, now a memory + practiced this
  session): capture bounded on tmpfs, scp to `captures/v2-live/` immediately after the
  run, then delete Pi-side files AND kill the tcpdump/journalctl processes; verify with
  ls/pgrep/df. Stale unbounded tcpdumps from earlier sessions were found still running.
- Deploy/restart only BETWEEN runs (unchanged; a restart freezes an active game).
- nora's MET review earns its place: it caught the inverted role labels and two
  overstatements BEFORE the owner was asked to stamp — the stamp was made on corrected
  claims.
