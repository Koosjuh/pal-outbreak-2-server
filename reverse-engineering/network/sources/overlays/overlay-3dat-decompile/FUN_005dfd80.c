FUNCTION FUN_005dfd80 @ 0x005dfd80  size=88
CALLERS (1): FUN_005dfee0@0x005dfee0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005dfd80(undefined8 param_1)

{
  func_0x00106b60(param_1,0,0x80);
  *(undefined4 *)((int)param_1 + 0x20) = *(undefined4 *)(iRam00701068 + 0x5ff6c);
  *(int *)(iRam00701068 + 0x5ff6c) = (int)param_1;
  return;
}



================================================================