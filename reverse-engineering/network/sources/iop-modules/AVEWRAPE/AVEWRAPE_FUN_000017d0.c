FUNCTION FUN_000017d0 @ 0x000017d0 size=80
CALLERS (1): FUN_00002098@0x00002098
CALLEES (1): FUN_00002804@0x00002804

void FUN_000017d0(int param_1)

{
  short sVar1;
  undefined2 local_18 [2];
  undefined4 local_14;
  undefined4 local_10;
  
  local_18[0] = 0;
  local_14 = *(undefined4 *)(param_1 + 0x1c);
  local_10 = *(undefined4 *)(param_1 + 0x20);
  sVar1 = FUN_00002804(&DAT_0000417c,local_18,0);
  *(int *)(param_1 + 0x18) = (int)sVar1;
  return;
}


================================================================