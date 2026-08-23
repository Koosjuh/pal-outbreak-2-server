FUNCTION FUN_005ae210 @ 0x005ae210  size=72
CALLERS (1): FUN_005ae130@0x005ae130
CALLEES (2): FUN_00618b60@0x00618b60, FUN_005b24c0@0x005b24c0
----------------------------------------------------------------

undefined8 FUN_005ae210(int param_1)

{
  FUN_00618b60();
  func_0x003adb80();
  FUN_005b24c0();
  *(undefined1 *)(param_1 + 0x447) = 0;
  *(char *)(param_1 + 0x993) = *(char *)(param_1 + 0x993) + '\x01';
  return 0;
}



================================================================