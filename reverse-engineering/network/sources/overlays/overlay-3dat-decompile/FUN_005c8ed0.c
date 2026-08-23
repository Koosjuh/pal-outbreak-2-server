FUNCTION FUN_005c8ed0 @ 0x005c8ed0  size=552
CALLERS (0): 
CALLEES (4): FUN_005c9130@0x005c9130, FUN_005dd920@0x005dd920, FUN_005d8b00@0x005d8b00, FUN_005c92d0@0x005c92d0
----------------------------------------------------------------

void FUN_005c8ed0(void)

{
  uint uVar1;
  
  func_0x00106b60(iRam00701068 + 0x68e89,0,0x100);
  func_0x00106b60(iRam00701068 + 0x4f97c,0,4);
  func_0x00106b60(iRam00701068 + 0x68dd8,0,0x50);
  FUN_005c92d0();
  FUN_005c9130();
  func_0x00106b60(iRam00701068 + 0x60dd0,0,0x8000);
  uVar1 = 2;
  *(int *)(iRam00701068 + 0x68dd4) = iRam00701068 + 0x60dd0;
  *(undefined1 *)(iRam00701068 + 0x60dd0) = 0;
  *(int *)(iRam00701068 + 0x68dd4) = *(int *)(iRam00701068 + 0x68dd4) + 1;
  do {
    func_0x00106b60(iRam00701068 + uVar1 * 8 + 0x68f94,0,8);
    uVar1 = uVar1 + 1 & 0xffff;
  } while (uVar1 < 0x10);
  FUN_005d8b00(0x642c68);
  *(undefined1 *)(iRam00701070 + 0x38) = 0x1e;
  *(undefined1 *)(iRam00701070 + 0x2d) = 0;
  *(undefined1 *)(iRam00701070 + 0x2a) = 0;
  *(undefined1 *)(iRam00701070 + 0x2b) = 0;
  *(undefined4 *)(iRam00701070 + 4) = 0;
  *(undefined4 *)(iRam00701070 + 8) = 0;
  *(undefined4 *)(iRam00701070 + 0xc) = 0x248;
  *(undefined4 *)(iRam00701070 + 0x10) = 0x17c;
  *(undefined1 *)(iRam00701070 + 0x35) = 0xff;
  *(undefined2 *)(iRam00701068 + 0x68e78) = 0;
  *(undefined1 *)(iRam00701068 + 0x60dcf) = 0;
  FUN_005dd920(0x60,0xffffffffff000000);
  FUN_005dd920(0x5f,5);
  FUN_005dd920(0x5e,1);
  FUN_005dd920(99,0x10000);
  return;
}



================================================================