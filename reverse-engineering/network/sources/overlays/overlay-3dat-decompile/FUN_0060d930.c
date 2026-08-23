FUNCTION FUN_0060d930 @ 0x0060d930  size=332
CALLERS (1): FUN_0060dea0@0x0060dea0
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_0060d930(uint *param_1,short *param_2)

{
  short sVar1;
  undefined4 uVar2;
  
  if (*param_2 == 0x4d42) {
    param_1[1] = *(uint *)(param_2 + 9);
    param_1[2] = *(uint *)(param_2 + 0xb);
    sVar1 = param_2[0xe];
    if ((sVar1 == 0x18) || (sVar1 == 8)) {
      *param_1 = 0;
      if (sVar1 == 0x18) {
        param_1[5] = 3;
        param_1[3] = param_1[1] * 3;
        param_1[6] = 8;
        param_1[7] = 0x10;
        param_1[8] = 0xff;
        param_1[9] = 8;
        param_1[10] = 8;
        param_1[0xb] = 0xff;
        param_1[0xc] = 8;
        param_1[0xd] = 0;
        param_1[0xe] = 0xff;
        param_1[0xf] = 0;
        param_1[0x10] = 0;
        param_1[0x11] = 0;
      }
      else {
        *param_1 = *param_1 | 4;
        param_1[5] = 1;
        param_1[3] = param_1[5] * param_1[1];
        param_1[7] = 0;
        param_1[6] = 0;
        param_1[8] = 0;
        param_1[10] = 0;
        param_1[9] = 0;
        param_1[0xb] = 0;
        param_1[0xd] = 0;
        param_1[0xc] = 0;
        param_1[0xe] = 0;
        param_1[0x10] = 0;
        param_1[0xf] = 0;
        param_1[0x11] = 0;
      }
      uVar2 = 1;
    }
    else {
      func_0x0019c840(0x64b660);
      uVar2 = 0;
    }
  }
  else {
    func_0x0019c840(0x64b620);
    uVar2 = 0;
  }
  return uVar2;
}



================================================================