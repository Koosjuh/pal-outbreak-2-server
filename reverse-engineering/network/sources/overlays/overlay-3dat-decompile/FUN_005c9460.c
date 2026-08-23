FUNCTION FUN_005c9460 @ 0x005c9460  size=432
CALLERS (0): 
CALLEES (5): FUN_005d59f0@0x005d59f0, FUN_005dd920@0x005dd920, FUN_005cd760@0x005cd760, FUN_005d5cc0@0x005d5cc0, FUN_005cd320@0x005cd320
----------------------------------------------------------------

void FUN_005c9460(void)

{
  FUN_005cd320();
  *(undefined1 *)(iRam00701068 + 0x68e81) = 2;
  *(undefined1 *)(iRam00701068 + 0x68e80) = 2;
  *(undefined1 *)(iRam00701068 + 0x68e82) = 1;
  FUN_005d5cc0(iRam00701068 + 0x4f7a0);
  *(undefined4 *)(iRam00701070 + 0x10) = 0;
  *(undefined4 *)(iRam00701070 + 8) = 0;
  *(undefined1 *)(iRam00701070 + 0x2f) = 0;
  *(undefined1 *)(iRam00701070 + 0x30) = 0;
  FUN_005cd760();
  func_0x00106b60(iRam00701070 + 0x57f,0,0x11);
  func_0x00106b60(iRam00701070 + 0x590,0,0x11);
  func_0x00106b60(iRam00701070 + 0x55d,0,0x11);
  func_0x00106b60(iRam00701070 + 0x56e,0,0x11);
  func_0x00106b60(iRam00701070 + 0x5a1,0,0x11);
  func_0x00106b60(iRam00701070 + 0x5b2,0,0x11);
  *(undefined1 *)(iRam00701070 + 0x32) = 0;
  *(undefined1 *)(iRam00701070 + 0x31) = 0;
  func_0x0010a4f0(iRam00701070 + 0x57f,0x3c9580,0x10);
  *(undefined1 *)(iRam00701070 + 0x2e) = 0;
  *(undefined1 *)(iRam00701068 + 0x68e84) = 2;
  FUN_005dd920(0x14,0xffffffffff000000);
  FUN_005d59f0();
  func_0x001ad210(7);
  return;
}



================================================================