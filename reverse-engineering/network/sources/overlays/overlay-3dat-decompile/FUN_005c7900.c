FUNCTION FUN_005c7900 @ 0x005c7900  size=208
CALLERS (1): FUN_00606fc0@0x00606fc0
CALLEES (0): 
----------------------------------------------------------------

undefined8 FUN_005c7900(void)

{
  int aiStack_20 [8];
  
  if (cRam00700fd8 == '\x01') {
    func_0x001c3380(aiStack_20);
    if (aiStack_20[0] == 4) {
      func_0x001c33f0();
      return 0xffffffffffffffff;
    }
    if (aiStack_20[0] == 3) {
      func_0x001c33f0();
      return 1;
    }
  }
  else {
    if (cRam00700fd8 != '\0') {
      return 0;
    }
    if (0 < iRam0086f838) {
      return 1;
    }
    cRam00700fd8 = '\x01';
    uRam0086f800 = 0;
    uRam0086f7f8 = 0;
    iRam0086f838 = iRam00365e04;
    func_0x001c3300();
  }
  return 0;
}



================================================================