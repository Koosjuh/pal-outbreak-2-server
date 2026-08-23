FUNCTION FUN_005fd9e0 @ 0x005fd9e0  size=1860
CALLERS (0): 
CALLEES (7): FUN_005af2e0@0x005af2e0, FUN_00618c20@0x00618c20, FUN_0062fea0@0x0062fea0, FUN_005bac80@0x005bac80, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0, FUN_005fe4b0@0x005fe4b0
----------------------------------------------------------------

void FUN_005fd9e0(int param_1)

{
  char cVar1;
  int *piVar2;
  long lVar3;
  undefined8 uVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined1 auStack_80 [128];
  
  if (*(char *)(param_1 + 4) != '\0') goto LAB_005fda74;
  if (*(char *)(param_1 + 2) == '\0') {
    if (('\x01' < *(char *)(param_1 + 3)) &&
       ((int)(uint)bRam006970f4 <= *(char *)(param_1 + 3) + -2)) {
      FUN_00618c20();
      return;
    }
LAB_005fda60:
    cVar1 = *(char *)(param_1 + 4);
  }
  else {
    if (*(char *)(param_1 + 2) == '\x01') goto LAB_005fda60;
    cVar1 = *(char *)(param_1 + 4);
  }
  *(char *)(param_1 + 4) = cVar1 + '\x01';
  *(undefined1 *)(param_1 + 1) = 1;
LAB_005fda74:
  if (((*(char *)(param_1 + 2) == '\x01') && (cVar1 = *(char *)(param_1 + 3), -1 < cVar1)) &&
     (cVar1 < '\b')) {
    if (*(char *)((cVar1 * 0x3c - (int)cVar1) * 0x10 + 0x6c7c2c) == '\0') {
      *(undefined1 *)(param_1 + 1) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 1) = 1;
    }
  }
  if (*(char *)(param_1 + 3) < '\0') {
    cVar1 = *(char *)(param_1 + 2);
    if (cVar1 == '\x03') {
      lVar3 = FUN_005bac80((undefined1)uRam006c4b96);
      if (lVar3 != 0) {
        FUN_005af2e0(0x14);
        FUN_005af2c0(0);
        FUN_005af1e0(100,0x68,0,lVar3);
      }
      piVar2 = (int *)func_0x001b6a90(uRam006c4b96);
      if (piVar2 != (int *)0x0) {
        FUN_005af2e0(0x12);
        FUN_005af2c0(0);
        sVar5 = 0x94;
        for (; *piVar2 != 0; piVar2 = piVar2 + 1) {
          FUN_005af1e0(0x5c,sVar5,0);
          sVar5 = sVar5 + 0x16;
        }
      }
    }
    else {
      if (cVar1 == '\0') {
        FUN_005af2e0(0x10);
        FUN_005af2c0(0x15);
        uVar4 = FUN_0062fea0(0x25);
        FUN_005af1e0(0x48,0x3c,0,uVar4);
        uVar4 = FUN_0062fea0(0x24);
        FUN_005af1e0(0x148,0x3c,0,uVar4);
        FUN_005af2e0(0x12);
        FUN_005af2c0(0x14);
        uVar4 = FUN_0062fea0(9);
        FUN_005af1e0(0x48,0x56,0,uVar4);
        FUN_005af1e0(0x148,0x56,0,0x6970b2);
        FUN_005af2e0(0x12);
        uVar4 = FUN_0062fea0(10);
        FUN_005af1e0(0x48,0x72,0,uVar4);
        if (cRam006c550e == '\0') {
          uVar4 = FUN_0062fea0(bRam006970f2 + 0x29);
          FUN_005af1e0(0x148,0x72,0,uVar4);
        }
        else {
          FUN_005af1e0(0x148,0x72,0);
        }
        iVar6 = 0;
        uVar8 = (uint)bRam006970f4;
        for (iVar7 = 0; iVar7 < (int)uVar8; iVar7 = iVar7 + 1) {
          func_0x00106b60(auStack_80,0,0x80);
          iVar9 = iVar6 * 0x14a8;
          iVar10 = (iVar7 + 2) * 0x1c + 0x56;
          FUN_005af1e0(0x48,iVar10,0,iVar9 + 0x6970f6);
          FUN_005af1e0(0x148,iVar10,0,iVar9 + (uint)*(byte *)(iVar9 + 0x69713a) * 0x41 + 0x69715d);
          iVar6 = iVar6 + 1;
        }
      }
      else if (cVar1 == '\x01') {
        FUN_005af2e0(0x10);
        FUN_005af2c0(0x15);
        uVar4 = FUN_0062fea0(0x27);
        FUN_005af1e0(0x48,0x3c,0,uVar4);
        uVar4 = FUN_0062fea0(0x28);
        FUN_005af1e0(0x172,0x3c,0,uVar4);
        FUN_005af2e0(0x12);
        iVar7 = 0;
        iVar9 = 0;
        iVar6 = 0;
        do {
          iVar6 = (iVar6 * 4 + iVar7 * -5) * 0x10;
          if (*(char *)(iVar6 + 0x6c7c2c) != '\0') {
            func_0x00109728(auStack_80,0x649888,iVar6 + 0x6c7c3c);
            FUN_005af2c0(0x11);
            iVar10 = iVar9 * 0x1c + 0x56;
            FUN_005af1e0(0x48,iVar10,0,auStack_80);
            FUN_005af2c0(0);
            if (*(short *)(iVar6 + 0x6c7d1a) == 0) {
              uVar4 = func_0x001b6950(*(undefined2 *)(iVar6 + 0x6c7d18));
              func_0x00109728(auStack_80,0x649ae8,uVar4,
                              (&PTR_DAT_0068ae30)[*(short *)(iVar6 + 0x6c7d1c)]);
              FUN_005af1e0(0x192,iVar10,0,auStack_80);
              iVar9 = iVar9 + 1;
            }
            else {
              lVar3 = FUN_005fe4b0(*(undefined2 *)(iVar6 + 0x6c7d18));
              if ((-1 < lVar3) && (lVar3 = func_0x001b68b0(lVar3), lVar3 != 0)) {
                FUN_005af1e0(0x192,iVar10,0,lVar3);
              }
              iVar9 = iVar9 + 1;
            }
          }
          iVar7 = iVar7 + 1;
          iVar6 = iVar7 * 0x10;
        } while (iVar7 < 4);
      }
      FUN_005af2e0(0x12);
      FUN_005af2c0(0x14);
      uVar4 = FUN_0062fea0(6);
      FUN_005af1e0(0x48,0x136,0,uVar4);
      lVar3 = FUN_005bac80((undefined1)uRam006c4b96);
      if (lVar3 != 0) {
        FUN_005af1e0(0x148,0x136,0,lVar3);
      }
      FUN_005af2e0(0x12);
      FUN_005af2c0(0);
      uVar4 = FUN_0062fea0(0x14);
      FUN_005af1e0(0x48,0x152,0,uVar4);
      if (cRam006c5499 == '\0') {
        FUN_005af2c0(0xf);
      }
      else {
        FUN_005af2c0(0);
      }
      iVar6 = sRam006c4b94 * 4;
      if (*(char *)(iVar6 + 0x6c4baa) == '\0') {
        lVar3 = func_0x001b6950(*(undefined1 *)(iVar6 + 0x6c4bac));
        if (lVar3 != 0) {
          cVar1 = *(char *)(sRam006c4b94 * 4 + 0x6c4bab);
          if (cVar1 == '\0') {
            FUN_005af1e0(0x160,0x152,0,lVar3);
          }
          else {
            func_0x00109728(auStack_80,0x649ae8,lVar3,(&PTR_DAT_0068ae30)[cVar1]);
            FUN_005af1e0(0x160,0x152,0,auStack_80);
          }
        }
      }
      else {
        lVar3 = FUN_005fe4b0(*(undefined1 *)(iVar6 + 0x6c4bac));
        if ((-1 < lVar3) && (lVar3 = func_0x001b68b0(lVar3), lVar3 != 0)) {
          FUN_005af1e0(0x160,0x152,0,lVar3);
        }
      }
      FUN_005af2e0(0x12);
      if (cRam006c5499 == '\x01') {
        FUN_005af2c0(0xf);
      }
      else {
        FUN_005af2c0(0);
      }
      uVar4 = FUN_0062fea0(0xe);
      lVar3 = func_0x001ae3e0(uVar4);
      uVar4 = FUN_0062fea0(0xe);
      iVar6 = (int)lVar3;
      if (lVar3 < 0) {
        iVar6 = iVar6 + 1;
      }
      iVar7 = (iVar6 >> 1) * 0x12;
      iVar6 = (int)((ulong)((long)((iVar6 >> 1) * 9) << 0x21) >> 0x20);
      if (iVar7 < 0) {
        iVar6 = iVar7 + 1;
      }
      FUN_005af1e0(0x140 - (iVar6 >> 1),0x16e,0,uVar4);
    }
  }
  return;
}



================================================================