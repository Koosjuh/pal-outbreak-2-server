FUNCTION FUN_00001fb0 @ 0x00001fb0 size=88
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_00001fb0(int param_1)

{
  short sVar1;
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_14 = param_1 + 0x1c;
  local_10 = param_1 + 0x11c;
  local_c = param_1 + 0x120;
  local_18 = 0;
  sVar1 = FUN_00003614(&DAT_00004173,&local_18,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================