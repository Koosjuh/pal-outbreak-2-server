FUNCTION FUN_000000a8 @ 0x000000a8 size=192
CALLERS (1): FUN_00002098@0x00002098
CALLEES (3): FUN_00002804@0x00002804, FUN_00002814@0x00002814, FUN_00002850@0x00002850

/* WARNING: Type propagation algorithm not settling */

void FUN_000000a8(undefined4 *param_1)

{
  short sVar1;
  undefined2 local_30 [2];
  undefined4 local_2c;
  undefined4 local_28;
  undefined2 local_20;
  undefined2 local_1e;
  int *local_1c;
  int local_18 [2];
  
  local_2c = 9;
  local_28 = *param_1;
  local_30[0] = 0;
  DAT_00002c64 = param_1[1];
  local_18[0] = 9;
  FUN_00002850(1,local_18,4);
  local_18[0] = local_18[0] + -1;
  FUN_00002850(2,local_18,4);
  FUN_00002814(local_30);
  local_20 = 1;
  local_1e = 4;
  local_18[1] = 1;
  local_1c = local_18 + 1;
  sVar1 = FUN_00002804(&DAT_0000412e,&local_20,0);
  param_1[6] = (int)sVar1;
  return;
}


================================================================