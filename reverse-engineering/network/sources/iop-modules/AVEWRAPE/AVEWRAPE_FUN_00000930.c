FUNCTION FUN_00000930 @ 0x00000930 size=76
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_00000930(int param_1)

{
  short sVar1;
  undefined2 local_10;
  undefined2 local_e;
  
  local_10 = *(undefined2 *)(param_1 + 0x1c);
  local_e = *(undefined2 *)(param_1 + 0x1e);
  sVar1 = FUN_00002804(&DAT_0000411a,&local_10,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================