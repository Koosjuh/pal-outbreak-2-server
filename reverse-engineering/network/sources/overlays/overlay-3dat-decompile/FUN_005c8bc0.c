FUNCTION FUN_005c8bc0 @ 0x005c8bc0  size=84
CALLERS (0): 
CALLEES (1): FUN_005d8340@0x005d8340
----------------------------------------------------------------

void FUN_005c8bc0(void)

{
  long lVar1;
  
  lVar1 = FUN_005d8340(iRam00701068 + 0x4f97c);
  if (lVar1 != 0) {
    uRam00700fe8 = 0;
    uRam00700fe0 = 0xffffffff;
    *(undefined1 *)(iRam00701070 + 1) = 3;
  }
  return;
}



================================================================