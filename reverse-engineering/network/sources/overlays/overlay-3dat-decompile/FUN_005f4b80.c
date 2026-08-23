FUNCTION FUN_005f4b80 @ 0x005f4b80  size=92
CALLERS (5): FUN_005fec30@0x005fec30, FUN_005fede0@0x005fede0, FUN_005f7c80@0x005f7c80, FUN_0062d640@0x0062d640, FUN_00600200@0x00600200
CALLEES (1): FUN_005b18c0@0x005b18c0
----------------------------------------------------------------

undefined4 FUN_005f4b80(void)

{
  undefined4 uVar1;
  long lVar2;
  
  uVar1 = 0;
  if (cRam006c4ba3 == '\0') {
    if ((cRam006c50fb == '\0') && (lVar2 = FUN_005b18c0(), lVar2 != 0)) {
      uVar1 = 1;
      uRam006c4ba4 = 0;
      cRam006c4ba3 = '\x01';
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



================================================================