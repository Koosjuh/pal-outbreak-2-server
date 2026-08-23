FUNCTION FUN_00009f28 @ 0x00009f28 size=72
CALLERS (3): FUN_000062e0@0x000062e0, FUN_00006200@0x00006200, FUN_00006630@0x00006630
CALLEES (1): FUN_000060a8@0x000060a8

uint FUN_00009f28(uint param_1,int *param_2)

{
  for (; param_2 != (int *)0x0; param_2 = (int *)*param_2) {
    param_1 = FUN_000060a8(param_1,param_2[4],param_2[5] - param_2[4]);
    param_1 = param_1 & 0xffff;
  }
  return param_1 & 0xffff;
}


================================================================