FUNCTION FUN_005c40a0 @ 0x005c40a0  size=656
CALLERS (0): 
CALLEES (2): FUN_005c5ad0@0x005c5ad0, FUN_005c5810@0x005c5810
----------------------------------------------------------------

void FUN_005c40a0(void)

{
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_10 [16];
  
  if (cRam006cbc0c != '\0') {
    if ((cRam006cbc08 == 'c') || (cRam006cbc08 == '\x06')) {
      auStack_10[0] = 0;
      if (cRam0070047d == '\0') {
        FUN_005c5810();
      }
      else if (iRam00700420 == 0) {
        auStack_10[0] = 0xff;
      }
      else if ((iRam00700428 == 0) || ((uRam00700470 & 0x40000000) == 0)) {
        uRam006fbe57 = 0;
      }
      else {
        uRam006fbe57 = 1;
      }
      cRam006cbc0c = '\0';
      cRam006cbc08 = '\0';
      (*pcRam006cbbec)(auStack_10,auStack_10);
    }
    else if (cRam006cbc08 == '\x05') {
      if (cRam006cbc0d != '\0') {
        cRam006cbc08 = 'c';
        cRam006cbc0d = '\0';
      }
    }
    else if (cRam006cbc08 == '\x04') {
      if (iRam00700428 == 0) {
        cRam006cbc08 = 'c';
      }
      else {
        cRam006cbc08 = '\x05';
        func_0x00106b60(&uStack_50,0,0x3c);
        uStack_50 = 0x4f494400;
        uStack_4c = 1;
        uStack_48 = 0x700428;
        func_0x001e0ed8(uRam006febac,&uStack_50,1,0x5c4020);
      }
    }
    else if (cRam006cbc08 == '\x03') {
      if (cRam006cbc0d != '\0') {
        cRam006cbc0d = '\0';
        cRam006cbc08 = '\x04';
      }
    }
    else if (cRam006cbc08 == '\x02') {
      if (iRam00700420 == 0) {
        cRam006cbc08 = 'c';
      }
      else if (iRam00700424 == 0) {
        cRam006cbc08 = 'c';
      }
      else {
        cRam006cbc08 = '\x03';
        func_0x00106b60(&uStack_50,0,0x3c);
        uStack_50 = 0x4f494400;
        uStack_4c = 1;
        uStack_48 = 0x700424;
        func_0x001e094c(uRam006febac,&uStack_50,1,0x5c3fa0);
      }
    }
    else if ((cRam006cbc08 != '\x01') && (cRam006cbc08 == '\0')) {
      cRam006cbc08 = '\x01';
      uRam006cbbf0 = 0;
      uRam006cbbf4 = 0;
      cRam006cbc0d = '\0';
      func_0x00106b60(0x700430,0,0x24);
      func_0x00106b60(0x700454,0,0x28);
      FUN_005c5ad0(0x7003fd,0x5c3f90);
    }
  }
  return;
}



================================================================