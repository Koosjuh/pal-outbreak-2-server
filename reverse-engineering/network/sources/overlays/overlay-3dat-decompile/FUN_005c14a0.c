FUNCTION FUN_005c14a0 @ 0x005c14a0  size=712
CALLERS (0): 
CALLEES (2): FUN_005bf1e0@0x005bf1e0, FUN_005c3e50@0x005c3e50
----------------------------------------------------------------

void FUN_005c14a0(void)

{
  uint uVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
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
  
  if (cRam006cba04 != '\0') {
    if (cRam006cba00 == '\x04') {
      auStack_10[0] = 0xff;
      cRam006cba04 = '\0';
      cRam006cba00 = '\0';
      (*pcRam006cb9e4)(auStack_10,auStack_10);
    }
    else if (cRam006cba00 == '\x03') {
      auStack_10[0] = 0;
      cRam006cba04 = '\0';
      cRam006cba00 = '\0';
      (*pcRam006cb9e4)(auStack_10,auStack_10);
    }
    else if (cRam006cba00 == '\x02') {
      if (cRam006cba05 == '\x01') {
        cRam006cba05 = '\0';
        uRam006cb9ec = uRam006cb9ec + 1;
        if (uRam006cb9ec < 4) {
          cRam006cba00 = '\x01';
        }
        else {
          cRam006cba00 = '\x03';
        }
      }
      else if (cRam006cba05 == '\x02') {
        cRam006cba00 = '\x04';
      }
    }
    else if (cRam006cba00 == '\x01') {
      cRam006cba00 = '\x02';
      func_0x00106b60(&uStack_50,0,0x3c);
      uStack_4c = 1;
      uStack_50 = 0x4c4f4944;
      uVar1 = FUN_005bf1e0(0);
      uStack_44 = 0x53544154;
      uStack_38 = 0x53544154;
      iStack_48 = ((uVar1 & 0xffff) - 1) * 0x24 + 0x6fec28;
      uStack_40 = 0x21;
      puStack_3c = &DAT_006404c0;
      uStack_34 = 0x21;
      puStack_30 = &DAT_00640500 + (uRam006cb9ec * 2 + 2) * 4;
      uVar2 = func_0x001e0ed8(uRam006febac,&uStack_50,uRam007006a8,0x5c3da0);
      FUN_005c3e50(uVar2,0x5c13e0,0x7005e8);
    }
    else if (cRam006cba00 == '\0') {
      cRam006cba00 = '\x01';
      uRam006cb9e8 = 1;
      uRam006cb9ec = 0;
      cRam006cba05 = '\0';
      uRam006cbcca = 0;
      uRam006ce5c0 = 0;
      func_0x00106b60(0x6cf27c,0,0x8dc);
      func_0x00106b60(0x6fed70,0,0xfc);
      uRam006ce5c0 = 6;
      iVar4 = 0;
      do {
        uVar1 = FUN_005bf1e0(0);
        iVar5 = iVar4 + 1;
        iVar3 = iVar4 * 0x144;
        *(undefined4 *)(iVar4 * 0x24 + 0x6fed90) =
             *(undefined4 *)((uVar1 & 0xffff) * 0x24 + 0x6fec04);
        *(short *)(iVar3 + 0x6cf284) = (short)iVar4 + 1;
        *(undefined1 *)(iVar3 + 0x6cf298) = 3;
        *(undefined2 *)(iVar3 + 0x6cf286) = 0;
        iVar4 = iVar5;
      } while (iVar5 < 6);
    }
  }
  return;
}



================================================================