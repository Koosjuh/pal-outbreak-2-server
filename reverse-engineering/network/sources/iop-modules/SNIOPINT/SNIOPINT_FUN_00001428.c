FUNCTION FUN_00001428 @ 0x00001428 size=140
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_00001428(int param_1)

{
  short sVar1;
  undefined2 local_20 [2];
  undefined4 local_1c;
  undefined2 local_18;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  undefined2 local_10;
  int local_c;
  
  local_20[0] = *(undefined2 *)(param_1 + 0x1c);
  local_1c = *(undefined4 *)(param_1 + 0x20);
  local_18 = *(undefined2 *)(param_1 + 0x24);
  local_16 = 1;
  local_10 = *(undefined2 *)(param_1 + 0x26);
  local_c = param_1 + 0x2b;
  local_15 = *(undefined1 *)(param_1 + 0x28);
  local_14 = *(undefined1 *)(param_1 + 0x29);
  local_13 = *(undefined1 *)(param_1 + 0x2a);
  sVar1 = FUN_00003614(&DAT_00004122,local_20,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================