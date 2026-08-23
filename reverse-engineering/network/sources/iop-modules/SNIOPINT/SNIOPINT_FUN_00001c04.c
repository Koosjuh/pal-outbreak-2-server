FUNCTION FUN_00001c04 @ 0x00001c04 size=72
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_00001c04(int param_1)

{
  short sVar1;
  undefined2 local_10 [2];
  undefined2 local_c;
  
  local_10[0] = 0;
  local_c = 1;
  sVar1 = FUN_00003614(&DAT_00004155,local_10,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================