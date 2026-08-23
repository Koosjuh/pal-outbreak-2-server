FUNCTION FUN_00006714 @ 0x00006714 size=112
CALLERS (1): FUN_00006490@0x00006490
CALLEES (0): 

undefined * FUN_00006714(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  do {
    iVar1 = iVar1 >> 0x10;
    iVar2 = iVar2 + 1;
    if ((&DAT_000165a8)[iVar1 * 0xe] == 0) {
      (&DAT_000165a8)[iVar1 * 0xe] = 1;
      return &DAT_00016590 + iVar1 * 0x1c;
    }
    iVar1 = iVar2 * 0x10000;
  } while (iVar2 * 0x10000 >> 0x10 < 4);
  return (undefined *)0x0;
}


================================================================