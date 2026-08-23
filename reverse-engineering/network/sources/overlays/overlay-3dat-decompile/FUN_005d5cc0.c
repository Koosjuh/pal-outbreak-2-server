FUNCTION FUN_005d5cc0 @ 0x005d5cc0  size=240
CALLERS (12): FUN_005c9460@0x005c9460, FUN_005d3930@0x005d3930, FUN_005d60a0@0x005d60a0, FUN_005d47f0@0x005d47f0, FUN_005d09d0@0x005d09d0, FUN_005cc980@0x005cc980, FUN_005d5640@0x005d5640, FUN_005d0960@0x005d0960, FUN_005d0a40@0x005d0a40, FUN_005d6390@0x005d6390, FUN_005c9690@0x005c9690, FUN_005d1e80@0x005d1e80, ...
CALLEES (2): FUN_005dedf0@0x005dedf0, FUN_005dfb00@0x005dfb00
----------------------------------------------------------------

void FUN_005d5cc0(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  
  func_0x00106b60(iRam00701070 + 0x3b,0,0x100);
  func_0x00109eb8(iRam00701070 + 0x3b,param_1);
  if ((*(char *)(iRam00701068 + 0x60dcb) != '\0') &&
     (lVar2 = func_0x0010a700(iRam00701070 + 0x3b,0x642fc8), lVar2 != 0)) {
    iVar1 = func_0x0010a050(iRam00701070 + 0x3b);
    if (0 < 0xff - iVar1) {
      FUN_005dfb00(0x35ba00,iRam00701070 + iVar1 + 0x3b,uRam0035b9f0);
    }
  }
  FUN_005dedf0(iRam00701068 + 0x4f97c,iRam00701070 + 0x3b);
  return;
}



================================================================