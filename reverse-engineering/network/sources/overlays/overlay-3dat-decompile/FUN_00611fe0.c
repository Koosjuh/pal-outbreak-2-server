FUNCTION FUN_00611fe0 @ 0x00611fe0  size=60
CALLERS (1): FUN_00610830@0x00610830
CALLEES (1): thunk_EXT_FUN_001b00f0@0x006187d0
----------------------------------------------------------------

void FUN_00611fe0(undefined1 param_1)

{
  *(undefined1 *)(iRam0070d1c0 + 0x21) = *(undefined1 *)(iRam0070d1c0 + 0x20);
  *(undefined1 *)(iRam0070d1c0 + 0x20) = param_1;
  *(undefined1 *)(iRam0070d1c0 + 0x1f) = 0;
  *(undefined1 *)(iRam0070d1c0 + 0x4e) = 1;
  thunk_EXT_FUN_001b00f0();
  return;
}



================================================================