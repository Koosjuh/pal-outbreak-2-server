FUNCTION FUN_005c8db0 @ 0x005c8db0  size=72
CALLERS (0): 
CALLEES (2): FUN_005de0f0@0x005de0f0, FUN_005de110@0x005de110
----------------------------------------------------------------

void FUN_005c8db0(void)

{
  FUN_005de0f0();
  FUN_005de110(*(undefined4 *)(iRam00701068 + 0x68dd0));
  *(char *)(iRam00701070 + 2) = *(char *)(iRam00701070 + 2) + '\x01';
  return;
}



================================================================