FUNCTION FUN_0061fd70 @ 0x0061fd70  size=1248
CALLERS (1): FUN_00622180@0x00622180
CALLEES (19): FUN_0061e750@0x0061e750, FUN_0061f8c0@0x0061f8c0, FUN_0061f1f0@0x0061f1f0, FUN_0061f2d0@0x0061f2d0, FUN_0061ea30@0x0061ea30, FUN_0061f180@0x0061f180, FUN_0061e940@0x0061e940, FUN_0061f9d0@0x0061f9d0, FUN_0061f220@0x0061f220, FUN_0061f680@0x0061f680, FUN_0061e800@0x0061e800, FUN_0061e7f0@0x0061e7f0, ...
----------------------------------------------------------------

undefined4 FUN_0061fd70(void)

{
  long lVar1;
  ulong uVar2;
  
  if (cRam007152e1 != 'e') {
    if (cRam007152e1 != 'd') {
      if (cRam007152e1 == '\x14') {
        FUN_0061f4b0(0x36);
        FUN_0061f4b0(0x1a);
        sRam007152e4 = sRam007152e4 + -1;
        if (sRam007152e4 < 1) {
          cRam007152e1 = 6;
          FUN_0061f0f0(0x400);
          return 0;
        }
        if (0x3b < sRam007152e4) {
          return 0;
        }
        lVar1 = FUN_0061e7f0();
        if (lVar1 == 0) {
          return 0;
        }
        cRam007152e1 = 6;
        FUN_0061f0f0(0x400);
        return 0;
      }
      if (cRam007152e1 == '\x06') {
        return 1;
      }
      if (cRam007152e1 == '\x05') {
        FUN_0061f4b0(0x36);
        FUN_0061f4b0(0x1a);
        sRam007152e4 = sRam007152e4 + -1;
        if (sRam007152e4 < 1) {
          cRam007152e1 = cRam007152e1 + '\x01';
          FUN_0061f0f0(0x400);
          return 0;
        }
        if (0x3b < sRam007152e4) {
          return 0;
        }
        lVar1 = FUN_0061e7f0();
        if (lVar1 == 0) {
          return 0;
        }
        cRam007152e1 = cRam007152e1 + '\x01';
        FUN_0061f0f0(0x400);
        return 0;
      }
      if (cRam007152e1 == '\x04') {
        FUN_0061f4b0(0x36);
        lVar1 = FUN_0061d6a0();
        if (lVar1 == -1) {
          cRam007152e1 = 100;
          func_0x001069a8(0x3c9580,0x715280,0x10);
          return 0;
        }
        if (lVar1 != 1) {
          return 0;
        }
        cRam007152e1 = cRam007152e1 + '\x01';
        FUN_0061f220();
        sRam007152e4 = 0x5a;
        return 0;
      }
      if (cRam007152e1 == '\x03') {
        FUN_0061f4b0(0x36);
        FUN_0061ea30();
        func_0x001069a8(0x715280,0x3c9580,0x10);
        func_0x00106b60(0x3c9580,0,0x10);
        func_0x00106b60(0x874f30,0,0xac);
        uRam007152e2 = 0;
        cRam007152e1 = cRam007152e1 + '\x01';
        FUN_0061f1f0();
        return 0;
      }
      if (cRam007152e1 != '\x02') {
        if (cRam007152e1 == '\x01') {
          lVar1 = FUN_0061f9d0();
          if (lVar1 == 0) {
            return 0;
          }
          FUN_0061f4b0(0x36);
          sRam007152e4 = 10;
          sRam007152ea = 1;
          cRam007152e1 = cRam007152e1 + '\x01';
          FUN_0061f1f0();
          FUN_0061f2d0(4,2);
          FUN_0061f8c0();
          return 0;
        }
        if (cRam007152e1 == '\0') {
          FUN_0061f1b0();
          FUN_0061f4b0(0x36);
          lVar1 = FUN_0061f970();
          if (lVar1 == 0) {
            return 0;
          }
          cRam007152e1 = cRam007152e1 + '\x01';
          FUN_0061e940();
          return 0;
        }
        return 0;
      }
      FUN_0061f4b0(0x36);
      FUN_0061f4b0(0x17);
      FUN_0061f4b0(0x18);
      FUN_0061f4b0(0x19);
      FUN_0061f760(1);
      FUN_0061f760(2);
      FUN_0061f680(5);
      if (sRam007152e4 != 0) {
        sRam007152e4 = sRam007152e4 + -1;
        return 0;
      }
      uVar2 = FUN_0061e750();
      if ((uVar2 & 1) == 0) {
        if (((uVar2 & 2) != 0) && (sRam007152ea != 1)) {
          FUN_0061e720();
          sRam007152ea = 1;
        }
      }
      else if (sRam007152ea != 0) {
        FUN_0061e720();
        sRam007152ea = 0;
      }
      lVar1 = FUN_0061e7f0();
      if (lVar1 != 0) {
        FUN_0061f0f0();
        FUN_0061f0f0(0x80000);
        FUN_0061f0f0(0x100000);
        FUN_0061f0f0(0x200000);
        if (sRam007152ea == 0) {
          cRam007152e1 = cRam007152e1 + '\x01';
          return 0;
        }
        cRam007152e1 = 100;
        return 0;
      }
      lVar1 = FUN_0061e800(0x400);
      if (lVar1 == 0) {
        return 0;
      }
      FUN_0061f0f0(0x400);
      FUN_0061f0f0(0x80000);
      FUN_0061f0f0(0x100000);
      FUN_0061f180(0x200000);
      FUN_0061f0f0(2);
      cRam007152e1 = 100;
      return 0;
    }
    cRam007152e1 = 'e';
  }
  return 0xffffffff;
}



================================================================