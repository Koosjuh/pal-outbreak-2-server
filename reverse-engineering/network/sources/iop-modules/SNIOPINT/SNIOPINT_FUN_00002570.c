FUNCTION FUN_00002570 @ 0x00002570 size=84
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_00002570(int param_1)

{
  short sVar1;
  undefined2 local_18 [2];
  int local_14;
  undefined2 local_10;
  
  local_18[0] = *(undefined2 *)(param_1 + 0x1c);
  local_14 = param_1 + 0x20;
  local_10 = 1;
  sVar1 = FUN_00003614(&DAT_00004185,local_18,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================