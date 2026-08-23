FUNCTION FUN_0000acc8 @ 0x0000acc8 size=84
CALLERS (1): FUN_0000b5cc@0x0000b5cc
CALLEES (2): FUN_000006b0@0x000006b0, FUN_0000abec@0x0000abec

int FUN_0000acc8(int param_1)

{
  int iVar1;
  int local_10 [2];
  
  iVar1 = *(int *)(param_1 + 0x30);
  local_10[0] = 0;
  local_10[0] = FUN_000006b0(0);
  if (local_10[0] == 0) {
    local_10[0] = 0;
  }
  else {
    FUN_0000abec(local_10,iVar1 + 0x28,(int)*(short *)(iVar1 + 0x28));
  }
  return local_10[0];
}


================================================================