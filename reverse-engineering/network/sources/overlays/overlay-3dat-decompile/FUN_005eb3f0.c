FUNCTION FUN_005eb3f0 @ 0x005eb3f0  size=428
CALLERS (3): FUN_005f1570@0x005f1570, FUN_005f0e10@0x005f0e10, FUN_005f10a0@0x005f10a0
CALLEES (1): FUN_005f10a0@0x005f10a0
----------------------------------------------------------------

undefined4 FUN_005eb3f0(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  if (*(char *)(iRam007012a0 + 0xd892) == '\0') {
    uVar3 = 0;
  }
  else {
    lVar4 = FUN_005f10a0(param_1,param_2,2);
    if (lVar4 < 0) {
      uVar3 = 0xffffffff;
    }
    else {
      *(undefined2 *)(iRam007012a0 + 0xd894) =
           *(undefined2 *)((uint)*(byte *)(iRam007012a0 + 0xd892) * 2 + iRam007012a0 + 0xd89a);
      iVar5 = iRam007012a0 +
              ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
              (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
      iVar2 = *(int *)(iVar5 + 0x24e0);
      if (iVar2 == 0) {
        uVar3 = 0xffffffff;
      }
      else {
        *(undefined1 *)(iVar5 + 0x252e) = 0;
        *(undefined4 *)(iRam007012a0 + 4) = 0;
        *(undefined1 *)param_2 = 0;
        *(short *)(iVar2 + 0x2e) =
             *(short *)(iVar2 + 0x2e) + *(short *)(iVar5 + 0x2512) + *(short *)(iVar5 + 0x24fe);
        *(undefined2 *)(iVar2 + 0x24) = *(undefined2 *)(iVar2 + 0x2e);
        iVar6 = (uint)*(ushort *)(iVar5 + 0x2500) - (uint)*(ushort *)(iVar5 + 0x2512);
        if ((int)(uint)*(ushort *)(iVar5 + 0x24fc) < iVar6) {
          *(short *)(iVar5 + 0x24fc) = (short)iVar6;
        }
        uVar7 = (uint)*(ushort *)(iVar5 + 0x24fc) + (uint)*(byte *)(iVar5 + 0x2525) * 2 +
                (uint)*(ushort *)(iVar5 + 0x2512) * 2;
        if (*(ushort *)(iVar2 + 0x1c) < uVar7) {
          *(short *)(iVar2 + 0x1c) = (short)uVar7;
        }
        if (*(char *)(iRam007012a0 + 0x186) == -10) {
          uVar7 = (uint)*(ushort *)(iVar5 + 0x2508) + (uint)*(ushort *)(iVar5 + 0x24fc);
          if (*(ushort *)(iRam007012a0 + 0x182) < uVar7) {
            *(short *)(iRam007012a0 + 0x182) = (short)uVar7;
          }
        }
        cVar1 = *(char *)(iRam007012a0 + 0xd892);
        if (cVar1 != '\0') {
          *(char *)(iRam007012a0 + 0xd892) = cVar1 + -1;
        }
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}



================================================================