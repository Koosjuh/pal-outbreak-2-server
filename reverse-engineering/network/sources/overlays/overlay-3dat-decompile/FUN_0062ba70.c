FUNCTION FUN_0062ba70 @ 0x0062ba70  size=164
CALLERS (5): FUN_00629370@0x00629370, FUN_00628710@0x00628710, FUN_005ff950@0x005ff950, FUN_005f76f0@0x005f76f0, FUN_005f8d40@0x005f8d40
CALLEES (5): FUN_0062c1d0@0x0062c1d0, FUN_0062bb20@0x0062bb20, FUN_0062bda0@0x0062bda0, FUN_0062c350@0x0062c350, FUN_0062bbc0@0x0062bbc0
----------------------------------------------------------------

undefined8 FUN_0062ba70(void)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (cRam00695d28 == '\x04') {
    uVar1 = FUN_0062c350();
  }
  else if (cRam00695d28 == '\x03') {
    uVar1 = FUN_0062c1d0();
  }
  else if (cRam00695d28 == '\x02') {
    uVar1 = FUN_0062bda0();
  }
  else if (cRam00695d28 == '\x01') {
    uVar1 = FUN_0062bbc0();
  }
  else if (cRam00695d28 == '\0') {
    uVar1 = FUN_0062bb20();
  }
  return uVar1;
}



================================================================