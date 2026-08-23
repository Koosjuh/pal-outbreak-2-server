FUNCTION FUN_00005e78 @ 0x00005e78 size=108
CALLERS (1): FUN_00005f2c@0x00005f2c
CALLEES (2): FUN_00001198@0x00001198, FUN_00000da8@0x00000da8

void FUN_00005e78(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  if ((param_4 == 0) || (*(int *)(param_1 + 0x24) != 0)) {
    iVar1 = FUN_00001198(param_2,param_3);
  }
  else {
    iVar1 = FUN_00000da8();
  }
  if (iVar1 < 0) {
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
  }
  return;
}


================================================================