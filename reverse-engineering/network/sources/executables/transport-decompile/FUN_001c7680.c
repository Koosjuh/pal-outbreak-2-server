
undefined8 FUN_001c7680(undefined8 param_1)

{
  ushort uVar1;
  ushort uVar2;
  char cVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  ushort *puVar7;
  ushort uVar8;
  uint uVar9;
  
  uVar2 = uRam00365e0c;
  piVar5 = (int *)param_1;
  if (*(char *)(piVar5[0xc] + 6) == -1) {
    iVar6 = *piVar5;
    if (iVar6 == 4) {
      uRam0035ccb4 = 1;
      uVar8 = 0;
      iVar6 = ((uint)uRam00365e0c * 0x12 + (uint)uRam00365e0c) * 0x20;
      uVar1 = *(ushort *)(iVar6 + 0x365f78);
      for (uVar9 = 0; uVar9 < 0x40; uVar9 = uVar9 + 1 & 0xff) {
        puVar7 = (ushort *)(uVar9 * 2 + 0x3619d0);
        if (uVar2 == *puVar7) {
          uVar8 = uVar8 + 1 & 0xff;
          *puVar7 = 0xffff;
          if (uVar1 < uVar8) break;
        }
      }
      *(undefined4 *)(iVar6 + 0x365f7c) = 0;
      *(undefined2 *)(((uint)uRam00365e0c * 0x12 + (uint)uRam00365e0c) * 0x20 + 0x365f78) = 0;
      uRam00365e0e = 0;
      uRam00365e0c = 0;
      *(undefined1 *)((int)piVar5 + 0xd) = 4;
    }
    else if ((((iVar6 == 5) || (iVar6 == 1)) || (iVar6 == 7)) || (iVar6 == 0)) {
      piVar5[0x37] = 9;
      *(undefined1 *)(piVar5 + 3) = 7;
      *(undefined1 *)((int)piVar5 + 0xd) = 0;
      *(undefined1 *)((int)piVar5 + 0xe) = 0;
      *(undefined1 *)((int)piVar5 + 0xf) = 0;
      *(undefined2 *)(piVar5 + 4) = 0;
      *(undefined2 *)((int)piVar5 + 0x12) = 0;
      *(undefined2 *)(piVar5 + 5) = 0;
      *(undefined2 *)((int)piVar5 + 0x16) = 0;
    }
    else {
      *(undefined1 *)((int)piVar5 + 0xd) = 0x31;
    }
  }
  else {
    cVar3 = FUN_001c3a60();
    if (cVar3 == '\x01') {
      uRam00365e08 = FUN_001c3b10(param_1);
      uVar4 = FUN_001c3b10(param_1);
      *(undefined4 *)(((uint)uRam00365e0c * 0x12 + (uint)uRam00365e0c) * 0x20 + 0x365f7c) = uVar4;
      *(undefined1 *)((int)piVar5 + 0xd) = 10;
    }
    else if (cVar3 == '\0') {
      uRam00365e0c = uRam00365e0c + 1;
      if ((uRam00365e0c < uRam00365e1e) && (*piVar5 != 4)) {
        uRam00365e12 = 0;
        uRam00365e10 = 0;
        *(undefined1 *)((int)piVar5 + 0xd) = 8;
      }
      else {
        uRam00365e12 = 0;
        uRam00365e10 = 0;
        uRam00365e0c = 0;
        if (uRam00365f78 < 0x100) {
          uRam00365e1c = (undefined1)uRam00365f78;
        }
        else {
          uRam00365e1c = 0xff;
        }
        *(undefined1 *)((int)piVar5 + 0xd) = 0xc;
      }
    }
    else {
      *(undefined1 *)((int)piVar5 + 0xd) = 4;
    }
    uRam00365e1a = 8;
  }
  uRam00365e18 = 0;
  return 0;
}

