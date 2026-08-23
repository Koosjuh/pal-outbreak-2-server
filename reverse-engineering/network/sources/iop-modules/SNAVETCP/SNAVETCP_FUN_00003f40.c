FUNCTION FUN_00003f40 @ 0x00003f40 size=144
CALLERS (1): FUN_00004620@0x00004620
CALLEES (2): FUN_0000e750@0x0000e750, FUN_0000e738@0x0000e738

undefined4 FUN_00003f40(void)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  
  DAT_00016160 = FUN_0000e738();
  uVar2 = 0xffffffff;
  if (DAT_00016160 != -1) {
    iVar3 = 0;
    if (0 < DAT_00016160) {
      do {
        sVar1 = FUN_0000e750((int)(short)iVar3);
        iVar3 = iVar3 + 1;
        if (sVar1 != 0) {
          return 0xffffffff;
        }
      } while (iVar3 * 0x10000 >> 0x10 < (int)DAT_00016160);
    }
    uVar2 = 0;
  }
  return uVar2;
}


================================================================