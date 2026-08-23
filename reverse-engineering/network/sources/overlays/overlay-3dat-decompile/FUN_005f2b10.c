FUNCTION FUN_005f2b10 @ 0x005f2b10  size=820
CALLERS (1): FUN_005ee010@0x005ee010
CALLEES (2): FUN_005f3230@0x005f3230, FUN_005d9350@0x005d9350
----------------------------------------------------------------

void FUN_005f2b10(void)

{
  ushort uVar1;
  uint uVar2;
  short sVar3;
  int iVar4;
  int iStack_4;
  
  iStack_4 = iRam007012a0 + (uint)*(ushort *)(iRam007012a0 + 0x188) * 4 + 0x1540;
  iVar4 = iRam007012a0 +
          ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
          (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
  if (*(char *)(iRam007012a0 + 0x186) == -10) {
    uVar1 = *(ushort *)(iVar4 + 0x251e);
    *(short *)(iRam007012a0 + 0x16) =
         *(short *)(iRam007012a0 + 0x16) + *(short *)(iRam007012a0 + 0x18) * 8 + 0x18;
    *(undefined1 *)(iRam007012a0 + 0xd8de) = 1;
    uVar2 = (uint)uVar1 + (uint)*(ushort *)(iRam007012a0 + 0x16);
    if (*(ushort *)(iVar4 + 0x2502) < uVar2) {
      *(short *)(iVar4 + 0x2502) = (short)uVar2;
    }
    if ((*(byte *)(iVar4 + 0x2530) & 2) == 0) {
      uVar2 = (uint)uVar1 + (uint)*(ushort *)(iRam007012a0 + 0x18) * 8 + 0x18;
      if (*(ushort *)(iVar4 + 0x2500) < uVar2) {
        *(short *)(iVar4 + 0x2500) = (short)uVar2;
      }
    }
    else if (*(ushort *)(iVar4 + 0x2500) < *(ushort *)(iVar4 + 0x2502)) {
      *(ushort *)(iVar4 + 0x2500) = *(ushort *)(iVar4 + 0x2502);
    }
  }
  else {
    uVar2 = (uint)*(ushort *)(iVar4 + 0x251e) + (uint)*(ushort *)(iRam007012a0 + 0xd8ce) & 0xffff;
    if ((*(byte *)(iVar4 + 0x2530) & 2) == 0) {
      if ((*(ushort *)(iRam007012a0 + 0xd8ce) == 0) ||
         (uVar2 + (uint)*(ushort *)(iRam007012a0 + 0x18) * 8 + 0x18 <=
          (uint)*(ushort *)(iRam007012a0 + 0xd8dc))) {
        uVar2 = uVar2 + *(ushort *)(iRam007012a0 + 0xd8d6) & 0xffff;
      }
      else {
        uVar2 = FUN_005f3230(iVar4 + 0x24e0,&iStack_4);
        uVar2 = uVar2 & 0xffff;
      }
    }
    else {
      uVar2 = uVar2 + *(ushort *)(iRam007012a0 + 0xd8d6) & 0xffff;
    }
    *(short *)(iRam007012a0 + 0xd8d2) =
         *(short *)(iRam007012a0 + 0xd8d2) + *(short *)(iRam007012a0 + 0x18) * 8 + 0x18;
    *(short *)(iRam007012a0 + 0x16) =
         *(short *)(iRam007012a0 + 0x16) + *(short *)(iRam007012a0 + 0x18) * 8 + 0x18;
    if ((*(char *)(iRam007012a0 + 0x186) == '\0') && (*(char *)(iRam007012a0 + 0xe96b) == '\0')) {
      sVar3 = *(short *)(iRam007012a0 + 0xd8d8) +
              *(short *)(iVar4 + 0x251c) + *(short *)(iRam007012a0 + 0xd8d0) +
              *(short *)(iStack_4 + 2);
      FUN_005d9350(uVar2 + *(ushort *)(iVar4 + 0x251a) & 0xffff,sVar3 + -0x14,
                   (uint)*(ushort *)(iVar4 + 0x251a) +
                   (uint)*(ushort *)(iRam007012a0 + 0xd8d2) +
                   (uint)*(ushort *)(iVar4 + 0x251e) + (uint)*(ushort *)(iRam007012a0 + 0xd8d6) &
                   0xffff,sVar3);
    }
    *(undefined2 *)(iRam007012a0 + 0xd8ce) = *(undefined2 *)(iRam007012a0 + 0xd8d2);
    *(undefined1 *)(iRam007012a0 + 0xd8de) = 1;
    if (*(char *)(iRam007012a0 + 0x186) == '\x01') {
      if (*(ushort *)(iStack_4 + 2) < 0x14) {
        *(undefined2 *)(iStack_4 + 2) = 0x14;
      }
      *(undefined2 *)(iVar4 + 0x2518) = *(undefined2 *)(iRam007012a0 + 0xd8d4);
    }
  }
  return;
}



================================================================