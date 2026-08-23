FUNCTION FUN_005f2e50 @ 0x005f2e50  size=768
CALLERS (1): FUN_005ee610@0x005ee610
CALLEES (2): FUN_005ee220@0x005ee220, FUN_005f3230@0x005f3230
----------------------------------------------------------------

void FUN_005f2e50(void)

{
  ushort uVar1;
  uint uVar2;
  short sVar3;
  int iVar4;
  ushort *puStack_4;
  
  sVar3 = 0;
  puStack_4 = (ushort *)(iRam007012a0 + (uint)*(ushort *)(iRam007012a0 + 0x188) * 4 + 0x1540);
  iVar4 = iRam007012a0 +
          ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
          (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
  if (*(char *)(iRam007012a0 + 0x186) == -10) {
    uVar1 = *(ushort *)(iVar4 + 0x251e);
    *(short *)(iRam007012a0 + 0x16) =
         *(short *)(iRam007012a0 + 0x16) + *(short *)(iRam007012a0 + 0xdf6);
    *(char *)(iRam007012a0 + 0xd8de) =
         *(char *)(iRam007012a0 + 0xd8de) + *(char *)(iRam007012a0 + 0xdf6);
    uVar2 = (uint)uVar1 + (uint)*(ushort *)(iRam007012a0 + 0x16);
    if (*(ushort *)(iVar4 + 0x2502) < uVar2) {
      *(short *)(iVar4 + 0x2502) = (short)uVar2;
    }
    if ((*(byte *)(iVar4 + 0x2530) & 2) == 0) {
      uVar2 = (uint)uVar1 + (uint)*(ushort *)(iRam007012a0 + 0xdf6);
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
         (uVar2 + *(ushort *)(iRam007012a0 + 0xdf6) <= (uint)*(ushort *)(iRam007012a0 + 0xd8dc))) {
        uVar2 = uVar2 + *(ushort *)(iRam007012a0 + 0xd8d6) & 0xffff;
      }
      else {
        uVar2 = FUN_005f3230(iVar4 + 0x24e0,&puStack_4);
        uVar2 = uVar2 & 0xffff;
      }
    }
    else {
      uVar2 = uVar2 + *(ushort *)(iRam007012a0 + 0xd8d6) & 0xffff;
    }
    if (*(char *)(iRam007012a0 + 0x186) == '\0') {
      sVar3 = *(short *)(iVar4 + 0x251c);
      uVar2 = uVar2 + *(ushort *)(iVar4 + 0x251a) & 0xffff;
    }
    FUN_005ee220(uVar2,*(short *)(iRam007012a0 + 0xd8d0) + sVar3 + *(short *)(iRam007012a0 + 0xd8d8)
                 ,puStack_4);
    sVar3 = *(short *)(iRam007012a0 + 0xd8ce) + *(short *)(iRam007012a0 + 0xdf6);
    *(short *)(iRam007012a0 + 0xd8d2) = sVar3;
    *(short *)(iRam007012a0 + 0xd8ce) = sVar3;
    *(short *)(iRam007012a0 + 0x16) =
         *(short *)(iRam007012a0 + 0x16) + *(short *)(iRam007012a0 + 0xdf6);
    *(char *)(iRam007012a0 + 0xd8de) =
         *(char *)(iRam007012a0 + 0xd8de) + *(char *)(iRam007012a0 + 0xdf6);
    if (*(char *)(iRam007012a0 + 0x186) == '\x01') {
      if (*puStack_4 < *(ushort *)(iRam007012a0 + 0xd8d2)) {
        *puStack_4 = *(ushort *)(iRam007012a0 + 0xd8d2);
      }
      if (puStack_4[1] < *(ushort *)(iRam007012a0 + 0xdf8)) {
        puStack_4[1] = *(ushort *)(iRam007012a0 + 0xdf8);
      }
      *(undefined2 *)(iVar4 + 0x2518) = *(undefined2 *)(iRam007012a0 + 0xd8d4);
    }
  }
  return;
}



================================================================