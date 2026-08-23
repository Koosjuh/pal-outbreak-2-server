FUNCTION FUN_005fcc70 @ 0x005fcc70  size=1840
CALLERS (0): 
CALLEES (7): FUN_005af2e0@0x005af2e0, FUN_00618c20@0x00618c20, FUN_0062fea0@0x0062fea0, FUN_005bac80@0x005bac80, FUN_005af2c0@0x005af2c0, FUN_005af1e0@0x005af1e0, FUN_005fe4b0@0x005fe4b0
----------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x005fcdd0) */
/* WARNING: Removing unreachable block (ram,0x005fcf88) */

void FUN_005fcc70(int param_1)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined1 auStack_80 [128];
  
  if (*(char *)(param_1 + 4) == '\0') {
    if (('\x01' < *(char *)(param_1 + 3)) &&
       ((int)(uint)bRam006970f4 <= *(char *)(param_1 + 3) + -2)) {
      FUN_00618c20();
      return;
    }
    *(char *)(param_1 + 4) = *(char *)(param_1 + 4) + '\x01';
    *(undefined1 *)(param_1 + 1) = 1;
  }
  if (*(char *)(param_1 + 3) < '\0') {
    FUN_005af2e0(0x10);
    FUN_005af2c0(0x15);
    uVar4 = FUN_0062fea0(0x24);
    FUN_005af1e0(0x48,0x3c,0,uVar4);
    uVar4 = FUN_0062fea0(0x25);
    FUN_005af1e0(0x148,0x3c,0,uVar4);
    FUN_005af2e0(0x12);
    if (cRam006970a0 == '\x01') {
      FUN_005af2c0(0);
      uVar4 = FUN_0062fea0(9);
      FUN_005af1e0(0x48,0x56,0,uVar4);
      if (cRam006c5498 == '\0') {
        FUN_005af2c0(0xf);
      }
      func_0x00109eb8(auStack_80,0x6970b2);
      lVar5 = func_0x001ae3e0(auStack_80);
      if (lVar5 == 0) {
        FUN_005af1e0(0x148,0x56,0,auStack_80);
        for (iVar7 = 0; iVar7 < 10; iVar7 = iVar7 + 1) {
          FUN_005af1e0(iVar7 * 9 + 0x148,0x56,0,0x649ae0);
        }
      }
      else {
        FUN_005af1e0(0x148,0x56,0,auStack_80);
      }
    }
    else {
      FUN_005af2c0(2);
      uVar4 = FUN_0062fea0(9);
      FUN_005af1e0(0x48,0x56,0,uVar4);
      if (cRam006c5498 == '\0') {
        FUN_005af2c0(0xf);
      }
      else {
        FUN_005af2c0(0);
      }
      func_0x00109eb8(auStack_80,0x6970b2);
      func_0x001ae3e0(auStack_80);
      FUN_005af1e0(0x148,0x56,0,auStack_80);
    }
    FUN_005af2c0(0);
    FUN_005af2e0(0x12);
    if (cRam006970a1 != '\x01') {
      FUN_005af2c0(2);
    }
    uVar4 = FUN_0062fea0(10);
    FUN_005af1e0(0x48,0x72,0,uVar4);
    if (cRam006c5498 == '\x01') {
      FUN_005af2c0(0xf);
    }
    else {
      FUN_005af2c0(0);
    }
    if (cRam006970a1 == '\x01') {
      func_0x00109eb8(auStack_80,0x6970a2);
      lVar5 = func_0x001ae3e0(auStack_80);
      if (lVar5 == 0) {
        FUN_005af1e0(0x148,0x72,0,auStack_80);
        for (iVar7 = 0; iVar7 < 4; iVar7 = iVar7 + 1) {
          FUN_005af1e0(iVar7 * 9 + 0x148,0x72,0,0x649ae0);
        }
      }
      else {
        FUN_005af1e0(0x148,0x72,0,auStack_80);
      }
    }
    else {
      uVar4 = FUN_0062fea0(0xb);
      FUN_005af1e0(0x148,0x72,0,uVar4);
    }
    uVar9 = (uint)bRam006970f4;
    iVar6 = 0;
    FUN_005af2e0(0x12);
    for (iVar7 = 0; iVar7 < (int)uVar9; iVar7 = iVar7 + 1) {
      func_0x00106b60(auStack_80,0,0x80);
      FUN_005af2c0(0);
      iVar3 = iVar6 * 0x14a8;
      if (*(char *)(iVar3 + 0x697138) != '\x01') {
        FUN_005af2c0(2);
      }
      func_0x00109eb8(auStack_80,iVar3 + 0x6970f6);
      func_0x001ae3e0(auStack_80);
      iVar8 = (iVar7 + 2) * 0x1c + 0x56;
      FUN_005af1e0(0x48,iVar8,0,auStack_80);
      if ((long)cRam006c5498 == (long)(iVar7 + 2)) {
        FUN_005af2c0(0xf);
        bVar2 = *(byte *)(iVar3 + 0x69713a);
      }
      else {
        FUN_005af2c0(0);
        bVar2 = *(byte *)(iVar3 + 0x69713a);
      }
      func_0x00109eb8(auStack_80,iVar3 + (uint)bVar2 * 0x41 + 0x69715d);
      func_0x001ae3e0(auStack_80);
      FUN_005af1e0(0x148,iVar8,0,auStack_80);
      iVar6 = iVar6 + 1;
    }
    FUN_005af2e0(0x12);
    FUN_005af2c0(0);
    uVar4 = FUN_0062fea0(6);
    FUN_005af1e0(0x48,0x136,0,uVar4);
    if (cRam006c5498 == '\b') {
      FUN_005af2c0(0xf);
    }
    else {
      FUN_005af2c0(0);
    }
    lVar5 = FUN_005bac80(uRam006c4b96);
    if (lVar5 != 0) {
      FUN_005af1e0(0x148,0x136,0,lVar5);
    }
    FUN_005af2e0(0x12);
    FUN_005af2c0(0);
    uVar4 = FUN_0062fea0(0x14);
    FUN_005af1e0(0x48,0x152,0,uVar4);
    if (cRam006c5498 == '\t') {
      FUN_005af2c0(0xf);
    }
    else {
      FUN_005af2c0(0);
    }
    iVar7 = sRam006c4b94 * 4;
    if (*(char *)(iVar7 + 0x6c4baa) == '\0') {
      lVar5 = func_0x001b6950(*(undefined1 *)(iVar7 + 0x6c4bac));
      if (lVar5 != 0) {
        cVar1 = *(char *)(sRam006c4b94 * 4 + 0x6c4bab);
        if (cVar1 == '\0') {
          FUN_005af1e0(0x160,0x152,0,lVar5);
        }
        else {
          func_0x00109728(auStack_80,0x649ae8,lVar5,(&PTR_DAT_0068ae30)[cVar1]);
          FUN_005af1e0(0x160,0x152,0,auStack_80);
        }
      }
    }
    else {
      lVar5 = FUN_005fe4b0(*(undefined1 *)(iVar7 + 0x6c4bac));
      if ((-1 < lVar5) && (lVar5 = func_0x001b68b0(lVar5), lVar5 != 0)) {
        FUN_005af1e0(0x160,0x152,0,lVar5);
      }
    }
    FUN_005af2e0(0x12);
    if (cRam006c5498 == '\n') {
      FUN_005af2c0(0xf);
    }
    else {
      FUN_005af2c0(0);
    }
    uVar4 = FUN_0062fea0(0xc);
    lVar5 = func_0x001ae3e0(uVar4);
    uVar4 = FUN_0062fea0(0xc);
    iVar7 = (int)lVar5;
    if (lVar5 < 0) {
      iVar7 = iVar7 + 1;
    }
    iVar6 = (iVar7 >> 1) * 0x12;
    iVar7 = (int)((ulong)((long)((iVar7 >> 1) * 9) << 0x21) >> 0x20);
    if (iVar6 < 0) {
      iVar7 = iVar6 + 1;
    }
    FUN_005af1e0(0x140 - (iVar7 >> 1),0x16e,0,uVar4);
  }
  return;
}



================================================================