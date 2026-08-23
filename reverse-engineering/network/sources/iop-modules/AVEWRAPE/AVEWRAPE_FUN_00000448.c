FUNCTION FUN_00000448 @ 0x00000448 size=108
CALLERS (1): FUN_00002098@0x00002098
CALLEES (0): 

void FUN_00000448(int *param_1)

{
  if (DAT_00002c58 != -0xe) {
    *param_1 = (int)DAT_00002c58;
    param_1[1] = (int)DAT_00002c5a;
    param_1[2] = DAT_00002c5c;
    param_1[3] = (uint)DAT_00002c60;
    DAT_00002c58 = 0xfff2;
    DAT_00002c5a = 0;
    DAT_00002c5c = 0;
    DAT_00002c60 = 0;
    return;
  }
  *param_1 = -1;
  param_1[1] = -1;
  param_1[2] = -1;
  param_1[3] = -1;
  return;
}


================================================================