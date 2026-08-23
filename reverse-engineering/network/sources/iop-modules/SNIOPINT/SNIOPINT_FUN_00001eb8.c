FUNCTION FUN_00001eb8 @ 0x00001eb8 size=68
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_00001eb8(int param_1)

{
  short sVar1;
  undefined1 auStack_10 [2];
  undefined2 local_e;
  
  local_e = 3;
  sVar1 = FUN_00003614(&DAT_00004164,auStack_10,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================