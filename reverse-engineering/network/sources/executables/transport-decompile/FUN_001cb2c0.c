
void FUN_001cb2c0(void)

{
  puRam0036b900 = (undefined4 *)0x36b920;
  if (cRam00343575 == '\0') {
    if (iRam0036b920 != 0) {
      if (iRam0036b9a4 != 0) {
        FUN_001cbae0(0xff0,1);
        puRam0036b900[0x21] = 0;
      }
      *puRam0036b900 = 0;
      FUN_00106b60(0x36b920,0,0x98);
    }
  }
  else {
    func_0x003acce0();
  }
  return;
}

