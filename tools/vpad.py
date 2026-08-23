#!/usr/bin/env python3
"""
vpad.py - programmable virtual gamepad for autonomous PCSX2 navigation.

Uses ViGEmBus + vgamepad to present a virtual Xbox360 controller that PCSX2 reads
as SDL-0 (Pad1 = DualShock2). This is the input half of the autonomous RE loop
(the other halves are capture_screenshot for vision + PINE for game state).
Savestates freeze this VM, so scripted pad input is the navigation path.

PS2 -> SDL face -> X360 button mapping (PCSX2 binds Triangle=FaceNorth etc.):
  cross(X)=A  circle(O)=B  square=X  triangle=Y  up/down/left/right=DPad
  l1=LB r1=RB l2/r2=triggers  start=START  select=BACK

DAEMON MODE (keeps the pad connected so PCSX2 doesn't see connect/disconnect churn):
  python tools/vpad.py daemon                 # hold the pad, execute queued commands
  python tools/vpad.py send "down down cross"  # enqueue a whitespace/comma sequence
  python tools/vpad.py send "wait:500 triangle" # wait:MS delays; hold:btn:MS long-press

ONE-SHOT (connects, plays, disconnects - fine for a quick probe):
  python tools/vpad.py tap down,down,cross
"""
import sys, os, time, pathlib

import vgamepad as vg

B = vg.XUSB_BUTTON
BTN = {
    "cross": B.XUSB_GAMEPAD_A, "x": B.XUSB_GAMEPAD_A,
    "circle": B.XUSB_GAMEPAD_B, "o": B.XUSB_GAMEPAD_B,
    "square": B.XUSB_GAMEPAD_X,
    "triangle": B.XUSB_GAMEPAD_Y, "back": B.XUSB_GAMEPAD_Y,   # PS2 Triangle = go-back here
    "up": B.XUSB_GAMEPAD_DPAD_UP, "down": B.XUSB_GAMEPAD_DPAD_DOWN,
    "left": B.XUSB_GAMEPAD_DPAD_LEFT, "right": B.XUSB_GAMEPAD_DPAD_RIGHT,
    "l1": B.XUSB_GAMEPAD_LEFT_SHOULDER, "r1": B.XUSB_GAMEPAD_RIGHT_SHOULDER,
    "start": B.XUSB_GAMEPAD_START, "select": B.XUSB_GAMEPAD_BACK,
}
HOLD_MS = 120          # default button hold
GAP_MS = 180           # default gap between presses (menus need settle time)

QDIR = pathlib.Path(os.environ.get("TEMP", ".")) / "vpad"
QFILE = QDIR / "cmd.txt"
LOGF = QDIR / "log.txt"


def _tap(gp, name, hold_ms=HOLD_MS):
    b = BTN[name]
    gp.press_button(button=b); gp.update()
    time.sleep(hold_ms / 1000.0)
    gp.release_button(button=b); gp.update()


def run_seq(gp, tokens):
    """tokens: list of 'down'|'cross'|... , 'wait:MS', 'hold:btn:MS'."""
    for tok in tokens:
        tok = tok.strip().lower()
        if not tok:
            continue
        if tok.startswith("wait:"):
            time.sleep(int(tok.split(":")[1]) / 1000.0); continue
        if tok.startswith("hold:"):
            _, name, ms = tok.split(":"); _tap(gp, name, int(ms))
        elif tok in BTN:
            _tap(gp, tok)
        else:
            _log(f"  ! unknown token: {tok}"); continue
        time.sleep(GAP_MS / 1000.0)


def _tokens(s):
    return [t for t in s.replace(",", " ").split() if t]


def _log(msg):
    QDIR.mkdir(parents=True, exist_ok=True)
    with open(LOGF, "a") as f:
        f.write(f"{time.strftime('%H:%M:%S')} {msg}\n")
    print(msg, flush=True)


def daemon():
    QDIR.mkdir(parents=True, exist_ok=True)
    QFILE.write_text("")
    gp = vg.VX360Gamepad()
    _log("vpad daemon up - virtual X360 connected, polling queue")
    try:
        while True:
            txt = QFILE.read_text() if QFILE.exists() else ""
            if txt.strip():
                QFILE.write_text("")               # claim the command
                if txt.strip() == "__quit__":
                    _log("vpad daemon quit"); return
                _log(f"seq: {txt.strip()}")
                run_seq(gp, _tokens(txt))
                _log("seq done")
            time.sleep(0.05)
    finally:
        del gp


def send(seq):
    QDIR.mkdir(parents=True, exist_ok=True)
    QFILE.write_text(seq)
    print(f"queued: {seq}")


def one_shot(seq):
    gp = vg.VX360Gamepad()
    time.sleep(0.3)                                # let PCSX2 enumerate the pad
    run_seq(gp, _tokens(seq))
    time.sleep(0.3)


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print(__doc__); sys.exit(1)
    cmd = sys.argv[1]
    if cmd == "daemon":
        daemon()
    elif cmd == "send":
        send(" ".join(sys.argv[2:]))
    elif cmd == "tap":
        one_shot(" ".join(sys.argv[2:]))
    else:
        print(__doc__); sys.exit(1)
