FUNCTION FUN_00001778 @ 0x00001778 size=140
CALLERS (1): FUN_00001804@0x00001804
CALLEES (2): FUN_0000823c@0x0000823c, FUN_00008244@0x00008244

undefined4 FUN_00001778(int *param_1,int param_2)

{
  uint uVar1;
  
  FUN_00008244(DAT_0000d97c);
  uVar1 = param_1[3] + param_2;
  param_1[3] = uVar1;
  if ((uint)(param_1[2] + *param_1) <= uVar1) {
    param_1[3] = uVar1 - *param_1;
  }
  param_1[1] = param_1[1] - param_2;
  FUN_0000823c(DAT_0000d97c);
  return 0;
}


================================================================