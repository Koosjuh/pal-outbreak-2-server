FUNCTION FUN_000025c4 @ 0x000025c4 size=92
CALLERS (1): FUN_00002858@0x00002858
CALLEES (1): FUN_00003614@0x00003614

void FUN_000025c4(int param_1)

{
  short sVar1;
  undefined2 local_20 [2];
  int *local_1c;
  undefined2 local_18;
  int local_10 [2];
  
  local_10[0] = param_1 + 0x1e;
  local_20[0] = *(undefined2 *)(param_1 + 0x1c);
  local_1c = local_10;
  local_18 = 1;
  sVar1 = FUN_00003614(&DAT_00004186,local_20,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================