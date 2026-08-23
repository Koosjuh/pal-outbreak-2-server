FUNCTION FUN_000088ac @ 0x000088ac size=136
CALLERS (2): FUN_000032bc@0x000032bc, FUN_000027e4@0x000027e4
CALLEES (1): FUN_00008470@0x00008470

int FUN_000088ac(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 1) {
    if (param_1 == 0) {
      return -0xe;
    }
    if (*(int *)(param_1 + 0x1c) == 0) {
      return -0xe;
    }
    if (*(int *)(*(int *)(param_1 + 0x1c) + 0x70) == 0) {
      return 0;
    }
    iVar1 = FUN_00008470();
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  else if (param_2 < 2) {
    if (param_2 != 0) {
      return -10;
    }
  }
  else if (param_2 != 2) {
    return -10;
  }
  return 0;
}


================================================================