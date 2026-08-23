FUNCTION FUN_006188b0 @ 0x006188b0  size=548
CALLERS (0): 
CALLEES (0): 
----------------------------------------------------------------

void FUN_006188b0(void)

{
  int iVar1;
  int iStack_30;
  undefined4 uStack_2c;
  undefined1 auStack_10 [8];
  undefined4 uStack_8;
  
  iVar1 = iRam006fe8ec;
  if (cRam006cbb44 != '\0') {
    switch(cRam006cbb40) {
    case '\0':
      cRam006cbb40 = cRam006cbb40 + '\x01';
      uRam006cbb28 = 0;
      uRam006cbb2c = 0;
      uRam006cbb45 = 0;
      uRam006cbb46 = 0;
      uRam006fe8f4 = 0;
      func_0x00106b60(0x6fe8f8,0,0x180);
      if (cRam007006a7 != '\0') {
        func_0x001c3320();
        return;
      }
      cRam006cbb40 = '\x02';
      break;
    case '\x01':
      func_0x001c3380(&iStack_30);
      if (iStack_30 == 4) {
        func_0x001c33f0();
        auStack_10[0] = 0xff;
        uStack_8 = uStack_2c;
        cRam006cbb44 = '\0';
        cRam006cbb40 = '\0';
        (*pcRam006cbb24)(auStack_10,auStack_10);
      }
      else if (iStack_30 == 3) {
        func_0x001c33f0();
        cRam006cbb40 = cRam006cbb40 + '\x01';
      }
      break;
    case '\x02':
      cRam006cbb40 = '\x04';
      uRam006fe8f4 = 2;
      func_0x001069a8(iRam006fe8ec,uRam00368474,iRam0036846c);
      uRam006fe8fc = 0;
      iRam006fe900 = iVar1;
      iVar1 = iVar1 + iRam0036846c;
      iRam006fe8f8 = iRam0036846c;
      func_0x001069a8(iVar1,uRam00368478,uRam00368470);
      uRam006fe908 = 0;
      uRam006fe904 = uRam00368470;
      iRam006fe90c = iVar1;
      break;
    case '\x04':
      uRam00700680 = 0;
      auStack_10[0] = 0;
      cRam007006a7 = '\0';
      cRam006cbb44 = '\0';
      cRam006cbb40 = '\0';
      (*pcRam006cbb24)(auStack_10,auStack_10);
      break;
    case '\x05':
      uRam00700680 = 0;
      auStack_10[0] = 0xff;
      cRam007006a7 = '\0';
      cRam006cbb44 = '\0';
      cRam006cbb40 = '\0';
      (*pcRam006cbb24)(auStack_10,auStack_10);
    }
  }
  return;
}



================================================================