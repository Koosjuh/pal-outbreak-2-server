FUNCTION FUN_005f3e30 @ 0x005f3e30  size=276
CALLERS (1): FUN_005f3de0@0x005f3de0
CALLEES (5): FUN_005de2a0@0x005de2a0, FUN_00634550@0x00634550, FUN_005ac3b0@0x005ac3b0, FUN_005b2400@0x005b2400, FUN_006386f0@0x006386f0
----------------------------------------------------------------

void FUN_005f3e30(int param_1)

{
  func_0x001a7990();
  *(char *)(param_1 + 8) = *(char *)(param_1 + 8) + '\x01';
  func_0x001af970(4,0x5f4220);
  func_0x001ad290();
  func_0x001ad820();
  func_0x001ad8c0(1);
  func_0x001d41c0();
  if (iRam00337dd0 == 0) {
    func_0x007de660();
    iRam00337dd0 = 1;
  }
  FUN_006386f0();
  func_0x001c0490(*(undefined4 *)((uint)bRam0034359d * 4 + 0x6495f0));
  FUN_00634550(bRam0034359d);
  FUN_005ac3b0();
  FUN_005b2400();
  func_0x00106b60(0x874500,0,0xa28);
  func_0x00106b60(0x3c8a90,0,0x1d7c);
  FUN_005de2a0(iRam003435bc + 0x2ff000);
  uRam00343639 = 1;
  return;
}



================================================================