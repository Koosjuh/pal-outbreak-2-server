FUNCTION FUN_005bcc30 @ 0x005bcc30  size=172
CALLERS (1): FUN_005bcee0@0x005bcee0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005bcc30(void)

{
  char acStack_40 [64];
  
  if (cRam006ff2ac == '\0') {
    uRam006ff2a8 = 0;
    cRam006ff2ac = '\x01';
    cRam006ff2ad = '\0';
    cRam006ff2ae = '\0';
    REG_RCNT1_MODE = 0x800;
    REG_RCNT1_COUNT = 0;
    REG_RCNT1_MODE = 0x283;
    func_0x00106b60(acStack_40,0x55,0x40);
    acStack_40[0] = cRam006ff2ad + cRam006ff2ae;
    func_0x001dfda0(uRam006febac,0,acStack_40,0x40,0x5bce80);
  }
  return;
}



================================================================