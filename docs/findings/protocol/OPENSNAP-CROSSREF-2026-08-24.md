# openSNAP ↔ PAL Outbreak F2 cross-reference (2026-08-24)

**Question answered:** can openSNAP (GrenderG) and Bioserver2 (gh0stl1ne GitLab) help bring this
project to completion?

**Answer:** Bioserver2 GitLab = **already vendored** (our `references/bioserver/bioserver-docker-2.4.1`
is a Docker packaging of exactly that codebase — identical 33 Java files, README credits gh0stl1ne).
It is the **KDDI/KICS application-layer** reference (JP transport differs), as already recorded in
FACTS/memory. Nothing new there.
openSNAP = **major new cross-validation source**: an independent clean-room implementation of the
same SN@P transport our PAL client speaks, derived from Auto Modellista (SLUS_206.42) which links the
same `kk*`/`cpn*` SNAP client library family. Vendored at `references/external_repos/openSNAP`
(commit `bcd22f8`, AGPL-3.0 — see its PROVENANCE.md; **reference only, no code copying**).

Upstream explicitly lists "Western versions of Resident Evil Outbreak" as its next protocol target —
collaboration/upstreaming is a real option.

---

## 1. Framing — SAME WIRE PROTOCOL (Observation, both sides independently confirmed)

| Field | Our L1 spec (SLES_533.19 decompile) | openSNAP (SLUS_206.42 + captures) | Verdict |
|---|---|---|---|
| wire+0x00 u16 BE | flags \| len (len = low 10 bits `&0x3ff`, incl. 16B header, excl. trailer) | `TYPE_MASK 0xFC00` / `LENGTH_MASK 0x03FF`, same inclusion | MATCH |
| wire+0x02 u8 | "SUB byte" (our G2 discovery: op28 echoes it) | `packet_number` | MATCH — **names our field** |
| wire+0x03 u8 | opcode | `command` | MATCH |
| wire+0x04 u32 | (first 4 of "12-byte session token") | `session_id` | MATCH (refines our token model) |
| wire+0x08 u32 BE | reliable msg id/seq | `sequence_number` | MATCH |
| wire+0x0c u32 BE | ack field | `acknowledge_number` | MATCH |
| trailer | `ba 47 66 11` (FUN_001d6468) | `FOOTER_MARKER 0xBA476611` (+ `...10` KAGE variant) | MATCH |

## 2. Flag bits — openSNAP RESOLVES our open 🟡 hypotheses (Inference until PAL-decompile-checked)

| Bit | Our L1 spec status | openSNAP semantics (SLUS_206.42-proofed) |
|---|---|---|
| 0x8000 | ✅ RELIABLE | `FLAG_RELIABLE` — MATCH |
| 0x4000 | ✅ carries-ACK | `FLAG_RESPONSE` — compatible (response channel carries ack) |
| 0x2000 | 🟡 routing bit | **`FLAG_ROOM`** (room channel context) |
| 0x1000 | 🟡 routing bit | **`FLAG_LOBBY`** (lobby context = BOTH channel bits set, 0x3000) |
| 0x0800 | ✅ COALESCED | `FLAG_MULTI` — MATCH |
| 0x0400 | (unmapped) | **`FLAG_RELAY`** (chat/game relay; room chat 0xA400, lobby chat 0xB400) |

Our observed kind bytes decode cleanly under this model:
`0xB0` = reliable + lobby-context; `0x60` = openSNAP's documented **bare transport ACK `0x6000`**
(cmd 0x00) — exactly our 20-byte ACK frame; `0xF0` = reliable+response+lobby — i.e. the
"who=0xF0 op48" G2 mystery frames are simply **response-channel reliable frames**, which is
consistent with why acking them (`SNAP_ACK_OP48_F0`) was required.

## 3. Command table — semantic names for our numeric ops (Inference; AM client, shared middleware)

| Our op | openSNAP name | Notes vs our RE |
|---|---|---|
| 0x00 | CMD_ACK | bare transport ack — matches |
| 0x01 | CMD_LOGIN_TO_KICS | **KICS** = the KDDI service name → explains the Bioserver kinship |
| 0x04 | CMD_CREATE_GAME_ROOM | = our op04 create-slot (G12) — matches |
| 0x05 | CMD_DELETE (lobby/room by channel bits) | |
| 0x06 | CMD_JOIN (lobby OR room by channel bits) | = our op06; the lobby/room duality explains the two op06 shapes we saw |
| 0x07 | CMD_LEAVE (lobby OR room) | = our op07 — matches |
| 0x08 | CMD_CHANGE_ATTRIBUTE | |
| 0x09 | CMD_QUERY_ATTRIBUTE | |
| 0x0A | CMD_QUERY_USER | = our op0a member-list — matches |
| 0x0B | CMD_QUERY_GAME_ROOMS | candidate semantic for room-list flows |
| 0x0E | CMD_QUERY_LOBBIES | |
| 0x0F | CMD_SEND (chat/game pkt by flags) | **chat path for the G12 chat gap**: room chat = 0xA400, lobby chat = 0xB400 |
| 0x10 | CMD_SEND_TARGET ("targeted variant with payload subcommands") | = our op10 sub-selector (sub-0x01/0x02/0x0C/0x0E) — **independently confirms the sub-selector model** |
| 0x11 | CMD_SEND_GAME_PACKET_TO_GAME_SERVER | |
| 0x14 | CMD_SEND_ECHO | |
| 0x28 | CMD_RESULT_WRAPPER (status 0x00=OK, 0x27=error dialog) | = our op28 reply wrapper; **echoed packet_number = our G2 "SUB byte echo" discovery**; status codes match our status-0 usage |
| 0x2C/0x2D/0x2E/0x31 | bootstrap LOGIN_CLIENT / SUCCESS / FAIL / FAILURE | fail reason 0x13 = invalid password |
| 0x40/0x41 | CMD_BOOTSTRAP_LOGIN_SWAN / _CHECK | ⚠ our op40 = phase-3 keepalive; AM labels it bootstrap-SWAN. Possibly dual-use or Outbreak-divergent — **do not adopt without a PAL decompile check** |
| 0x48/0x49 | **absent from AM table** | our area-grid NAME query / LOID-STAT list appear Outbreak-specific (or a later SNAP rev). Keep our RE as authority |
| 0x6E | client callback slot "kkSetJoinGameClassCallBack" | = our 0x6e ENTER reply (sets 0x6ff2b1) — **"join game class" names the mechanism** |
| 0x78 | "kkSetLeaveGameClassCallBack" | candidate semantic for the leave/park-death path (post-leave C3 work) |

## 4. Behavioral mechanics openSNAP already implements (useful designs; AGPL — reimplement, do not copy)

- Ack-every-reliable + **duplicate-reliable suppression with re-ACK** (duplicate arrives → ACK again,
  do not re-execute) — directly relevant to our retransmit/pool-exhaustion battles.
- Bare-ACK dedup on outbound, multi-message (0x0800) datagram walk, per-session inbound seq window
  (`accept_incoming` rejects `<= last`), separate reliable/unreliable outbound seq allocation.
- Bootstrap (UDP 9090) vs game (UDP 9091) role split, plugin architecture per game, storage
  interface (SQLite today, swappable), env-config, DNS + web signup services, and a test suite
  incl. `test_udp_reliability` + log-replay tests.

## 5. What openSNAP does NOT give us

- No Outbreak plugin yet (AM only) — all Outbreak app-layer payloads (area records, room records,
  charstats blobs, create-slot 0x65xx/0x66xx handshake, TCP 10127 lobby ladder 0x61xx/0x62xx)
  remain OUR corpus + Bioserver2-semantics work. That is exactly the layer G5/G8/G12 live in.
- No PAL TCP lobby service, no DNAS — our v2 already has those.
- Python/SQLite single-process — fine for lobby-scale load, but production scaling is an
  architecture decision either way; our Node v2 evidence-locked build remains the production base.

## 6. Recommended path to completion (proposal, owner decides)

1. **Adopt the names/semantics, keep our evidence bar:** for each table-3 row used by v2, do the
   one-function PAL decompile check (the jpt_kkCommand-equivalent dispatch in SLES_533.19) and
   promote the mapping Inference→Confirmed in the corpus; update L1 spec §1.2 flag names
   (0x2000 ROOM / 0x1000 LOBBY / 0x0400 RELAY) the same way.
2. **Mine openSNAP's engine behaviors as an oracle** for transport edge cases (duplicate policy,
   ack dedup, seq windows) when v2's SN@P layer hits ambiguity — cheaper than fresh MIPS traces.
3. **Chat (G12 gap):** test the CMD_SEND 0x0F with 0xA400/0xB400 framing hypothesis first.
4. **Long-term:** consider collaborating upstream (openSNAP wants western Outbreak support) OR keep
   v2 as the production server and treat openSNAP purely as reference. License note: AGPL-3.0 —
   protocol facts are free to use; code copying would AGPL our server.

Classification: §1 Observation (both sides evidence-backed); §2/§3 Inference (AM-derived, shared
middleware — each row needs a PAL decompile check before "Confirmed"); §6 Proposal.
