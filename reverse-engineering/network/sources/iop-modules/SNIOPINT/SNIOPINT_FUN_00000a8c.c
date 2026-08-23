FUNCTION FUN_00000a8c @ 0x00000a8c size=112
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_00000a8c(int param_1)

{
  short sVar1;
  undefined4 local_20;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined2 local_14;
  undefined4 local_10;
  
  local_20 = *(undefined4 *)(param_1 + 0x1c);
  local_1c = *(undefined2 *)(param_1 + 0x20);
  local_1a = *(undefined2 *)(param_1 + 0x22);
  local_17 = 0;
  local_16 = 0;
  local_15 = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  sVar1 = FUN_00003614(&DAT_00004111,&local_20,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================