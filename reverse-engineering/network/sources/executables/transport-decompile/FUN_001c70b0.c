
undefined8 FUN_001c70b0(undefined8 param_1)

{
  bool bVar1;
  ushort uVar2;
  byte bVar3;
  undefined1 uVar4;
  ushort uVar5;
  long lVar6;
  int *piVar7;
  ushort *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  piVar7 = (int *)param_1;
  if (*(char *)(piVar7[0xc] + 6) == -1) {
    piVar7[0x37] = 9;
    *(undefined1 *)(piVar7 + 3) = 7;
    *(undefined1 *)((int)piVar7 + 0xd) = 0;
    *(undefined1 *)((int)piVar7 + 0xe) = 0;
    *(undefined1 *)((int)piVar7 + 0xf) = 0;
    *(undefined2 *)(piVar7 + 4) = 0;
    *(undefined2 *)((int)piVar7 + 0x12) = 0;
    *(undefined2 *)(piVar7 + 5) = 0;
    *(undefined2 *)((int)piVar7 + 0x16) = 0;
  }
  else {
    uVar5 = FUN_001c3ab0();
    uVar2 = uRam00365e1e;
    bVar1 = uVar5 < uRam00365e1e;
    uRam00365e1e = uVar5;
    if (bVar1) {
      for (; uVar9 = 0, uVar5 < uVar2; uVar5 = uVar5 + 1) {
        do {
          puVar8 = (ushort *)(uVar9 * 2 + 0x3619d0);
          if (uVar5 == *puVar8) {
            *puVar8 = 0xffff;
          }
          uVar9 = uVar9 + 1 & 0xff;
        } while (uVar9 < 0x40);
      }
    }
    if (uRam00365e1e < 0x11) {
      if (uRam00365e1e == 0) {
        piVar7[0x37] = -1;
        *(undefined1 *)(piVar7 + 3) = 7;
        *(undefined1 *)((int)piVar7 + 0xd) = 0;
        *(undefined1 *)((int)piVar7 + 0xe) = 0;
        *(undefined1 *)((int)piVar7 + 0xf) = 0;
        *(undefined2 *)(piVar7 + 4) = 0;
        *(undefined2 *)((int)piVar7 + 0x12) = 0;
        *(undefined2 *)(piVar7 + 5) = 0;
        *(undefined2 *)((int)piVar7 + 0x16) = 0;
        return 0;
      }
    }
    else {
      if (*piVar7 == 1) {
        piVar7[0x37] = -1;
        *(undefined1 *)(piVar7 + 3) = 7;
        *(undefined1 *)((int)piVar7 + 0xd) = 0;
        *(undefined1 *)((int)piVar7 + 0xe) = 0;
        *(undefined1 *)((int)piVar7 + 0xf) = 0;
        *(undefined2 *)(piVar7 + 4) = 0;
        *(undefined2 *)((int)piVar7 + 0x12) = 0;
        *(undefined2 *)(piVar7 + 5) = 0;
        *(undefined2 *)((int)piVar7 + 0x16) = 0;
        return 0;
      }
      uRam00365e1e = 0x10;
    }
    uRam00365e18 = FUN_001c3ab0(param_1);
    bVar3 = FUN_001c3a60(param_1);
    bRam00365e1c = bVar3;
    for (uVar9 = 0; uVar9 < bVar3; uVar9 = uVar9 + 1 & 0xff) {
      lVar6 = FUN_001c3b90(param_1,(uRam00365e0c + uVar9) * 0x260 + 0x365e20,0x3e);
      if (lVar6 < 0) {
        piVar7[0x37] = -1;
        *(undefined1 *)(piVar7 + 3) = 7;
        *(undefined1 *)((int)piVar7 + 0xd) = 0;
        *(undefined1 *)((int)piVar7 + 0xe) = 0;
        *(undefined1 *)((int)piVar7 + 0xf) = 0;
        *(undefined2 *)(piVar7 + 4) = 0;
        *(undefined2 *)((int)piVar7 + 0x12) = 0;
        *(undefined2 *)(piVar7 + 5) = 0;
        *(undefined2 *)((int)piVar7 + 0x16) = 0;
        return 0;
      }
      lVar6 = FUN_001c3b90(param_1,(uRam00365e0c + uVar9) * 0x260 + 0x365e5f,0xf);
      uVar10 = 0;
      if (lVar6 < 0) {
        piVar7[0x37] = -1;
        *(undefined1 *)(piVar7 + 3) = 7;
        *(undefined1 *)((int)piVar7 + 0xd) = 0;
        *(undefined1 *)((int)piVar7 + 0xe) = 0;
        *(undefined1 *)((int)piVar7 + 0xf) = 0;
        *(undefined2 *)(piVar7 + 4) = 0;
        *(undefined2 *)((int)piVar7 + 0x12) = 0;
        *(undefined2 *)(piVar7 + 5) = 0;
        *(undefined2 *)((int)piVar7 + 0x16) = 0;
        return 0;
      }
      do {
        uVar4 = FUN_001c3a60(param_1);
        uVar11 = uVar10 + 1 & 0xff;
        *(undefined1 *)(uVar10 + (uRam00365e0c + uVar9) * 0x260 + 0x365e6f) = uVar4;
        uVar10 = uVar11;
      } while (uVar11 < 8);
      lVar6 = FUN_001c3b90(param_1,(uRam00365e0c + uVar9) * 0x260 + 0x365e77,0xff);
      if (lVar6 < 0) {
        piVar7[0x37] = -1;
        *(undefined1 *)(piVar7 + 3) = 7;
        *(undefined1 *)((int)piVar7 + 0xd) = 0;
        *(undefined1 *)((int)piVar7 + 0xe) = 0;
        *(undefined1 *)((int)piVar7 + 0xf) = 0;
        *(undefined2 *)(piVar7 + 4) = 0;
        *(undefined2 *)((int)piVar7 + 0x12) = 0;
        *(undefined2 *)(piVar7 + 5) = 0;
        *(undefined2 *)((int)piVar7 + 0x16) = 0;
        return 0;
      }
      *(undefined4 *)((uRam00365e0c + uVar9) * 0x260 + 0x365f7c) = 0;
    }
    uRam00365e18 = uRam00365e18 + bVar3;
    if (uRam00365e18 < uRam00365e1e) {
      uRam00365e0c = uRam00365e0c + bVar3;
      *(undefined1 *)((int)piVar7 + 0xd) = 6;
    }
    else if (*piVar7 == 4) {
      uRam00365e10 = 0;
      uRam00365e0c = uRam00365e0e;
      if (uRam00365e0e != 0) {
        for (uVar9 = 0; uVar9 < uRam00365e0e; uVar9 = uVar9 + 1 & 0xff) {
          sRam00365e12 = sRam00365e12 + *(short *)(uVar9 * 0x260 + 0x365f78);
        }
      }
      *(undefined1 *)((int)piVar7 + 0xd) = 8;
    }
    else {
      uRam00365e10 = 0;
      uRam00365e0c = 0;
      *(undefined1 *)((int)piVar7 + 0xd) = 8;
    }
  }
  return 0;
}

