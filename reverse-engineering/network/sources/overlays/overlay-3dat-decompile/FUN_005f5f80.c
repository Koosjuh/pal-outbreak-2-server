FUNCTION FUN_005f5f80 @ 0x005f5f80  size=96
CALLERS (2): FUN_005fe620@0x005fe620, FUN_005f76f0@0x005f76f0
CALLEES (2): FUN_005f5fe0@0x005f5fe0, FUN_005f60d0@0x005f60d0
----------------------------------------------------------------

undefined8 FUN_005f5f80(void)

{
  undefined8 uVar1;
  
  if (cRam00695ce0 == '\x01') {
    uVar1 = FUN_005f60d0(0x695ce0);
  }
  else {
    if (cRam00695ce0 == '\0') {
      FUN_005f5fe0();
    }
    uVar1 = 0;
  }
  return uVar1;
}



================================================================