FUNCTION FUN_005c6500 @ 0x005c6500  size=2136
CALLERS (0): 
CALLEES (9): FUN_005c5bb0@0x005c5bb0, FUN_005c5e30@0x005c5e30, FUN_005c5d30@0x005c5d30, FUN_005c5cd0@0x005c5cd0, FUN_005c6360@0x005c6360, FUN_005c28f0@0x005c28f0, FUN_005c5eb0@0x005c5eb0, FUN_005c5120@0x005c5120, FUN_005c5db0@0x005c5db0
----------------------------------------------------------------

void FUN_005c6500(void)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  char cVar7;
  byte bVar8;
  byte bStack_80;
  undefined1 uStack_7f;
  ushort uStack_7e;
  undefined1 auStack_7c [60];
  byte abStack_40 [18];
  undefined1 auStack_2e [22];
  undefined1 auStack_18 [16];
  undefined4 uStack_8;
  char cStack_4;
  byte bStack_3;
  
  if (cRam006cbb94 != '\0') {
    if (cRam006cbb90 == 'c') {
      auStack_18[0] = 0;
      cRam006cbb94 = '\0';
      cRam006cbb90 = '\0';
      (*pcRam006cbb74)(auStack_18,auStack_18);
    }
    else if (cRam006cbb90 == '\r') {
      cRam006cbb90 = 'c';
      for (iVar1 = 0; iVar1 < (int)(uint)bRam006ff2b3; iVar1 = iVar1 + 1) {
        iVar6 = iVar1 * 0x114;
        func_0x0010a4f0(iVar6 + 0x6fffad,iVar6 + 0x700710,0x10);
        func_0x0010a4f0(iVar6 + 0x6fffbd,iVar6 + 0x700720,0x10);
        func_0x001069a8(iVar6 + 0x6fffd1,iVar6 + 0x700734,0xf0);
      }
    }
    else if (cRam006cbb90 == '\f') {
      cRam006cbb90 = '\r';
      for (iVar1 = 1; iVar1 < (int)(uint)bRam00700708; iVar1 = iVar1 + 1) {
        FUN_005c5120(iVar1 * 0x114 + 0x700b60,&uStack_8);
        FUN_005c5eb0(uStack_8);
      }
    }
    else if (cRam006cbb90 == '\v') {
      func_0x00106b60(&bStack_80,0,0x36);
      bStack_80 = bRam007006f8;
      uStack_7e = ((ushort)bRam007006f0 * 5 + (ushort)bRam007006f0 * 0x14) * 2;
      if (bRam007006f0 < 4) {
        uStack_7f = 0x32;
      }
      else {
        uStack_7f = 0x28;
      }
      func_0x001069a8(auStack_7c,
                      (uint)uStack_7e + ((uint)bRam007006f8 * 0x44 + (uint)bRam007006f8) * 4 +
                      0x700734,uStack_7f);
      FUN_005c5120(((uint)bRam00700700 * 0x44 + (uint)bRam00700700) * 4 + 0x700b60,&uStack_8);
      FUN_005c5e30(uStack_8,&bStack_80);
      bRam007006f0 = bRam007006f0 + 1;
      if (4 < bRam007006f0) {
        bRam007006f0 = 0;
        bRam007006f8 = bRam007006f8 + 1;
        if (bRam00700708 <= bRam007006f8) {
          bRam00700700 = bRam00700700 + 1;
          if (bRam00700700 < bRam00700708) {
            bRam007006f8 = 0;
          }
          else {
            cRam006cbb90 = cRam006cbb90 + '\x01';
          }
        }
      }
    }
    else if (cRam006cbb90 == '\n') {
      if (bRam006ff2b3 < 2) {
        cRam006cbb90 = '\r';
      }
      else {
        cRam006cbb90 = '\v';
        bRam00700700 = 1;
        bRam007006f8 = 0;
        bRam007006f0 = 0;
      }
    }
    else if (cRam006cbb90 == '\t') {
      func_0x00106b60(abStack_40,0,0x22);
      abStack_40[1] = 0;
      abStack_40[0] = bRam007006f8;
      func_0x001069a8(abStack_40 + 2,((uint)bRam00700700 * 0x44 + (uint)bRam00700700) * 4 + 0x700b60
                      ,0x10);
      func_0x001069a8(auStack_2e,((uint)bRam007006f8 * 0x44 + (uint)bRam007006f8) * 4 + 0x700720,
                      0x10);
      FUN_005c5120(((uint)bRam00700700 * 0x44 + (uint)bRam00700700) * 4 + 0x700b60,&uStack_8);
      FUN_005c5db0(uStack_8,abStack_40);
      bRam007006f8 = bRam007006f8 + 1;
      if (bRam00700708 <= bRam007006f8) {
        bRam00700700 = bRam00700700 + 1;
        if (bRam00700700 < bRam00700708) {
          bRam007006f8 = 0;
        }
        else {
          cRam006cbb90 = cRam006cbb90 + '\x01';
        }
      }
    }
    else if (cRam006cbb90 == '\b') {
      if (bRam006ff2b3 < 2) {
        cRam006cbb90 = '\r';
      }
      else {
        cRam006cbb90 = '\t';
        bRam00700700 = 1;
        bRam007006f8 = 0;
        bRam007006f0 = 0;
      }
    }
    else {
      if (cRam006cbb90 != '\a') {
        if (cRam006cbb90 != '\x06') {
          if (cRam006cbb90 != '\x05') {
            if (cRam006cbb90 != '\x04') {
              if (cRam006cbb90 == '\x03') {
                return;
              }
              if (cRam006cbb90 != '\0') {
                return;
              }
              cRam006cbb90 = 1;
              uRam006cbb78 = 0;
              uRam006cbb95 = 0;
              iRam006cbb7c = 0;
              bRam006ff2b3 = 0;
              func_0x00106b60(0x6ff70d,0,0x450);
              func_0x00106b60(0x6ffb5d,0,0x450);
              func_0x00106b60(0x6ff2b5,0,4);
              bRam006ff2b3 = 0;
              uRam006ff2b5 = 1;
              iVar6 = 0;
              iVar1 = 0;
              do {
                iVar1 = (iVar1 * 4 + iVar6 * 5) * 4;
                pcVar4 = (char *)(iVar1 + 0x6ff2bd);
                if (*pcVar4 != '\0') {
                  iVar2 = 0x8a;
                  pcVar3 = (char *)(iVar1 + 0x6ff70d);
                  do {
                    iVar2 = iVar2 + -1;
                    cVar7 = pcVar4[1];
                    *pcVar3 = *pcVar4;
                    pcVar4 = pcVar4 + 2;
                    pcVar3[1] = cVar7;
                    pcVar3 = pcVar3 + 2;
                  } while (0 < iVar2);
                  bRam006ff2b3 = bRam006ff2b3 + 1;
                }
                iVar6 = iVar6 + 1;
                iVar1 = iVar6 * 0x10;
              } while (iVar6 < 4);
              uVar5 = (uint)bRam006ff2b3;
              for (iVar1 = 0; iVar1 < (int)uVar5; iVar1 = iVar1 + 1) {
                FUN_005c5120(iVar1 * 0x114 + 0x6ff70d,&uStack_8);
                FUN_005c5bb0(uStack_8);
              }
              FUN_005c28f0(0,0x5c6350);
              return;
            }
            iRam006cbb7c = 900;
            cRam006cbb90 = '\x05';
          }
          uVar5 = 0;
          for (iVar1 = 0; iVar1 < (int)(uint)bRam006ff2b3; iVar1 = iVar1 + 1) {
            if (*(char *)(iVar1 + 0x6ff2b5) != '\0') {
              uVar5 = uVar5 + 1;
            }
          }
          iRam006cbb7c = iRam006cbb7c + -1;
          if ((-1 < iRam006cbb7c) && (uVar5 != bRam006ff2b3)) {
            return;
          }
          cRam006cbb90 = cRam006cbb90 + '\x01';
          return;
        }
        cRam006cbb90 = '\a';
        iRam006cbb7c = 0;
      }
      bVar8 = 0;
      cRam006cbb90 = cRam006cbb90 + '\x01';
      for (iVar1 = 0; iVar1 < (int)(uint)bRam006ff2b3; iVar1 = iVar1 + 1) {
        if (*(char *)(iVar1 + 0x6ff2b5) == '\x01') {
          bVar8 = bVar8 + 1;
        }
      }
      iVar1 = 0;
      cVar7 = '\x01';
      while (iVar1 < (int)(uint)bRam006ff2b3) {
        func_0x00106b60(&cStack_4,0,2);
        if (iVar1 < 1) {
LAB_005c68c0:
          iVar1 = iVar1 + 1;
        }
        else {
          if (*(char *)(iVar1 + 0x6ff2b5) != '\x01') {
            if (*(char *)(iVar1 + 0x6ff2b5) == '\0') {
              FUN_005c5120(iVar1 * 0x114 + 0x6ff70d,&uStack_8);
              FUN_005c5cd0(uStack_8);
            }
            goto LAB_005c68c0;
          }
          cStack_4 = cVar7;
          bStack_3 = bVar8;
          FUN_005c5120(iVar1 * 0x114 + 0x6ff70d,&uStack_8);
          FUN_005c5d30(uStack_8,&cStack_4);
          iVar1 = iVar1 + 1;
          cVar7 = cVar7 + '\x01';
        }
      }
      FUN_005c6360();
      uRam006ff2b4 = 0;
      bRam006ff2b3 = bVar8;
    }
  }
  return;
}



================================================================