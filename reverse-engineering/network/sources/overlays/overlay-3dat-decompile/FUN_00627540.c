FUNCTION FUN_00627540 @ 0x00627540  size=532
CALLERS (1): FUN_00622180@0x00622180
CALLEES (10): FUN_0061f0f0@0x0061f0f0, FUN_0061f4b0@0x0061f4b0, FUN_0061e960@0x0061e960, FUN_0061f1d0@0x0061f1d0, FUN_0061f0e0@0x0061f0e0, FUN_0061e910@0x0061e910, FUN_0061f680@0x0061f680, FUN_0061e7f0@0x0061e7f0, FUN_0061f1a0@0x0061f1a0, FUN_0061f760@0x0061f760
----------------------------------------------------------------

undefined4 FUN_00627540(void)

{
  undefined4 uVar1;
  long lVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar1 = uVar3;
  if (cRam007152e1 == '\x03') {
    FUN_0061f4b0(0xa5);
    FUN_0061f680(0xf);
    lVar2 = FUN_0061e910();
    if (lVar2 == 0) {
      FUN_0061f0e0();
      uVar1 = 0xffffffff;
    }
  }
  else if (cRam007152e1 == '\x02') {
    lVar2 = FUN_0061e910();
    if (lVar2 == 0) {
      FUN_0061f0e0();
      uVar1 = 1;
    }
  }
  else if (cRam007152e1 == '\x01') {
    if (cRam007152e2 == '\x01') {
      sRam007152e4 = sRam007152e4 + -1;
      if (sRam007152e4 < 1) {
        FUN_0061f0f0(0x80000);
        FUN_0061f0f0(0x100000);
        cRam007152e2 = '\0';
        cRam007152e1 = '\x02';
        FUN_0061e960(0,0x14,1);
      }
    }
    else if (cRam007152e2 == '\0') {
      FUN_0061f760(0x11);
      if (sRam007152e4 == 0) {
        lVar2 = FUN_0061e7f0();
        if (lVar2 != 0) {
          if ((long)sRam007152ea < (long)(int)(uRam00365cf0 - 1)) {
            sRam007152ea = sRam007152ea + 1;
            sRam007152e4 = 10;
          }
          else {
            cRam007152e2 = cRam007152e2 + '\x01';
          }
        }
      }
      else {
        sRam007152e4 = sRam007152e4 + -1;
      }
    }
  }
  else if (cRam007152e1 == '\0') {
    uVar1 = 1;
    if (uRam00365cf0 != 0) {
      FUN_0061f1a0();
      FUN_0061f1d0();
      sRam007152ea = 0;
      sRam007152e4 = 10;
      cRam007152e2 = '\0';
      cRam007152e1 = cRam007152e1 + '\x01';
      FUN_0061e960(0,0x14,0);
      uVar1 = uVar3;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



================================================================