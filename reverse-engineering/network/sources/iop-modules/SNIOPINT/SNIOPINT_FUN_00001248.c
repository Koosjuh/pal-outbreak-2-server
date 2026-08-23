FUNCTION FUN_00001248 @ 0x00001248 size=128
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_00001248(int param_1)

{
  short sVar1;
  undefined4 local_28;
  undefined2 local_24;
  undefined2 local_22;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined2 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  code *local_10;
  
  local_28 = *(undefined4 *)(param_1 + 0x1c);
  local_24 = *(undefined2 *)(param_1 + 0x20);
  local_22 = *(undefined2 *)(param_1 + 0x22);
  local_1f = 0;
  local_1e = 0;
  local_1d = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = FUN_00001104;
  sVar1 = FUN_00003614(&DAT_00004120,&local_28,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================