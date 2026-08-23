FUNCTION FUN_005f2450 @ 0x005f2450  size=700
CALLERS (1): FUN_005ed1f0@0x005ed1f0
CALLEES (4): FUN_005ec170@0x005ec170, FUN_005d93f0@0x005d93f0, FUN_005ef780@0x005ef780, FUN_005ed160@0x005ed160
----------------------------------------------------------------

void FUN_005f2450(long param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  short *psVar6;
  
  iVar5 = iRam007012a0 + (uint)*(ushort *)(iRam007012a0 + 0x188) * 4;
  iVar3 = iRam007012a0 +
          ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
          (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
  if (*(char *)(iRam007012a0 + 0x186) == -10) {
    uVar2 = (uint)*(ushort *)(iVar3 + 0x251e) + (uint)*(ushort *)(iRam007012a0 + 0x8f4);
    if (*(ushort *)(iVar3 + 0x2500) < uVar2) {
      *(short *)(iVar3 + 0x2500) = (short)uVar2;
    }
    uVar2 = (uint)*(ushort *)(iVar3 + 0x251e) + (uint)*(ushort *)(iRam007012a0 + 0x8f4);
    if (*(ushort *)(iVar3 + 0x2502) < uVar2) {
      *(short *)(iVar3 + 0x2502) = (short)uVar2;
    }
  }
  else {
    psVar6 = (short *)(iRam007012a0 + 0x8f4);
    sVar1 = *(short *)(iRam007012a0 + 0xd8ce) +
            *(short *)(iVar3 + 0x251e) + *(short *)(iRam007012a0 + 0xd8d6);
    if (*(ushort *)(iRam007012a0 + 0x8f4) == 0) {
      if (*(char *)(iRam007012a0 + 0x186) == '\0') {
        *psVar6 = *(short *)(iRam007012a0 + 0xd8dc) - *(short *)(iVar3 + 0x251e);
      }
      else {
        *psVar6 = 0x248;
      }
    }
    else if (*(ushort *)(iRam007012a0 + 0x8f4) < 2) {
      *psVar6 = 2;
    }
    *(short *)(iRam007012a0 + 0xd8d0) = *(short *)(iRam007012a0 + 0xd8d0) + 10;
    if ((*(char *)(iRam007012a0 + 0x186) == '\0') && (*(char *)(iRam007012a0 + 0xe96b) == '\0')) {
      if (param_1 != 0) {
        sVar1 = sVar1 + *(short *)(iVar3 + 0x251a);
      }
      sVar4 = *(short *)(iRam007012a0 + 0xd8d0) +
              *(short *)(iVar3 + 0x251c) + *(short *)(iRam007012a0 + 0xd8d8);
      FUN_005d93f0(sVar1,sVar4,sVar1 + *(short *)(iRam007012a0 + 0x8f4),
                   sVar4 + *(short *)(iRam007012a0 + 0x8f2));
    }
    *(short *)(iRam007012a0 + 0xd8d0) =
         *(short *)(iRam007012a0 + 0xd8d0) + *(short *)(iRam007012a0 + 0x8f2) + 10;
    *(undefined2 *)(iRam007012a0 + 0xd8d4) = *(undefined2 *)(iRam007012a0 + 0xd8d0);
    FUN_005ec170(iRam007012a0 + 0xd8ce);
    if (*(char *)(iRam007012a0 + 0x186) == '\x01') {
      *(short *)(iVar5 + 0x1540) = sVar1 + *(short *)(iRam007012a0 + 0x8f4);
      *(short *)(iVar5 + 0x1542) = *(short *)(iRam007012a0 + 0x8f2) + 0x14;
      *(undefined2 *)(iVar3 + 0x2518) = *(undefined2 *)(iRam007012a0 + 0xd8d4);
    }
    *(undefined2 *)(iRam007012a0 + 0x8f2) = 0;
    FUN_005ef780(iVar3 + 0x24e0);
    FUN_005ed160();
    FUN_005ef780(iVar3 + 0x24e0);
  }
  return;
}



================================================================