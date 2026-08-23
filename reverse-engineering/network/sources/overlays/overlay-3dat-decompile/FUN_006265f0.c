FUNCTION FUN_006265f0 @ 0x006265f0  size=312
CALLERS (1): FUN_00622180@0x00622180
CALLEES (8): FUN_0061f4b0@0x0061f4b0, FUN_0061e960@0x0061e960, FUN_0061f1d0@0x0061f1d0, FUN_0061f0e0@0x0061f0e0, FUN_0061e910@0x0061e910, FUN_0061e7f0@0x0061e7f0, FUN_0061f1a0@0x0061f1a0, FUN_0061f760@0x0061f760
----------------------------------------------------------------

undefined4 FUN_006265f0(void)

{
  long lVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (cRam007152e1 == '\x03') {
    lVar1 = FUN_0061e910();
    if (lVar1 == 0) {
      FUN_0061f0e0();
      uVar2 = 0xffffffff;
    }
  }
  else if (cRam007152e1 == '\x02') {
    lVar1 = FUN_0061e910();
    if (lVar1 == 0) {
      FUN_0061f0e0();
      uVar2 = 1;
    }
  }
  else if (cRam007152e1 == '\x01') {
    FUN_0061f760(0xc);
    lVar1 = FUN_0061e7f0();
    if (lVar1 != 0) {
      cRam007152e1 = '\x02';
      FUN_0061e960(0,0x14,1);
    }
  }
  else if (cRam007152e1 == '\0') {
    if (cRam0086f864 == '\0') {
      cRam007152e1 = '\x02';
    }
    else {
      FUN_0061f4b0(0x35);
      FUN_0061f1a0();
      FUN_0061f1d0();
      cRam007152e1 = cRam007152e1 + '\x01';
      uRam007152e4 = 300;
      FUN_0061e960(0,0x14,0);
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



================================================================