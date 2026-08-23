FUNCTION FUN_006205c0 @ 0x006205c0  size=1440
CALLERS (1): FUN_00622180@0x00622180
CALLEES (17): FUN_0061e940@0x0061e940, FUN_0061f1d0@0x0061f1d0, FUN_0061f3d0@0x0061f3d0, FUN_00620570@0x00620570, FUN_0061f9d0@0x0061f9d0, FUN_0061e910@0x0061e910, FUN_0061ea20@0x0061ea20, FUN_0061e7f0@0x0061e7f0, FUN_0061f0f0@0x0061f0f0, FUN_0061f450@0x0061f450, FUN_0061f4b0@0x0061f4b0, FUN_0061f8d0@0x0061f8d0, ...
----------------------------------------------------------------

undefined4 FUN_006205c0(void)

{
  long lVar1;
  
  if (cRam007152e1 != '\x16') {
    if (cRam007152e1 != '\x15') {
      if (cRam007152e1 == '\x14') {
        lVar1 = FUN_0061e960(0,0x14,1);
        if (lVar1 == 0) {
          return 0;
        }
        cRam007152e1 = cRam007152e1 + '\x01';
        return 0;
      }
      if (cRam007152e1 != 'g') {
        if (cRam007152e1 != 'f') {
          if (cRam007152e1 == 'e') {
            lVar1 = FUN_0061e960(0,0x14,1);
            if (lVar1 == 0) {
              return 0;
            }
            cRam007152e1 = cRam007152e1 + '\x01';
            return 0;
          }
          if (cRam007152e1 == 'd') {
            if (sRam007152e4 != 0) {
              sRam007152e4 = sRam007152e4 + -1;
              return 0;
            }
            lVar1 = FUN_0061e7f0();
            if (lVar1 != 0) {
              cRam007152e1 = cRam007152e1 + '\x01';
              return 0;
            }
            FUN_0061f4b0(0xab);
            return 0;
          }
          if (cRam007152e1 == '\x0f') {
            if (0 < (short)(sRam007152e6 + -1)) {
              sRam007152e6 = sRam007152e6 + -1;
              return 0;
            }
            cRam007152e1 = 9;
            sRam007152e4 = 0;
            sRam007152e6 = 0x2d;
            uRam007152f5 = 3;
            return 0;
          }
          if (cRam007152e1 == '\b') {
            sRam007152e6 = sRam007152e6 + -1;
            if (0 < sRam007152e6) {
              return 0;
            }
            cRam007152e1 = 100;
            sRam007152e4 = 0x3c;
            FUN_0061f1d0();
            FUN_0061f450();
            return 0;
          }
          if (cRam007152e1 == '\v') {
            if (0 < (short)(sRam007152e6 + -1)) {
              sRam007152e6 = sRam007152e6 + -1;
              return 0;
            }
            cRam007152e1 = 0x14;
            sRam007152e4 = 0;
            sRam007152e6 = 0;
            FUN_0061f0f0(0x2000);
            return 0;
          }
          if (cRam007152e1 == '\t') {
            if (0 < (short)(sRam007152e6 + -1)) {
              sRam007152e6 = sRam007152e6 + -1;
              return 0;
            }
            cRam007152e1 = 8;
            sRam007152e6 = 10;
            sRam007152e4 = 0;
            FUN_0061f0f0(0x4000);
            FUN_0061f0f0(0x8000);
            FUN_0061f0f0(0x2000000);
            FUN_0061f0f0(0x2000);
            FUN_0061f0f0(0x400);
            return 0;
          }
          if (cRam007152e1 == '\x05') {
            lVar1 = FUN_00620570(0x7152ea);
            if (lVar1 != 0) {
              sRam007152e6 = 0x3d;
            }
            lVar1 = func_0x012307f0(0x7152e3,0x7152e6,0x7152e4);
            if (lVar1 < 0) {
              uRam007152e2 = 0;
              cRam007152e1 = 0xf;
              sRam007152e6 = 0x38;
              uRam007152f5 = 2;
              uRam007152e3 = 0;
              uRam00715360 = func_0x012307e0();
              return 0;
            }
            if (lVar1 < 1) {
              return 0;
            }
            cRam007152e1 = 0xb;
            uRam007152e2 = 0;
            uRam007152e3 = 0;
            sRam007152e6 = 0x18;
            uRam007152f5 = 3;
            return 0;
          }
          if (cRam007152e1 == '\x1e') {
            if (0 < (short)(sRam007152e6 + -1)) {
              sRam007152e6 = sRam007152e6 + -1;
              return 0;
            }
            cRam007152e1 = 5;
            sRam007152e6 = 0;
            return 0;
          }
          if (cRam007152e1 != '\n') {
            if (cRam007152e1 == '\x04') {
              lVar1 = FUN_0061e960(0,0x14,0);
              if (lVar1 == 0) {
                return 0;
              }
              sRam007152e4 = 0;
              cRam007152e1 = 10;
              sRam007152e6 = 10;
              uRam007152e3 = 0;
              uRam00715360 = 0;
              FUN_0061f1a0();
              FUN_0061f1d0();
              FUN_0061f3d0();
              FUN_0061f3b0();
              return 0;
            }
            if (cRam007152e1 == '\x03') {
              lVar1 = FUN_0061f9d0();
              if (lVar1 == 0) {
                return 0;
              }
              cRam007152e1 = cRam007152e1 + '\x01';
              return 0;
            }
            if (cRam007152e1 == '\x02') {
              lVar1 = FUN_0061f970();
              if (lVar1 == 0) {
                return 0;
              }
              cRam007152e1 = cRam007152e1 + '\x01';
              return 0;
            }
            if (cRam007152e1 != '\x01') {
              if (cRam007152e1 != '\0') {
                return 0;
              }
              lVar1 = FUN_0061f8d0();
              if (lVar1 == 0) {
                return 0;
              }
              cRam007152e1 = cRam007152e1 + '\x01';
              FUN_0061ea20(0);
              FUN_0061e940();
              sRam007152e6 = 0x1e;
              return 0;
            }
            sRam007152e6 = sRam007152e6 + -1;
            if (sRam007152e6 != 0) {
              return 0;
            }
            cRam007152e1 = 2;
            uRam007152e3 = 0;
            sRam007152e4 = 0;
            uRam007152f5 = 0;
            return 0;
          }
          if (0 < (short)(sRam007152e6 + -1)) {
            sRam007152e6 = sRam007152e6 + -1;
            return 0;
          }
          cRam007152e1 = 0x1e;
          sRam007152e6 = 0x18;
          uRam007152ea = 0;
          uRam007152f5 = 1;
          return 0;
        }
        lVar1 = FUN_0061e910();
        if (lVar1 != 0) {
          return 0;
        }
        cRam007152e1 = cRam007152e1 + '\x01';
        FUN_0061f0d0();
      }
      return 0xffffffff;
    }
    lVar1 = FUN_0061e910();
    if (lVar1 != 0) {
      return 0;
    }
    cRam007152e1 = cRam007152e1 + '\x01';
    FUN_0061f0d0();
  }
  return 1;
}



================================================================