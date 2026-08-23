FUNCTION FUN_0000218c @ 0x0000218c size=124
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_0000218c(int param_1)

{
  short sVar1;
  undefined2 local_28 [2];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  undefined4 *local_10;
  undefined4 local_c;
  
  local_28[0] = 0;
  local_24 = 0;
  local_20 = *(undefined4 *)(param_1 + 0x1c);
  local_18 = &DAT_0000c5a8;
  local_14 = &DAT_0000c5ac;
  local_1c = 0;
  local_10 = &DAT_0000c5b0;
  local_c = *(undefined4 *)(param_1 + 0x20);
  sVar1 = FUN_00003614(&DAT_00004179,local_28,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================