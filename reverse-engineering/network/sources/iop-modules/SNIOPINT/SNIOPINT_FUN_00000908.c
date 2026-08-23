FUNCTION FUN_00000908 @ 0x00000908 size=96
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_00000908(int param_1)

{
  short sVar1;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  int local_10;
  
  local_18 = *(undefined2 *)(param_1 + 0x1c);
  local_16 = *(undefined2 *)(param_1 + 0x1e);
  local_14 = *(undefined2 *)(param_1 + 0x20);
  local_10 = param_1 + 0x22;
  sVar1 = FUN_00003614(&DAT_00004109,&local_18,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================