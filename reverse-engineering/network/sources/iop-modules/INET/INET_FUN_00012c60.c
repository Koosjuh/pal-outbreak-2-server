FUNCTION FUN_00012c60 @ 0x00012c60 size=136
CALLERS (5): FUN_00015430@0x00015430, FUN_000161ec@0x000161ec, FUN_00015a28@0x00015a28, FUN_000151ec@0x000151ec, FUN_0001748c@0x0001748c
CALLEES (4): FUN_0000d508@0x0000d508, FUN_00017bf4@0x00017bf4, FUN_0000a7e0@0x0000a7e0, FUN_00012c00@0x00012c00

void FUN_00012c60(undefined4 *param_1)

{
  undefined4 uVar1;
  
  FUN_0000d508(param_1 + 0x33,0);
  uVar1 = param_1[2];
  if (param_1[1] != 0) {
    *(undefined4 *)(param_1[1] + 8) = param_1[2];
    uVar1 = DAT_0001b9a4;
  }
  DAT_0001b9a4 = uVar1;
  uVar1 = param_1[1];
  if (param_1[2] != 0) {
    *(undefined4 *)(param_1[2] + 4) = param_1[1];
    uVar1 = DAT_0001b9a0;
  }
  DAT_0001b9a0 = uVar1;
  uVar1 = FUN_00017bf4(param_1[0x32]);
  param_1[0x32] = uVar1;
  FUN_00012c00(param_1);
  *param_1 = 0;
  FUN_0000a7e0();
  return;
}


================================================================