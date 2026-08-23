FUNCTION FUN_00001c4c @ 0x00001c4c size=60
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_00001c4c(int param_1)

{
  short sVar1;
  
  sVar1 = FUN_00003614(&DAT_00004156,0,param_1 + 0x1c);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================