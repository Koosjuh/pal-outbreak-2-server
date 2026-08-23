FUNCTION FUN_006231b0 @ 0x006231b0  size=424
CALLERS (1): FUN_00622180@0x00622180
CALLEES (6): FUN_0061f340@0x0061f340, FUN_0061f0d0@0x0061f0d0, FUN_0061f1d0@0x0061f1d0, FUN_005b24c0@0x005b24c0, FUN_0061f3b0@0x0061f3b0, FUN_00623800@0x00623800
----------------------------------------------------------------

undefined4 FUN_006231b0(void)

{
  char cVar1;
  long lVar2;
  undefined4 uVar3;
  
  cVar1 = *(char *)(iRam00715298 + 1);
  uVar3 = 0;
  if (cVar1 == '\x04') {
    FUN_0061f0d0();
    func_0x001ad820();
    uVar3 = 0xffffffff;
  }
  else if (cVar1 == '\x03') {
    lVar2 = FUN_00623800();
    if (lVar2 != 0) {
      *(char *)(iRam00715298 + 1) = *(char *)(iRam00715298 + 1) + '\x01';
    }
  }
  else if (cVar1 == '\x02') {
    FUN_0061f0d0();
    uVar3 = 1;
    func_0x001ad820();
  }
  else if (cVar1 == '\x01') {
    if ((uRam003433b8 & 0x8000) == 0) {
      sRam0035b746 = 0;
    }
    else {
      sRam0035b746 = sRam0035b746 + 2;
    }
    lVar2 = func_0x001c0c50();
    uRam007152e4 = (ushort)bRam0035b74d;
    if (lVar2 == 4) {
      uRam007152e2 = 0;
      uRam007152e1 = 3;
    }
    else if (lVar2 == 2) {
      FUN_0061f0d0();
      func_0x001ad820();
      FUN_005b24c0();
      uRam007152e1 = 2;
    }
    uVar3 = 0;
  }
  else if (cVar1 == '\0') {
    func_0x001c04a0();
    FUN_0061f340(0);
    FUN_0061f3b0();
    FUN_0061f1d0();
    *(undefined2 *)(iRam00715298 + 4) = 0;
    *(char *)(iRam00715298 + 1) = *(char *)(iRam00715298 + 1) + '\x01';
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



================================================================