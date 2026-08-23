FUNCTION FUN_00624c70 @ 0x00624c70  size=1132
CALLERS (1): FUN_00622180@0x00622180
CALLEES (11): FUN_005de2a0@0x005de2a0, FUN_005c80a0@0x005c80a0, FUN_005c84e0@0x005c84e0, FUN_0061e960@0x0061e960, FUN_0061e940@0x0061e940, FUN_005c8810@0x005c8810, FUN_0061f1d0@0x0061f1d0, FUN_0061f0e0@0x0061f0e0, FUN_0061e910@0x0061e910, FUN_0061d6a0@0x0061d6a0, FUN_0061f1a0@0x0061f1a0
----------------------------------------------------------------

undefined4 FUN_00624c70(void)

{
  long lVar1;
  undefined4 uVar2;
  
  if (cRam007152e1 == 'd') {
    uVar2 = 0xfffffffe;
  }
  else if (cRam007152e1 == '2') {
    uVar2 = 0xffffffff;
    if (cRam00701e18 == -1) {
      cRam007152e1 = 'd';
    }
  }
  else {
    if (cRam007152e1 != '\a') {
      if (cRam007152e1 != '\x06') {
        if (cRam007152e1 == '\x05') {
          lVar1 = FUN_0061d6a0();
          if (lVar1 == -1) {
            cRam007152e1 = cRam007152e1 + '\x01';
            FUN_0061e960(0,0x14,1);
            func_0x00106b60(0x870870,0,0x10);
            func_0x00106b60(0x3c9580,0,0x10);
            func_0x001069a8(0x3c9580,0x7152c0,0x10);
            return 0;
          }
          if (lVar1 != 1) {
            return 0;
          }
          cRam007152e1 = cRam007152e1 + '\x01';
          FUN_0061e960(0,0x14);
          return 0;
        }
        if (cRam007152e1 == '\x04') {
          FUN_0061f1a0();
          FUN_0061f1d0();
          FUN_0061e960(0,0x14,0);
          uRam007152e2 = 0;
          cRam007152e1 = cRam007152e1 + '\x01';
          func_0x00106b60(0x7152c0,0,0x10);
          func_0x001069a8(0x7152c0,0x3c9580,0x10);
          func_0x00106b60(0x3c9580,0,0x10);
          func_0x001069a8(0x3c9580,0x870870,0x10);
          return 0;
        }
        if (cRam007152e1 != '\x03') {
          if (cRam007152e1 == '\x02') {
            FUN_005de2a0(iRam003435bc + 0x2ff000);
            func_0x00106b60(0x701e20,0,0x100);
            func_0x00109eb8(0x701e20,0x35b8e0);
            uRam003c8a80 = 0;
            uRam00701f20 = 0;
            func_0x001ee370();
            FUN_005c80a0(0);
            cRam007152e1 = cRam007152e1 + '\x01';
            func_0x00106b60(0x870870,0,0x10);
            return 0;
          }
          if (cRam007152e1 != '\x01') {
            if (cRam007152e1 != '\0') {
              return 0;
            }
            func_0x001ad820();
            sRam007152e4 = 10;
            cRam007152e1 = cRam007152e1 + '\x01';
          }
          sRam007152e4 = sRam007152e4 + -1;
          if (sRam007152e4 != 0) {
            return 0;
          }
          FUN_0061e940();
          cRam007152e1 = cRam007152e1 + '\x01';
          uRam007152ee = 3;
          return 0;
        }
        lVar1 = FUN_005c8810();
        if (lVar1 == -1) {
          FUN_005c84e0();
          func_0x001ad820();
          cRam007152e1 = 0x32;
          uRam007152ee = 0;
          return 0;
        }
        if (lVar1 != 1) {
          return 0;
        }
        FUN_005c84e0();
        func_0x001ad820();
        cRam007152e1 = cRam007152e1 + '\x01';
        if (cRam00870870 == '\0') {
          cRam007152e1 = '\x06';
        }
        uRam007152ee = 0;
        return 0;
      }
      lVar1 = FUN_0061e910();
      if (lVar1 != 0) {
        return 0;
      }
      FUN_0061f0e0();
      cRam007152e1 = cRam007152e1 + '\x01';
    }
    if (cRam00701e18 == '\x02') {
      if (cRam00870870 == '\0') {
        uVar2 = 1;
      }
      else {
        func_0x00106b60(0x86f820,0,0x10);
        func_0x00106b60(0x86f810,0,0x10);
        func_0x00109eb8(0x86f820,0x3c9580);
        uVar2 = 2;
      }
    }
    else {
      uVar2 = 0xfffffffe;
      if (cRam00701e18 != -1) {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}



================================================================