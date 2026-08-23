FUNCTION FUN_0061ded0 @ 0x0061ded0  size=1888
CALLERS (4): FUN_00619750@0x00619750, FUN_006296a0@0x006296a0, FUN_00604180@0x00604180, FUN_00628210@0x00628210
CALLEES (15): FUN_0061e630@0x0061e630, FUN_0061ea30@0x0061ea30, FUN_0061dd90@0x0061dd90, FUN_005b8da0@0x005b8da0, FUN_0061e770@0x0061e770, FUN_0061ddf0@0x0061ddf0, FUN_005b8cf0@0x005b8cf0, FUN_0061d690@0x0061d690, thunk_EXT_FUN_001f46e0@0x0061e6d0, FUN_0061e6e0@0x0061e6e0, FUN_0061e640@0x0061e640, FUN_005b9110@0x005b9110, ...
----------------------------------------------------------------

undefined4 FUN_0061ded0(void)

{
  char cVar1;
  long lVar2;
  undefined4 uVar3;
  
  lVar2 = (long)cRam0071535c;
  uVar3 = 0;
  if (lVar2 == 0x83) {
    sRam007152e4 = sRam007152e4 + -1;
    cVar1 = cRam0071535c;
    if (sRam007152e4 == 0) {
      cRam0071535c = 'n';
      cVar1 = cRam0071535c;
    }
  }
  else {
    cVar1 = cRam0071535c + '\x01';
    if (lVar2 != 0x82) {
      if (lVar2 == 0x79) {
        sRam007152e4 = sRam007152e4 + -1;
        cVar1 = cRam0071535c;
        if (sRam007152e4 == 0) {
          cRam0071535c = cRam0071535d;
          cRam0071535d = '\0';
          cVar1 = cRam0071535c;
        }
      }
      else if (lVar2 == 0x78) {
        cRam0071535c = cRam0071535c + '\x01';
        FUN_005b8da0(uRam0071535e,0x715309);
        cVar1 = cRam0071535c;
      }
      else if (lVar2 == 0x6f) {
        sRam007152e4 = sRam007152e4 + -1;
        cVar1 = cRam0071535c;
        if (sRam007152e4 == 0) {
          cRam0071535c = cRam0071535d;
          cRam0071535d = '\0';
          cVar1 = cRam0071535c;
        }
      }
      else if (lVar2 == 0x6e) {
        sRam007152e4 = 3;
        cRam0071535c = cRam0071535c + '\x01';
        FUN_005b9110(uRam0071535e);
        cVar1 = cRam0071535c;
      }
      else if (lVar2 == 0x65) {
        sRam007152e4 = sRam007152e4 + -1;
        cVar1 = cRam0071535c;
        if (sRam007152e4 == 0) {
          cRam0071535c = cRam0071535d;
          cRam0071535d = '\0';
          cVar1 = cRam0071535c;
        }
      }
      else if (lVar2 == 100) {
        cRam0071535c = cRam0071535c + '\x01';
        FUN_005b8cf0(uRam0071535e);
        cVar1 = cRam0071535c;
      }
      else {
        if (lVar2 == 0x5c) {
          uVar3 = 0xffffffff;
        }
        else if (lVar2 == 0x5b) {
          uVar3 = 0xffffffff;
        }
        else {
          if (lVar2 != 0x5a) {
            if (lVar2 == 0x46) {
              FUN_0061dd90(0x29,0x72);
              func_0x001f46e0();
              return 0;
            }
            if (lVar2 == 0x3c) {
              FUN_0061dd90(0x33,0x23);
              return 0;
            }
            if (lVar2 == 0x33) {
              FUN_0061ddf0();
              lVar2 = FUN_0061e770(0);
              if (lVar2 != 0) {
                FUN_0061ddd0(0x5b);
                return 0;
              }
              if (sRam007152e6 != 0) {
                return 0;
              }
              FUN_0061ddd0(0x5c);
              return 0;
            }
            if (lVar2 == 0x32) {
              FUN_0061dd90(0x33,0x68);
              return 0;
            }
            if (lVar2 == 0x29) {
              FUN_0061ddf0();
              func_0x001ca750();
              lVar2 = FUN_0061e6e0();
              if (lVar2 == 0) {
                cRam0071535c = '\x1f';
              }
              else {
                lVar2 = FUN_0061e770(0);
                if ((lVar2 != 0) || (sRam007152e6 == 0)) {
                  FUN_0061ddd0(0x5c);
                }
              }
              func_0x001ca720();
              return 0;
            }
            if (lVar2 == 0x28) {
              FUN_0061dd90(0x29,0x2d);
              func_0x001ca750();
              thunk_EXT_FUN_001f46e0();
              func_0x001ca720();
              return 0;
            }
            if (lVar2 != 0x1f) {
              if (lVar2 == 0x1e) {
                FUN_0061dd90(0x1f,0x2c);
                func_0x001ca750();
                func_0x001f46e0();
                func_0x001ca720();
                return 0;
              }
              if (lVar2 != 7) {
                if (lVar2 != 6) {
                  if (lVar2 == 5) {
                    if (sRam007152ea != 0) {
                      cRam0071535c = 0x3c;
                      cRam0071535d = 0;
                      return 0;
                    }
                    FUN_0061dd90();
                    return 0;
                  }
                  if (lVar2 == 4) {
                    func_0x001ca750();
                    sRam007152ea = FUN_0061e650();
                    func_0x001ca720();
                    if (sRam007152ea == -1) {
                      return 0;
                    }
                    FUN_0061ddd0(5);
                    return 0;
                  }
                  if (lVar2 == 3) {
                    FUN_0061dd90(4,0x31);
                    func_0x001ca750();
                    FUN_0061e680(iRam003435e8 + 0x20000);
                    func_0x001ca720();
                    return 0;
                  }
                  if (lVar2 != 2) {
                    if (lVar2 == 1) {
                      lVar2 = FUN_0061d690(0);
                      if (lVar2 == 0) {
                        return 0;
                      }
                      uRam007152e3 = 0;
                      sRam007152e4 = 10;
                      cRam0071535c = cRam0071535c + '\x01';
                      func_0x001ca750();
                      FUN_0061e630();
                      uRam0071535a = func_0x001bcba0(iRam003435e8 + 0x40000);
                      sRam007152e4 = 10;
                      sRam007152ea = 0;
                      FUN_0061e640(iRam003435e8 + 0x20000);
                      func_0x001ca720();
                      return 0;
                    }
                    if (lVar2 == 0) {
                      cRam0071535c = cRam0071535c + '\x01';
                      uRam007152e3 = 0;
                      func_0x001ca750();
                      FUN_0061ea30();
                      func_0x001ca720();
                      uRam00715359 = uRam007152ed;
                      func_0x00106b60(iRam003435e8 + 0x20000,0,0x1d7c);
                      func_0x001069a8(iRam003435e8 + 0x20000,0x3c8a90,0x1d7c);
                      FUN_0061dd90(1,0x1d);
                      return 0;
                    }
                    return 0;
                  }
                  func_0x001ca750();
                  sRam007152ea = FUN_0061e650();
                  func_0x001ca720();
                  if (((sRam007152ea == -0xfe) || (sRam007152ea == -0xfd)) ||
                     (sRam007152ea == -0xfc)) {
                    FUN_0061ddd0(0x46);
                    return 0;
                  }
                  if (sRam007152ea == -0xff) {
                    FUN_0061ddd0(0x1e);
                    return 0;
                  }
                  if (sRam007152ea != -0x100) {
                    if (sRam007152ea == -1) {
                      return 0;
                    }
                    if ((sRam007152ea != 0) && (sRam007152ea != -0xfb)) {
                      return 0;
                    }
                    FUN_0061ddd0(3);
                    return 0;
                  }
                  FUN_0061ddd0(0x3c);
                  return 0;
                }
                cRam0071535c = cRam0071535c + '\x01';
                sRam007152e4 = 0x96;
              }
              sRam007152e4 = sRam007152e4 + -1;
              if (0x78 < sRam007152e4) {
                return 0;
              }
              if ((sRam007152e4 != 0) && (lVar2 = FUN_0061e770(0), lVar2 == 0)) {
                return 0;
              }
              FUN_0061ddd0(0x5a);
              return 0;
            }
            FUN_0061ddf0();
            func_0x001ca750();
            lVar2 = FUN_0061e6e0();
            if (lVar2 == 0) {
              lVar2 = FUN_0061e770(0);
              if ((lVar2 != 0) || (sRam007152e6 == 0)) {
                FUN_0061ddd0(0x5c);
              }
            }
            else {
              FUN_0061ddd0(0);
            }
            func_0x001ca720();
            return 0;
          }
          uVar3 = 1;
        }
        cRam0071535d = '\0';
        cRam0071535c = '\0';
        cVar1 = cRam0071535c;
      }
    }
  }
  cRam0071535c = cVar1;
  return uVar3;
}



================================================================