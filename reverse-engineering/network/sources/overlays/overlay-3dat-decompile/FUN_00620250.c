FUNCTION FUN_00620250 @ 0x00620250  size=800
CALLERS (1): FUN_00622180@0x00622180
CALLEES (17): FUN_0061e750@0x0061e750, FUN_0061f8c0@0x0061f8c0, FUN_0061f2d0@0x0061f2d0, FUN_0061e940@0x0061e940, FUN_0061f1d0@0x0061f1d0, FUN_0061f0e0@0x0061f0e0, FUN_0061f9d0@0x0061f9d0, FUN_0061e910@0x0061e910, FUN_0061e800@0x0061e800, FUN_0061ea20@0x0061ea20, FUN_0061e7f0@0x0061e7f0, FUN_0061f0f0@0x0061f0f0, ...
----------------------------------------------------------------

undefined4 FUN_00620250(void)

{
  ulong uVar1;
  long lVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  switch(cRam007152e1) {
  case '\0':
    FUN_0061f4b0(0x36);
    lVar2 = FUN_0061f970();
    if (lVar2 != 0) {
      cRam007152e1 = cRam007152e1 + '\x01';
      FUN_0061e940();
      FUN_0061ea20(0);
      uVar3 = 0;
    }
    break;
  case '\x01':
    FUN_0061f4b0(0x36);
    lVar2 = FUN_0061f9d0();
    if (lVar2 != 0) {
      sRam007152e4 = 10;
      sRam007152e8 = 1;
      cRam007152e1 = cRam007152e1 + '\x01';
      FUN_0061f1d0();
      FUN_0061f2d0(3,2);
      FUN_0061f8c0();
    }
    break;
  case '\x02':
    FUN_0061f4b0(0x13);
    FUN_0061f4b0(0x14);
    FUN_0061f4b0(0x16);
    FUN_0061f4b0(0x15);
    if (sRam007152e4 == 0) {
      uVar1 = FUN_0061e750();
      if ((uVar1 & 2) == 0) {
        if (((uVar1 & 1) != 0) && (sRam007152e8 != 0)) {
          FUN_0061e720();
          sRam007152e8 = 0;
        }
      }
      else if (sRam007152e8 != 1) {
        FUN_0061e720();
        sRam007152e8 = 1;
      }
      lVar2 = FUN_0061e7f0();
      if (lVar2 == 0) {
        lVar2 = FUN_0061e800();
        if (lVar2 != 0) {
          cRam007152e1 = '\x06';
          FUN_0061f0f0(0x400);
          FUN_0061f0f0(0x80000);
          FUN_0061f0f0(0x100000);
          FUN_0061f0f0(0x200000);
        }
      }
      else {
        sRam007152e6 = 0xf;
        cRam007152e1 = cRam007152e1 + '\x01';
        FUN_0061f0f0(0x80000);
        FUN_0061f0f0(0x100000);
        FUN_0061f0f0(0x200000);
      }
    }
    else {
      sRam007152e4 = sRam007152e4 + -1;
    }
    break;
  case '\x03':
    FUN_0061f4b0(0x13);
    FUN_0061f4b0(0x14);
    FUN_0061f4b0(0x16);
    sRam007152e6 = sRam007152e6 + -1;
    if (sRam007152e6 < 1) {
      if (sRam007152e8 == 0) {
        FUN_0061f0e0();
        cRam007152e1 = cRam007152e1 + '\x01';
        func_0x001a6910(0,0,10);
        FUN_0061e960(0,0x14,1);
      }
      else {
        FUN_0061f0f0(0x400);
        cRam007152e1 = '\x06';
      }
    }
    break;
  case '\x04':
    lVar2 = FUN_0061e910();
    if (lVar2 != 0) {
      return 0;
    }
    func_0x001a6780();
    cRam007152e1 = cRam007152e1 + '\x01';
    FUN_0061f0d0();
  case '\x05':
    uVar3 = 1;
    break;
  case '\x06':
    lVar2 = FUN_0061e910();
    if (lVar2 != 0) {
      return 0;
    }
    cRam007152e1 = cRam007152e1 + '\x01';
  case '\a':
    uVar3 = 0xffffffff;
  }
  return uVar3;
}



================================================================