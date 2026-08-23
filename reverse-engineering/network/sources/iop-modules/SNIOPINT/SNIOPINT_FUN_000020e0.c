FUNCTION FUN_000020e0 @ 0x000020e0 size=60
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_000020e0(int param_1)

{
  short sVar1;
  
  sVar1 = FUN_00003614(&DAT_00004177,param_1 + 0x1c,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================