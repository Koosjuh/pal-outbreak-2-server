FUNCTION FUN_00010070 @ 0x00010070 size=36
CALLERS (12): FUN_0000e3c8@0x0000e3c8, FUN_00006f6c@0x00006f6c, FUN_0000dc5c@0x0000dc5c, FUN_00010000@0x00010000, FUN_00010108@0x00010108, FUN_0000e0e0@0x0000e0e0, FUN_0000985c@0x0000985c, FUN_0000670c@0x0000670c, FUN_0000baf0@0x0000baf0, FUN_0000a720@0x0000a720, FUN_0000bb44@0x0000bb44, FUN_000097c0@0x000097c0
CALLEES (0): 

void FUN_00010070(int param_1)

{
  if ((param_1 != 0) && (*(char *)(param_1 + 0x18) == '\x01')) {
    *(undefined1 *)(param_1 + 0x18) = 0;
  }
  return;
}


================================================================