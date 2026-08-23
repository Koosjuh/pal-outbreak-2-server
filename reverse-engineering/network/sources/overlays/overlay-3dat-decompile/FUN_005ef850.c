FUNCTION FUN_005ef850 @ 0x005ef850  size=520
CALLERS (13): FUN_005eb1d0@0x005eb1d0, FUN_005f0930@0x005f0930, FUN_005f0a10@0x005f0a10, FUN_005f0b20@0x005f0b20, FUN_005f0e10@0x005f0e10, FUN_005ea880@0x005ea880, FUN_005eb5a0@0x005eb5a0, FUN_005eb640@0x005eb640, FUN_005f10a0@0x005f10a0, FUN_005eb750@0x005eb750, FUN_005ea820@0x005ea820, FUN_005eb6f0@0x005eb6f0, ...
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005ef850(undefined1 param_1)

{
  ushort *puVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  ushort uVar6;
  
  uVar6 = *(ushort *)(iRam007012a0 + 0xd890);
  uVar3 = 0xffffffff;
  if (uVar6 < 499) {
    uVar6 = uVar6 + 1;
    *(ushort *)(iRam007012a0 + 0xd890) = uVar6;
    *(ushort *)(iRam007012a0 + 0xd894) = uVar6;
    iVar4 = iRam007012a0;
    puVar1 = (ushort *)(iRam007012a0 + 0xd894);
    *(char *)(iRam007012a0 + 0xd892) = *(char *)(iRam007012a0 + 0xd892) + '\x01';
    iVar4 = iVar4 + ((uint)*puVar1 * 0x18 - (uint)*puVar1) * 4;
    bVar2 = *(byte *)(iRam007012a0 + 0xd892);
    piVar5 = (int *)(iVar4 + 0x24e0);
    if (bVar2 < 0x10) {
      if (*(byte *)(iRam007012a0 + 0xd8ba) < bVar2) {
        *(byte *)(iRam007012a0 + 0xd8ba) = bVar2;
      }
      *(undefined2 *)((uint)*(byte *)(iRam007012a0 + 0xd892) * 2 + iRam007012a0 + 0xd89a) =
           *(undefined2 *)(iRam007012a0 + 0xd894);
      *(undefined1 *)(iVar4 + 0x252e) = 1;
      if (*(char *)(iRam007012a0 + 0x186) == -10) {
        *(undefined1 *)(iVar4 + 0x24fa) = *(undefined1 *)(iRam007012a0 + 0xd892);
        *(undefined2 *)(iVar4 + 0x24f8) = *(undefined2 *)(iRam007012a0 + 0xd894);
        uVar6 = *(ushort *)((uint)*(byte *)(iRam007012a0 + 0xd892) * 2 + iRam007012a0 + 0xd898);
        *piVar5 = iRam007012a0 + ((uint)uVar6 * 0x18 - (uint)uVar6) * 4 + 0x24e0;
        *(undefined1 *)(iVar4 + 0x24fb) = param_1;
        *(undefined4 *)(iVar4 + 0x24e4) = *(undefined4 *)(*piVar5 + 0x10);
        *(undefined4 *)(iVar4 + 0x24e8) = 0;
        *(int **)(*piVar5 + 0x10) = piVar5;
        if (*(int *)(iVar4 + 0x24e4) != 0) {
          *(int **)(*(int *)(iVar4 + 0x24e4) + 8) = piVar5;
        }
        if (*(int *)(*piVar5 + 0xc) == 0) {
          *(int **)(*piVar5 + 0xc) = piVar5;
        }
        uVar3 = 0;
      }
      else {
        uVar3 = 0;
      }
    }
    else {
      *(byte *)(iRam007012a0 + 0xd892) = 0xf;
      uVar3 = 0xffffffff;
      *(undefined1 *)(iRam007012a0 + 0xd8ba) = 0x10;
    }
  }
  return uVar3;
}



================================================================