FUNCTION FUN_005c8e70 @ 0x005c8e70  size=64
CALLERS (0): 
CALLEES (2): FUN_005d8340@0x005d8340, FUN_005d5e90@0x005d5e90
----------------------------------------------------------------

void FUN_005c8e70(void)

{
  long lVar1;
  
  lVar1 = FUN_005d8340(iRam00701068 + 0x4f97c);
  if (lVar1 != 0) {
    uRam00700fe8 = 0;
    FUN_005d5e90(0xffffffffffffffff);
  }
  return;
}



================================================================