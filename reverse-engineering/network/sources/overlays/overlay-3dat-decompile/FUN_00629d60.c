FUNCTION FUN_00629d60 @ 0x00629d60  size=2132
CALLERS (0): 
CALLEES (6): FUN_005af2e0@0x005af2e0, FUN_0062fea0@0x0062fea0, FUN_005b7cd0@0x005b7cd0, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0, FUN_0062fd90@0x0062fd90
----------------------------------------------------------------

void FUN_00629d60(int param_1)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  int iVar8;
  uint uVar9;
  undefined2 *puVar10;
  long lVar11;
  short *psVar12;
  undefined1 auStack_80 [128];
  
  iVar6 = *(int *)(param_1 + 0x10);
  cVar2 = *(char *)(param_1 + 3);
  if (cVar2 == '\x04') {
    FUN_005af2e0(0x14);
    FUN_005af2c0(0);
    iVar4 = 0;
    iVar8 = 0;
    iVar6 = 0;
    do {
      iVar6 = (iVar6 * 4 + iVar4 * 5) * 2;
      if (*(char *)(iVar6 + 0x6c5e5a) != '\0') {
        FUN_005af2e0(0x12);
        uVar7 = FUN_0062fea0(0x69);
        func_0x00109728(auStack_80,0x66ad48,uVar7,iVar4 * 0x25 + 0x6c5be5);
        FUN_005af1e0(DAT_0066acd0,(int)((float)(int)DAT_0066acd2 + (float)iVar8 * 22.0),0,auStack_80
                    );
        FUN_005b7cd0((float)(int)DAT_0066acd0,(float)(int)DAT_0066acd2 + (float)(iVar8 + 1) * 22.0,0
                     ,iVar6 + 0x6c5e5a);
        iVar8 = iVar8 + 2;
      }
      iVar4 = iVar4 + 1;
      iVar6 = iVar4 * 0x10;
    } while (iVar4 < 3);
  }
  else {
    iVar4 = 0;
    if ((cVar2 == '\x03') || (cVar2 == '\x02')) {
      iVar8 = 0;
      do {
        iVar8 = iVar8 * 4 + iVar4 * 5;
        if (*(char *)(iVar8 + 0x6c5be5) != '\0') {
          FUN_005af2e0(0x14);
          FUN_005af2c0(0x15);
          uVar7 = FUN_0062fea0(0x23);
          FUN_005af1e0(DAT_0066acc8,(int)DAT_0066acca + iVar4 * 0x20,0,uVar7);
          FUN_005af2c0(0x10);
          uVar7 = FUN_0062fea0(0x23);
          iVar5 = func_0x001ae3e0(uVar7);
          FUN_005af1e0((int)DAT_0066acc8 + iVar5 * 10,(int)DAT_0066acca + iVar4 * 0x20,0,
                       iVar8 + 0x6c5be5);
        }
        iVar4 = iVar4 + 1;
        iVar8 = iVar4 * 8;
      } while (iVar4 < 3);
      if (*(char *)(param_1 + 3) == '\x02') {
        FUN_005af2e0(0x14);
        FUN_005af2c0(0);
        iVar4 = func_0x001ae3e0(0x6c5b54);
        iVar8 = 0;
        for (; (iVar8 < 4 && (func_0x00106b60(auStack_80,0,0x80), 0 < iVar4)); iVar4 = iVar4 + -0x30
            ) {
          if (iVar4 < 0x30) {
            func_0x0010a4f0(auStack_80,iVar8 * 0x30 + 0x6c5b54,iVar4);
          }
          else {
            func_0x0010a4f0(auStack_80,iVar8 * 0x30 + 0x6c5b54,0x30);
          }
          FUN_005af1e0(DAT_0066acd0,(int)((float)(int)DAT_0066acd2 + (float)iVar8 * 22.0),0,
                       auStack_80);
          iVar8 = iVar8 + 1;
        }
        uVar7 = FUN_0062fea0(0x68);
        func_0x00109728(auStack_80,0x66a9d8,uVar7);
        if (*(short *)(iVar6 + 10) == 4) {
          FUN_005af2c0(0xf);
        }
        else {
          FUN_005af2c0(0);
        }
      }
      else {
        uVar7 = FUN_0062fea0(0x67);
        func_0x00109728(auStack_80,0x66a9d8,uVar7);
        if (*(short *)(iVar6 + 10) == 3) {
          FUN_005af2c0(0xf);
        }
        else {
          FUN_005af2c0(0);
        }
      }
      FUN_005af2e0(0x12);
      uVar7 = FUN_0062fea0(0x67);
      iVar6 = func_0x001ae3e0(uVar7);
      iVar6 = iVar6 * 9;
      if (iVar6 < 0) {
        iVar6 = iVar6 + 1;
      }
      FUN_005af1e0(0x140 - (iVar6 >> 1),0x168,0,auStack_80);
    }
    else if (cVar2 == '\x01') {
      FUN_005af2e0(0x14);
      FUN_005af2c0(0x15);
      uVar7 = FUN_0062fea0(0x23);
      FUN_005af1e0(DAT_0066acc8,DAT_0066acca,0,uVar7);
      FUN_005af2c0(0x10);
      uVar7 = FUN_0062fea0(0x23);
      iVar6 = func_0x001ae3e0(uVar7);
      FUN_005af1e0((int)DAT_0066acc8 + iVar6 + 10,DAT_0066acca,0,0x6c5a9b);
      FUN_005af2e0(0x14);
      FUN_005af2c0(0);
      iVar6 = func_0x001ae3e0(0x6c5aaf);
      for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {
        func_0x00106b60(auStack_80,0,0x80);
        if (iVar6 < 1) {
          return;
        }
        if (iVar6 < 0x30) {
          func_0x0010a4f0(auStack_80,iVar4 * 0x30 + 0x6c5aaf,iVar6);
        }
        else {
          func_0x0010a4f0(auStack_80,iVar4 * 0x30 + 0x6c5aaf,0x30);
        }
        iVar6 = iVar6 + -0x30;
        FUN_005af1e0(DAT_0066acd0,(int)((float)(int)DAT_0066acd2 + (float)iVar4 * 22.0),0,auStack_80
                    );
      }
    }
    else if (cVar2 == '\0') {
      FUN_005af2e0(0x12);
      FUN_005af2c0(0);
      lVar11 = 0;
      if (bRam006c555e == 0) {
        uVar7 = FUN_0062fea0(0x19);
        iVar4 = func_0x001ae3e0(uVar7);
        iVar4 = iVar4 * 9;
        if (iVar4 < 0) {
          iVar4 = iVar4 + 1;
        }
        FUN_005af1e0(0x140 - (iVar4 >> 1),0xa7,0,uVar7);
      }
      else {
        while (lVar11 < (long)(ulong)bRam006c555e) {
          bVar1 = *(short *)(iVar6 + 10) != lVar11;
          if (bVar1) {
            FUN_005af2e0(0x10);
            FUN_005af2c0(0);
          }
          else {
            FUN_005af2e0(0x12);
            FUN_005af2c0(0xf);
          }
          uVar9 = (uint)!bVar1;
          iVar8 = (int)lVar11;
          func_0x00109728(auStack_80,0x66ad40,iVar8 + 1);
          puVar10 = (undefined2 *)(iVar8 * 2 + uVar9 * 0x28 + 0x66acf0);
          iVar4 = uVar9 * 6;
          psVar12 = (short *)(iVar4 + 0x66acd8);
          FUN_005af1e0(*(undefined2 *)(iVar4 + 0x66acdc),*puVar10,0,auStack_80);
          FUN_005af2e0(0x14);
          FUN_005af2c0(0x15);
          uVar7 = FUN_0062fea0(0x23);
          FUN_005af1e0(*psVar12,*puVar10,0,uVar7);
          FUN_005af2c0(0x10);
          uVar7 = FUN_0062fea0(0x23);
          iVar4 = func_0x001ae3e0(uVar7);
          FUN_005af1e0(iVar4 + 10 + (int)*psVar12,*puVar10,0,iVar8 * 0xa5 + 0x6c5573);
          lVar11 = (long)(iVar8 + 1);
        }
      }
      FUN_005af2e0(0x12);
      FUN_005af2c0(0);
      uVar7 = FUN_0062fea0(0x4e);
      FUN_005af1e0(0x1c8,0x17,2,uVar7);
      iVar8 = 0;
      for (iVar4 = 0; iVar4 < (int)(uint)bRam006c555e; iVar4 = iVar4 + 1) {
        if (*(char *)(iVar4 * 0xa5 + 0x6c5562) != '\0') {
          iVar8 = iVar8 + 1;
        }
      }
      func_0x00109728(auStack_80,0x66ad40,iVar8);
      FUN_005af1e0(0x22b,0x17,2,auStack_80);
      iVar4 = FUN_0062fd90(0x11);
      iVar8 = 0;
      do {
        if ((long)*(short *)(iVar6 + 10) == (long)(iVar8 + 8)) {
          FUN_005af2c0(0xf);
          uVar3 = *(undefined4 *)(iVar4 + 8);
        }
        else {
          FUN_005af2c0(0);
          uVar3 = *(undefined4 *)(iVar4 + 8);
        }
        iVar5 = func_0x001ae3e0(uVar3);
        iVar5 = iVar5 * 9;
        if (iVar5 < 0) {
          iVar5 = iVar5 + 1;
        }
        FUN_005af1e0(0x140 - (iVar5 >> 1),*(undefined2 *)(&DAT_0066ad00 + iVar8 * 2),0,
                     *(undefined4 *)(iVar4 + 8));
        iVar8 = iVar8 + 1;
        iVar4 = iVar4 + 0xc;
      } while (iVar8 < 2);
    }
  }
  return;
}



================================================================