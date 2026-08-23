FUNCTION FUN_00606610 @ 0x00606610  size=268
CALLERS (1): FUN_006063c0@0x006063c0
CALLEES (0): 
----------------------------------------------------------------

void FUN_00606610(void)

{
  long lVar1;
  
  sRam0070cdca = sRam0070cdca + -1;
  if (sRam0070cdca < 1) {
    sRam0070cdca = 10;
    sRam0070cdc8 = sRam0070cdc8 + -1;
    func_0x001ee650(uRam0035a6f4);
    func_0x001ee680(0x35a6f4);
  }
  else {
    lVar1 = func_0x001ee430(uRam0035a6f4,0x35a714);
    if (lVar1 < 0) {
      sRam0070cdc8 = sRam0070cdc8 + -1;
      sRam0070cdca = sRam0070cdca + 10;
      func_0x001ee650(uRam0035a6f4);
      func_0x001ee680(0x35a6f4);
    }
    else if (sRam0035a714 == 4) {
      sRam0070cdca = 0;
      uRam0070cdcc = 0;
      sRam0070cdc8 = sRam0070cdc8 + 1;
    }
  }
  return;
}



================================================================