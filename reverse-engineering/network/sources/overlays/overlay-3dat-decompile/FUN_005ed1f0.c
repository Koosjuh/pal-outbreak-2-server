FUNCTION FUN_005ed1f0 @ 0x005ed1f0  size=576
CALLERS (2): FUN_005e9a90@0x005e9a90, FUN_005e9b20@0x005e9b20
CALLEES (4): FUN_005ec170@0x005ec170, FUN_005d93f0@0x005d93f0, FUN_005f2450@0x005f2450, FUN_005ed160@0x005ed160
----------------------------------------------------------------

void FUN_005ed1f0(long param_1)

{
  uint uVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  undefined2 *puVar5;
  short sVar6;
  ushort *puVar8;
  uint uVar7;
  
  if (*(char *)(iRam007012a0 + 0xd892) == '\0') {
    puVar5 = (undefined2 *)(iRam007012a0 + 0x8f4);
    iVar4 = iRam007012a0 + (uint)*(ushort *)(iRam007012a0 + 0x188) * 4;
    uVar1 = (uint)*(ushort *)(iRam007012a0 + 0x12) + (uint)*(ushort *)(iRam007012a0 + 0xd8bc);
    puVar8 = (ushort *)(iVar4 + 0x1540);
    uVar7 = uVar1 & 0xffff;
    sVar6 = (short)uVar1;
    if (*(ushort *)(iRam007012a0 + 0x8f4) == 0) {
      if (*(char *)(iRam007012a0 + 0x186) == '\0') {
        *puVar5 = *(undefined2 *)(iRam007012a0 + 0x10);
      }
      else {
        *puVar5 = 0x248;
      }
    }
    else if (*(ushort *)(iRam007012a0 + 0x8f4) < 2) {
      *puVar5 = 2;
    }
    *(short *)(iRam007012a0 + 0xd8be) = *(short *)(iRam007012a0 + 0xd8be) + 10;
    if (*(char *)(iRam007012a0 + 0x186) == '\0') {
      if (param_1 != 0) {
        uVar1 = (uint)*puVar8;
        iVar2 = (uint)*(ushort *)(iRam007012a0 + 0x10) - (uint)*(ushort *)(iRam007012a0 + 0x12);
        if ((int)uVar1 < iVar2) {
          iVar2 = iVar2 - uVar1;
          if (iVar2 < 0) {
            iVar2 = iVar2 + 1;
          }
          uVar7 = uVar7 + (iVar2 >> 1 & 0xffffU) & 0xffff;
        }
      }
      sVar6 = (short)uVar7;
      if (*(char *)(iRam007012a0 + 0xe96b) == '\0') {
        sVar3 = *(short *)(iRam007012a0 + 0xd8c6) + *(short *)(iRam007012a0 + 0xd8be);
        FUN_005d93f0(uVar7,sVar3,uVar7 + *(ushort *)(iRam007012a0 + 0x8f4) & 0xffff,
                     *(short *)(iRam007012a0 + 0x8f2) + sVar3);
      }
    }
    *(short *)(iRam007012a0 + 0xd8be) =
         *(short *)(iRam007012a0 + 0xd8be) + *(short *)(iRam007012a0 + 0x8f2) + 10;
    *(undefined2 *)(iRam007012a0 + 0xd8c2) = *(undefined2 *)(iRam007012a0 + 0xd8be);
    FUN_005ec170(iRam007012a0 + 0xd8bc);
    if (*(char *)(iRam007012a0 + 0x186) == '\x01') {
      *puVar8 = sVar6 + *(short *)(iRam007012a0 + 0x8f4);
      *(short *)(iVar4 + 0x1542) = *(short *)(iRam007012a0 + 0x8f2) + 0x14;
    }
    *(undefined2 *)(iRam007012a0 + 0x8f2) = 0;
    FUN_005ed160();
  }
  else {
    FUN_005f2450();
  }
  return;
}



================================================================