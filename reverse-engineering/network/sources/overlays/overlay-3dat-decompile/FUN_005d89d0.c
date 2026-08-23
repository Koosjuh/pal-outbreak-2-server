FUNCTION FUN_005d89d0 @ 0x005d89d0  size=152
CALLERS (1): FUN_005e9f80@0x005e9f80
CALLEES (0): 
----------------------------------------------------------------

void FUN_005d89d0(long param_1,undefined8 param_2)

{
  func_0x00106b60(iRam00701070 + 0x3b,0,0x100);
  func_0x00109eb8(iRam00701070 + 0x3b,param_2);
  if (param_1 == 0) {
    *(undefined4 *)(iRam00701068 + 0x69014) = 0x1e;
  }
  else {
    *(int *)(iRam00701068 + 0x69014) = (int)param_1 * 0x1e;
  }
  return;
}



================================================================