FUNCTION FUN_00002a0c @ 0x00002a0c size=152
CALLERS (1): FUN_00011498@0x00011498
CALLEES (1): FUN_00002aa4@0x00002aa4

undefined4 FUN_00002a0c(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (DAT_0001618c != 0) {
    iVar1 = 0;
    do {
      if (((&DAT_000187c4)[(iVar1 >> 0x10) * 8] == param_1) &&
         ((&DAT_000187b0)[(iVar1 >> 0x10) * 0x20] != '\0')) {
        FUN_00002aa4();
        return 0;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar2 * 0x10000;
    } while (iVar2 * 0x10000 >> 0x10 < (int)(uint)DAT_0001618c);
  }
  return 0xffffffff;
}


================================================================