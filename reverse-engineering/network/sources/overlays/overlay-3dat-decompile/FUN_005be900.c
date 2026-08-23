FUNCTION FUN_005be900 @ 0x005be900  size=152
CALLERS (2): FUN_006076c0@0x006076c0, FUN_006075e0@0x006075e0
CALLEES (0): 
----------------------------------------------------------------

undefined4 FUN_005be900(void)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((cRam006cbbe4 != '\0') && (uVar1 = 1, cRam006cbbe0 != '\x02')) {
    if (cRam006cbbe0 == '\x01') {
      cRam006cbbe0 = cRam006cbbe0 + '\x01';
      func_0x001d4de0(uRam006febac);
      func_0x001ca780();
      uRam0035b9e0 = 0xffffffff;
    }
    else {
      if (cRam006cbbe0 != '\0') {
        return 0;
      }
      cRam006cbbe0 = '\x01';
    }
    uVar1 = 0;
  }
  return uVar1;
}



================================================================