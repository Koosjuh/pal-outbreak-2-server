FUNCTION FUN_00622d60 @ 0x00622d60  size=472
CALLERS (1): FUN_00622180@0x00622180
CALLEES (9): FUN_0061f0f0@0x0061f0f0, FUN_0061f4b0@0x0061f4b0, FUN_0061f1f0@0x0061f1f0, FUN_0061f470@0x0061f470, FUN_0061f680@0x0061f680, FUN_0061e800@0x0061e800, FUN_0061e7f0@0x0061e7f0, FUN_0061f1a0@0x0061f1a0, FUN_0061f1b0@0x0061f1b0
----------------------------------------------------------------

undefined4 FUN_00622d60(void)

{
  char cVar1;
  short sVar2;
  long lVar3;
  
  cVar1 = *(char *)(iRam00715298 + 1);
  if (cVar1 == '\n') {
    return 0xffffffff;
  }
  if (cVar1 != '\x04') {
    if (cVar1 != '\x03') {
      if (cVar1 == '\x02') {
        FUN_0061f4b0(0x37);
        FUN_0061f4b0(1);
        FUN_0061f680(3);
        lVar3 = FUN_0061e7f0();
        if (lVar3 != 0) {
          *(undefined1 *)(iRam00715298 + 1) = 3;
          *(undefined2 *)(iRam00715298 + 4) = 0xf;
          FUN_0061f0f0(0x10000);
          return 0;
        }
        lVar3 = FUN_0061e800();
        if (lVar3 == 0) {
          return 0;
        }
        *(undefined1 *)(iRam00715298 + 1) = 10;
        *(undefined2 *)(iRam00715298 + 4) = 1;
        FUN_0061f0f0(0x10000);
        return 0;
      }
      if (cVar1 == '\x01') {
        sVar2 = *(short *)(iRam00715298 + 6) + -1;
        *(short *)(iRam00715298 + 6) = sVar2;
        if (sVar2 != 0) {
          return 0;
        }
        FUN_0061f470();
        *(char *)(iRam00715298 + 1) = *(char *)(iRam00715298 + 1) + '\x01';
        return 0;
      }
      if (cVar1 == '\0') {
        func_0x001b39f0();
        *(char *)(iRam00715298 + 1) = *(char *)(iRam00715298 + 1) + '\x01';
        FUN_0061f1a0();
        FUN_0061f1b0();
        FUN_0061f1f0();
        *(undefined2 *)(iRam00715298 + 6) = 10;
        func_0x001a7e20(0x622130);
        return 0;
      }
      return 0;
    }
    FUN_0061f4b0(0x37);
    sVar2 = *(short *)(iRam00715298 + 4) + -1;
    *(short *)(iRam00715298 + 4) = sVar2;
    if (sVar2 != 0) {
      return 0;
    }
    *(char *)(iRam00715298 + 1) = *(char *)(iRam00715298 + 1) + '\x01';
  }
  return 1;
}



================================================================