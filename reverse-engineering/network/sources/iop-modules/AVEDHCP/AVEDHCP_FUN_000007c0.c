FUNCTION FUN_000007c0 @ 0x000007c0 size=100
CALLERS (0): 
CALLEES (1): FUN_000005a8@0x000005a8

void FUN_000007c0(void)

{
  int iVar1;
  int iVar2;
  
  if (DAT_00002f50 == 0) {
    iVar2 = 1;
    iVar1 = 0x10000;
    do {
      iVar1 = FUN_000005a8(iVar1 >> 0x10,0);
      if (iVar1 != 0) {
        DAT_00002f50 = iVar2 + 10;
        return;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar2 * 0x10000;
    } while (iVar2 < 9);
  }
  return;
}


================================================================