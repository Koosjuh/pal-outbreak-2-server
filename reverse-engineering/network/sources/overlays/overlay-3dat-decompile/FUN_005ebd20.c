FUNCTION FUN_005ebd20 @ 0x005ebd20  size=992
CALLERS (3): FUN_005f1570@0x005f1570, FUN_005f0e10@0x005f0e10, FUN_005f10a0@0x005f10a0
CALLEES (7): FUN_005ec100@0x005ec100, FUN_005f0b20@0x005f0b20, FUN_005f10a0@0x005f10a0, FUN_005ef780@0x005ef780, FUN_005f2280@0x005f2280, FUN_005ed160@0x005ed160, FUN_005ef0e0@0x005ef0e0
----------------------------------------------------------------

undefined4 FUN_005ebd20(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  if (*(char *)(iRam007012a0 + 0xd892) == '\0') {
    uVar3 = 0;
  }
  else {
    lVar5 = FUN_005f10a0(param_1,param_2,4);
    if (lVar5 < 0) {
      uVar3 = 0xffffffff;
    }
    else {
      *(undefined2 *)(iRam007012a0 + 0xd894) =
           *(undefined2 *)((uint)*(byte *)(iRam007012a0 + 0xd892) * 2 + iRam007012a0 + 0xd89a);
      iVar4 = iRam007012a0 +
              ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
              (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
      iVar2 = *(int *)(iVar4 + 0x24e0);
      iVar8 = iVar4 + 0x24e0;
      if (iVar2 == 0) {
        uVar3 = 0xffffffff;
      }
      else {
        FUN_005ec100(*(undefined1 *)(iVar4 + 0x252f));
        *(undefined1 *)(iVar4 + 0x252e) = 0;
        FUN_005ef0e0(param_2);
        iVar7 = ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
                (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4 + iRam007012a0;
        *(byte *)(iVar7 + 0x2530) = *(byte *)(iVar7 + 0x2530) & 0xfe;
        *(undefined1 *)(iRam007012a0 + 0x18c) = 0;
        *(undefined1 *)
         (((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
          (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4 + iRam007012a0 + 0x252f) = 0;
        if ((*(char *)(iRam007012a0 + 0x186) == -10) && (*(byte *)(iVar4 + 0x2527) != 0)) {
          iVar7 = (*(byte *)(iVar4 + 0x2527) - 1) *
                  ((uint)*(ushort *)(iVar4 + 0x2512) + (uint)*(ushort *)(iVar4 + 0x2510) * 2);
          if ((int)(uint)*(ushort *)(iVar4 + 0x2500) < iVar7) {
            *(short *)(iVar4 + 0x2500) = (short)iVar7;
          }
        }
        if (*(ushort *)(iVar4 + 0x24fc) < *(ushort *)(iVar4 + 0x2500)) {
          *(ushort *)(iVar4 + 0x24fc) = *(ushort *)(iVar4 + 0x2500);
        }
        if (*(char *)(iVar4 + 0x2528) == '\0') {
          if (*(ushort *)(iVar4 + 0x24fe) < *(ushort *)(iRam007012a0 + 0xd8d0)) {
            *(ushort *)(iVar4 + 0x24fe) = *(ushort *)(iRam007012a0 + 0xd8d0);
          }
          if (*(ushort *)(iVar4 + 0x24fe) < *(ushort *)(iVar4 + 0x2504)) {
            *(ushort *)(iVar4 + 0x24fe) = *(ushort *)(iVar4 + 0x2504);
          }
        }
        else if (*(char *)(iRam007012a0 + 0x186) != '\0') {
          *(undefined2 *)(iVar4 + 0x2520) = *(undefined2 *)(iRam007012a0 + 0xd8d0);
        }
        *(undefined2 *)(iVar4 + 0x2518) = *(undefined2 *)(iRam007012a0 + 0xd8d0);
        uVar6 = (uint)*(ushort *)(iVar4 + 0x24fe) + (uint)*(ushort *)(iVar4 + 0x2510) * 2;
        if (*(ushort *)(iVar2 + 0x1e) < uVar6) {
          *(short *)(iVar2 + 0x1e) = (short)uVar6;
        }
        if (*(char *)(iVar4 + 0x2527) == '\0') {
          *(short *)(iVar2 + 0x2c) =
               *(short *)(iVar2 + 0x2c) +
               *(short *)(iVar4 + 0x2512) +
               *(short *)(iVar4 + 0x24fc) + *(short *)(iVar4 + 0x2510) * 2;
          if (*(char *)(iRam007012a0 + 0x186) == -10) {
            *(short *)(iVar2 + 0x20) =
                 *(short *)(iVar2 + 0x20) +
                 *(short *)(iVar4 + 0x2512) +
                 *(short *)(iVar4 + 0x24fc) + *(short *)(iVar4 + 0x2510) * 2;
            *(char *)(iVar2 + 0x44) = *(char *)(iVar2 + 0x44) + '\x01';
          }
        }
        if (*(char *)(iRam007012a0 + 0x186) == -10) {
          *(short *)(iVar2 + 0x22) =
               *(short *)(iVar2 + 0x22) +
               *(short *)(iVar4 + 0x2512) +
               *(short *)(iVar4 + 0x2502) + *(short *)(iVar4 + 0x2510) * 2;
        }
        FUN_005f2280(iVar8);
        if (*(char *)(iRam007012a0 + 0x186) == -10) {
          uVar6 = (uint)*(ushort *)(iVar4 + 0x2508) + (uint)*(ushort *)(iVar4 + 0x24fc);
          if (*(ushort *)(iRam007012a0 + 0x182) < uVar6) {
            *(short *)(iRam007012a0 + 0x182) = (short)uVar6;
          }
        }
        cVar1 = *(char *)(iRam007012a0 + 0xd892);
        if (cVar1 == '\0') {
          uVar3 = 0xffffffff;
        }
        else {
          *(char *)(iRam007012a0 + 0xd892) = cVar1 + -1;
          lVar5 = FUN_005f0b20(iVar8);
          if (lVar5 < 0) {
            uVar3 = 0xffffffff;
          }
          else {
            FUN_005ef780(iVar8);
            FUN_005ed160();
            FUN_005ef780(iVar8);
            uVar3 = 0;
          }
        }
      }
    }
  }
  return uVar3;
}



================================================================