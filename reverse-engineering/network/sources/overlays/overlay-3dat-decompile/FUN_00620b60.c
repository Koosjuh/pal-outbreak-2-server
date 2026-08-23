FUNCTION FUN_00620b60 @ 0x00620b60  size=476
CALLERS (1): FUN_00622180@0x00622180
CALLEES (10): FUN_0061e960@0x0061e960, FUN_0061f0d0@0x0061f0d0, FUN_0061e940@0x0061e940, FUN_0061f1d0@0x0061f1d0, FUN_0061f9d0@0x0061f9d0, FUN_0061e910@0x0061e910, FUN_0061ea20@0x0061ea20, FUN_0061d6a0@0x0061d6a0, FUN_0061f970@0x0061f970, FUN_0061f1a0@0x0061f1a0
----------------------------------------------------------------

undefined4 FUN_00620b60(void)

{
  long lVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  switch(cRam007152e1) {
  case '\0':
    if ((cRam003c98a0 == '\x01') && (cRam00715308 == '\0')) {
      cRam007152e1 = 6;
      return 0;
    }
    cRam003c98a0 = '\x01';
    cRam007152e1 = cRam007152e1 + '\x01';
  case '\x01':
    lVar1 = FUN_0061f970();
    if (lVar1 != 0) {
      uRam007152e8 = 0;
      cRam007152e1 = cRam007152e1 + '\x01';
      FUN_0061ea20(0);
      FUN_0061e940();
      uVar2 = 0;
    }
    break;
  case '\x02':
    lVar1 = FUN_0061f9d0();
    if (lVar1 != 0) {
      uRam007152e4 = 10;
      cRam007152e1 = cRam007152e1 + '\x01';
      FUN_0061f1a0();
      FUN_0061f1d0();
      FUN_0061e960(0,0x14,0);
      uRam007152e2 = 0;
    }
    break;
  case '\x03':
    cRam007152e1 = cRam007152e1 + '\x01';
    break;
  case '\x04':
    cRam007152e1 = cRam007152e1 + '\x01';
    break;
  case '\x05':
    lVar1 = FUN_0061d6a0();
    if (lVar1 != -1) {
      if (lVar1 != 1) {
        return 0;
      }
      cRam00715308 = '\0';
    }
    cRam007152e1 = cRam007152e1 + '\x01';
    FUN_0061e960(0,0x14,1);
    break;
  case '\x06':
    lVar1 = FUN_0061e910();
    if (lVar1 != 0) {
      return 0;
    }
    cRam007152e1 = cRam007152e1 + '\x01';
    FUN_0061f0d0();
  case '\a':
    uVar2 = 1;
  }
  return uVar2;
}



================================================================