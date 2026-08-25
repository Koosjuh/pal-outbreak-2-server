# Lobby "go back / leave area" flow — RE (2026-07-03)

> **CORRECTION 2026-08-24 (SUPERSEDED in part):** §5's reading of the sel-6/sel-7 completion
> consumer's `param_1` is wrong. `param_1` is the 0x10-byte **stack header struct** built by the
> dispatcher, NOT the app body: `+0x00` = cmd-type marker (0x27 frame = FAIL path, 0x28 = OK),
> `+0x0c` = **pktid** (`wire+0x2e >> 8`) — not "body status" / "match id at body+0xc". Proof and
> the full corrected dispatch chain (incl. the 0x1000-bit room/lobby slot split this doc did not
> see): `analysis/op28-channel-bit-dispatch-2026-08-24.md`. Original text kept below for history.

Ground truth = PAL `SLES_533.19` decompile (`analysis/claude-helper-module-full-2026-05-29.txt`,
`analysis/callback-table-install-{map,evidence}-2026-05-25.md`). Bioserver2 = application intent
only. Grades: **Confirmed** (decompile cite) / **Likely** / **Hypothesis**.

Blocker being explained: in the in-area lobby (`0x6c4b90 == 2`), pressing **Triangle to go back**
freezes — screen stays at 2, cursor locks, only op41 (sync) on the wire.

---

## 0. TL;DR (the machine, in one paragraph)

Triangle-back in the room list runs `FUN_005f7690` → sets lobby main-state `+0xe = 3`,
leave-phase `+0x10 = 2`. The state-3 handler `FUN_005f8060` (phase 2) **arms a "leave" SN@P
context** via `FUN_005c0e30(0,0,0,0x5f81a0)` and advances phase to `+0x10 = 3` (busy-wait). The
context driver `FUN_005c1c80` sends **one or two reliable SN@P requests** (via `func_0x001dd1dc`
/ `func_0x001dd07c`, optional `'STAT'` via `func_0x001dd33c`) and then **waits on a reply**
(`cRam006cbb6d`). Each request installs a **reply handler in the op28 selector table**
(`func_0x001dd1dc` → **selector 7**, `func_0x001dd07c` → **selector 7 + flag 0x1000**,
`func_0x001dd33c` → **selector 8**). If the server never delivers those op28/selector replies (or
the request never left the PS2), `cRam006cbb6d` stays 0, the driver never reaches its done-state,
`+0x10` is stuck at 3, and the lobby SM never runs `FUN_005f8060` phase 4 (which is the only code
that writes `0x6c4b90 = 1` to return to Area Select). **Freeze.**

---

## 1. Input path — how Triangle-back enters the leave machine (Confirmed)

Lobby frame `FUN_005f76f0(0x6c4b90)` dispatches on `+1`; `+1==0` → SM `FUN_005f7800`
(helper:46115-46152). `FUN_005f7800` dispatches main-state `+0xe` (`0x6c4b9e`); state 1 =
`FUN_005f7c80` (the cursor-active room list) (helper:46163-46187).

In `FUN_005f7c80`, button reads use `FUN_005b14b0(mask)`:
- `FUN_005b14b0(0x10)` (confirm) → the room-select path → main-state `+0xe = 2` (`FUN_005f7f30`).
- else `FUN_005b14b0(0x200)` (cancel/Triangle) → `func_0x001b0140(2)` (buzz/UI) + **`FUN_005f7690(param_1,0)`** (helper:46356-46428). **This is the Triangle-back handler.**

`FUN_005f7690(param_1, param_2)` (helper:46085-46105, Confirmed):
```
+1  = 0            ; frame dispatch → run SM
+0xe = 3           ; main state → leave
param_2==0 (Triangle path): +0xf = 0 ; +0x10 = 2
param_2!=0        : +0xf = 0 ; +0x10 = 0
FUN_005aec20(); FUN_005b9110(0x4c) ; +0x45b = 2
```
So Triangle-back sets **main `+0xe=3`, leave-phase `+0x10=2`**.

> Note: there is also a *menu-item* leave (main-state 2 `FUN_005f7f30`, cursor 0 → `+0xe=4`
> `FUN_005f8220`) that sends via `FUN_005bfd80` (cb `0x5f82a0`). That is a **different**
> teardown (helper:46577-46592 / 46603-46622) and is NOT the Triangle path. This doc traces
> the Triangle path (`+0xe=3` / `FUN_005f8060`), which matches "press Triangle → freeze".

---

## 2. The leave state-3 handler `FUN_005f8060` (Confirmed, helper:46523-46566)

Dispatches leave-phase `+0x10`:
- **phase 0**: `+0x10=1`, sound, `+0x16=0x2e`.
- **phase 1**: countdown `+0x16`; on `<0` → `+0x10++`.
- **phase 2** (Triangle entry): `+0x10 = 3`; `FUN_005b68e0()`; **`+0x42b = 8`**; `+0x997 = 0`;
  **`FUN_005c0e30(0,0,0,0x5f81a0)`** — arm leave context, completion cb `0x5f81a0`.
- **phase 3**: `FUN_005b6900()` busy-wait — **STUCK HERE while frozen** (nothing advances `+0x10`
  except the completion cb `0x5f81a0`).
- **phase 4**: on `+0x997==1` → **screen reset to Area Select**:
  `*param_1(0x6c4b90)=1; +1=0; +0xe=0; +0xf=0; +0x10=0; +0x11=0; +0x12=0`.
  on `+0x997==2` → `FUN_005f6970()` (error/alt path).

⇒ **The only code that returns the client to Area Select (`0x6c4b90 → 1`) is phase 4, and phase
4 is reached only when the completion cb `0x5f81a0` sets `+0x997` and advances `+0x10` 3→4.**
`0x5f81a0` runs only when the leave context driver completes. (Confirmed by structure; the body
of `0x5f81a0` itself is not in the dumps — see §6.)

---

## 3. Leave context arm `FUN_005c0e30` (Confirmed, helper:16470-16491)

Guarded by latch `cRam006cbb6c==0`. On arm:
```
zero 0x460 bytes at 0x6cdbe6
FUN_005bf0e0(0..2, params)     ; stash the 3 context handles
uRam006ff2b1 = 3
cRam006cbb6c = 1              ; LATCH busy
pcRam006cbb48 = FUN_005c1c80  ; driver
uRam006cbb4c = 0x5f81a0       ; completion cb (from FUN_005f8060 phase 2)
```
Same arm/driver/completion-cb shape as the op49 arm `FUN_005bfbe0` (helper:15612) and op48.

**Freeze sub-case:** `FUN_005f8060` set `+0x10=3` *before* calling `FUN_005c0e30`. If
`cRam006cbb6c` was already 1 (a prior leave/area context left latched by another `FUN_005c0e30`
caller — `FUN_0062cb00/FUN_0062e720/FUN_00617a50`), the arm returns -1 and **no request is sent**,
yet `+0x10` is already 3 → identical freeze. (Likely secondary cause; verify the latch at
back-press.)

---

## 4. Leave driver `FUN_005c1c80` — the requests + the reply it waits on (Confirmed, helper:17019-17092)

State byte `cRam006cbb68` (0→…→4/5); reply flag `cRam006cbb6d` (set by the reply, see §5):
- **case 0**: `+0x68=1`; `if FUN_005bf1e0(2)==0 → case 2` (skip, ctx2 handle absent);
  else **`FUN_005c0750(0x5c1c30)`** (send #1).
- **case 1**: wait `cRam006cbb6d`: `==1 → case 2`; `==2 → case 5` (fail).
- **case 2**: `+0x68=3`; `if ((FUN_005bf1e0(1)==0 && FUN_005bf1e0(0)==0) || cRam006ce5c4!=0) →
  case 4` (done, no send); else **`FUN_005bfe00(0x5c1c30)`** (send #2).
- **case 3**: wait `cRam006cbb6d`: `==1 → case 4`; `==2 → case 5`.
- **case 4 (success)**: teardown (`FUN_005bf180/130` ×3), `cRam006cbb6c=0`,
  `(*0x5f81a0)(arg0=0,…)`.
- **case 5 (fail)**: `cRam006cbb6c=0`, `(*0x5f81a0)(arg0=0xff,…)`.

`FUN_005bf1e0(n)` = per-level handle-present gate: ctx2=`bRam006ce5d0`, ctx1=`bRam006ce5cf`,
ctx0=`bRam006ce5ce` (helper:15132-15145). So the number of leave requests (0/1/2) depends on
which level handles are live in the current lobby.

### The two senders (Confirmed)
**`FUN_005c0750` (send #1, helper:16166-16200):**
- `FUN_005be0a0(1,0,0x5c1c30)` → allocate a **pending-reply slot** (table `0x6ca960`, stride
  0x20; cb→`+0xc`, tag→`+0x1c`, msg-id→`+0x1e`) (helper:14164-14184).
- if `cRam006ff2b0!=0`: `func_0x001dd33c(uRam006febac, 'STAT'(0x53544154), &0x40000000, 4, 0,
  0x5c06b0)` — reliable **`'STAT'`** send, reply cb `0x5c06b0`.
- tag `+0x1c = FUN_005c2080(2) = 0x70`; msg-id `+0x1e = func_0x001dd1dc(uRam006febac, 0x5c06c0)`.

**`FUN_005bfe00` (send #2, helper:15750-15768):**
- `FUN_005be0a0(1,0,0x5c1c30)`; tag `+0x1c = FUN_005c2080(1) = 0x43`;
  msg-id `+0x1e = func_0x001dd07c(uRam006febac, 0x5bfe90)` — reply cb `0x5bfe90`.

### Wire identity of the requests / the reply the client waits on (Confirmed slot map)
`func_0x001dd07c/1dc/33c` each: alloc pool buffer `FUN_001d5288(conn,…)` (the **same
`conn+0x520` reliable-send pool** op49 uses), read a per-connection channel byte
(`conn+0x61a`/`0x61b`/`0x61c`), send via **`FUN_001e180c`** (flags `0xb000`/`0xa000`), then
**install a reply handler in the dispatcher slot table** `conn+0x548+slot*4`:

| Sender | Used by | Install slot | Dispatcher meaning (map:54-56) |
|---|---|---:|---|
| `func_0x001dd07c` | `FUN_005bfe00` (send #2) | **0x23** | **op28 selector 7, flag 0x1000** |
| `func_0x001dd1dc` | `FUN_005c0750` (send #1) | **0x24** | **op28 selector 7, normal** |
| `func_0x001dd33c` | `FUN_005c0750` `'STAT'` | **0x25** | **op28 selector 8** |

(Slots from `callback-table-install-map-2026-05-25.md:54-56,87-89`; install disasm
`callback-table-install-evidence-2026-05-25.md:549-551,588-590,627-629`.)

⇒ **The reply the client is waiting on is an `opcode 0x28` (selector-carrying) reply with
selector 7 (both the normal and the flag-0x1000 variant) and selector 8 for the `'STAT'` leg.**
This is the **same op28/selector family** the server already speaks for area-confirm (selector 6)
and the cmd0c poll (selector 12).

---

## 5. How the reply completes the machine (Confirmed, helper:15779-15798 / 14194-14235 / 14099-14120)

Reply plumbing (identical shape for both legs; `FUN_005bfe90` shown):
1. Server op28/selector-7 reply arrives → dispatcher → the low-level reply cb (`0x5bfe90` /
   `0x5c06c0`).
2. `FUN_005bfe90` (helper:15779): reads reply `body[0]` — `==0` → `cRam006cbc84=0` (OK);
   `==0x27('\'')` → `cRam006cbc84=0xff` (fail). Sets `sRam006cbc80 = reply.body+0xc` (**the echoed
   msg-id**), `sRam006cbc7c = FUN_005c2080(1)=0x43` (tag), `sRam006cbc7e = 2`; calls
   `FUN_005bdfe0(0)`.
3. `FUN_005bdfe0` (helper:14099): `sRam006cbc7e==2` → arg0 = 0(ok)/0xff(fail) →
   `FUN_005be120(arg,1,0)`.
4. `FUN_005be120` (helper:14194): scans the pending table `0x6ca960` for a slot whose
   `+0x1e == sRam006cbc80` **and** `+0x1c == sRam006cbc7c`; clears it and calls its cb
   (`0x5c1c30`) with the ok/fail byte.
5. `0x5c1c30` sets **`cRam006cbb6d = 1` (ok) / `2` (fail)** (Likely — cb body not in dumps, §6;
   it is the only writer consistent with `FUN_005c1c80` case 1/3).
6. `FUN_005c1c80` advances → case 4 → completion cb `0x5f81a0(arg0=0)` → sets `+0x997=1`,
   `+0x10=4` (Likely, §6) → `FUN_005f8060` phase 4 → **`0x6c4b90 = 1` (back to Area Select).**

**Reply-match requirement (Confirmed):** the reply must echo, at `body+0xc`, the **msg-id** the
client assigned to the request (the incremented `conn+0x61a/b` channel byte). Exactly like op48/
op49 replies mirror `request_id` (`game_udp_server.js:554`). Status is `body[0]` (0=OK, 0x27=fail).

---

## 6. What the server must send — concrete (server-satisfiable IF the request transmits)

When the client emits the leave request(s) on the current SN@P connection (`uRam006febac`, the
same conn as op48/op49), reply with, per outstanding request:

- **op28 reply, selector 7 (normal, no 0x1000 flag)** — completes `FUN_005c0750` send #1.
- **op28 reply, selector 7 (flag 0x1000 variant)** — completes `FUN_005bfe00` send #2.
- **op28 reply, selector 8** — completes the `'STAT'` leg (only sent when `cRam006ff2b0!=0`).

Each reply body: `body[0]=0` (status OK), and `body[0xc]=` the request's msg-id / channel byte
echoed back so `FUN_005be120` matches. Deliver on the same conn/port as the op48/op49 replies,
via the existing op28/selector reply builder (the code path already used for
`SNAP_AREA_CONFIRM_REPLY` op28/sel6 and `SNAP_CMD0C_SELECTOR12`).

Which of the 1/2/3 replies are actually needed depends on the live level handles at back-press
(`bRam006ce5ce/cf/d0`) and `cRam006ff2b0`. Safest server behavior: answer **any** inbound leave
request with the matching-selector op28 status-0 reply (mirror id).

### `who` byte / body fields
The request is a reliable DATA on the op48/op49 conn; the server keys off the **op28 selector**
in the reply (7 and 7|0x1000 and 8), not a distinct "who". The **exact request opcode byte** the
client puts on the wire (so the server can recognize "this is a leave request and reply now") is
set inside `FUN_001e180c` / the un-dumped head of `func_0x001dd07c/1dc/33c` — **needs Ghidra
(§7).** Until then, recognize the leave by: reliable DATA on the lobby conn immediately after
`0x6c4b9e` goes to 3 / `0x6cbb6c` goes to 1 (PINE-correlated).

---

## 7. Needs fresh Ghidra decompile (prioritized)

1. **`func_0x001e180c`** and the **buffer-building head of `func_0x001dd07c` / `_001dd1dc` /
   `_001dd33c`** — to get the **request opcode byte on the wire** (so the server can match the
   leave request without guessing). Highest priority: without it we can only *reply by selector*,
   not *recognize the request opcode*.
2. **`FUN_005c1c30`** (`0x5c1c30`) — confirm it sets `cRam006cbb6d = 1/2` from the reply status
   byte (assumed in §5 step 5).
3. **`FUN_005f81a0`** (`0x5f81a0`) — confirm it sets `+0x997=1/2` and `+0x10=4` (assumed §5 step
   6, §2 phase 4).
4. **`FUN_005c06b0` / `FUN_005c06c0`** — the send-#1 low-level reply handlers (analogues of
   `FUN_005bfe90`); confirm they set `sRam006cbc7c/80/7e` and call `FUN_005bdfe0`.
5. **`FUN_0062cb00` / `FUN_0062e720` / `FUN_00617a50`** — other `FUN_005c0e30` callers; confirm
   none leaves `cRam006cbb6c` latched into the lobby (the §3 secondary freeze).

---

## 8. EE fields to watch (PINE) — validates the model + discriminates the two root causes

Lobby struct base `0x6c4b90`:
| Addr | Field | Frozen value | Should become |
|---|---|---|---|
| `0x6c4b90` | screen id | **2** | **1** (Area Select) on success |
| `0x6c4b9e` | main state `+0xe` | **3** (leave) | 0 after phase 4 |
| `0x6c4ba0` | leave phase `+0x10` | **3** (busy-wait) | 4 → then reset |
| `0x6c5527` | result `+0x997` | **0** | 1 (ok) / 2 (err) |

Leave context:
| Addr | Field | Frozen | Meaning |
|---|---|---|---|
| `0x6cbb6c` | latch | **1** | leave in flight |
| `0x6cbb68` | driver step | **1 or 3** | waiting for reply |
| `0x6cbb6d` | reply flag | **0** | reply not received (→1 ok/2 fail) |
| `0x6ff2b0` | STAT gate | — | nonzero ⇒ selector-8 also sent |
| `0x25b790` | pool err | **0x65?** | if 0x65 ⇒ request pool-alloc FAILED (never sent) |

**Discriminator (the key experiment, §9):**
- If at back-press `0x6cbb6c=1`, `0x6cbb68∈{1,3}`, `0x6cbb6d=0`, **and `0x25b790!=0x65`** and a new
  reliable DATA (not op41) is on the wire → **request sent, server didn't reply** → the §6 op28
  reply fixes it. Server-satisfiable.
- If `0x25b790=0x65` and **no** new DATA on the wire (only op41) → **request never left the PS2**
  (same `conn+0x520` reliable-send pool exhaustion as the op49 cursor-lock,
  `LOBBY-STATE-MACHINE-RE-2026-07-02.md`). Then **op28 replies alone cannot fix it**; the fix is
  the shared transport problem: our server must ACK the game's reliable sends so `conn+0x520`
  frees. Same wall, different symptom.
- If `0x6cbb6c` was **already 1** before back-press (arm refused) → the §3 latch case; needs the
  `FUN_005c0e30`-caller audit (§7.5).

---

## 9. Highest-leverage next experiment (single change + verify)

**Hypothesis:** the Triangle-back leave request *does* transmit, and the freeze is a missing
op28/selector-7 reply (the analogue of the area-confirm sel6 reply that already works).

**Server change (one):** extend the existing op28/selector reply path to also answer **selector 7
(both the normal and 0x1000-flag variants) and selector 8** with `body[0]=0` and the request
msg-id mirrored — gated behind a new `SNAP_LOBBY_LEAVE_REPLY` flag so it is isolated and
rollback = flag off.

**Verify (rig):**
1. PINE-watch `0x6cbb6c,0x6cbb68,0x6cbb6d,0x25b790,0x6c4b90,0x6c4ba0` (light interval; PINE
   observer-effect breaks render, so watch few addresses).
2. pcap on 9090: confirm (a) a new reliable DATA leaves the PS2 on Triangle-back, and (b) the
   server's op28/sel7 reply, then (c) `0x6cbb6d` flips 0→1 and `0x6c4b90` flips 2→1.
3. Screen: lobby returns to Area Select.

**What failure proves:** if `0x25b790=0x65` and no new DATA appears, the leave request never
transmitted → this is the `conn+0x520` reliable-send-pool wall (op49 finding), not a reply gap →
stop tuning the leave reply and work the transport ACK/pool problem.

---

## Confidence summary

- Input→leave-machine chain (`FUN_005f7690` → `+0xe=3`/`+0x10=2` → `FUN_005f8060` phase 2 →
  `FUN_005c0e30` → `FUN_005c1c80` → `FUN_005c0750`/`FUN_005bfe00`): **Confirmed** (cited).
- Reply the client waits on = **op28 selector 7 (±0x1000) + selector 8, status 0, id mirrored**,
  routed through `FUN_005be120` → `cRam006cbb6d`: **Confirmed** (slot map + reply plumbing cited);
  the final two hops (`0x5c1c30` sets `cRam006cbb6d`; `0x5f81a0` sets `+0x997`/`+0x10`) are
  **Likely** pending §7.2/§7.3.
- Return-to-Area-Select is a **local screen write** (`0x6c4b90=1`) in phase 4, gated entirely on
  the reply — **Confirmed**. No area-select data re-serve is required by *this* code to leave; on
  re-entry the normal Area-Select op48 re-activation applies as before (unchanged).
- Whether the request actually transmits (server-satisfiable) vs. is dropped at
  `conn+0x520` pool-alloc (same op49 wall): **Open** — resolved only by the §8 PINE/pcap
  discriminator. Honest bottom line: the reply is fully specified and server-craftable, but it
  only helps if the leave request leaves the PS2.
