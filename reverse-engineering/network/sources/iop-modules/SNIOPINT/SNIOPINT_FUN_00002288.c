FUNCTION FUN_00002288 @ 0x00002288 size=60
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_00002288(int param_1)

{
  short sVar1;
  
  sVar1 = FUN_00003614(&DAT_0000417a,0,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================