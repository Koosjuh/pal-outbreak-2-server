FUNCTION FUN_0000a5c8 @ 0x0000a5c8 size=68
CALLERS (1): FUN_00012170@0x00012170
CALLEES (0): 

void FUN_0000a5c8(undefined4 *param_1,uint param_2)

{
  if (0xb < param_2) {
    param_1[2] = param_2 - 0xc;
    DAT_0001b97c = (int)param_1 + param_2;
    DAT_0001b9e0 = (int)param_2 >> 3;
    DAT_0001b970 = param_1;
    DAT_0001b974 = param_1;
    param_1[1] = 0;
    *param_1 = 0;
    DAT_0001b978 = param_1;
    DAT_0001b9d4 = param_2;
    DAT_0001b9d8 = param_2;
  }
  return;
}


================================================================