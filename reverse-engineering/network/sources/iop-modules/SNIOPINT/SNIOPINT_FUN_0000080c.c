FUNCTION FUN_0000080c @ 0x0000080c size=92
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_0000080c(int param_1)

{
  short sVar1;
  undefined2 local_18 [2];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18[0] = 0;
  local_14 = *(undefined4 *)(param_1 + 0x1c);
  local_10 = *(undefined4 *)(param_1 + 0x20);
  local_c = *(undefined4 *)(param_1 + 0x24);
  sVar1 = FUN_00003614(&DAT_00004105,local_18,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================