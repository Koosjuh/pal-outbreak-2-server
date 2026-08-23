FUNCTION FUN_0061d6a0 @ 0x0061d6a0  size=1764
CALLERS (3): FUN_00624c70@0x00624c70, FUN_00620b60@0x00620b60, FUN_0061fd70@0x0061fd70
CALLEES (11): FUN_0061f0f0@0x0061f0f0, FUN_0061d690@0x0061d690, thunk_EXT_FUN_001f46e0@0x0061e6d0, FUN_0061e630@0x0061e630, FUN_0061f4b0@0x0061f4b0, FUN_0061ea30@0x0061ea30, FUN_0061e6e0@0x0061e6e0, FUN_0061e640@0x0061e640, FUN_0061e650@0x0061e650, FUN_0061e7f0@0x0061e7f0, FUN_0061e680@0x0061e680
----------------------------------------------------------------

undefined4 FUN_0061d6a0(void)

{
  long lVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (cRam007152e2 == ')') {
    uVar2 = 0xffffffff;
  }
  else if (cRam007152e2 == '(') {
    FUN_0061f4b0(0xb);
    FUN_0061f4b0(0xc);
    if (0 < sRam007152e4) {
      sRam007152e4 = sRam007152e4 + -1;
    }
    if ((sRam007152e4 < 0x349) && (lVar1 = FUN_0061e7f0(), lVar1 != 0)) {
      cRam007152e2 = '\x15';
      FUN_0061f0f0(0x400);
    }
    else {
      FUN_0061e650();
      lVar1 = func_0x001f5630(0);
      if (lVar1 == 0) {
        func_0x001f4680();
        cRam007152e2 = '\x19';
        sRam007152e4 = 0x14;
      }
    }
  }
  else if (cRam007152e2 == '#') {
    FUN_0061f4b0(0xf);
    FUN_0061f4b0(0x10);
    if (0 < sRam007152e4) {
      sRam007152e4 = sRam007152e4 + -1;
    }
    if ((sRam007152e4 < 0xb) && (lVar1 = FUN_0061e7f0(), lVar1 != 0)) {
      cRam007152e2 = '\x15';
      func_0x001f4680();
      FUN_0061f0f0(0x400);
    }
    else {
      lVar1 = FUN_0061e6e0();
      if ((lVar1 != 0) && (lVar1 == 1)) {
        func_0x001f4680();
        cRam007152e2 = '\x19';
        sRam007152e4 = 0x14;
      }
    }
  }
  else if (cRam007152e2 == '\x1e') {
    uRam007152e8 = 0xff03;
    FUN_0061f4b0(0xf);
    FUN_0061f4b0(0x10);
    if (0 < sRam007152e4) {
      sRam007152e4 = sRam007152e4 + -1;
    }
    if ((sRam007152e4 < 0x349) && (lVar1 = FUN_0061e7f0(), lVar1 != 0)) {
      cRam007152e2 = '\x15';
      func_0x001f4680();
      FUN_0061f0f0(0x400);
    }
    else {
      FUN_0061e650();
      lVar1 = func_0x001f5630(0);
      if (lVar1 == 0) {
        func_0x001f4680();
        cRam007152e2 = '\x19';
        sRam007152e4 = 0x14;
      }
    }
  }
  else if (cRam007152e2 == '\x19') {
    uRam007152e3 = 0;
    cRam007152e2 = '\x02';
    sRam007152e4 = 0x14;
    FUN_0061e640(iRam003435bc + 0x31f000);
  }
  else if (cRam007152e2 == '\x15') {
    uVar2 = 0xffffffff;
  }
  else if (cRam007152e2 == '\x14') {
    uRam007152e8 = 0xff01;
    FUN_0061f4b0(0xd);
    FUN_0061f4b0(0xe);
    if (0 < sRam007152e4) {
      sRam007152e4 = sRam007152e4 + -1;
    }
    if ((sRam007152e4 < 0x349) && (lVar1 = FUN_0061e7f0(), lVar1 != 0)) {
      cRam007152e2 = cRam007152e2 + '\x01';
      func_0x001f4680();
      FUN_0061f0f0(0x400);
    }
    else {
      FUN_0061e650();
      lVar1 = func_0x001f5630(0);
      if (lVar1 != 0) {
        func_0x001f4680();
        cRam007152e2 = '\x19';
        sRam007152e4 = 0x14;
      }
    }
  }
  else if (cRam007152e2 == '\x05') {
    uVar2 = 1;
  }
  else if (cRam007152e2 == '\x04') {
    FUN_0061f4b0(10);
    sRam007152e4 = sRam007152e4 + -1;
    if (sRam007152e4 < 1) {
      cRam007152e2 = cRam007152e2 + '\x01';
    }
    else if ((sRam007152e4 < 0xb) && (lVar1 = FUN_0061e7f0(), lVar1 != 0)) {
      cRam007152e2 = cRam007152e2 + '\x01';
    }
  }
  else if (cRam007152e2 == '\x03') {
    FUN_0061f4b0(9);
    if (sRam007152e4 == 0) {
      lVar1 = FUN_0061e650();
      if (lVar1 == -0x100) {
        cRam007152e2 = '(';
        sRam007152e4 = 900;
      }
      else if (lVar1 == -0xff) {
        cRam007152e2 = '\x14';
        sRam007152e4 = 900;
        thunk_EXT_FUN_001f46e0();
      }
      else if ((lVar1 != -1) && (lVar1 == 0)) {
        sRam007152e4 = 0x3c;
        cRam007152e2 = cRam007152e2 + '\x01';
        func_0x001f5650();
      }
    }
    else {
      sRam007152e4 = sRam007152e4 + -1;
    }
  }
  else if (cRam007152e2 == '\x02') {
    FUN_0061f4b0(8);
    if (sRam007152e4 == 0) {
      lVar1 = FUN_0061e650();
      if (lVar1 == -0x100) {
        cRam007152e2 = '(';
        sRam007152e4 = 900;
        thunk_EXT_FUN_001f46e0();
      }
      else if (lVar1 == -0xff) {
        cRam007152e2 = '\x14';
        sRam007152e4 = 900;
        thunk_EXT_FUN_001f46e0();
      }
      else if (lVar1 != -1) {
        if ((lVar1 == 0) || (lVar1 == -0xfb)) {
          cRam007152e2 = cRam007152e2 + '\x01';
          sRam007152e4 = 0x3c;
          uRam00715359 = uRam007152ed;
          FUN_0061e680(iRam003435bc + 0x31f000);
          func_0x001f5650();
        }
        else {
          cRam007152e2 = '\x1e';
          sRam007152e4 = 900;
          thunk_EXT_FUN_001f46e0();
        }
      }
    }
    else {
      sRam007152e4 = sRam007152e4 + -1;
    }
  }
  else if (cRam007152e2 == '\x01') {
    lVar1 = FUN_0061d690(0);
    if (lVar1 != 0) {
      uRam007152e3 = 0;
      sRam007152e4 = 0x14;
      cRam007152e2 = cRam007152e2 + '\x01';
      FUN_0061e630();
      uRam0071535a = func_0x001bcba0(iRam003435bc + 0x33f000);
      FUN_0061e640(iRam003435bc + 0x31f000);
    }
  }
  else if (cRam007152e2 == '\0') {
    cRam007152e2 = '\x01';
    uRam007152e3 = 0;
    FUN_0061ea30();
    uRam007152e8 = 0;
    uRam00715359 = uRam007152ed;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



================================================================