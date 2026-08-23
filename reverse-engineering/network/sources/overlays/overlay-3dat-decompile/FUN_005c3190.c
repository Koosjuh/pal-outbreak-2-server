FUNCTION FUN_005c3190 @ 0x005c3190  size=476
CALLERS (0): 
CALLEES (3): FUN_005c2f40@0x005c2f40, FUN_005bf1e0@0x005bf1e0, FUN_005c2b50@0x005c2b50
----------------------------------------------------------------

void FUN_005c3190(void)

{
  short sVar1;
  undefined8 uVar2;
  undefined1 auStack_10 [16];
  
  if (cRam006cba54 != '\0') {
    if (cRam006cba50 == '\x10') {
      auStack_10[0] = 0xff;
      cRam006cba54 = '\0';
      cRam006cba50 = '\0';
      (*pcRam006cba34)(auStack_10,auStack_10);
    }
    else if (cRam006cba50 == '\x02') {
      auStack_10[0] = 0;
      cRam006cba54 = '\0';
      cRam006cba50 = '\0';
      (*pcRam006cba34)(auStack_10,auStack_10);
    }
    else if (cRam006cba50 == '\x01') {
      if (cRam006cba55 == '\x01') {
        cRam006cba50 = '\x02';
        cRam006cba55 = '\0';
        FUN_005c2f40(1,*(undefined4 *)(iRam006cba44 * 0x144 + 0x6cfa18));
      }
      else if (cRam006cba55 == '\x02') {
        cRam006cba50 = '\x10';
      }
    }
    else if (cRam006cba50 == '\0') {
      cRam006cba55 = '\0';
      if (cRam006ff2b0 == '\0') {
        cRam006cba50 = '\x01';
        uRam006ca890 = 0;
        func_0x001de0c0(uRam006febac,*(undefined4 *)(iRam006cba44 * 0x24 + 0x6fee68),0x5c3370);
      }
      else {
        cRam006cba50 = '\x02';
        FUN_005c2f40(0,0);
        if (cRam006d2294 == '\0') {
          sVar1 = FUN_005bf1e0(0);
          uVar2 = FUN_005c2b50(sVar1 + -1);
          func_0x001069a8((iRam006cba44 + -1) * 0x144 + 0x6cfb76,uVar2,0xf);
        }
      }
    }
  }
  return;
}



================================================================