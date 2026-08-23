FUNCTION FUN_005ac8a0 @ 0x005ac8a0  size=376
CALLERS (1): FUN_006233e0@0x006233e0
CALLEES (12): FUN_005b2460@0x005b2460, FUN_005ac400@0x005ac400, FUN_00606af0@0x00606af0, FUN_00608300@0x00608300, FUN_005aca50@0x005aca50, FUN_00606cb0@0x00606cb0, FUN_005aca20@0x005aca20, FUN_00606cf0@0x00606cf0, FUN_006063c0@0x006063c0, FUN_006088b0@0x006088b0, FUN_005ac810@0x005ac810, FUN_005ac4c0@0x005ac4c0, ...
----------------------------------------------------------------

undefined8 FUN_005ac8a0(void)

{
  undefined8 uVar1;
  
  FUN_005b2460();
  uRam006c4fde = 0;
  uRam006c4618 = uRam003434a0;
  uRam006c4610 = uRam003434a8;
  uRam006c4620 = uRam003434b8;
  if (cRam006c4faa == '\x17') {
    FUN_005ac4c0();
  }
  else if (cRam006c4faa == '\n') {
    FUN_006088b0();
  }
  else if (cRam006c4faa == '\t') {
    FUN_00606cb0();
  }
  else if (cRam006c4faa == '\b') {
    FUN_00606af0();
  }
  else {
    if (cRam006c4faa == '\x05') {
      uVar1 = FUN_006063c0();
      return uVar1;
    }
    if (cRam006c4faa == '\x04') {
      FUN_005aca50();
    }
    else if (cRam006c4faa == '\x01') {
      FUN_005aca20();
    }
    else if (cRam006c4faa == '\0') {
      FUN_005ac810();
    }
    else if (cRam006c4faa == '\x03') {
      FUN_005ac400();
    }
    else if (cRam006c4faa == '\a') {
      FUN_00606cf0();
    }
    else if (cRam006c4faa == '\x06') {
      FUN_00608300();
    }
  }
  return 0;
}



================================================================