FUNCTION FUN_00001e68 @ 0x00001e68 size=80
CALLERS (1): FUN_00002858@0x00002858
CALLEES (2): FUN_00003614@0x00003614, FUN_000001c8@0x000001c8

void FUN_00001e68(undefined4 *param_1)

{
  short sVar1;
  undefined1 auStack_10 [2];
  undefined2 local_e;
  
  FUN_000001c8(*param_1);
  local_e = 2;
  sVar1 = FUN_00003614(&DAT_00004164,auStack_10,0);
  param_1[6] = (int)sVar1;
  return;
}


================================================================