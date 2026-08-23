FUNCTION FUN_000066a4 @ 0x000066a4 size=112
CALLERS (1): FUN_000060c0@0x000060c0
CALLEES (0): 

undefined * FUN_000066a4(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  do {
    iVar1 = iVar1 >> 0x10;
    iVar2 = iVar2 + 1;
    if ((&DAT_00016610)[iVar1 * 10] == 0) {
      (&DAT_00016610)[iVar1 * 10] = 1;
      return &DAT_00016600 + iVar1 * 0x14;
    }
    iVar1 = iVar2 * 0x10000;
  } while (iVar2 * 0x10000 >> 0x10 < 0x20);
  return (undefined *)0x0;
}


================================================================