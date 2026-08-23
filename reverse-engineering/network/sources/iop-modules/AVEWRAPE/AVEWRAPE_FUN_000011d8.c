FUNCTION FUN_000011d8 @ 0x000011d8 size=84
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_000011d8(int param_1)

{
  short sVar1;
  undefined2 local_10;
  undefined2 local_e;
  int local_c;
  
  local_10 = *(undefined2 *)(param_1 + 0x1c);
  local_e = *(undefined2 *)(param_1 + 0x1e);
  local_c = param_1 + 0x20;
  sVar1 = FUN_00002804(&DAT_0000415b,&local_10,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================