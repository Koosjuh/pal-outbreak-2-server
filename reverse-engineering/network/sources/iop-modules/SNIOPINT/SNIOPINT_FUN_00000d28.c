FUNCTION FUN_00000d28 @ 0x00000d28 size=100
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_00000d28(int param_1)

{
  short sVar1;
  undefined2 local_20 [2];
  undefined4 local_1c;
  undefined1 local_18;
  undefined1 local_17;
  undefined2 local_14;
  int local_10;
  
  local_20[0] = *(undefined2 *)(param_1 + 0x1c);
  local_17 = 1;
  local_10 = param_1 + 0x20;
  local_1c = 0;
  local_18 = 0;
  local_14 = *(undefined2 *)(param_1 + 0x1e);
  sVar1 = FUN_00003614(&DAT_00004118,local_20,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================