FUNCTION FUN_005ee010 @ 0x005ee010  size=520
CALLERS (1): FUN_005e9e20@0x005e9e20
CALLEES (4): FUN_005ed460@0x005ed460, FUN_005f2b10@0x005f2b10, FUN_005eced0@0x005eced0, FUN_005d9350@0x005d9350
----------------------------------------------------------------

void FUN_005ee010(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  int iStack_4;
  
  if (*(char *)(iRam007012a0 + 0xd892) == '\0') {
    iStack_4 = iRam007012a0 + (uint)*(ushort *)(iRam007012a0 + 0x188) * 4 + 0x1540;
    uVar4 = (uint)*(ushort *)(iRam007012a0 + 0x12) + (uint)*(ushort *)(iRam007012a0 + 0xd8bc) &
            0xffff;
    if ((*(ushort *)(iRam007012a0 + 0xd8bc) == 0) ||
       (uVar4 + (uint)*(ushort *)(iRam007012a0 + 0x18) * 8 + 0x18 <=
        (uint)*(ushort *)(iRam007012a0 + 0x10))) {
      uVar4 = uVar4 + *(ushort *)(iRam007012a0 + 0xd8c4);
    }
    else {
      uVar4 = FUN_005ed460(&iStack_4,uVar4);
    }
    *(short *)(iRam007012a0 + 0xd8c0) =
         *(short *)(iRam007012a0 + 0xd8c0) + *(short *)(iRam007012a0 + 0x18) * 8 + 0x18;
    uVar1 = *(ushort *)(iRam007012a0 + 0x12);
    uVar2 = *(ushort *)(iRam007012a0 + 0xd8c4);
    uVar3 = *(ushort *)(iRam007012a0 + 0xd8c0);
    if ((*(char *)(iRam007012a0 + 0x186) == '\0') && (*(char *)(iRam007012a0 + 0xe96b) == '\0')) {
      uVar5 = FUN_005eced0(iStack_4);
      sVar6 = *(short *)(iRam007012a0 + 0xd8be) + *(short *)(iStack_4 + 2);
      FUN_005d9350((uVar4 & 0xffff) + (uVar5 & 0xffff) & 0xffff,sVar6 + -0x14,
                   ((uint)uVar3 + (uint)uVar1 + (uint)uVar2 & 0xffff) + (uVar5 & 0xffff) & 0xffff,
                   sVar6);
    }
    *(undefined2 *)(iRam007012a0 + 0xd8bc) = *(undefined2 *)(iRam007012a0 + 0xd8c0);
    *(undefined1 *)(iRam007012a0 + 0xd8cc) = 1;
    if ((*(char *)(iRam007012a0 + 0x186) == '\x01') && (*(ushort *)(iStack_4 + 2) < 0x14)) {
      *(undefined2 *)(iStack_4 + 2) = 0x14;
    }
  }
  else {
    FUN_005f2b10();
  }
  return;
}



================================================================