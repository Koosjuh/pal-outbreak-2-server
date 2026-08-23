FUNCTION FUN_005eacd0 @ 0x005eacd0  size=1052
CALLERS (3): FUN_005f1570@0x005f1570, FUN_005f0e10@0x005f0e10, FUN_005f10a0@0x005f10a0
CALLEES (5): FUN_005ec170@0x005ec170, FUN_005f21f0@0x005f21f0, FUN_005f10a0@0x005f10a0, FUN_005f1da0@0x005f1da0, FUN_005ed160@0x005ed160
----------------------------------------------------------------

undefined4 FUN_005eacd0(undefined8 param_1,undefined8 param_2)

{
  byte bVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  
  if (*(char *)(iRam007012a0 + 0xd892) == '\0') {
    uVar5 = 0;
  }
  else {
    lVar8 = FUN_005f10a0(param_1,param_2,1);
    if (lVar8 < 0) {
      uVar5 = 0xffffffff;
    }
    else {
      *(undefined2 *)(iRam007012a0 + 0xd894) =
           *(undefined2 *)((uint)*(byte *)(iRam007012a0 + 0xd892) * 2 + iRam007012a0 + 0xd89a);
      iVar6 = iRam007012a0 +
              ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
              (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
      iVar4 = *(int *)(iVar6 + 0x24e0);
      if (*(int *)(iVar6 + 0x24ec) != 0) {
        uVar7 = FUN_005f1da0(*(int *)(iVar6 + 0x24ec),0xfffffffffffffff6);
        uVar7 = (uint)*(ushort *)(iVar6 + 0x2512) +
                (uVar7 & 0xffff) + (uint)*(byte *)(iVar6 + 0x2525) * 2;
        if (*(ushort *)(iVar6 + 0x24fc) < uVar7) {
          *(short *)(iVar6 + 0x24fc) = (short)uVar7;
        }
      }
      *(undefined1 *)(iVar6 + 0x252e) = 0;
      *(undefined4 *)(iRam007012a0 + 4) = 0;
      *(undefined1 *)param_2 = 0;
      uVar7 = (uint)*(byte *)(iVar6 + 0x2525) +
              (uint)*(ushort *)(iVar6 + 0x2504) + (uint)*(ushort *)(iVar6 + 0x2512);
      if (*(ushort *)(iVar6 + 0x24fe) < uVar7) {
        *(short *)(iVar6 + 0x24fe) = (short)uVar7;
      }
      bVar1 = *(byte *)(iRam007012a0 + 0xd892);
      if (bVar1 < 2) {
        if (bVar1 != 0) {
          *(byte *)(iRam007012a0 + 0xd892) = bVar1 - 1;
        }
        if (*(char *)(iRam007012a0 + 0xd892) == '\0') {
          if (*(char *)(iRam007012a0 + 0x186) == '\x01') {
            *(short *)((uint)*(ushort *)(iRam007012a0 + 0x188) * 4 + iRam007012a0 + 0x1540) =
                 *(short *)(iVar6 + 0x2508) + *(short *)(iVar6 + 0x24fc);
            *(short *)((uint)*(ushort *)(iRam007012a0 + 0x188) * 4 + iRam007012a0 + 0x1542) =
                 *(short *)(iVar6 + 0x250a) + *(short *)(iVar6 + 0x24fe);
          }
          else if (*(char *)(iRam007012a0 + 0x186) == -10) {
            uVar7 = (uint)*(ushort *)(iVar6 + 0x2508) + (uint)*(ushort *)(iVar6 + 0x24fc);
            if (*(ushort *)(iRam007012a0 + 0x182) < uVar7) {
              *(short *)(iRam007012a0 + 0x182) = (short)uVar7;
            }
          }
          *(short *)(iRam007012a0 + 0xd8c2) =
               *(short *)(iRam007012a0 + 0xd8c2) + *(short *)(iVar6 + 0x24fe);
          *(undefined2 *)(iRam007012a0 + 0xd8be) = *(undefined2 *)(iRam007012a0 + 0xd8c2);
          FUN_005ec170(iRam007012a0 + 0xd8bc);
          FUN_005ed160();
          if (*(char *)(iRam007012a0 + 0x18b) != '\0') {
            *(undefined1 *)(iRam007012a0 + 0x18c) = 1;
          }
        }
      }
      else {
        if (iVar4 == 0) {
          return 0xffffffff;
        }
        *(short *)(iVar4 + 0x24) = *(short *)(iVar4 + 0x24) + *(short *)(iVar6 + 0x24fe);
        *(short *)(iVar4 + 0x2e) = *(short *)(iVar4 + 0x2e) + *(short *)(iVar6 + 0x24fe);
        if (*(char *)(iRam007012a0 + 0x186) == -10) {
          uVar7 = (uint)*(ushort *)(iVar6 + 0x24fc) + (uint)*(ushort *)(iVar4 + 0x3e);
          if (*(ushort *)(iVar4 + 0x20) < uVar7) {
            *(short *)(iVar4 + 0x20) = (short)uVar7;
          }
          *(char *)(iVar4 + 0x44) = *(char *)(iVar4 + 0x44) + '\x01';
        }
        cVar2 = *(char *)(iRam007012a0 + 0xd892);
        if (cVar2 != '\0') {
          *(char *)(iRam007012a0 + 0xd892) = cVar2 + -1;
        }
        if ((*(byte *)(iVar4 + 0x50) & 1) != 0) {
          *(undefined1 *)(iRam007012a0 + 0x18c) = 1;
        }
      }
      FUN_005f21f0(iVar6 + 0x24e0);
      uVar5 = 0;
      if (1 < *(byte *)(iRam007012a0 + 0xd892)) {
        *(undefined2 *)(iRam007012a0 + 0x16) = 0;
        *(undefined2 *)(iRam007012a0 + 0xd8d6) = *(undefined2 *)(iVar4 + 0x28);
        *(undefined2 *)(iRam007012a0 + 0xd8d8) = *(undefined2 *)(iVar4 + 0x2a);
        *(undefined2 *)(iRam007012a0 + 0xd8d2) = 0;
        *(undefined2 *)(iRam007012a0 + 0xd8ce) = 0;
        *(undefined1 *)(iRam007012a0 + 0xd8de) = 0;
        uVar3 = *(undefined2 *)(iVar4 + 0x2e);
        *(undefined2 *)(iRam007012a0 + 0xd8d4) = uVar3;
        *(undefined2 *)(iRam007012a0 + 0xd8d0) = uVar3;
        *(undefined2 *)(iRam007012a0 + 0xd8dc) = *(undefined2 *)(iVar4 + 0x20);
        uVar5 = 0;
      }
    }
  }
  return uVar5;
}



================================================================