FUNCTION FUN_005ee610 @ 0x005ee610  size=556
CALLERS (2): FUN_005e8d30@0x005e8d30, FUN_005e8eb0@0x005e8eb0
CALLEES (4): FUN_005ee220@0x005ee220, FUN_005ed460@0x005ed460, FUN_005eced0@0x005eced0, FUN_005f2e50@0x005f2e50
----------------------------------------------------------------

void FUN_005ee610(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  short sVar4;
  ushort *puStack_4;
  
  if (*(char *)(iRam007012a0 + 0xd892) == '\0') {
    puStack_4 = (ushort *)(iRam007012a0 + (uint)*(ushort *)(iRam007012a0 + 0x188) * 4 + 0x1540);
    uVar2 = (uint)*(ushort *)(iRam007012a0 + 0x12) + (uint)*(ushort *)(iRam007012a0 + 0xd8bc) &
            0xffff;
    if (*(char *)(iRam007012a0 + 0x186) == '\0') {
      iVar1 = FUN_005eced0(puStack_4);
      uVar2 = uVar2 + iVar1 & 0xffff;
    }
    if ((*(short *)(iRam007012a0 + 0xd8bc) == 0) ||
       (uVar2 + *(ushort *)(iRam007012a0 + 0xdf6) <= (uint)*(ushort *)(iRam007012a0 + 0x10))) {
      uVar2 = uVar2 + *(ushort *)(iRam007012a0 + 0xd8c4) & 0xffff;
    }
    else {
      uVar2 = FUN_005ed460(&puStack_4,uVar2);
      uVar2 = uVar2 & 0xffff;
      if (*(char *)(iRam007012a0 + 0x186) == '\0') {
        iVar1 = FUN_005eced0(puStack_4);
        uVar2 = uVar2 + iVar1 & 0xffff;
      }
    }
    if (*(char *)(iRam007012a0 + 0x186) == -10) {
      uVar3 = uVar2 + *(ushort *)(iRam007012a0 + 0xdf6);
      if (*(ushort *)(iRam007012a0 + 0x182) < uVar3) {
        *(short *)(iRam007012a0 + 0x182) = (short)uVar3;
      }
    }
    FUN_005ee220(uVar2,*(short *)(iRam007012a0 + 0xd8c6) + *(short *)(iRam007012a0 + 0xd8be),
                 puStack_4);
    sVar4 = *(short *)(iRam007012a0 + 0xd8bc) + *(short *)(iRam007012a0 + 0xdf6);
    *(short *)(iRam007012a0 + 0xd8c0) = sVar4;
    *(short *)(iRam007012a0 + 0xd8bc) = sVar4;
    *(undefined1 *)(iRam007012a0 + 0xd8cc) = 1;
    if (*(char *)(iRam007012a0 + 0x186) == '\x01') {
      if (*puStack_4 < *(ushort *)(iRam007012a0 + 0xd8c0)) {
        *puStack_4 = *(ushort *)(iRam007012a0 + 0xd8c0);
      }
      if (puStack_4[1] < *(ushort *)(iRam007012a0 + 0xdf8)) {
        puStack_4[1] = *(ushort *)(iRam007012a0 + 0xdf8);
      }
    }
  }
  else {
    FUN_005f2e50();
  }
  return;
}



================================================================