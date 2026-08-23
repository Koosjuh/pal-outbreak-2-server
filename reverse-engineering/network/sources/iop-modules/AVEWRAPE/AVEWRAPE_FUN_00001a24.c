FUNCTION FUN_00001a24 @ 0x00001a24 size=84
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_00001a24(int param_1)

{
  short sVar1;
  undefined2 local_18 [2];
  int local_14;
  undefined2 local_10;
  
  local_18[0] = *(undefined2 *)(param_1 + 0x1c);
  local_14 = param_1 + 0x20;
  local_10 = 1;
  sVar1 = FUN_00002804(&DAT_00004185,local_18,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================