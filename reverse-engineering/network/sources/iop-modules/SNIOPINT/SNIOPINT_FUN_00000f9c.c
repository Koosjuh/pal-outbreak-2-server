FUNCTION FUN_00000f9c @ 0x00000f9c size=68
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_00000f9c(int param_1)

{
  short sVar1;
  undefined2 local_10 [4];
  
  local_10[0] = *(undefined2 *)(param_1 + 0x1c);
  sVar1 = FUN_00003614(&DAT_0000411c,local_10,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================