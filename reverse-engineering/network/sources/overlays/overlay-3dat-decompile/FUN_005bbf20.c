FUNCTION FUN_005bbf20 @ 0x005bbf20  size=152
CALLERS (1): FUN_005bba20@0x005bba20
CALLEES (3): FUN_005c5c10@0x005c5c10, FUN_005c5c70@0x005c5c70, FUN_005bdf90@0x005bdf90
----------------------------------------------------------------

void FUN_005bbf20(undefined8 param_1)

{
  if (cRam006ff2b1 == '\x01') {
    uRam006ff2b2 = 0;
    uRam006ff2af = 0;
    func_0x00106b60(0x6fb758,0,0x654);
    if ((cRam006c4b90 == '\x04') || (cRam006c4b90 == '\x0e')) {
      FUN_005c5c10(param_1);
      FUN_005bdf90(1,0);
    }
    else {
      FUN_005c5c70(param_1);
    }
  }
  return;
}



================================================================