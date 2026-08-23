FUNCTION FUN_005eb7d0 @ 0x005eb7d0  size=448
CALLERS (3): FUN_005eb640@0x005eb640, FUN_005f10a0@0x005f10a0, FUN_005eb750@0x005eb750
CALLEES (8): FUN_005f0a10@0x005f0a10, FUN_005f0300@0x005f0300, FUN_005f0190@0x005f0190, FUN_005f0340@0x005f0340, FUN_005ef780@0x005ef780, FUN_005efa60@0x005efa60, FUN_005f00b0@0x005f00b0, FUN_005ef640@0x005ef640
----------------------------------------------------------------

undefined4 FUN_005eb7d0(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  int *piVar5;
  int *piVar6;
  
  iVar1 = iRam007012a0 +
          ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
          (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
  if (*(int *)(iVar1 + 0x24e0) == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    *(undefined1 *)(iRam007012a0 + 0x18d) = 1;
    FUN_005f00b0(iVar1 + 0x24e0);
    if (*(char *)(iRam007012a0 + 0x186) == '\0') {
      FUN_005efa60(iRam007012a0 + 0xf1c);
    }
    lVar4 = FUN_005f0a10();
    if (lVar4 < 0) {
      uVar2 = 0xffffffff;
    }
    else {
      iVar3 = iRam007012a0 +
              ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
              (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
      iVar1 = *(int *)(iVar3 + 0x24e0);
      piVar6 = (int *)(iVar3 + 0x24e0);
      if (iVar1 == 0) {
        uVar2 = 0xffffffff;
      }
      else {
        *(undefined2 *)(iVar3 + 0x2504) = 0;
        FUN_005f0190(piVar6,iVar1);
        FUN_005f0300(piVar6,iVar1);
        FUN_005f0340(piVar6,iVar1);
        if (*(char *)(iVar3 + 0x2528) != '\0') {
          *(short *)(iVar3 + 0x2520) = *(short *)(*piVar6 + 0x1e) + *(short *)(iVar3 + 0x2510) * -2;
          piVar5 = piVar6;
          while( true ) {
            if (*(ushort *)((int)piVar5 + 0x42) == 0) break;
            iVar1 = iRam007012a0 + (uint)*(ushort *)((int)piVar5 + 0x42) * 0x5c;
            piVar5 = (int *)(iVar1 + 0x24e0);
            *(short *)(iVar3 + 0x2520) =
                 *(short *)(iVar3 + 0x2520) +
                 *(short *)(iVar3 + 0x2512) + *(short *)(iVar3 + 0x2510) * 2;
            *(short *)(iVar3 + 0x2520) =
                 *(short *)(iVar3 + 0x2520) +
                 *(short *)(*(int *)(iVar1 + 0x24e0) + 0x1e) + *(short *)(iVar3 + 0x2510) * -2;
          }
          FUN_005ef640(piVar6);
        }
        FUN_005ef780(piVar6);
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}



================================================================