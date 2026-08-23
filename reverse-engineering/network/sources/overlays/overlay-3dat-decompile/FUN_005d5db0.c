FUNCTION FUN_005d5db0 @ 0x005d5db0  size=56
CALLERS (1): FUN_005d0af0@0x005d0af0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005d5db0(int param_1,int param_2)

{
  *(int *)(iRam00701070 + 4) = *(int *)(iRam00701070 + 4) + param_1;
  *(int *)(iRam00701070 + 8) = *(int *)(iRam00701070 + 8) + param_2;
  *(undefined1 *)(iRam00701078 + 4) = 0;
  return;
}



================================================================