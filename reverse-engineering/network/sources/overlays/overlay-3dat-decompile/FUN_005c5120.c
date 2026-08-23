FUNCTION FUN_005c5120 @ 0x005c5120  size=128
CALLERS (6): FUN_005c6500@0x005c6500, FUN_005c4d20@0x005c4d20, FUN_005bbfc0@0x005bbfc0, FUN_005bc050@0x005bc050, FUN_005bb670@0x005bb670, FUN_005bc430@0x005bc430
CALLEES (0): 
----------------------------------------------------------------

void FUN_005c5120(char *param_1,uint *param_2)

{
  *param_2 = (int)*param_1 << 0x1c | (param_1[1] + -0x30) * 0x1000000 |
             (param_1[2] + -0x30) * 0x100000 | (param_1[3] + -0x30) * 0x10000 |
             (param_1[4] + -0x30) * 0x1000 | (param_1[5] + -0x30) * 0x100 |
             (param_1[6] + -0x30) * 0x10 | (int)param_1[7] - 0x30U;
  return;
}



================================================================