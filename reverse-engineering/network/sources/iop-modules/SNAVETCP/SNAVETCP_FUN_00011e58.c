FUNCTION FUN_00011e58 @ 0x00011e58 size=120
CALLERS (5): FUN_000102e4@0x000102e4, FUN_00010694@0x00010694, FUN_00011da8@0x00011da8, FUN_0001090c@0x0001090c, FUN_0000fc2c@0x0000fc2c
CALLEES (1): FUN_00014f2c@0x00014f2c

undefined4 FUN_00011e58(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_00014f2c();
  iVar3 = 0;
  if (iVar1 < 0) {
    *param_1 = -1;
  }
  else {
    iVar2 = 0;
    do {
      if (*(int *)((int)&DAT_000228a0 + iVar2) == iVar1) {
        *param_1 = iVar3;
        return 0;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar3 * 4;
    } while (iVar3 < 0x10);
    *param_1 = iVar1;
  }
  return 0;
}


================================================================