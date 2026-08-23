FUNCTION FUN_0000097c @ 0x0000097c size=68
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_0000097c(int param_1)

{
  short sVar1;
  undefined2 local_10 [4];
  
  local_10[0] = *(undefined2 *)(param_1 + 0x1c);
  sVar1 = FUN_00002804(&DAT_0000411c,local_10,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================