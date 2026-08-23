FUNCTION FUN_00001bcc @ 0x00001bcc size=52
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002848@0x00002848

void FUN_00001bcc(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 local_10 [2];
  
  uVar1 = FUN_00002848(local_10);
  param_1[6] = uVar1;
  *param_1 = local_10[0];
  return;
}


================================================================