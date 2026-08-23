FUNCTION FUN_0000164c @ 0x0000164c size=92
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_0000164c(int param_1)

{
  short sVar1;
  undefined4 local_18;
  undefined2 local_14;
  undefined4 local_10;
  code *local_c;
  
  local_18 = *(undefined4 *)(param_1 + 0x1c);
  local_14 = *(undefined2 *)(param_1 + 0x20);
  local_10 = 0;
  local_c = FUN_000015a8;
  sVar1 = FUN_00003614(&DAT_00004124,&local_18,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================