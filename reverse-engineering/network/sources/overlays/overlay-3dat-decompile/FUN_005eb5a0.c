FUNCTION FUN_005eb5a0 @ 0x005eb5a0  size=152
CALLERS (0): 
CALLEES (4): FUN_005ec100@0x005ec100, FUN_005f0e10@0x005f0e10, FUN_005ef5e0@0x005ef5e0, FUN_005ef850@0x005ef850
----------------------------------------------------------------

undefined4 FUN_005eb5a0(undefined8 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  long lVar2;
  
  lVar2 = FUN_005f0e10(param_1,param_2,3);
  if (lVar2 < 0) {
    uVar1 = 0xffffffff;
  }
  else {
    *(undefined4 *)(iRam007012a0 + 4) = 0;
    *(undefined1 *)param_2 = 0;
    FUN_005ef5e0();
    lVar2 = FUN_005ef850(3);
    if (lVar2 < 0) {
      uVar1 = 0xffffffff;
    }
    else {
      *(undefined1 *)
       (((uint)*(ushort *)(iRam007012a0 + 0xd894) * 0x18 - (uint)*(ushort *)(iRam007012a0 + 0xd894))
        * 4 + iRam007012a0 + 0x252f) = 1;
      FUN_005ec100();
      uVar1 = 0;
    }
  }
  return uVar1;
}



================================================================