FUNCTION FUN_00004820 @ 0x00004820 size=328
CALLERS (1): FUN_00004620@0x00004620
CALLEES (0): 

undefined4 FUN_00004820(void)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = DAT_000161a8;
  uVar2 = (uint)DAT_0001619d;
  DAT_00016898 = 1;
  iVar3 = 0;
  if (uVar2 != 0) {
    do {
      sVar1 = (short)iVar3;
      iVar3 = iVar3 + 1;
      *(undefined2 *)(sVar1 * 0x14 + iVar4) = 0;
    } while (iVar3 * 0x10000 >> 0x10 < (int)uVar2);
  }
  uVar2 = (uint)DAT_0001619a;
  iVar4 = 0;
  if (uVar2 != 0) {
    iVar3 = 0;
    do {
      (&DAT_000183fe)[(iVar3 >> 0x10) * 0xe] = 0;
      iVar4 = iVar4 + 1;
      iVar3 = iVar4 * 0x10000;
    } while (iVar4 * 0x10000 >> 0x10 < (int)uVar2);
  }
  iVar4 = 0;
  DAT_000168a0 = 0;
  DAT_0001689c = 0;
  iVar3 = 0;
  do {
    (&DAT_000165a8)[(iVar3 >> 0x10) * 0xe] = 0;
    iVar4 = iVar4 + 1;
    iVar3 = iVar4 * 0x10000;
  } while (iVar4 * 0x10000 >> 0x10 < 4);
  iVar4 = 0;
  iVar3 = 0;
  do {
    (&DAT_00016610)[(iVar3 >> 0x10) * 10] = 0;
    iVar4 = iVar4 + 1;
    iVar3 = iVar4 * 0x10000;
  } while (iVar4 * 0x10000 >> 0x10 < 0x20);
  return 0;
}


================================================================