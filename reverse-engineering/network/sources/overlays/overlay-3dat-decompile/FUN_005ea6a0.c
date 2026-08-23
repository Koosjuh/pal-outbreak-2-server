FUNCTION FUN_005ea6a0 @ 0x005ea6a0  size=120
CALLERS (0): 
CALLEES (1): FUN_005eee00@0x005eee00
----------------------------------------------------------------

undefined8 FUN_005ea6a0(undefined8 param_1,int param_2)

{
  int iVar1;
  
  if (0x7d < *(int *)(iRam007012a0 + 4)) {
    FUN_005eee00(iRam007012a0 + 0xd8e4);
  }
  iVar1 = *(int *)(iRam007012a0 + 4);
  *(int *)(iRam007012a0 + 4) = iVar1 + 1;
  *(undefined1 *)(param_2 + iVar1) = 0x26;
  *(undefined1 *)(param_2 + *(int *)(iRam007012a0 + 4)) = 0;
  return 0;
}



================================================================