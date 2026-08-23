FUNCTION FUN_00624850 @ 0x00624850  size=1044
CALLERS (1): FUN_00622180@0x00622180
CALLEES (17): FUN_0061e750@0x0061e750, FUN_0061f1f0@0x0061f1f0, FUN_0061f180@0x0061f180, FUN_0061f0e0@0x0061f0e0, FUN_0061e910@0x0061e910, FUN_0061f270@0x0061f270, FUN_0061f680@0x0061f680, FUN_0061e800@0x0061e800, FUN_0061e7f0@0x0061e7f0, FUN_0061f0f0@0x0061f0f0, FUN_0061f250@0x0061f250, FUN_0061f4b0@0x0061f4b0, ...
----------------------------------------------------------------

int FUN_00624850(void)

{
  ulong uVar1;
  long lVar2;
  int iVar3;
  
  iVar3 = 0;
  switch(cRam007152e1) {
  case '\0':
    func_0x001ee370();
    FUN_0061f4b0(0x35);
    FUN_0061f1a0();
    FUN_0061f1b0();
    FUN_0061f250();
    FUN_0061f270(0xd,0);
    sRam007152e4 = 10;
    func_0x00106b60(0x86f820,0,0x10);
    func_0x00106b60(0x86f810,0,0x10);
    if (cRam003c9580 == '\0') {
      sRam007152e8 = 1;
    }
    else {
      sRam007152e8 = 0;
      func_0x00109eb8(0x86f820,0x3c9580);
    }
    cRam007152e1 = cRam007152e1 + '\x01';
    FUN_0061e960(0,0x14,0);
    iVar3 = 0;
    break;
  case '\x01':
    FUN_0061f4b0(0x35);
    FUN_0061f680(0xd);
    if (sRam007152e4 == 0) {
      uVar1 = FUN_0061e750();
      if ((uVar1 & 1) == 0) {
        if (((uVar1 & 2) != 0) && (sRam007152e8 != 1)) {
          FUN_0061e720();
          sRam007152e8 = 1;
        }
      }
      else if (sRam007152e8 != 0) {
        if (cRam003c9580 == '\0') {
          sRam007152e8 = 1;
        }
        else {
          FUN_0061e720();
          sRam007152e8 = 0;
        }
      }
      FUN_0061f4b0((int)sRam007152e8 + 0x99U & 0xff);
      lVar2 = FUN_0061e7f0();
      if (lVar2 == 0) {
        lVar2 = FUN_0061e800(0x80);
        if (lVar2 != 0) {
          FUN_0061f0f0(0x80);
          FUN_0061f0f0(0x100);
          FUN_0061f180(0x200);
          cRam007152e1 = '\x04';
          sRam007152e4 = 5;
        }
      }
      else {
        FUN_0061f0f0();
        FUN_0061f0f0(0x100);
        FUN_0061f0f0(0x200);
        cRam007152e1 = '\x02';
        FUN_0061e960(0,0x14,1);
      }
    }
    else {
      sRam007152e4 = sRam007152e4 + -1;
    }
    break;
  case '\x02':
    lVar2 = FUN_0061e910();
    if (lVar2 != 0) {
      return 0;
    }
    FUN_0061f0e0();
    cRam007152e1 = cRam007152e1 + '\x01';
  case '\x03':
    iVar3 = sRam007152e8 + 1;
    break;
  case '\x04':
    FUN_0061f4b0(0x35);
    sRam007152e4 = sRam007152e4 + -1;
    if (sRam007152e4 < 1) {
      sRam007152e4 = 10;
      cRam007152e1 = cRam007152e1 + '\x01';
      FUN_0061f470();
      FUN_0061f1f0();
    }
    break;
  case '\x05':
    FUN_0061f4b0(0x35);
    FUN_0061f4b0(0xa5);
    FUN_0061f680(0xf);
    if (sRam007152e4 == 0) {
      lVar2 = FUN_0061e7f0();
      if (lVar2 == 0) {
        lVar2 = FUN_0061e800();
        if (lVar2 != 0) {
          cRam007152e1 = '\x01';
          sRam007152e4 = 10;
          FUN_0061f0f0(0x10000);
          FUN_0061f0f0(0x400);
          FUN_0061f270(0xd,0);
        }
      }
      else {
        cRam007152e1 = cRam007152e1 + '\x01';
        FUN_0061e960(0,0x14,1);
      }
    }
    else {
      sRam007152e4 = sRam007152e4 + -1;
    }
    break;
  case '\x06':
    lVar2 = FUN_0061e910();
    if (lVar2 != 0) {
      FUN_0061f4b0();
      FUN_0061f4b0(0xa5);
      FUN_0061f680(0xf);
      return 0;
    }
    FUN_0061f0e0(0x35);
    cRam007152e1 = cRam007152e1 + '\x01';
  case '\a':
    iVar3 = -1;
  }
  return iVar3;
}



================================================================