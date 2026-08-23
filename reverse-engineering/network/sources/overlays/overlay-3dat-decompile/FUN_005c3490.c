FUNCTION FUN_005c3490 @ 0x005c3490  size=1352
CALLERS (0): 
CALLEES (5): FUN_005c2ae0@0x005c2ae0, FUN_005c2b70@0x005c2b70, FUN_005bf1e0@0x005bf1e0, FUN_005bdfe0@0x005bdfe0, FUN_005c4f00@0x005c4f00
----------------------------------------------------------------

void FUN_005c3490(void)

{
  char cVar1;
  byte bVar2;
  short sVar3;
  undefined2 uVar4;
  char *pcVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  uint uVar14;
  undefined2 auStack_18 [4];
  undefined1 auStack_10 [16];
  
  if (cRam006cba7c != '\0') {
    if (cRam006cba78 == '\x02') {
      if (cRam006cba7d == '\x01') {
        uRam006ff2b1 = 1;
        auStack_10[0] = 0;
        cRam006cba7c = '\0';
        cRam006cba78 = '\0';
        (*pcRam006cba5c)(auStack_10,auStack_10);
        uRam006cbc7e = 0x10;
        uRam006d2158 = FUN_005bf1e0(2);
        FUN_005bdfe0(0x18);
      }
      else if (cRam006cba7d == '\x02') {
        auStack_10[0] = 0xff;
        cRam006cba7c = '\0';
        cRam006cba78 = '\0';
        (*pcRam006cba5c)(auStack_10,auStack_10);
      }
    }
    else if (cRam006cba78 == '\x01') {
      if (cRam006cba7d == '\x01') {
        cRam006cba78 = '\x02';
        cRam006cba7d = '\0';
        func_0x001dc508(uRam006febac,0x6cc01a,0x6cc03b,uRam006ca888,1,uRam006febe4 << 1,0x5c3a40);
      }
      else if (cRam006cba7d == '\x02') {
        auStack_10[0] = 0xff;
        cRam006cba7c = '\0';
        cRam006cba78 = '\0';
        (*pcRam006cba5c)(auStack_10,auStack_10);
      }
    }
    else if (cRam006cba78 == '\0') {
      cRam006cba78 = '\x01';
      cRam006cba7d = '\0';
      pbVar13 = (byte *)0x6cc044;
      func_0x00106b60(0x7005c0,0,0x10);
      sVar3 = FUN_005bf1e0(0);
      uVar4 = FUN_005c4f00();
      pcVar5 = (char *)FUN_005c2ae0(sVar3 + -1,uVar4);
      bVar2 = bRam006d2296;
      uVar14 = (uint)bRam006d2296;
      func_0x00106b60(auStack_18,0,8);
      uVar10 = (int)*pcVar5 >> 2 & 3;
      uVar9 = (int)*pcVar5 >> 4 & 3;
      lVar7 = FUN_005c4f00();
      if (lVar7 == 0) {
        for (iVar6 = 0; iVar6 < (int)((uVar9 - uVar10) + 1 & 0xff); iVar6 = iVar6 + 1) {
          auStack_18[iVar6] = *(undefined2 *)(&DAT_00640528 + (iVar6 + uVar10) * 2);
        }
        cVar1 = *pcVar5;
        uVar9 = (int)cVar1 & 3;
        if ((cVar1 >> 7 & 1U) != 0) {
          uVar9 = (int)cVar1 & 3;
          if ((cVar1 >> 6 & 1U) != 0) {
            uVar9 = (uint)bRam006cc044;
          }
          pbVar13 = (byte *)0x6cc045;
        }
        uRam006ca888 = auStack_18[uVar9];
      }
      else {
        cRam007006a4 = (char)uVar10 + '\x01';
        cRam007006a5 = (char)uVar9 + '\x01';
        uRam006ca888 = *(undefined2 *)(&DAT_00640528 + uVar9 * 2);
      }
      uRam007006a6 = 0;
      lVar7 = FUN_005c4f00();
      if (lVar7 == 0) {
        cVar1 = pcVar5[1];
        uVar10 = (int)cVar1 & 7;
        if (((cVar1 >> 7 & 1U) != 0) && (uVar10 = (int)cVar1 & 7, (cVar1 >> 6 & 1U) != 0)) {
          uVar10 = (uint)*pbVar13;
        }
        iRam006febf0 = *(int *)(&DAT_00640530 + uVar10 * 4);
      }
      else {
        uVar10 = (int)pcVar5[1] & 0x3f;
        uRam007006a6 = (undefined1)uVar10;
        iRam006febf0 = uVar10 * 300;
      }
      uVar9 = uVar9 & 3 | (uVar10 & 7) << 2;
      if ((char)bVar2 < '\0') {
        uVar14 = 0;
      }
      iRam006febec = iRam006febf0;
      for (iVar6 = 0; iVar6 < (int)uVar14; iVar6 = iVar6 + 1) {
        *(undefined1 *)(iVar6 + 0x7005c9) = *(undefined1 *)(iVar6 + 0x6cc044);
      }
      uRam007005c0 = (ushort)bRam006d2296;
      lVar7 = FUN_005c4f00();
      if (lVar7 == 0) {
        if (cRam006d2295 == '\0') {
          sVar3 = FUN_005bf1e0(0);
          uVar8 = FUN_005c2b70(sVar3 + -1);
          func_0x00106b60(0x6cc03b,0,9);
          func_0x001069a8(0x6cc03b,uVar8,8);
        }
        if (cRam006cc03b != '\0') {
          uVar9 = uVar9 | 0x80;
        }
      }
      uVar10 = FUN_005bf1e0(1);
      uVar12 = 0;
      uVar11 = 1;
      iVar6 = 4;
      uVar14 = uRam007006b0;
      do {
        if (*(uint *)(iVar6 + 0x7006b0) < uVar14) {
          uVar12 = uVar11 & 0xff;
          uVar14 = *(uint *)(iVar6 + 0x7006b0);
        }
        uVar11 = uVar11 + 1;
        iVar6 = uVar11 * 4;
      } while ((int)uVar11 < 4);
      uRam006febe4 = uVar9 << 8 | *(uint *)(&DAT_0064054c + (uVar10 & 0xffff) * 4) |
                     *(uint *)(uVar12 * 4 + 0x640570) | uRam006febe4;
      func_0x001069a8(0x7005b0,0x7005c0,0x10);
      uRam007005ac = 1;
      func_0x001de470(uRam006febac,0x7004d0,0x5c39e0);
    }
  }
  return;
}



================================================================