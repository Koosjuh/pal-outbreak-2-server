FUNCTION FUN_00000b50 @ 0x00000b50 size=92
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_00000b50(int param_1)

{
  short sVar1;
  undefined2 local_18 [2];
  undefined4 local_14;
  undefined4 local_10;
  
  local_18[0] = *(undefined2 *)(param_1 + 0x1c);
  local_14 = 0;
  local_10 = 0x280;
  sVar1 = FUN_00003614(&DAT_00004112,local_18,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================