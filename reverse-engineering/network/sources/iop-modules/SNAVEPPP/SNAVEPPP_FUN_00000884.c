FUNCTION FUN_00000884 @ 0x00000884 size=68
CALLERS (5): FUN_0000f710@0x0000f710, FUN_00000090@0x00000090, FUN_00003b50@0x00003b50, FUN_0000e90c@0x0000e90c, FUN_00008ed8@0x00008ed8
CALLEES (0): 

int * FUN_00000884(int *param_1,short param_2)

{
  if (param_1 != (int *)0x0) {
    if ((int)param_2 <= (*param_1 + -8) - (int)param_1) {
      *param_1 = *param_1 - (int)param_2;
      *(short *)(param_1 + 1) = (short)param_1[1] + param_2;
      return param_1;
    }
  }
  return (int *)0x0;
}


================================================================