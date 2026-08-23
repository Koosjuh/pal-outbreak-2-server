FUNCTION FUN_006233e0 @ 0x006233e0  size=504
CALLERS (1): FUN_00622180@0x00622180
CALLEES (4): FUN_005ac610@0x005ac610, FUN_005ac8a0@0x005ac8a0, FUN_00623600@0x00623600, FUN_005f4440@0x005f4440
----------------------------------------------------------------

undefined8 FUN_006233e0(void)

{
  char cVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  cVar1 = *(char *)(iRam00715298 + 1);
  if (cVar1 == 'b') {
    FUN_005ac610();
    FUN_00623600();
    uRam007152e1 = 0;
    uRam007152e0 = 0x2c;
    uRam007152f1 = 1;
    uRam007152ee = 0;
    uRam0071543c = 1;
    uRam00715478 = 1;
    uRam007152d0 = 0;
    uRam007152a0 = 0;
    func_0x001ee370();
    uVar2 = 0;
  }
  else if (cVar1 == 'c') {
    FUN_00623600();
    uRam007152e1 = 0;
    uRam007152e0 = 0x31;
    uVar2 = 0;
    uRam007152f1 = 1;
    uRam0071543c = 1;
    uRam007152ee = 0;
  }
  else if (cVar1 == '\x02') {
    iRam0086f838 = iRam0086f838 + -1;
    if (iRam0086f838 < 1) {
      iRam0086f838 = 0;
    }
    iRam0086f830 = iRam0086f830 + -1;
    if (iRam0086f830 < 1) {
      iRam0086f830 = 0;
    }
    uVar2 = FUN_005ac8a0();
  }
  else if (cVar1 == '\x01') {
    cVar1 = *(char *)(iRam00715298 + 2) + -1;
    *(char *)(iRam00715298 + 2) = cVar1;
    if (cVar1 == '\0') {
      func_0x001ee370();
      func_0x00106b60(0x874f30,0,0xac);
      uRam0086f7f0 = 0;
      uRam0086f800 = 0;
      uRam0086f7f8 = 0;
      iRam0086f838 = iRam00365e04;
      FUN_005f4440();
      *(char *)(iRam00715298 + 1) = *(char *)(iRam00715298 + 1) + '\x01';
      FUN_005ac610();
    }
  }
  else if (cVar1 == '\0') {
    *(undefined1 *)(iRam00715298 + 1) = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



================================================================