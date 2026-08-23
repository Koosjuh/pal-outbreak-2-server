FUNCTION FUN_00623800 @ 0x00623800  size=564
CALLERS (1): FUN_006231b0@0x006231b0
CALLEES (5): FUN_0061f600@0x0061f600, FUN_0061f4b0@0x0061f4b0, FUN_0061f0e0@0x0061f0e0, FUN_0061f1d0@0x0061f1d0, FUN_0061e7f0@0x0061e7f0
----------------------------------------------------------------

undefined4 FUN_00623800(void)

{
  char cVar1;
  short sVar2;
  long lVar3;
  
  cVar1 = *(char *)(iRam00715298 + 2);
  if (cVar1 != '\x04') {
    if (cVar1 != '\x03') {
      if (cVar1 != '\x02') {
        if (cVar1 == '\x01') {
          sVar2 = *(short *)(iRam00715298 + 4) + -1;
          *(short *)(iRam00715298 + 4) = sVar2;
          if (0 < sVar2) {
            return 0;
          }
          *(char *)(iRam00715298 + 2) = *(char *)(iRam00715298 + 2) + '\x01';
          *(undefined2 *)(iRam00715298 + 4) = 0x3c;
          FUN_0061f1d0();
          return 0;
        }
        if (cVar1 == '\0') {
          *(undefined1 *)(iRam00715298 + 2) = 1;
          *(undefined2 *)(iRam00715298 + 4) = 0x14;
          FUN_0061f0e0();
          return 0;
        }
        return 0;
      }
      if (*(short *)(iRam00715298 + 4) == 0) {
        lVar3 = FUN_0061e7f0();
        if (lVar3 != 0) {
          *(char *)(iRam00715298 + 2) = *(char *)(iRam00715298 + 2) + '\x01';
          return 0;
        }
        FUN_0061f4b0(0xab);
      }
      else {
        *(short *)(iRam00715298 + 4) = *(short *)(iRam00715298 + 4) + -1;
      }
      if (cRam0035b74f == -0x56) {
        FUN_0061f600(0xc);
        return 0;
      }
      if (cRam0035b74f == -0x55) {
        FUN_0061f600(8);
        return 0;
      }
      if (cRam0035b74f != -0x54) {
        if (cRam0035b74f == -0x53) {
          FUN_0061f600(6);
          return 0;
        }
        if (cRam0035b74f == -0x52) {
          FUN_0061f600(2);
          return 0;
        }
        if (cRam0035b74f == -0x51) {
          FUN_0061f600(1);
          return 0;
        }
        if (cRam0035b74f != -5) {
          if (cRam0035b74f == -3) {
            FUN_0061f600(4);
            return 0;
          }
          if (cRam0035b74f != -2) {
            return 0;
          }
          FUN_0061f600(3);
          return 0;
        }
        FUN_0061f600(5);
        return 0;
      }
      FUN_0061f600(7);
      return 0;
    }
    *(undefined1 *)(iRam00715298 + 2) = 4;
  }
  return 1;
}



================================================================