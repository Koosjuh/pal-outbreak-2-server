FUNCTION FUN_005ca8f0 @ 0x005ca8f0  size=196
CALLERS (1): FUN_005c80a0@0x005c80a0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005ca8f0(void)

{
  *(undefined1 *)(iRam00701068 + 0x68f94) = 1;
  *(undefined4 *)(iRam00701068 + 0x68f98) = 0xffffffff;
  *(undefined1 *)(iRam00701068 + 0x68f95) = 0;
  func_0x001af010(0xd,0,0xffffffffff000000,0xffffffffffffffff,0xffffffffffffffff);
  *(undefined1 *)(iRam00701068 + 0x68f9c) = 1;
  *(undefined4 *)(iRam00701068 + 0x68fa0) = 0xff000001;
  *(undefined1 *)(iRam00701068 + 0x68f9d) = 0;
  func_0x001af010(0xe,0,0xffffffffff000000,0xffffffffff000001,0xffffffffff000001);
  return;
}



================================================================