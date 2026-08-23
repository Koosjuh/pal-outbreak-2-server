FUNCTION FUN_00002688 @ 0x00002688 size=52
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003658@0x00003658

void FUN_00002688(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 local_10 [2];
  
  uVar1 = FUN_00003658(local_10);
  param_1[6] = uVar1;
  *param_1 = local_10[0];
  return;
}


================================================================