FUNCTION FUN_005ee470 @ 0x005ee470  size=280
CALLERS (1): FUN_005e91f0@0x005e91f0
CALLEES (2): FUN_005ed630@0x005ed630, FUN_005d9790@0x005d9790
----------------------------------------------------------------

void FUN_005ee470(void)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  byte bVar4;
  int iVar5;
  long lVar6;
  
  if ((*(char *)(iRam007012a0 + 0x186) == '\0') &&
     (iVar5 = 0, *(char *)(iRam007012a0 + 0xe96b) == '\0')) {
    bVar3 = true;
    while (bVar3) {
      lVar6 = func_0x00109d70(iRam007012a0 + iVar5 * 0x104 + 0xea81,iRam007012a0 + 0xfac1);
      if (lVar6 == 0) {
        bVar4 = FUN_005ed630(iRam007012a0 + 399);
        iVar5 = iVar5 * 0x104 + iRam007012a0;
        sVar1 = *(short *)(iVar5 + 0xeb82);
        sVar2 = *(short *)(iVar5 + 0xeb80);
        FUN_005d9790(sVar2 + *(short *)(iRam007012a0 + 0x1538),
                     sVar1 + *(short *)(iRam007012a0 + 0x153a),
                     sVar2 + *(short *)(iRam007012a0 + 0x153c),
                     sVar1 + *(short *)(iRam007012a0 + 0x153e),0x6494e8,iRam007012a0 + 0x1428,
                     iRam007012a0 + 0x1328,bVar4 | 0x80);
        return;
      }
      iVar5 = iVar5 + 1;
      bVar3 = iVar5 < 0x10;
    }
  }
  return;
}



================================================================