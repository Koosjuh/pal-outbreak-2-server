FUNCTION FUN_005ca1a0 @ 0x005ca1a0  size=240
CALLERS (0): 
CALLEES (5): FUN_005cce30@0x005cce30, FUN_005d5b10@0x005d5b10, FUN_005cc980@0x005cc980, FUN_005d8840@0x005d8840, FUN_005ca6a0@0x005ca6a0
----------------------------------------------------------------

void FUN_005ca1a0(void)

{
  char cVar1;
  
  FUN_005ca6a0();
  cVar1 = *(char *)(iRam00701070 + 0x2e);
  if ((cVar1 == '\t') || (cVar1 == '\b')) {
    cVar1 = FUN_005cce30();
    if (cVar1 != '\0') {
      FUN_005d5b10();
    }
  }
  else if (cVar1 == '\x04') {
    FUN_005d8840();
    FUN_005d5b10();
  }
  else if ((cVar1 == '\x02') || (cVar1 == '\x01')) {
    cVar1 = FUN_005cc980();
    if (cVar1 == '\x01') {
      FUN_005d5b10();
    }
    else if ((cVar1 != '\0') && (cVar1 == -1)) {
      FUN_005d5b10();
    }
  }
  return;
}



================================================================