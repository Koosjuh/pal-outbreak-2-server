FUNCTION FUN_005f0b20 @ 0x005f0b20  size=748
CALLERS (1): FUN_005ebd20@0x005ebd20
CALLEES (1): FUN_005ef850@0x005ef850
----------------------------------------------------------------

undefined4 FUN_005f0b20(int param_1)

{
  undefined2 *puVar1;
  char cVar2;
  int in_v0_lo;
  int iVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  
  if (*(char *)(param_1 + 0x47) != '\0') {
    puVar1 = (undefined2 *)(iRam007012a0 + 0xd894);
    *(undefined2 *)(iRam007012a0 + 0xd898) = *puVar1;
    *(undefined2 *)(param_1 + 0x34) = *puVar1;
    iVar6 = iRam007012a0 +
            ((uint)*(ushort *)(iRam007012a0 + 0xd898) * 0x18 -
            (uint)*(ushort *)(iRam007012a0 + 0xd898)) * 4;
    for (iVar7 = 0; iVar7 < (int)(*(byte *)(iVar6 + 0x2527) - 1); iVar7 = iVar7 + 1) {
      lVar5 = FUN_005ef850(4);
      if (lVar5 < 0) {
        return 0xffffffff;
      }
      iVar3 = iRam007012a0 +
              ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
              (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
      iVar4 = *(int *)(iVar3 + 0x24e0);
      if (iVar4 == 0) {
        return 0xffffffff;
      }
      if (*(char *)(iRam007012a0 + 0x186) == -10) {
        *(undefined1 *)(iVar3 + 0x252c) = *(undefined1 *)(iVar4 + 0x4c);
        *(undefined1 *)(iVar3 + 0x252d) = *(undefined1 *)(iVar4 + 0x4d);
        *(undefined2 *)(iVar3 + 0x2514) = *(undefined2 *)(iRam007012a0 + 0xd898);
        *(undefined1 *)(iVar3 + 0x2527) = *(undefined1 *)(iVar6 + 0x2527);
        *(undefined1 *)(iVar3 + 0x2528) = *(undefined1 *)(iVar6 + 0x2528);
        *(undefined1 *)(iVar3 + 0x2525) = *(undefined1 *)(iVar4 + 0x45);
        *(undefined2 *)(iVar3 + 0x2512) = *(undefined2 *)(iVar4 + 0x32);
        *(undefined2 *)(iVar3 + 0x2510) = *(undefined2 *)(iVar4 + 0x30);
        *(undefined1 *)(iVar3 + 0x2524) = 0;
        *(undefined2 *)(iVar3 + 0x2500) = 0;
        *(undefined2 *)(iVar3 + 0x24fc) = 0;
        *(undefined2 *)(iVar3 + 0x24fe) = *(undefined2 *)(iVar6 + 0x24fe);
        *(undefined2 *)(iVar3 + 0x2504) = *(undefined2 *)(iVar6 + 0x2504);
        *(undefined1 *)(iVar3 + 0x2526) = *(undefined1 *)(iVar6 + 0x2526);
      }
      *(char *)(iVar4 + 0x4c) = *(char *)(iVar4 + 0x4c) + '\x01';
      *(short *)(iVar3 + 0x2508) =
           *(short *)(iVar3 + 0x2510) + *(short *)(iVar4 + 0x28) + *(short *)(iVar4 + 0x2c);
      *(short *)(iVar3 + 0x250a) =
           *(short *)(iVar3 + 0x2510) + *(short *)(iVar4 + 0x2a) + *(short *)(iVar4 + 0x2e);
      *(undefined2 *)(iVar3 + 0x250c) = 0;
      *(undefined2 *)(iVar3 + 0x250e) = 0;
      *(undefined2 *)(iRam007012a0 + 0xd894) =
           *(undefined2 *)(iRam007012a0 + (uint)*(byte *)(iRam007012a0 + 0xd892) * 2 + 0xd89a);
      iVar4 = iRam007012a0 +
              ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
              (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
      param_1 = iVar4 + 0x24e0;
      in_v0_lo = *(int *)(iVar4 + 0x24e0);
      if (in_v0_lo == 0) {
        return 0xffffffff;
      }
      cVar2 = *(char *)(iRam007012a0 + 0xd892);
      if (cVar2 == '\0') {
        return 0xffffffff;
      }
      *(char *)(iRam007012a0 + 0xd892) = cVar2 + -1;
    }
    if (*(char *)(iRam007012a0 + 0x186) == -10) {
      *(undefined1 *)(param_1 + 0x49) = 1;
    }
    *(short *)(in_v0_lo + 0x2c) =
         *(short *)(in_v0_lo + 0x2c) +
         *(short *)(iVar6 + 0x2512) + *(short *)(iVar6 + 0x24fc) + *(short *)(iVar6 + 0x2510) * 2;
    if (*(char *)(iRam007012a0 + 0x186) == -10) {
      *(short *)(in_v0_lo + 0x20) =
           *(short *)(in_v0_lo + 0x20) +
           *(short *)(iVar6 + 0x2512) + *(short *)(iVar6 + 0x24fc) + *(short *)(iVar6 + 0x2510) * 2;
      *(char *)(in_v0_lo + 0x44) = *(char *)(in_v0_lo + 0x44) + '\x01';
    }
  }
  return 0;
}



================================================================