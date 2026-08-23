FUNCTION FUN_00620d60 @ 0x00620d60  size=4452
CALLERS (2): FUN_00625670@0x00625670, FUN_005b2e40@0x005b2e40
CALLEES (27): thunk_FUN_0061f0d0@0x0061ea00, FUN_0061f2d0@0x0061f2d0, FUN_0061f180@0x0061f180, FUN_0061e940@0x0061e940, FUN_0061f0e0@0x0061f0e0, FUN_0061f3d0@0x0061f3d0, FUN_00620570@0x00620570, FUN_0061f9d0@0x0061f9d0, FUN_0061e910@0x0061e910, FUN_0061f680@0x0061f680, FUN_0061e800@0x0061e800, FUN_0061e7f0@0x0061e7f0, ...
----------------------------------------------------------------

long FUN_00620d60(void)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  
  iVar1 = iRam00343658;
  lVar4 = 0;
  if (cRam00715439 == 'I') {
    iRam00343650 = 0x380700;
    iRam00343654 = 0x388700;
    lVar4 = 1;
    iRam00343658 = 0x390700;
  }
  else if (cRam00715439 == 'H') {
    lVar2 = FUN_0061e910();
    if (lVar2 == 0) {
      cRam00715439 = cRam00715439 + '\x01';
      FUN_0061f0d0();
    }
  }
  else if (cRam00715439 == 'G') {
    sRam007152e4 = sRam007152e4 + -1;
    if (sRam007152e4 < 1) {
      cRam00715439 = 'H';
      FUN_0061e960(0,0x14,1);
    }
  }
  else if (cRam00715439 == 'F') {
    lVar2 = func_0x011e9b40(0x71543b,0x7152e6,iRam00343654,uRam00715364,0x8000);
    if (lVar2 < 1) {
      if (lVar2 < 0) {
        sRam007152e4 = 0;
        cRam00715439 = '\"';
        sRam007152e6 = 0x20;
        uRam007152f5 = 2;
        cRam0071543a = '\0';
        uRam0071543b = 0;
        uRam00715360 = func_0x011e99c0();
      }
    }
    else {
      func_0x001069a8(0x245e38,iVar1,10);
      func_0x001f3640(0);
      func_0x001f3640(4);
      lVar2 = func_0x001a0260(9,1);
      if (lVar2 == 0) {
        lVar2 = func_0x001a0260(8,1);
        if (lVar2 != 0) {
          func_0x001f3640(9);
        }
      }
      else {
        func_0x001f3640(10);
      }
      cRam0071543a = '\0';
      sRam007152e4 = 0x18;
      uRam007152f5 = 3;
      uRam0071543b = 0;
      sRam007152e6 = 0;
      cRam00715439 = cRam00715439 + '\x01';
    }
  }
  else if (cRam00715439 == '7') {
    sRam007152e4 = sRam007152e4 + -1;
    if (sRam007152e4 < 1) {
      FUN_0061f1a0();
      FUN_0061f1d0();
      FUN_0061f2d0(0xb,2);
      cRam0071543a = '\0';
      cRam00715439 = '\x01';
      sRam007152e4 = 10;
      sRam007152ea = 1;
    }
  }
  else if (cRam00715439 == '6') {
    iRam00343650 = 0x380700;
    iRam00343654 = 0x388700;
    lVar4 = -1;
    iRam00343658 = 0x390700;
  }
  else if (cRam00715439 == '5') {
    sRam007152e4 = sRam007152e4 + -1;
    if (sRam007152e4 < 1) {
      FUN_0061f0d0();
      func_0x00106b60(0x702140,0,0x8000);
      iRam00343650 = 0x380700;
      iRam00343654 = 0x388700;
      lVar4 = -1;
      iRam00343658 = 0x390700;
    }
  }
  else if (cRam00715439 == '4') {
    FUN_0061f4b0(0x54);
    FUN_0061f680(6);
    if (sRam007152e4 < 1) {
      sRam007152ea = 0;
      sRam007152e4 = 10;
      cRam00715439 = cRam00715439 + '\x01';
      FUN_0061f0f0(0x80000);
      FUN_0061f0f0(0x100000);
      FUN_0061f180(0x200000);
    }
    else {
      uVar3 = FUN_0061e750();
      if (((uVar3 & 1) == 0) || (sRam007152ea == 0)) {
        if (((uVar3 & 2) == 0) || (sRam007152ea == 1)) {
          lVar2 = FUN_0061e7f0();
          if (lVar2 == 0) {
            lVar2 = FUN_0061e800(0x80000);
            if (lVar2 != 0) {
              FUN_0061f0f0(0x80000);
              FUN_0061f0f0(0x100000);
              FUN_0061f180(0x200000);
              cRam00715439 = '7';
              sRam007152e4 = 10;
            }
          }
          else {
            FUN_0061f0f0();
            FUN_0061f0f0(0x100000);
            FUN_0061f0f0(0x200000);
            if (sRam007152ea == 0) {
              FUN_0061f0f0(0x400);
              sRam007152e4 = 10;
              cRam00715439 = cRam00715439 + '\x01';
            }
            else {
              cRam00715439 = '7';
              sRam007152e4 = 10;
            }
          }
        }
        else {
          sRam007152ea = 1;
          FUN_0061e720();
        }
      }
      else {
        sRam007152ea = 0;
        FUN_0061e720();
      }
    }
  }
  else if (cRam00715439 == '3') {
    FUN_0061f4b0(0x54);
    FUN_0061f680(6);
    sRam007152e4 = sRam007152e4 + -1;
    if (sRam007152e4 < 1) {
      sRam007152e4 = 0xe10;
      cRam00715439 = cRam00715439 + '\x01';
    }
  }
  else if (cRam00715439 == '2') {
    sRam007152e4 = sRam007152e4 + -1;
    if (sRam007152e4 < 1) {
      cRam00715439 = '3';
      sRam007152e4 = 0xf;
      sRam007152ea = 1;
      FUN_0061f2d0(0xb,2);
    }
  }
  else if (cRam00715439 == '&') {
    sRam007152e4 = sRam007152e4 + -1;
    if (sRam007152e4 < 1) {
      cRam00715439 = '2';
      sRam007152e4 = 10;
      sRam007152ea = 0;
      FUN_0061f0f0(0x4000000);
    }
    else if ((sRam007152e4 <= sRam007152e6) && (lVar2 = FUN_0061e7f0(), lVar2 != 0)) {
      cRam00715439 = '2';
      sRam007152e4 = 10;
      FUN_0061f0f0(0x4000000);
    }
  }
  else if (cRam00715439 == '%') {
    sRam007152e4 = sRam007152e4 + -1;
    if (sRam007152e4 < 1) {
      cRam00715439 = '&';
      sRam007152e4 = 0x13b;
      sRam007152e6 = 0xd2;
    }
  }
  else if (cRam00715439 == '$') {
    sRam007152e4 = sRam007152e4 + -1;
    if (sRam007152e4 < 1) {
      sRam007152e4 = 5;
      cRam00715439 = '%';
      FUN_0061f1d0();
      FUN_0061f450();
    }
  }
  else if (cRam00715439 == '#') {
    sRam007152e4 = sRam007152e4 + -1;
    if (sRam007152e4 < 1) {
      sRam007152e4 = 10;
      cRam00715439 = '$';
      FUN_0061f0f0(0x4000);
      FUN_0061f0f0(0x8000);
      FUN_0061f0f0(0x2000000);
      FUN_0061f0f0(0x400);
    }
  }
  else if (cRam00715439 == '\"') {
    sRam007152e4 = sRam007152e4 + -1;
    if (sRam007152e4 < 1) {
      cRam00715439 = '#';
      uRam007152f5 = 3;
      sRam007152e4 = 0x2d;
      FUN_0061f0f0(0x2000);
    }
  }
  else if (cRam00715439 == '\x19') {
    sRam007152e4 = sRam007152e4 + -1;
    if (sRam007152e4 < 1) {
      FUN_0061f1a0();
      FUN_0061f1d0();
      FUN_0061f2d0(0xb,2);
      cRam0071543a = '\0';
      cRam00715439 = '\x01';
      sRam007152e4 = 10;
      sRam007152ea = 1;
    }
  }
  else if (cRam00715439 == '\x18') {
    lVar2 = func_0x001b7ff0();
    if (lVar2 == 0) {
      lVar4 = func_0x001f5620();
      if (lVar4 == 0) {
        func_0x001069a8(0x380700,iRam00343650,0x8000);
        func_0x00106b60(0x390700,0,0x40);
        func_0x001069a8(0x390700,iRam00343658,0x18);
        iRam00343650 = 0x380700;
        iRam00343654 = 0x388700;
        iRam00343658 = 0x390700;
        func_0x001069a8(0x388700,0x380700,0x8000);
        uRam0071543b = 0;
        cRam00715439 = 'F';
        uRam00715364 = *(undefined4 *)(iVar1 + 0x14);
        uRam007152f5 = 1;
        sRam007152e6 = 0;
        uRam00715360 = 0;
      }
      else {
        cRam00715439 = '\x19';
        sRam007152e4 = 10;
      }
    }
  }
  else if (cRam00715439 == '\x17') {
    sRam007152e4 = sRam007152e4 + -1;
    if (sRam007152e4 < 1) {
      cRam00715439 = '\x18';
      uRam007152e2 = 0;
      uRam007152e3 = 0;
      FUN_0061f1d0();
      func_0x0010a4f0(iVar1,0x6ca054,10);
      func_0x0010a4f0(iVar1 + 10,0x6ca064,4);
      func_0x001b7b50(4,1);
    }
  }
  else if (cRam00715439 == '\x16') {
    sRam007152e6 = sRam007152e6 + -1;
    if (sRam007152e6 < 1) {
      sRam007152e4 = 10;
      cRam00715439 = '\x17';
      FUN_0061f0f0(0x4000);
      FUN_0061f0f0(0x8000);
      FUN_0061f0f0(0x2000000);
      FUN_0061f0f0(0x2000);
      FUN_0061f0f0(0x400);
    }
    else if ((sRam007152e6 < 0x3d) && (lVar2 = FUN_0061e7f0(), lVar2 != 0)) {
      sRam007152e4 = 10;
      cRam00715439 = cRam00715439 + '\x01';
      FUN_0061f0f0(0x4000);
      FUN_0061f0f0(0x8000);
      FUN_0061f0f0(0x2000000);
      FUN_0061f0f0(0x2000);
      FUN_0061f0f0(0x400);
    }
  }
  else if (cRam00715439 == '\x15') {
    lVar2 = func_0x011e99d0(0x71543b,0x7152e6,iRam00343650,uRam00715364,0x8000);
    if (lVar2 < 1) {
      if (lVar2 < 0) {
        sRam007152e4 = 0;
        cRam00715439 = '\"';
        sRam007152e6 = 0x20;
        uRam007152f5 = 2;
        cRam0071543a = '\0';
        uRam0071543b = 0;
        uRam00715360 = func_0x011e99c0();
      }
    }
    else {
      sRam007152e4 = (short)lVar2;
      cRam00715439 = '\x16';
      sRam007152e6 = 0x72;
      uRam007152f5 = 3;
      cRam0071543a = '\0';
      uRam0071543b = 0;
      *(int *)(iVar1 + 0x14) = (int)lVar2;
    }
  }
  else if (cRam00715439 == '\x14') {
    FUN_0061f8d0(2);
    cRam0071543a = '\0';
    cRam00715439 = cRam00715439 + '\x01';
  }
  else if (cRam00715439 == '\x06') {
    lVar2 = FUN_00620570(0x7152ea);
    if (lVar2 != 0) {
      sRam007152e6 = 0x1f;
    }
    lVar2 = func_0x01230800(0x71543b,0x7152e6,0x7152e4);
    if (lVar2 < 0) {
      cRam0071543a = '\0';
      cRam00715439 = '\"';
      sRam007152e6 = 0x20;
      uRam007152f5 = 2;
      uRam0071543b = 0;
      sRam007152e4 = 0;
      uRam00715360 = func_0x012307e0();
    }
    else if (0 < lVar2) {
      cRam0071543a = '\0';
      cRam00715439 = '\x14';
      uRam0071543b = 0;
      sRam007152e6 = 0;
      uRam00715364 = uRam006ca050;
      iRam00343650 = iRam003435bc;
      iRam00343654 = iRam003435bc + 0x8000;
      iRam00343658 = iRam003435bc + 0x10000;
      func_0x001069a8(iRam003435bc,0x702140,0x8000);
    }
  }
  else if (cRam00715439 == '\x05') {
    sRam007152e6 = sRam007152e6 + -1;
    if (sRam007152e6 < 1) {
      cRam00715439 = '\x06';
      sRam007152e6 = 0;
    }
  }
  else if (cRam00715439 == '\x04') {
    sRam007152e4 = sRam007152e4 + -1;
    if (sRam007152e4 < 1) {
      cRam00715439 = '\x05';
      sRam007152e6 = 0x18;
      uRam007152f5 = 1;
      uRam0071543b = 0;
      sRam007152e4 = 0;
      sRam007152ea = 0;
      uRam00715360 = 0;
      FUN_0061f3d0();
      FUN_0061f3b0();
    }
  }
  else if (cRam00715439 == '\x03') {
    sRam007152e4 = sRam007152e4 + -1;
    if (sRam007152e4 < 1) {
      sRam007152e4 = 10;
      cRam00715439 = '\x04';
      FUN_0061f1d0();
      FUN_0061f8d0(1);
    }
  }
  else if (cRam00715439 == '\x02') {
    FUN_0061f4b0(0x52);
    FUN_0061f680(6);
    FUN_0061f760(10);
    FUN_0061f760(0xb);
    if (sRam007152e4 < 1) {
      sRam007152ea = 0;
      cRam00715439 = '2';
      sRam007152e4 = 10;
      FUN_0061f0f0(0x80000);
      FUN_0061f0f0(0x100000);
      FUN_0061f180(0x200000);
    }
    else {
      uVar3 = FUN_0061e750();
      if ((uVar3 & 1) == 0) {
        if (((uVar3 & 2) != 0) && (sRam007152ea != 1)) {
          sRam007152ea = 1;
          FUN_0061e720();
        }
      }
      else if (sRam007152ea != 0) {
        sRam007152ea = 0;
        FUN_0061e720();
      }
      lVar2 = FUN_0061e7f0();
      if (lVar2 == 0) {
        lVar2 = FUN_0061e800(0x80000);
        if (lVar2 != 0) {
          FUN_0061f0f0(0x80000);
          FUN_0061f0f0(0x100000);
          FUN_0061f180(0x200000);
          cRam00715439 = '2';
          sRam007152e4 = 10;
        }
      }
      else {
        FUN_0061f0f0();
        FUN_0061f0f0(0x100000);
        FUN_0061f0f0(0x200000);
        if (sRam007152ea == 0) {
          sRam007152e4 = 10;
          cRam00715439 = cRam00715439 + '\x01';
          FUN_0061f0e0();
        }
        else {
          cRam00715439 = '2';
          sRam007152e4 = 10;
        }
      }
    }
  }
  else if (cRam00715439 == '\x01') {
    FUN_0061f4b0(0x52);
    FUN_0061f680(6);
    FUN_0061f760(10);
    FUN_0061f760(0xb);
    sRam007152e4 = sRam007152e4 + -1;
    if (sRam007152e4 < 1) {
      cRam0071543a = '\0';
      sRam007152e4 = 0xe10;
      sRam007152ea = 1;
      uRam0071543b = 0;
      uRam007152e2 = 0;
      uRam007152e3 = 0;
      cRam00715439 = cRam00715439 + '\x01';
    }
  }
  else if (cRam00715439 == '\0') {
    if (cRam0071543a == '\x02') {
      lVar2 = FUN_0061f9d0();
      if (lVar2 != 0) {
        cRam0071543a = '\0';
        cRam00715439 = cRam00715439 + '\x01';
        FUN_0061f1a0();
        FUN_0061f1d0();
        sRam007152ea = 1;
        FUN_0061f2d0(0xb,2);
        sRam007152e4 = 10;
      }
    }
    else if (cRam0071543a == '\x01') {
      lVar2 = FUN_0061f970();
      if (lVar2 != 0) {
        cRam0071543a = cRam0071543a + '\x01';
      }
    }
    else if (cRam0071543a == '\0') {
      uRam006ca050 = uRam00365dec;
      func_0x001069a8(0x6ca054,0x365dd1,0x10);
      func_0x001069a8(0x6ca064,0x365de1,8);
      uRam007152f5 = 0;
      uRam0071535e = 0;
      uRam00715360 = 0;
      cRam0071543a = cRam0071543a + '\x01';
      thunk_FUN_0061f0d0(0);
      FUN_0061ea10();
      FUN_0061ea20(0);
      FUN_0061e940();
    }
  }
  else {
    lVar4 = 0;
  }
  return lVar4;
}



================================================================