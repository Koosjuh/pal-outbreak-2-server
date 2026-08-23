FUNCTION FUN_005ae2c0 @ 0x005ae2c0  size=68
CALLERS (1): FUN_005ae130@0x005ae130
CALLEES (1): FUN_005af310@0x005af310
----------------------------------------------------------------

undefined8 FUN_005ae2c0(int param_1)

{
  long lVar1;
  
  lVar1 = FUN_005af310();
  if (lVar1 != 0) {
    *(char *)(param_1 + 0x993) = *(char *)(param_1 + 0x993) + '\x01';
  }
  return 0;
}



================================================================