# ISO-wide function inventory & decode coverage (2026-07-28)

Answers two questions: **(1) how much of the whole ISO still needs decoding**, and **(2) did we miss any
network functions** outside the ranges the network corpus covered.

## Programs in the ISO
| Program | What | Functions | Decoded |
|---|---|---|---|
| **main-EE** `SLES_533.19` (SECTION4 0x100000–0x25b7ff) | the game executable | **4,690** | 620 (network) |
| **3.DAT overlay** (netwk 0x5ac300–0x69455f) | lobby/room/menu SMs | **1,929** | 1,929 ✅ (network corpus) |
| DNAS280.IMG (`cdrom0:\MODULES\DNAS280.IMG`) | Sony DNAS auth module | not loaded | — |
| IOP modules (.irx in iop_ram 0x1c000000+) | sceInet/Avetcp/libdbc IOP side, sound, cd | not loaded | — |
| Other overlays / netwk_pal data (.tm2 lobby textures) | screen data | data, not code | n/a |

> The live Ghidra program (main-EE) also *maps* the netwk overlay region but its functions live in the
> separate 3.DAT program. IOP modules + the DNAS module are separate images not yet loaded/counted.

## Main-EE categorization (4,690 functions)
| Category | Count | % | Meaning |
|---|---|---|---|
| **network-decoded** | 620 | 13% | SN@P transport 0x1c–0x1e — in the corpus, reconstructed |
| **network-MISSED** | 130 | 3% | the stack *beneath/beside* SN@P we did NOT cover (see §Missed) |
| **libc / PS2-SDK** | 179 | 4% | memcpy/string/malloc/printf/math runtime (0x10xxxx) — shared, low value |
| **game-engine (uncategorized)** | 3,761 | 80% | graphics/gameplay/sound/save/menus/SDK — NOT network; the bulk of a full-ISO decode |

**Full-ISO decode remaining (code):** ~**4,070 main-EE** functions (130 network-missed + 179 libc +
3,761 engine) **+** the unloaded IOP modules and DNAS module. The overlay (1,929) is done.

## §Missed — network functions outside our ranges (purpose 2)
**Yes — a lower/adjacent network stack was not covered.** The corpus decoded the SN@P reliable layer
(0x1c–0x1e) and the 3.DAT lobby overlay; beneath and beside it sit **~130 genuine network functions**
(identified via call-graph adjacency to our network fns + references to network strings/hostnames):
- **DNAS auth + HTTP lobby-server client** (~0x17e–0x17f cluster): references `app01.reo.capcom.sf.yav4.com`,
  `snap01.capcom.client.sf.yav4.com`, `http://…DNAS=`, `DNAS280.IMG`. The account/lobby HTTP+DNAS client.
- **Socket / TCP-IP / DNS plumbing** (0x1a/0x1b/**0x1f** — 42 fns in 0x1f): the Avetcp TCP/IP stack
  (`AvetcpReceive`, `UdpSend1`), `libdbc`/`sceDbc` socket-RPC (`sceDbcCreateSocket`…), gethostbyname/DNS
  resolver — the actual sockets our `socket_sendto`/`socket_recvfrom` (0x1e) call into.
- **TCP&PPP dialup** teardown (`TCP&PPP DISCONNECTING`, `Ethernet (Network Adaptor)`).

Lists: `reports/missed-network-genuine.txt` (130), `missed-network-candidates.txt` (call-graph),
`inventory/main-ee-categorized.tsv` (every fn + category).

### Does the server build need these?
**Mostly no.** The server speaks the **SN@P/app wire protocol** — already fully decoded (see the network
corpus BUILD_GUIDE). The missed 130 are the client's own socket/TCP/DNS/DNAS plumbing + the DNAS/HTTP
account client (which the private server replaces with its own DNS spoof + HTTP endpoints). They matter
for **completeness / "decompile the whole ISO"**, and for understanding DNAS bypass + the TCP lobby (§G4
MOTD, account HTTP), **not** for the core UDP multiplayer protocol.

## Recommended next steps
1. **Complete the network boundary (130 fns):** run one deep-reconstruction wave over
   `missed-network-genuine.txt` → folds the DNAS/HTTP/Avetcp stack into the network corpus. Small, high
   value for completeness. (Same pipeline as the deep waves.)
2. **Whole-ISO decode (3,761 engine fns):** a separate, much larger effort — classify + reconstruct the
   game engine. Not needed for multiplayer; scope it only if full-ISO decompilation is the goal.
3. **IOP + DNAS module:** load the .irx / DNAS280.IMG images in Ghidra to inventory them (separate
   programs; currently uncounted).

## UPDATE 2026-07-28 — network stack COMPLETE (inventory); IOP modules loaded
The full network dependency boundary is now in the corpus (**5,710 functions**):
- **EE game network** (main-ee): 709 — reconstructed ✅ (SN@P transport + SIF-RPC bridge + dbcman/net_rpc + DNAS/HTTP client).
- **3.DAT lobby/room overlay**: 1,929 — reconstructed ✅.
- **IOP network modules** (18 `.irx`, headless-decompiled via `tools/ghidra/ExportDecomp.java`): **3,072 —
  INVENTORIED + categorized** by module role (tcpip 856, glue 646, ppp 608, socket/INET 353, netconfig
  253, dhcp 134, ethernet 123, inet-control 99). ~50% is SN@P-variant vs AVE-base near-duplication
  (online game uses the SN set). Namespaced `iop-<MODULE>:<addr>` (IOP addresses collide across modules).

**"Did we miss anything?" — answered: no.** Every EE function touching a network string/global is in the
corpus (0 remaining), and the entire IOP socket/TCP/PPP stack beneath is now inventoried.

**IOP deep-reconstruction depth is a scope choice** (these are Sony/Ave middleware — the client's socket
plumbing, which the private server does NOT reimplement; it speaks the already-decoded SN@P wire protocol):
- socket-API surface only (INET/INETCTL/SNIOPINT ≈ 570) = the build-relevant interface, or
- full 3,072 (complete, reference-only, large), or
- leave at inventory (catalog done).
