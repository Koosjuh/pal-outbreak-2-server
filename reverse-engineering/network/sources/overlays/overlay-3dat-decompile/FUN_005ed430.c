FUNCTION FUN_005ed430 @ 0x005ed430  size=48
CALLERS (6): FUN_005f39d0@0x005f39d0, FUN_005eed40@0x005eed40, FUN_005ed460@0x005ed460, FUN_005ee840@0x005ee840, FUN_005f3230@0x005f3230, FUN_005f3310@0x005f3310
CALLEES (0): 
----------------------------------------------------------------

void FUN_005ed430(undefined2 *param_1,int *param_2)

{
  param_1[2] = 0;
  param_1[3] = param_1[3] + *(short *)(*param_2 + 2);
  *param_1 = param_1[2];
  param_1[1] = param_1[3];
  *(undefined1 *)(param_1 + 8) = 0;
  return;
}



================================================================