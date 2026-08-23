FUNCTION FUN_00625190 @ 0x00625190  size=1240
CALLERS (1): FUN_00622180@0x00622180
CALLEES (23): FUN_0061e750@0x0061e750, FUN_0061f180@0x0061f180, FUN_0061e740@0x0061e740, FUN_0061f0e0@0x0061f0e0, FUN_006250e0@0x006250e0, FUN_0061e910@0x0061e910, FUN_00634ab0@0x00634ab0, FUN_0061f270@0x0061f270, FUN_0061f220@0x0061f220, FUN_0061f680@0x0061f680, FUN_0061f760@0x0061f760, FUN_0061f0f0@0x0061f0f0, ...
----------------------------------------------------------------

undefined4 FUN_00625190(void)

{
  char cVar1;
  long lVar2;
  undefined4 uVar3;
  uint uStack_4;
  
  uVar3 = 0;
  if (cRam007152e1 == '\v') {
    FUN_0061f4b0(0x35);
    FUN_0061f4b0(0x9c);
    FUN_0061f4b0(0x9b);
    FUN_0061f4b0(0x9f);
    FUN_0061f760(0xd);
    FUN_0061f760(0xe);
    cVar1 = FUN_00634ab0(0x7152b0,uRam003434a8,uRam003434a0);
    if (cVar1 == -1) {
      FUN_00637180();
      sRam007152e4 = 10;
      cRam007152e1 = '\x01';
      uRam007152e8 = (ushort)(cRam0086f810 == '\0');
      FUN_0061f0f0(0x400);
      FUN_0061f270(0xe,2);
    }
    else if (cVar1 == '\x01') {
      FUN_00637180();
      cRam007152e1 = '\x01';
      sRam007152e4 = 10;
      func_0x00106b60(0x86f810,0,0x10);
      func_0x00109eb8(0x86f810,0x7152b0);
      uRam007152e8 = (ushort)(cRam0086f810 == '\0');
      FUN_0061f0f0(0x400);
      FUN_0061f270(0xe,2);
    }
  }
  else if (cRam007152e1 == '\n') {
    FUN_0061f4b0(0x35);
    FUN_0061f4b0(0x9c);
    FUN_0061f4b0(0x9b);
    FUN_0061f760(0xd);
    FUN_0061f760(0xe);
    sRam007152e4 = sRam007152e4 + -1;
    if (sRam007152e4 < 1) {
      cRam007152e1 = cRam007152e1 + '\x01';
      func_0x00106b60(0x7152b0,0,0x10);
      func_0x00109eb8(0x7152b0,0x86f810);
      FUN_006371d0(0x42980000,0x138);
      FUN_006345e0(0,5,0xf,0x7152b0);
    }
  }
  else if (cRam007152e1 == '\x03') {
    lVar2 = FUN_0061e910();
    if (lVar2 == 0) {
      FUN_0061f0e0();
      uVar3 = 0xffffffff;
    }
  }
  else if (cRam007152e1 == '\x02') {
    lVar2 = FUN_0061e910();
    if (lVar2 == 0) {
      FUN_0061f0e0();
      uVar3 = 1;
    }
  }
  else if (cRam007152e1 == '\x01') {
    FUN_0061f4b0(0x35);
    FUN_0061f4b0(0x9c);
    FUN_0061f680(0xe);
    FUN_0061f4b0(0x9b);
    FUN_0061f760(0xd);
    FUN_0061f760(0xe);
    if (sRam007152e4 == 0) {
      uStack_4 = FUN_0061e750();
      FUN_006250e0(&uStack_4);
      if ((uStack_4 & 1) == 0) {
        if (((uStack_4 & 2) != 0) && (uRam007152e8 != 1)) {
          FUN_0061e720();
          uRam007152e8 = 1;
        }
      }
      else if (uRam007152e8 != 0) {
        FUN_0061e720();
        uRam007152e8 = 0;
      }
      if ((uStack_4 & 0x10) == 0) {
        if ((uStack_4 & 0x200) != 0) {
          FUN_0061e740();
          FUN_0061f0f0(0x80);
          FUN_0061f0f0(0x100);
          FUN_0061f180(0x200);
          cRam007152e1 = '\x03';
          FUN_0061e960(0,0x14,1);
        }
      }
      else {
        FUN_0061e730();
        FUN_0061f0f0(0x80);
        FUN_0061f0f0(0x100);
        FUN_0061f0f0(0x200);
        if (uRam007152e8 == 0) {
          cRam007152e1 = '\x02';
          FUN_0061e960(0,0x14,1);
        }
        else {
          cRam007152e1 = '\n';
          sRam007152e4 = 10;
          FUN_0061f220();
          func_0x00106b60(0x7152b0,0,0x10);
        }
      }
    }
    else {
      sRam007152e4 = sRam007152e4 + -1;
    }
  }
  else if (cRam007152e1 == '\0') {
    FUN_0061f4b0(0x35);
    FUN_0061f1a0();
    FUN_0061f1b0();
    FUN_0061f490();
    FUN_0061f250();
    FUN_0061f270(0xe,2);
    sRam007152e4 = 10;
    uRam007152e8 = 1;
    cRam007152e1 = cRam007152e1 + '\x01';
    FUN_0061e960(0,0x14,0);
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



================================================================