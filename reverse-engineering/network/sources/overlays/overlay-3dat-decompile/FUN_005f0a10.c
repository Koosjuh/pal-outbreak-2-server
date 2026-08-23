FUNCTION FUN_005f0a10 @ 0x005f0a10  size=272
CALLERS (1): FUN_005eb7d0@0x005eb7d0
CALLEES (4): FUN_005f0480@0x005f0480, FUN_005f07e0@0x005f07e0, FUN_005ef850@0x005ef850, FUN_005f00b0@0x005f00b0
----------------------------------------------------------------

undefined4 FUN_005f0a10(void)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  int iVar4;
  
  iVar1 = iRam007012a0 +
          ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
          (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
  iVar4 = *(int *)(iVar1 + 0x24e0);
  iVar1 = iVar1 + 0x24e0;
  if (iVar4 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    lVar3 = FUN_005f07e0(iVar1);
    if (lVar3 == 0) {
      uVar2 = 0;
    }
    else {
      do {
        lVar3 = FUN_005f0480(iVar1,iVar4,lVar3);
        if (lVar3 < 0) {
          return 0xffffffff;
        }
        lVar3 = FUN_005ef850(4);
        if (lVar3 < 0) {
          return 0xffffffff;
        }
        iVar1 = iRam007012a0 +
                ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
                (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
        iVar4 = *(int *)(iVar1 + 0x24e0);
        iVar1 = iVar1 + 0x24e0;
        if (iVar4 == 0) {
          return 0xffffffff;
        }
        FUN_005f00b0(iVar1,iVar4);
        lVar3 = FUN_005f07e0(iVar1);
      } while (lVar3 != 0);
      uVar2 = 0;
    }
  }
  return uVar2;
}



================================================================