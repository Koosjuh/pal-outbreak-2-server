FUNCTION FUN_005d5900 @ 0x005d5900  size=212
CALLERS (1): FUN_005d6390@0x005d6390
CALLEES (2): FUN_005d7540@0x005d7540, FUN_005d74a0@0x005d74a0
----------------------------------------------------------------

undefined4 FUN_005d5900(void)

{
  undefined4 uVar1;
  long lVar2;
  
  if ((*(char *)(iRam00701070 + 0x55d) == '\0') ||
     (lVar2 = func_0x00109d70(iRam00701070 + 0x55d,iRam00701080), lVar2 == 0)) {
    lVar2 = FUN_005d7540(0x642c20,iRam00701080);
  }
  else {
    lVar2 = FUN_005d7540(0x642c20,iRam00701070 + 0x55d);
  }
  if (lVar2 < 0) {
    uVar1 = 0xffffffff;
  }
  else {
    lVar2 = FUN_005d7540(0x642c28,iRam00701080 + 0x11);
    if (lVar2 < 0) {
      uVar1 = 0xffffffff;
    }
    else {
      FUN_005d74a0(iRam00701068 + 0x4f97c);
      uVar1 = 1;
      uRam00700fe8 = 1;
      *(undefined1 *)(iRam00701070 + 0x34) = 1;
    }
  }
  return uVar1;
}



================================================================