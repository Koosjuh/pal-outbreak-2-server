FUNCTION FUN_00001e18 @ 0x00001e18 size=80
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_00001e18(int param_1)

{
  short sVar1;
  undefined2 local_10 [4];
  
  local_10[0] = 0;
  FUN_00003614(&DAT_00004142,local_10,0);
  sVar1 = FUN_00003614(&DAT_00004162,0,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================