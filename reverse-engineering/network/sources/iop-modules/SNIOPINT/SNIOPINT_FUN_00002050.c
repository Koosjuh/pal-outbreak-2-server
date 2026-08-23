FUNCTION FUN_00002050 @ 0x00002050 size=84
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_00002050(int param_1)

{
  short sVar1;
  int local_18;
  int local_14;
  int local_10;
  
  local_18 = param_1 + 0x1c;
  local_14 = param_1 + 0x20;
  local_10 = param_1 + 0x24;
  sVar1 = FUN_00003614(&DAT_00004175,&local_18,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================