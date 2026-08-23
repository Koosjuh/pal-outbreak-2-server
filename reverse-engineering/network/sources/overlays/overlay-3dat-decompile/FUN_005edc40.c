FUNCTION FUN_005edc40 @ 0x005edc40  size=468
CALLERS (1): FUN_005e9680@0x005e9680
CALLEES (3): FUN_005f2940@0x005f2940, FUN_005ed6e0@0x005ed6e0, FUN_005d9dd0@0x005d9dd0
----------------------------------------------------------------

void FUN_005edc40(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  short sVar7;
  
  switch(*(undefined1 *)(iRam007012a0 + 0x4e4)) {
  case 0:
  case 1:
    sVar7 = *(short *)(iRam007012a0 + 0x4e6);
    if (sVar7 == 0) {
      sVar7 = 0x10;
    }
    break;
  case 2:
  case 3:
  case 4:
  case 5:
    sVar7 = *(short *)(iRam007012a0 + 0x4e6);
    if (sVar7 == 0) {
      iVar3 = func_0x0010a050(iRam007012a0 + 0x3e4);
      sVar7 = 0;
      for (iVar5 = 0; iVar5 < iVar3; iVar5 = iVar5 + 1) {
        bVar1 = *(byte *)(iRam007012a0 + iVar5 + 0x3e4);
        uVar6 = (uint)bVar1;
        iVar2 = iVar5;
        if ((bVar1 & 0x80) != 0) {
          do {
            iVar5 = iVar2;
            uVar4 = uVar6 << 1;
            uVar6 = uVar4 & 0xff;
            iVar2 = iVar5 + 1;
          } while ((uVar4 & 0x80) != 0);
        }
        sVar7 = sVar7 + 1;
      }
    }
    break;
  case 6:
    if ((*(char *)(iRam007012a0 + 0x186) == '\0') && (*(char *)(iRam007012a0 + 0xe96b) == '\0')) {
      FUN_005d9dd0(iRam007012a0 + 0x2e4,iRam007012a0 + 0x3e4);
    }
  case 7:
    sVar7 = *(short *)(iRam007012a0 + 0x6ec);
    break;
  default:
    goto switchD_005edc78_default;
  }
  if (*(char *)(iRam007012a0 + 0xd892) == '\0') {
    FUN_005ed6e0(*(short *)(iRam007012a0 + 0x12) + *(short *)(iRam007012a0 + 0xd8bc),
                 *(undefined2 *)(iRam007012a0 + 0xd8be),(short *)(iRam007012a0 + 0xd8bc),
                 iRam007012a0 + 0xd8c0,sVar7);
    if (*(char *)(iRam007012a0 + 0x186) == -10) {
      uVar6 = (uint)*(ushort *)(iRam007012a0 + 0xd8c4) + (uint)*(ushort *)(iRam007012a0 + 0xd8c0);
      if (*(ushort *)(iRam007012a0 + 0x182) < uVar6) {
        *(short *)(iRam007012a0 + 0x182) = (short)uVar6;
      }
    }
  }
  else {
    FUN_005f2940(sVar7);
  }
switchD_005edc78_default:
  return;
}



================================================================