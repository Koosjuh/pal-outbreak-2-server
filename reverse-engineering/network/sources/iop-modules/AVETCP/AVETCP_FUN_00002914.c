FUNCTION FUN_00002914 @ 0x00002914 size=180
CALLERS (1): FUN_00001930@0x00001930
CALLEES (1): FUN_00002aa4@0x00002aa4

void FUN_00002914(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (DAT_0001618c != 0) {
    iVar1 = 0;
    do {
      iVar1 = (iVar1 >> 0x10) * 0x20;
      if ((((&DAT_000187b0)[iVar1] & 3) != 0) && (((&DAT_000187b0)[iVar1] & 4) == 0)) {
        if ((&DAT_000187c0)[iVar1] == '\0') {
          FUN_00002aa4();
        }
        else {
          (&DAT_000187c0)[iVar1] = (&DAT_000187c0)[iVar1] + -1;
        }
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar2 * 0x10000;
    } while (iVar2 * 0x10000 >> 0x10 < (int)(uint)DAT_0001618c);
  }
  return;
}


================================================================