FUNCTION FUN_00006a8c @ 0x00006a8c size=276
CALLERS (1): FUN_000060c0@0x000060c0
CALLEES (3): FUN_00006784@0x00006784, FUN_00001760@0x00001760, FUN_000067e4@0x000067e4

undefined4 FUN_00006a8c(undefined *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = 0;
  do {
    iVar1 = iVar1 >> 0x10;
    if (((&DAT_000165a8)[iVar1 * 0xe] == 1) && (param_1 != &DAT_00016590 + iVar1 * 0x1c)) {
      iVar1 = (&DAT_000165a0)[iVar1 * 7];
      while (iVar1 != 0) {
        iVar2 = *(int *)(iVar1 + 0xc);
        FUN_00001760(iVar1);
        FUN_00006784(iVar1);
        iVar1 = iVar2;
      }
      FUN_000067e4(&DAT_00016590 + (short)iVar3 * 0x1c);
    }
    iVar3 = iVar3 + 1;
    iVar1 = iVar3 * 0x10000;
  } while (iVar3 * 0x10000 >> 0x10 < 4);
  *(undefined4 *)(param_1 + 0xc) = 0;
  DAT_0001689c = param_1;
  DAT_000168a0 = param_1;
  return 0;
}


================================================================