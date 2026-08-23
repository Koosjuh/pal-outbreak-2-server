FUNCTION FUN_005c1770 @ 0x005c1770  size=604
CALLERS (0): 
CALLEES (2): FUN_005bf1e0@0x005bf1e0, FUN_005c3e50@0x005c3e50
----------------------------------------------------------------

void FUN_005c1770(void)

{
  uint uVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  int iStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined *puStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined *puStack_30;
  undefined1 auStack_10 [16];
  
  if (cRam006cba2c != '\0') {
    if (cRam006cba28 == '\x03') {
      auStack_10[0] = 0xff;
      cRam006cba2c = '\0';
      cRam006cba28 = '\0';
      (*pcRam006cba0c)(auStack_10,auStack_10);
    }
    else if (cRam006cba28 == '\x02') {
      auStack_10[0] = 0;
      cRam006cba2c = '\0';
      cRam006cba28 = '\0';
      (*pcRam006cba0c)(auStack_10,auStack_10);
    }
    else if (cRam006cba28 == '\x01') {
      if (cRam006cba2d == '\x01') {
        cRam006cba28 = '\x02';
      }
      else if (cRam006cba2d == '\x02') {
        cRam006cba28 = '\x03';
      }
    }
    else if (cRam006cba28 == '\0') {
      cRam006cba28 = '\x01';
      uRam006cba10 = 1;
      uRam006cba14 = 1;
      cRam006cba2d = '\0';
      uRam006ff2b0 = 0;
      uRam006febe8 = 0;
      uRam006ff2b2 = 0;
      uRam006cbcca = 0;
      uRam006ce5c2 = 0;
      func_0x00106b60(0x6fee6c,0,0x438);
      func_0x00106b60(0x6cfb58,0,0x25f8);
      iVar3 = 0;
      do {
        iVar4 = iVar3 + 1;
        *(short *)(iVar3 * 0x144 + 0x6cfb60) = (short)iVar3 + 1;
        *(undefined1 *)(iVar3 * 0x144 + 0x6cfb74) = 1;
        iVar3 = iVar4;
      } while (iVar4 < 0x1e);
      func_0x00106b60(&uStack_50,0,0x3c);
      uStack_4c = 1;
      uStack_50 = 0x4c4f4944;
      uVar1 = FUN_005bf1e0(0);
      uStack_44 = 0x53544154;
      uStack_40 = 0x21;
      iStack_48 = ((uVar1 & 0xffff) - 1) * 0x24 + 0x6fec28;
      uVar1 = FUN_005bf1e0(1);
      uRam006ca898 = 0;
      puStack_3c = &DAT_006404c0 + ((uVar1 & 0xffff) - 1) * 8;
      uStack_38 = 0x53544154;
      uStack_34 = 0x21;
      puStack_30 = &DAT_006404f0;
      uVar2 = func_0x001e0ed8(uRam006febac,&uStack_50,0x1e,0x5c3da0);
      FUN_005c3e50(uVar2,0x5c19d0,0x7005f0);
    }
  }
  return;
}



================================================================