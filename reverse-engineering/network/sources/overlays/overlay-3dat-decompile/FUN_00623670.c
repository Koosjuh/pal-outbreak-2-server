FUNCTION FUN_00623670 @ 0x00623670  size=388
CALLERS (1): FUN_00622180@0x00622180
CALLEES (3): FUN_0061ea10@0x0061ea10, FUN_00606a50@0x00606a50, FUN_00606a70@0x00606a70
----------------------------------------------------------------

undefined8 FUN_00623670(void)

{
  char cVar1;
  short sVar2;
  char *pcVar3;
  long lVar4;
  
  cVar1 = pcRam00715298[1];
  if (cVar1 == '\x03') {
    if (*pcRam00715298 == '(') {
      func_0x001a8a00();
    }
    lVar4 = FUN_00606a70();
    if (lVar4 == 1) {
      return 1;
    }
  }
  else if (cVar1 == '\x02') {
    sVar2 = *(short *)(pcRam00715298 + 6);
    *(short *)(pcRam00715298 + 6) = sVar2 + -1;
    if ((short)(sVar2 + -1) == 0) {
      func_0x001b3ad0();
      FUN_0061ea10();
      if (*pcRam00715298 != '(') {
        return 1;
      }
      FUN_00606a50();
      pcRam00715298[1] = pcRam00715298[1] + '\x01';
    }
  }
  else if (cVar1 == '\x01') {
    sVar2 = *(short *)(pcRam00715298 + 6);
    *(short *)(pcRam00715298 + 6) = sVar2 + -1;
    if ((short)(sVar2 + -1) == 0) {
      func_0x001a7e90(0x622130);
      func_0x001a6910(0,0,8);
      pcVar3 = pcRam00715298;
      pcVar3[6] = '\n';
      pcVar3[7] = '\0';
      pcRam00715298[1] = pcRam00715298[1] + '\x01';
    }
  }
  else {
    if (cVar1 != '\0') {
      return 0;
    }
    func_0x001b39f0(7);
    pcVar3 = pcRam00715298;
    pcVar3[6] = '\x14';
    pcVar3[7] = '\0';
    pcRam00715298[1] = pcRam00715298[1] + '\x01';
  }
  return 0;
}



================================================================