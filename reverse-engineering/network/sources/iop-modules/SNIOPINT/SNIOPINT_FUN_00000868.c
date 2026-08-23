FUNCTION FUN_00000868 @ 0x00000868 size=64
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_00000868(int param_1)

{
  short sVar1;
  undefined2 local_10 [4];
  
  local_10[0] = 0;
  sVar1 = FUN_00003614(&DAT_00004106,local_10,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================