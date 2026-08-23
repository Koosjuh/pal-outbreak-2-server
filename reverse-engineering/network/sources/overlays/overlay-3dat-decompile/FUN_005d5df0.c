FUNCTION FUN_005d5df0 @ 0x005d5df0  size=152
CALLERS (2): FUN_005d1670@0x005d1670, FUN_005d2c20@0x005d2c20
CALLEES (0): 
----------------------------------------------------------------

void FUN_005d5df0(int param_1,int param_2,undefined1 param_3)

{
  switch(param_3) {
  case 1:
  case 2:
  case 3:
  case 4:
    *(int *)(iRam00701070 + 4) = *(int *)(iRam00701070 + 4) + param_1;
    *(int *)(iRam00701070 + 8) = *(int *)(iRam00701070 + 8) + param_2;
    break;
  case 5:
  case 6:
    *(char *)(iRam00701078 + 5) = *(char *)(iRam00701078 + 5) + (char)param_2;
  }
  *(undefined4 *)(iRam00701068 + 0x69018) = 2;
  *(undefined1 *)(iRam00701078 + 3) = param_3;
  return;
}



================================================================