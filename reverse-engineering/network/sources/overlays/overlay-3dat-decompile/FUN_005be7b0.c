FUNCTION FUN_005be7b0 @ 0x005be7b0  size=268
CALLERS (0): 
CALLEES (0): 
----------------------------------------------------------------

void FUN_005be7b0(void)

{
  char cVar1;
  undefined1 auStack_10 [16];
  
  if (cRam006cbbe4 != '\0') {
    if (cRam006cbbe0 == '\x03') {
      auStack_10[0] = 0xff;
      cRam006cbbe4 = '\0';
      cRam006cbbe0 = '\0';
      (*pcRam006cbbc4)(auStack_10,auStack_10);
    }
    else if (cRam006cbbe0 == '\x02') {
      auStack_10[0] = 0;
      func_0x00106b60(0x6ce5c8,0,10);
      uRam0070047c = 0;
      uRam006ff2b1 = 0;
      cRam006cbbe4 = '\0';
      cRam006cbbe0 = '\0';
      (*pcRam006cbbc4)(auStack_10,auStack_10);
    }
    else {
      cVar1 = cRam006cbbe0 + '\x01';
      if (cRam006cbbe0 == '\x01') {
        cRam006cbbe0 = cVar1;
        if (iRam0035b9e0 != -1) {
          func_0x001d4de0();
        }
        func_0x001ca780();
        iRam0035b9e0 = -1;
      }
      else if (cRam006cbbe0 == '\0') {
        uRam006cbbcc = 1;
        cRam006cbbe0 = '\x01';
      }
    }
  }
  return;
}



================================================================