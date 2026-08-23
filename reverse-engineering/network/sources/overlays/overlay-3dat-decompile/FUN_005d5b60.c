FUNCTION FUN_005d5b60 @ 0x005d5b60  size=64
CALLERS (11): FUN_005ca640@0x005ca640, FUN_005d3930@0x005d3930, FUN_005ca480@0x005ca480, FUN_005ce0e0@0x005ce0e0, FUN_005cf1e0@0x005cf1e0, FUN_005c8530@0x005c8530, FUN_005d5640@0x005d5640, FUN_005ca4f0@0x005ca4f0, FUN_005cf010@0x005cf010, FUN_005c9690@0x005c9690, FUN_005d1e80@0x005d1e80
CALLEES (1): FUN_005dd920@0x005dd920
----------------------------------------------------------------

void FUN_005d5b60(undefined1 param_1)

{
  *(undefined1 *)(iRam00701070 + 0x2e) = param_1;
  *(undefined1 *)(iRam00701070 + 1) = 2;
  *(undefined1 *)(iRam00701070 + 2) = 0;
  *puRam00701078 = 2;
  FUN_005dd920(0x14,0xffffffffff000000);
  return;
}



================================================================