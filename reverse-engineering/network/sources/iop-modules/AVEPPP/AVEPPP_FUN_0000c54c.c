FUNCTION FUN_0000c54c @ 0x0000c54c size=84
CALLERS (1): FUN_0000ce44@0x0000ce44
CALLEES (2): FUN_000006b0@0x000006b0, FUN_0000c4b0@0x0000c4b0

int FUN_0000c54c(int param_1)

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
    FUN_0000c4b0(local_10,iVar1 + 0x1c,(int)*(short *)(iVar1 + 0x1c));
  }
  return local_10[0];
}


================================================================