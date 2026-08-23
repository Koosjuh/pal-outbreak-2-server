# Pi runtime env — the golden's other half (git-tracked mirror)

A "golden" is **code + env**. The code lives in `server/*.js` (pinned by commit + md5 in
`GOLDENS.md`). The env lives in systemd drop-ins on the Pi at
`/etc/systemd/system/pal-server.service.d/*.conf` — which are **not** otherwise in git.
This directory mirrors them so a golden is fully reproducible from the repo, and so the
untracked-env gap that cost us 2026-07-04/05 can't recur.

Mirrored from the live Pi on **2026-07-05**, matching the CONFIRMED golden
`lobby-full-2026-07-05` (`ec69007`, gudp `25a5c956` / snap `8e01d0dc`).

## Effective SNAP_* flags in this env
`SNAP_ACK_OPS=all`, `SNAP_ACK_OP48_ALWAYS=1`, `SNAP_OP48_REPLY_ALL=1`, `SNAP_AREA_OP48=1`,
`SNAP_AREA_OP48_COUNT=10`, `SNAP_AREA_LIST=1`, `SNAP_AREA_CONFIRM_REPLY=1`,
`SNAP_LOBBY_LEAVE_REPLY=1`, `SNAP_ROOMLIST_REPLY=1`, `SNAP_CMD0C_SELECTOR12=1`,
`SNAP_OP40_KEEPALIVE=1`, `SNAP_OP40_KEY=SNAP-SWAN`, `SNAP_SUPPRESS_UNKNOWN_REPLY=1`,
`SNAP_TXSEQ_FIX=1`, `SNAP_LOBBY_SLOTS=2`, `SNAP_ROOM_COUNT=1`, `SNAP_ROOM_SEQ_ADVANCE=1`,
`SNAP_ROOM_SEQ_OFFSET=2`, `SNAP_ROOM_ENTER_OP=0x31`, `SNAP_ROOM_ENTER_F4=0x13`
(+ the `=0` / disabled experiment knobs each drop-in carries).

## ⚠️ `zzz-scenario.conf.disabled` — kept disabled on purpose
Sets `SNAP_AREA_SCENARIO=1`. On the golden code (`ec69007`/`8e01d0dc`) this is **inert** (no
code reads it). But on `d3dacf3` it activates the area-record `+0x03` write that **broke
first area-enter** (see `GOLDENS.md` → NOT A GOLDEN → `d3dacf3`). Left as `.disabled` so it
can never silently re-arm the regressor. Only re-enable if the scenario write is reworked to
not touch the area-select record the enter path reads.

## Apply this env to the Pi
```bash
scp -i <key> deploy/pi-env.d/*.conf <pi-user>@192.0.2.121:/tmp/env.d/
ssh -i <key> <pi-user>@192.0.2.121 \
  "sudo cp /tmp/env.d/*.conf /etc/systemd/system/pal-server.service.d/ && \
   sudo systemctl daemon-reload && sudo systemctl restart pal-server && \
   systemctl show pal-server.service -p Environment | tr ' ' '\n' | grep SNAP_"
```
`.disabled` files are intentionally NOT copied (they end in `.disabled`, not `.conf`).

## Keeping this in sync
This is a hand-synced mirror. After changing a drop-in on the Pi, re-pull it here (or
change it here and push) so repo == Pi. Verify: the flag list above must match
`systemctl show pal-server.service -p Environment`.
