FUNCTION FUN_00000b74 @ 0x00000b74 size=128
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_00000b74(int param_1)

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
  sVar1 = FUN_00002804(&DAT_00004125,local_20,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================