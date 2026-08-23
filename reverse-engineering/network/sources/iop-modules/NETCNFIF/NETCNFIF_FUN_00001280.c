FUNCTION FUN_00001280 @ 0x00001280 size=160
CALLERS (1): FUN_00001320@0x00001320
CALLEES (1): FUN_0000274c@0x0000274c

undefined4 FUN_00001280(int param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_2 + 8) == 1) {
    if (*param_3 == 0) {
      param_1 = param_1 + 0x600;
    }
    else {
      param_1 = param_1 + 0x700;
      if (*param_3 != 1) {
        return 0;
      }
    }
    uVar1 = FUN_0000274c(param_1,0x100,param_2 + 0xc);
    *param_3 = *param_3 + 1;
  }
  else if (*(int *)(param_2 + 8) == 3) {
    uVar1 = FUN_0000274c(param_1 + 0x500,0x100,param_2 + 0x20);
  }
  return uVar1;
}


================================================================