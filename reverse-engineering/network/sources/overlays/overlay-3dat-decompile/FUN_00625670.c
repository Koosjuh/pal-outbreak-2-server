FUNCTION FUN_00625670 @ 0x00625670  size=2092
CALLERS (1): FUN_00622180@0x00622180
CALLEES (17): FUN_0061f340@0x0061f340, FUN_0061f1f0@0x0061f1f0, FUN_00620d40@0x00620d40, FUN_00620d60@0x00620d60, FUN_0061f1d0@0x0061f1d0, FUN_0061f0e0@0x0061f0e0, FUN_0061e910@0x0061e910, FUN_0061f680@0x0061f680, FUN_0061e800@0x0061e800, FUN_0061e7f0@0x0061e7f0, FUN_0061f760@0x0061f760, FUN_0061f600@0x0061f600, ...
----------------------------------------------------------------

undefined4 FUN_00625670(void)

{
  long lVar1;
  int iStack_20;
  short sStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  
  if (cRam007152e1 != 'h') {
    if (cRam007152e1 != 'g') {
      if (cRam007152e1 == 'f') {
        FUN_0061f760(0xc);
        if (sRam007152e4 != 0) {
          sRam007152e4 = sRam007152e4 + -1;
          return 0;
        }
        lVar1 = FUN_0061e7f0();
        if (lVar1 == 0) {
          return 0;
        }
        cRam007152e1 = cRam007152e1 + '\x01';
        FUN_0061e960(0,0x14,1);
        return 0;
      }
      if (cRam007152e1 == 'e') {
        if (0 < (short)(sRam007152e4 + -1)) {
          sRam007152e4 = sRam007152e4 + -1;
          return 0;
        }
        sRam007152e4 = 0x3c;
        cRam007152e1 = 0x66;
        FUN_0061e960(0,0x14,0);
        FUN_0061f1d0();
        return 0;
      }
      if (cRam007152e1 == 'd') {
        FUN_0061f0e0();
        func_0x00106b60(0x86f864,0,0x1000);
        func_0x001069a8(0x86f864,iRam00365df8,0x1000);
        cRam007152e1 = cRam007152e1 + '\x01';
        sRam007152e4 = 5;
        return 0;
      }
      if (cRam007152e1 == '6') {
        lVar1 = FUN_0061e910();
        if (lVar1 != 0) {
          return 0;
        }
        FUN_0061f0e0();
        return 0xffffffff;
      }
      if (cRam007152e1 == '5') {
        return 1;
      }
      if (cRam007152e1 == '4') {
        lVar1 = FUN_0061e910();
        if (lVar1 != 0) {
          return 0;
        }
        FUN_0061f0e0();
        cRam007152e1 = 0;
        return 0;
      }
      if (cRam007152e1 != '3') {
        if (cRam007152e1 == '2') {
          cRam007152e1 = 0x33;
          FUN_00620d40();
          return 0;
        }
        if (cRam007152e1 != '\x10') {
          if (cRam007152e1 != '\x0f') {
            if (cRam007152e1 == '\x0e') {
              FUN_0061f4b0(0xa5);
              FUN_0061f680(0xf);
              if (sRam007152e4 != 0) {
                sRam007152e4 = sRam007152e4 + -1;
                return 0;
              }
              lVar1 = FUN_0061e7f0();
              if (lVar1 != 0) {
                cRam007152e2 = 0;
                cRam007152e1 = cRam007152e1 + '\x01';
                FUN_0061e960(0,0x14,1);
                return 0;
              }
              lVar1 = FUN_0061e800();
              if (lVar1 == 0) {
                return 0;
              }
              cRam007152e1 = cRam007152e1 + -1;
              cRam007152e2 = 0;
              sRam007152e4 = 10;
              return 0;
            }
            if (cRam007152e1 == '\r') {
              FUN_0061f4b0(0xa9);
              FUN_0061f680(0xf);
              if (sRam007152e4 != 0) {
                sRam007152e4 = sRam007152e4 + -1;
                return 0;
              }
              lVar1 = FUN_0061e7f0();
              if (lVar1 != 0) {
                cRam007152e1 = 0;
                cRam007152e2 = 0;
                FUN_0061f0e0();
                return 0;
              }
              lVar1 = FUN_0061e800();
              if (lVar1 == 0) {
                return 0;
              }
              cRam007152e2 = 0;
              cRam007152e1 = 0xf;
              FUN_0061e960(0,0x14,1);
              return 0;
            }
            if (cRam007152e1 == '\f') {
              if (sRam007152e4 == 0) {
                lVar1 = FUN_0061e7f0();
                if (lVar1 != 0) {
                  sRam007152e4 = 10;
                  cRam007152e1 = cRam007152e1 + '\x01';
                  FUN_0061f0e0();
                  FUN_0061f1f0();
                  FUN_0061f470();
                  return 0;
                }
                FUN_0061f4b0(0xab);
              }
              else {
                sRam007152e4 = sRam007152e4 + -1;
              }
              if (((((sRam007152e6 == 9) || (sRam007152e6 == -0x3c)) || (sRam007152e6 == -0x3d)) ||
                  ((sRam007152e6 == -0x3e || (sRam007152e6 == -0x3f)))) ||
                 ((((sRam007152e6 == -0x3a || ((sRam007152e6 == -1 || (sRam007152e6 == 8)))) ||
                   (sRam007152e6 == 6)) || ((sRam007152e6 == 5 || (sRam007152e6 == 4)))))) {
                FUN_0061f600(0xf);
              }
              else if ((((sRam007152e6 == 7) || (sRam007152e6 == 3)) || (sRam007152e6 == 2)) ||
                      (sRam007152e6 == 1)) {
                FUN_0061f600(0xe);
              }
              FUN_0061f760(0xf);
              return 0;
            }
            if (cRam007152e1 == '\v') {
              sRam007152e4 = sRam007152e4 + -1;
              if (0 < sRam007152e4) {
                return 0;
              }
              cRam007152e1 = 0xc;
              FUN_0061f1d0();
              sRam007152e4 = 0x3c;
              return 0;
            }
            if (cRam007152e1 == '\n') {
              FUN_0061f0e0();
              cRam007152e1 = cRam007152e1 + '\x01';
              sRam007152e4 = 5;
              return 0;
            }
            if (cRam007152e1 != '\x03') {
              if (cRam007152e1 != '\x02') {
                if (cRam007152e1 == '\x01') {
                  func_0x001c3380(&iStack_20);
                  if (iStack_20 == 4) {
                    uStack_18 = 0;
                    func_0x001c33f0();
                    sRam007152e6 = sStack_1c;
                    if (iRam00365df8 == 0) {
                      FUN_0061f0e0();
                      cRam007152e1 = 0xb;
                    }
                    else {
                      cRam007152e1 = 100;
                    }
                  }
                  else {
                    if (iStack_20 != 3) {
                      sRam007152e4 = (undefined2)uStack_18;
                      return 0;
                    }
                    if ((cRam007152e2 == '\0') &&
                       (func_0x00106b60(0x86f864,0,0x1000), iStack_10 != 0)) {
                      func_0x001069a8(0x86f864,uStack_14);
                    }
                    uStack_18 = 100;
                    func_0x001c33f0();
                    cRam007152e1 = 2;
                    FUN_0061e960(0,0x14,1);
                    if (iRam00365df8 != 0) {
                      cRam007152e1 = 100;
                    }
                  }
                  sRam007152e4 = (short)uStack_18;
                  return 0;
                }
                if (cRam007152e1 == '\0') {
                  func_0x001ee370();
                  FUN_0061f1a0();
                  FUN_0061f1d0();
                  FUN_0061f340(1);
                  FUN_0061f3b0();
                  sRam007152e4 = 0;
                  cRam007152e2 = 0;
                  cRam007152e1 = cRam007152e1 + '\x01';
                  if (iRam00715478 == 0) {
                    func_0x001c2f80();
                  }
                  else {
                    func_0x001c3180();
                  }
                  uStack_18 = 0;
                  FUN_0061e960(0,0x14,0);
                  return 0;
                }
                return 0;
              }
              lVar1 = FUN_0061e910();
              if (lVar1 != 0) {
                return 0;
              }
              FUN_0061f0e0();
              if (((cRam00365dd0 != '\0') && (iRam00365dec != 0)) && (iRam00365df0 != 0)) {
                cRam007152e1 = 0x32;
                return 0;
              }
              cRam007152e1 = cRam007152e1 + '\x01';
            }
            return 1;
          }
          lVar1 = FUN_0061e910();
          if (lVar1 != 0) {
            return 0;
          }
          cRam007152e2 = '\0';
          cRam007152e1 = cRam007152e1 + '\x01';
          FUN_0061f0e0();
        }
        return 0xffffffff;
      }
      lVar1 = FUN_00620d60();
      if (lVar1 == 0) {
        return 0;
      }
      if (lVar1 < 0) {
        cRam007152e1 = '6';
      }
      else {
        cRam007152e1 = cRam007152e1 + '\x01';
      }
      FUN_0061e960(0,0x14,1);
      return 0;
    }
    lVar1 = FUN_0061e910();
    if (lVar1 != 0) {
      return 0;
    }
    FUN_0061f0e0();
    cRam007152e1 = cRam007152e1 + '\x01';
  }
  return 0xfffffffe;
}



================================================================