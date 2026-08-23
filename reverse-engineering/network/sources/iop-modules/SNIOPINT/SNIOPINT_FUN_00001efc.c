FUNCTION FUN_00001efc @ 0x00001efc size=60
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_00001efc(int param_1)

{
  short sVar1;
  
  sVar1 = FUN_00003614(&DAT_00004165,0,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================