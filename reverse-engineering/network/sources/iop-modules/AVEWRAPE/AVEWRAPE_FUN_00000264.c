FUNCTION FUN_00000264 @ 0x00000264 size=64
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_00000264(int param_1)

{
  short sVar1;
  undefined2 local_10 [4];
  
  local_10[0] = 0;
  sVar1 = FUN_00002804(0x4106,local_10,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================