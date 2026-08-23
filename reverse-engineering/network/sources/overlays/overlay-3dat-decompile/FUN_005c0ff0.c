FUNCTION FUN_005c0ff0 @ 0x005c0ff0  size=560
CALLERS (0): 
CALLEES (5): FUN_005c2a70@0x005c2a70, FUN_005c2a90@0x005c2a90, FUN_005c4f40@0x005c4f40, FUN_005c4fd0@0x005c4fd0, FUN_005c3e50@0x005c3e50
----------------------------------------------------------------

void FUN_005c0ff0(void)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined1 auStack_70 [16];
  undefined1 auStack_60 [16];
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined1 *puStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined1 *puStack_3c;
  undefined1 auStack_10 [16];
  
  if (cRam006cb9dc != '\0') {
    if (cRam006cb9d8 == '\x03') {
      auStack_10[0] = 0xff;
      cRam006cb9dc = '\0';
      cRam006cb9d8 = '\0';
      (*pcRam006cb9bc)(auStack_10,auStack_10);
    }
    else if (cRam006cb9d8 == '\x02') {
      auStack_10[0] = 0;
      cRam006cb9dc = '\0';
      cRam006cb9d8 = '\0';
      (*pcRam006cb9bc)(auStack_10,auStack_10);
    }
    else if (cRam006cb9d8 == '\x01') {
      if (cRam006cb9dd == '\x01') {
        cRam006cb9d8 = '\x02';
        cRam006cb9dd = '\0';
      }
      else if (cRam006cb9dd == '\x02') {
        cRam006cb9d8 = '\x03';
      }
    }
    else if (cRam006cb9d8 == '\0') {
      cRam006cb9d8 = '\x01';
      uRam006cb9c0 = 1;
      uRam006cb9c4 = 1;
      cRam006cb9dd = '\0';
      uRam006ce5be = 0;
      func_0x00106b60(0x6ce5d4,0,0xca8);
      uVar3 = 0;
      iVar1 = 0;
      do {
        iVar1 = (iVar1 + uVar3) * 0x24;
        *(short *)(iVar1 + 0x6ce5dc) = (short)uVar3 + 1;
        *(undefined1 *)(iVar1 + 0x6ce5f0) = 0;
        uVar2 = FUN_005c2a70(uVar3 & 0xffff);
        func_0x001069a8(iVar1 + 0x6ce5f2,uVar2,0x18);
        uVar2 = FUN_005c2a90(uVar3 & 0xffff);
        func_0x001069a8(iVar1 + 0x6ce616,uVar2,0x100);
        uVar3 = uVar3 + 1;
        iVar1 = uVar3 * 8;
      } while ((int)uVar3 < 10);
      func_0x00106b60(0x6fec08,0,0x168);
      func_0x00106b60(&uStack_50,0,0x3c);
      uVar2 = FUN_005c4f40();
      func_0x00109eb8(auStack_60,uVar2);
      uVar2 = FUN_005c4fd0();
      func_0x00109eb8(auStack_70,uVar2);
      uStack_4c = 0x44;
      uStack_50 = 0x4e414d45;
      uStack_44 = 0x4e414d45;
      puStack_48 = auStack_60;
      puStack_3c = auStack_70;
      uStack_40 = 0x46;
      uVar2 = func_0x001e094c(uRam006febac,&uStack_50,10,0x5c3cf0);
      FUN_005c3e50(uVar2,0x5c1220,0x700630);
    }
  }
  return;
}



================================================================