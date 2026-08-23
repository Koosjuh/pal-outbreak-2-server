FUNCTION FUN_005eb0f0 @ 0x005eb0f0  size=212
CALLERS (0): 
CALLEES (4): FUN_005eb250@0x005eb250, FUN_005ef5b0@0x005ef5b0, FUN_005f0e10@0x005f0e10, FUN_005ef850@0x005ef850
----------------------------------------------------------------

undefined4 FUN_005eb0f0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = FUN_005f0e10(param_1,param_2,2);
  if (lVar3 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    *(undefined4 *)(iRam007012a0 + 4) = 0;
    *(undefined1 *)param_2 = 0;
    FUN_005ef5b0();
    lVar3 = FUN_005ef850(2);
    if (lVar3 < 0) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = 0;
      if (*(char *)(iRam007012a0 + 0x186) != -10) {
        iVar1 = *(int *)(((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 -
                         (uint)*(ushort *)(iRam007012a0 + 0xd894)) * 4 + iRam007012a0 + 0x24f4);
        if (iVar1 != 0) {
          *(int *)param_1 = iVar1;
          *(undefined4 *)(iRam007012a0 + 8) = 2;
          FUN_005eb250(param_1,param_2);
        }
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}



================================================================