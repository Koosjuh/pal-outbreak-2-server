FUNCTION FUN_005bcce0 @ 0x005bcce0  size=316
CALLERS (2): FUN_005bce20@0x005bce20, FUN_005bce80@0x005bce80
CALLEES (0): 
----------------------------------------------------------------

void FUN_005bcce0(long param_1)

{
  char acStack_40 [64];
  
  if (param_1 < 0) {
    bRam006ff2ae = bRam006ff2ae + 1;
  }
  else {
    bRam006ff2ad = bRam006ff2ad + 1;
    iRam006ff2a8 = iRam006ff2a8 + (int)param_1;
  }
  if ((uint)bRam006ff2ad + (uint)bRam006ff2ae < 8) {
    REG_RCNT1_MODE = 0x800;
    REG_RCNT1_COUNT = 0;
    REG_RCNT1_MODE = 0x283;
    func_0x00106b60(acStack_40,0x55,0x40);
    acStack_40[0] = bRam006ff2ad + bRam006ff2ae;
    func_0x001dfda0(uRam006febac,0,acStack_40,0x40,0x5bce80);
  }
  else {
    REG_RCNT1_MODE = 0x800;
    REG_RCNT1_COUNT = 0;
    REG_RCNT1_MODE = 0x83;
    uRam006ff2ac = 0;
    iRam0086f858 = iRam006ff2a8;
    uRam0086f850 = (uint)bRam006ff2ad;
    uRam0086f848 = (uint)bRam006ff2ae;
  }
  return;
}



================================================================