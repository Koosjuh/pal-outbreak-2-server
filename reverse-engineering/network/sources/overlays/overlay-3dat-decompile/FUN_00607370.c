FUNCTION FUN_00607370 @ 0x00607370  size=616
CALLERS (1): FUN_00606cf0@0x00606cf0
CALLEES (9): FUN_00607a10@0x00607a10, FUN_005c79d0@0x005c79d0, FUN_00606e40@0x00606e40, FUN_00606f60@0x00606f60, FUN_005af300@0x005af300, FUN_005b9110@0x005b9110, FUN_005c7a00@0x005c7a00, FUN_00606fa0@0x00606fa0, FUN_005b8cf0@0x005b8cf0
----------------------------------------------------------------

void FUN_00607370(undefined8 param_1)

{
  char cVar1;
  short sVar2;
  long lVar3;
  char *pcVar4;
  
  pcVar4 = (char *)param_1;
  cVar1 = pcVar4[1];
  if (cVar1 == '\x03') {
    sVar2 = *(short *)(pcVar4 + 4);
    *(short *)(pcVar4 + 4) = sVar2 + -1;
    if ((short)(sVar2 + -1) < 0) {
      FUN_00606f60();
      FUN_005b9110(0x4c);
    }
  }
  else if (cVar1 == '\x02') {
    sVar2 = *(short *)(pcVar4 + 4);
    *(short *)(pcVar4 + 4) = sVar2 + -1;
    if ((short)(sVar2 + -1) < 0) {
      FUN_00606e40();
      FUN_005af300(0,1);
      FUN_005b9110(0x4c);
    }
  }
  else if (cVar1 == '\x01') {
    lVar3 = FUN_005c7a00();
    if (lVar3 == -1) {
      pcVar4[1] = '\x03';
      pcVar4[4] = '\b';
      pcVar4[5] = '\0';
    }
    else if (lVar3 == 1) {
      pcVar4[1] = '\x02';
      pcVar4[4] = '\b';
      pcVar4[5] = '\0';
    }
  }
  else if (cVar1 == '\0') {
    lVar3 = func_0x001ee360();
    if (lVar3 == 0) {
      if ((iRam006c4610 != 0) || (cRam006c4628 != '\0')) {
        iRam0070cd78 = iRam006c50f4;
      }
      if ((iRam006c50f0 == 0) || (iRam0070cd78 = iRam0070cd78 + -1, -1 < iRam0070cd78)) {
        lVar3 = FUN_00607a10(0x6c5490);
        cVar1 = cRam006c5497;
        if (lVar3 == -2) {
          *pcVar4 = *pcVar4 + '\x01';
          pcVar4[1] = '\0';
          FUN_005af300(0,10);
        }
        else if ((lVar3 != -1) && (lVar3 == 0)) {
          func_0x001069a8(0x874410,cRam006c5497 * 0x104 + 0x874500,0x14);
          func_0x001069a8(0x874f3c,cVar1 * 0x158 + 0x70c048,0x10);
          pcVar4[1] = pcVar4[1] + '\x01';
          FUN_005c79d0((int)cVar1 + 1U & 0xffff);
          FUN_005b8cf0(0x51);
        }
      }
      else {
        FUN_00606fa0(param_1,1);
      }
    }
    else {
      FUN_00606fa0(param_1,0);
    }
  }
  return;
}



================================================================