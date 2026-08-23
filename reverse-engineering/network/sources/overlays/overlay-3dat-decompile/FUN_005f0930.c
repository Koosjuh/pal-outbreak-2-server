FUNCTION FUN_005f0930 @ 0x005f0930  size=224
CALLERS (1): FUN_005f10a0@0x005f10a0
CALLEES (5): FUN_005f0480@0x005f0480, FUN_005f08c0@0x005f08c0, FUN_005ef5e0@0x005ef5e0, FUN_005ef850@0x005ef850, FUN_005f00b0@0x005f00b0
----------------------------------------------------------------

undefined4 FUN_005f0930(long param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  
  do {
    FUN_005ef5e0();
    lVar3 = FUN_005ef850(4);
    if (lVar3 < 0) {
      return 0xffffffff;
    }
    iVar2 = iRam007012a0 +
            ((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
            (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4;
    iVar1 = *(int *)(iVar2 + 0x24e0);
    iVar2 = iVar2 + 0x24e0;
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    *(undefined1 *)(iRam007012a0 + 0x18d) = 1;
    FUN_005f00b0(iVar2,iVar1);
    lVar3 = FUN_005f0480(iVar2,iVar1,param_1);
    if (lVar3 < 0) {
      return 0xffffffff;
    }
    param_1 = FUN_005f08c0(param_2);
  } while (param_1 != 0);
  return 0;
}



================================================================