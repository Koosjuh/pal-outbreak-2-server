FUNCTION FUN_005bdc70 @ 0x005bdc70  size=228
CALLERS (2): FUN_005bc990@0x005bc990, FUN_005bcee0@0x005bcee0
CALLEES (0): 
----------------------------------------------------------------

void FUN_005bdc70(void)

{
  undefined1 uStack_10;
  undefined1 uStack_f;
  
  if (cRam006cb98c != '\0') {
    cRam006cb98c = '\0';
    uStack_10 = 0;
    uRam006cb988 = 0;
    uStack_f = 0;
    (*pcRam006cb96c)(&uStack_10,&uStack_10);
    uRam007006ac = (uint)uRam0036848c;
    uRam007006a8 = (uint)uRam0036848e;
    if (0xfa < uRam007006ac) {
      uRam007006ac = 0xfa;
    }
    if (0xfa < uRam007006a8) {
      uRam007006a8 = 0xfa;
    }
    if ((sRam00368490 != 0) && (sRam00368492 != 0)) {
      sRam006febe0 = sRam00368490;
      uRam006febde = 1;
      uRam006febdf = 0;
    }
  }
  return;
}



================================================================