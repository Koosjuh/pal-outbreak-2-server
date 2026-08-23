FUNCTION FUN_000016a8 @ 0x000016a8 size=128
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_000016a8(int param_1)

{
  short sVar1;
  undefined2 local_20 [2];
  undefined4 local_1c;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined2 local_14;
  int local_10;
  
  local_20[0] = *(undefined2 *)(param_1 + 0x1c);
  local_1c = *(undefined4 *)(param_1 + 0x20);
  local_18 = 1;
  local_14 = *(undefined2 *)(param_1 + 0x24);
  local_10 = param_1 + 0x29;
  local_17 = *(undefined1 *)(param_1 + 0x26);
  local_16 = *(undefined1 *)(param_1 + 0x27);
  local_15 = *(undefined1 *)(param_1 + 0x28);
  sVar1 = FUN_00003614(&DAT_00004125,local_20,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================