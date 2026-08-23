FUNCTION FUN_00006978 @ 0x00006978 size=276
CALLERS (2): FUN_00006490@0x00006490, FUN_000060c0@0x000060c0
CALLEES (3): FUN_000067e4@0x000067e4, FUN_00001760@0x00001760, FUN_00006784@0x00006784

undefined4 FUN_00006978(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  do {
    if ((&DAT_000165a8)[(iVar1 >> 0x10) * 0xe] == 1) {
      FUN_000067e4(&DAT_00016590 + (iVar1 >> 0x10) * 0x1c);
    }
    iVar2 = iVar2 + 1;
    iVar1 = iVar2 * 0x10000;
  } while (iVar2 * 0x10000 >> 0x10 < 4);
  iVar2 = 0;
  iVar1 = 0;
  do {
    if ((&DAT_00016610)[(iVar1 >> 0x10) * 10] == 1) {
      FUN_00001760(&DAT_00016600 + (iVar1 >> 0x10) * 0x14);
      FUN_00006784(&DAT_00016600 + (iVar1 >> 0x10) * 0x14);
    }
    iVar2 = iVar2 + 1;
    iVar1 = iVar2 * 0x10000;
  } while (iVar2 * 0x10000 >> 0x10 < 0x20);
  DAT_0001689c = 0;
  DAT_000168a0 = 0;
  return 0;
}


================================================================