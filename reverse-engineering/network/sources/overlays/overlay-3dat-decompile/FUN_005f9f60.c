FUNCTION FUN_005f9f60 @ 0x005f9f60  size=324
CALLERS (1): FUN_005f9540@0x005f9540
CALLEES (1): FUN_005b14b0@0x005b14b0
----------------------------------------------------------------

void FUN_005f9f60(int param_1)

{
  short sVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  
  sVar1 = *(short *)(param_1 + 0x53c);
  lVar2 = FUN_005b14b0(0x40004);
  if (lVar2 == 0) {
    lVar2 = FUN_005b14b0(0x80008);
    if (lVar2 != 0) {
      lVar2 = (long)(sVar1 + 1);
      iVar3 = 0;
      if (0xb < lVar2) {
        lVar2 = 1;
      }
      iVar4 = (int)lVar2;
      do {
        if (-1 < *(short *)(param_1 + iVar4 * 2 + 0x4ba)) goto LAB_005fa064;
        lVar2 = (long)((int)lVar2 + 1);
        if (0xb < lVar2) {
          lVar2 = 1;
        }
        iVar3 = iVar3 + 1;
        iVar4 = (int)lVar2;
      } while (iVar3 < 0x11);
      lVar2 = 1;
LAB_005fa064:
      if (*(short *)(param_1 + 0x53c) != lVar2) {
        func_0x001b0140(0);
      }
      *(short *)(param_1 + 0x53c) = (short)lVar2;
    }
  }
  else {
    lVar2 = (long)(sVar1 + -1);
    iVar3 = 0;
    if (lVar2 < 1) {
      lVar2 = 0xb;
    }
    iVar4 = (int)lVar2;
    do {
      if (-1 < *(short *)(param_1 + iVar4 * 2 + 0x4ba)) goto LAB_005f9fdc;
      lVar2 = (long)((int)lVar2 + -1);
      if (lVar2 < 1) {
        lVar2 = 0xb;
      }
      iVar3 = iVar3 + 1;
      iVar4 = (int)lVar2;
    } while (iVar3 < 0x11);
    lVar2 = 1;
LAB_005f9fdc:
    if (*(short *)(param_1 + 0x53c) != lVar2) {
      func_0x001b0140(0);
    }
    *(short *)(param_1 + 0x53c) = (short)lVar2;
  }
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)(*(short *)(param_1 + 0x53c) * 2 + param_1 + 0x4ba);
  return;
}



================================================================