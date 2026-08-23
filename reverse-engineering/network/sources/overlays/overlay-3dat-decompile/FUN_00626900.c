FUNCTION FUN_00626900 @ 0x00626900  size=1392
CALLERS (1): FUN_00622180@0x00622180
CALLEES (13): FUN_005bd250@0x005bd250, FUN_0061f1f0@0x0061f1f0, FUN_0061f1d0@0x0061f1d0, FUN_0061f0e0@0x0061f0e0, FUN_0061e910@0x0061e910, FUN_0061f680@0x0061f680, FUN_0061e800@0x0061e800, FUN_0061e7f0@0x0061e7f0, FUN_0061f760@0x0061f760, FUN_0061f4b0@0x0061f4b0, FUN_0061e960@0x0061e960, FUN_0061f470@0x0061f470, ...
----------------------------------------------------------------

undefined4 FUN_00626900(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  long lVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  undefined1 auStack_80 [16];
  undefined1 auStack_70 [64];
  undefined1 auStack_30 [16];
  undefined1 auStack_20 [32];
  
  puVar2 = (undefined1 *)0x10;
  puVar4 = auStack_30;
  puVar1 = puVar4;
  while (puVar1 != (undefined1 *)0x0) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
    puVar2 = puVar2 + -1;
    puVar1 = puVar2;
  }
  uVar5 = 0;
  switch(cRam007152e1) {
  case '\0':
    FUN_0061f4b0(0x35);
    FUN_0061f1a0();
    FUN_0061f1d0();
    sRam007152e4 = 300;
    sRam007152ea = 0xffff;
    cRam007152e1 = cRam007152e1 + '\x01';
    FUN_0061e960(0,0x14,0);
    return 0;
  case '\x01':
    cRam007152e1 = cRam007152e1 + '\x01';
    uRam007152e6 = 0;
    sRam007152e4 = 300;
    cRam0086f7e0 = '\0';
    func_0x00109728(auStack_20,0x66a858,uRam0035ba98 & 0xff,uRam0035ba98 >> 8 & 0xff,
                    uRam0035ba98 >> 0x10 & 0xff,uRam0035ba98 >> 0x18);
    uRam0035b9e0 = func_0x001d46ec(auStack_20,uRam0035b9e8,0x35b750);
    func_0x00109728(auStack_30,0x66a858,uRam0035bed8 & 0xff,uRam0035bed8 >> 8 & 0xff,
                    uRam0035bed8 >> 0x10 & 0xff,uRam0035bed8 >> 0x18);
    func_0x00106b60(auStack_70,0,0x3c);
    FUN_005bd250(auStack_70);
    func_0x00106b60(auStack_80,0,0x10);
    func_0x00109eb8(auStack_80,0x86f820);
    lVar3 = func_0x0010a050(0x86f820);
    if (lVar3 < 0xf) {
      auStack_80[(int)lVar3] = 0x2d;
    }
    func_0x001db7e8(uRam0035b9e0,0x86f820,0x86f810,auStack_70,auStack_80,auStack_30,0xcaf3,0);
    func_0x001ca8c0();
    uVar5 = 0;
    break;
  case '\x02':
    uRam007152e6 = uRam007152e6 + 1;
    if ((uRam007152e6 & 0x10) == 0) {
      FUN_0061f4b0(0xa8);
    }
    break;
  case '\x03':
    cRam007152e1 = '\n';
    FUN_0061e960(0,0x14,1);
    break;
  case '\x04':
    func_0x001d4de0(uRam0035b9e0);
    func_0x001ca780();
    uVar5 = 1;
    uRam0035b9e0 = 0xffffffff;
    break;
  case '\x05':
    sRam007152e4 = 0x3c;
    cRam007152e1 = cRam007152e1 + '\x01';
  case '\x06':
    if (sRam007152ea == -1) {
      FUN_0061f760(0x12);
    }
    else {
      FUN_0061f760(0x14);
    }
    if (sRam007152e4 == 0) {
      lVar3 = FUN_0061e7f0();
      if ((lVar3 != 0) && (cRam007152e1 = cRam007152e1 + '\x01', cRam0086f7e0 == '\x01')) {
        FUN_0061e960(0,0x14);
      }
      FUN_0061f4b0(0xab);
    }
    else {
      sRam007152e4 = sRam007152e4 + -1;
    }
    break;
  case '\a':
    lVar3 = FUN_0061e910();
    if (lVar3 == 0) {
      FUN_0061f0e0();
      if (cRam0086f7e0 == '\x01') {
        iRam007152a0 = iRam007152a0 + 1;
        uVar5 = 0xffffffff;
        if (iRam007152a0 < 3) {
          uVar5 = 2;
        }
      }
      else {
        sRam007152e4 = 10;
        cRam007152e1 = cRam007152e1 + '\x01';
        FUN_0061f0e0();
        FUN_0061f1f0();
        FUN_0061f470();
      }
      func_0x001d4de0(uRam0035b9e0);
      func_0x001ca780();
      uRam0035b9e0 = 0xffffffff;
    }
    else if (sRam007152ea == -1) {
      FUN_0061f760(0x12);
    }
    else {
      FUN_0061f760(0x14);
    }
    break;
  case '\b':
    FUN_0061f4b0(0xa9);
    FUN_0061f680(0xf);
    if (sRam007152e4 == 0) {
      lVar3 = FUN_0061e7f0();
      if (lVar3 == 0) {
        lVar3 = FUN_0061e800();
        if (lVar3 != 0) {
          cRam007152e2 = '\0';
          cRam007152e1 = '\x0f';
          FUN_0061e960(0,0x14,1);
        }
      }
      else {
        cRam007152e1 = '\x0f';
        cRam007152e2 = '\x01';
        FUN_0061e960(0,0x14);
      }
    }
    else {
      sRam007152e4 = sRam007152e4 + -1;
    }
    break;
  case '\n':
    lVar3 = FUN_0061e910();
    if (lVar3 == 0) {
      cRam007152e1 = '\x04';
      func_0x001dbe60(uRam0035b9e0);
      FUN_0061f0e0();
    }
    break;
  case '\x0f':
    lVar3 = FUN_0061e910();
    if (lVar3 != 0) {
      return 0;
    }
    cRam007152e1 = cRam007152e1 + '\x01';
    FUN_0061f0e0();
  case '\x10':
    uVar5 = 0xffffffff;
    if (cRam007152e2 == '\x01') {
      uVar5 = 3;
    }
  }
  return uVar5;
}



================================================================