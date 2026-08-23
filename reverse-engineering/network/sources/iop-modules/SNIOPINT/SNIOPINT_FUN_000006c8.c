FUNCTION FUN_000006c8 @ 0x000006c8 size=152
CALLERS (1): FUN_00002858@0x00002858
CALLEES (2): FUN_00003660@0x00003660, FUN_00003624@0x00003624

void FUN_000006c8(int param_1)

{
  short sVar1;
  undefined1 auStack_28 [4];
  undefined4 local_24;
  uint local_20;
  int local_18 [2];
  
  local_24 = 9;
  local_18[0] = 9;
  FUN_00003660(1,local_18,4);
  local_18[0] = local_18[0] + -1;
  FUN_00003660(2,local_18,4);
  local_20 = (uint)(DAT_0000c5b4 == 2);
  sVar1 = FUN_00003624(auStack_28);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================